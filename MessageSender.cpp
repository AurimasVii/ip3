#include "MessageSender.h"
#include <stdexcept>

MessageSender::MessageSender(Notifier* notifier) {
    if (!notifier)
        throw std::invalid_argument("Notifier strategy cannot be null.");
    strategy = notifier;
}

void MessageSender::setStrategy(Notifier* notifier) {
    if (!notifier)
        throw std::invalid_argument("Notifier strategy cannot be null.");
    strategy = notifier;
}

void MessageSender::sendNotification(const std::string& recipient, const std::string& sender,
                                      const std::string& password, const std::string& message) {
    try {
        if (!strategy)
            throw std::runtime_error("No strategy set for notification.");
        strategy->send(recipient, sender, password, message);
        logs.push_back("Sent: " + message + " to " + recipient);
    } catch (const std::exception& e) {
        std::cerr << "Error in sendNotification: " << e.what() << std::endl;
    }
}

void MessageSender::showLogs() const {
    std::cout << getLogsAsString();
}

std::string MessageSender::getLogsAsString() const {
    std::string result = "Logs:\n";
    for (const auto& log : logs) result += log + "\n";
    return result;
}