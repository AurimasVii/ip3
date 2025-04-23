#include "notifier.hpp"
#include <curl/curl.h>
#include <iostream>
#include <stdexcept>

class EmailNotifier : public Notifier {
public:
    void send(const std::string& recipient, const std::string& sender,
              const std::string& password, const std::string& message) override {
        CURL* curl = curl_easy_init();
        if (!curl) {
            throw std::runtime_error("Failed to initialize CURL for EmailNotifier");
        }

        try {
            struct curl_slist* recipients = nullptr;
            std::string from = "<" + sender + ">";
            std::string data = "To: " + recipient + "\r\nFrom: " + sender +
                               "\r\nSubject: C++ Notification\r\n\r\n" + message;

            curl_easy_setopt(curl, CURLOPT_USERNAME, sender.c_str());
            curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
            curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
            curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
            curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from.c_str());
            recipients = curl_slist_append(recipients, ("<" + recipient + ">").c_str());
            curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
            curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
            curl_easy_setopt(curl, CURLOPT_READDATA, &data);
            curl_easy_setopt(curl, CURLOPT_INFILESIZE, data.size());
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, [](char* buffer, size_t size, size_t nitems, void* instream) -> size_t {
                std::string* str = static_cast<std::string*>(instream);
                size_t len = str->copy(buffer, size * nitems);
                str->erase(0, len);
                return len;
            });

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                throw std::runtime_error("Email error: " + std::string(curl_easy_strerror(res)));
            }

            curl_slist_free_all(recipients);
            curl_easy_cleanup(curl);
        } catch (...) {
            curl_easy_cleanup(curl);
            throw;
        }
    }
};
