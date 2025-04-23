#include "notifier.hpp"
#include <curl/curl.h>
#include <iostream>
#include <stdexcept>

class SMSNotifier : public Notifier {
public:
    void send(const std::string& recipient, const std::string& sender, const std::string& password, const std::string& message) override {
        CURL* curl = curl_easy_init();
        if (!curl) {
            throw std::runtime_error("Failed to initialize CURL for SMS");
        }

        try {
            std::string sid = sender;
            std::string token = password;
            std::string from = sender;
            std::string postData = "To=" + recipient + "&From=" + from + "&Body=" + message;
            std::string url = "https://api.twilio.com/2025-04-23/Accounts/" + sid + "/Messages.json";

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
            curl_easy_setopt(curl, CURLOPT_USERPWD, (sid + ":" + token).c_str());

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                throw std::runtime_error("SMS error: " + std::string(curl_easy_strerror(res)));
            }

            curl_easy_cleanup(curl);
        } catch (...) {
            curl_easy_cleanup(curl);
            throw;
        }
    }
};
