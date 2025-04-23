#ifndef MESSAGE_SENDER_HPP
#define MESSAGE_SENDER_HPP

#include "notifier.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>

class MessageSender {
private:
    Notifier* strategy;
    std::vector<std::string> logs;

public:
    MessageSender(Notifier* notifier) {
        if (!notifier)
            throw std::invalid_argument("Notifier strategy cannot be null.");
        strategy = notifier;
    }

    void setStrategy(Notifier* notifier) {
        if (!notifier)
            throw std::invalid_argument("Notifier strategy cannot be null.");
        strategy = notifier;
    }

    void sendNotification(const std::string& recipient, const std::string& sender,
                          const std::string& password, const std::string& message) {
        try {
            if (!strategy)
                throw std::runtime_error("No strategy set for notification.");
            strategy->send(recipient, sender, password, message); //polimorfizmas
            logs.push_back("Sent: " + message + " to " + recipient);
        } catch (const std::exception& e) {
            std::cerr << "Error in sendNotification: " << e.what() << std::endl;
        }
    }

    void showLogs() const {
        std::cout << getLogsAsString();
    }

    std::string getLogsAsString() const {
        std::string result = "Logs:\n";
        for (const auto& log : logs) result += log + "\n";
        return result;
    }
};

#endif
