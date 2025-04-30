#include "smsNotifier.h"
#include <curl/curl.h>
#include <stdexcept>
#include <iostream>

void SMSNotifier::send(const std::string& recipient, const std::string& sender, const std::string& password, const std::string& message) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL for SMSNotifier");
    }

    try {
        std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + sender + "/Messages.json";
        std::string postFields = "To=" + recipient + "&From=" + sender + "&Body=" + message;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERNAME, sender.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

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