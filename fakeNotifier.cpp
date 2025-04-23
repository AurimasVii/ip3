
#include "notifier.hpp"
#include <iostream>
#include <string>

class FakeNotifier : public Notifier {
private:
    std::string lastMessage;
    std::string lastRecipient;
    std::string lastSender;
    std::string lastPassword;

public:
    void send(const std::string& recipient, const std::string& sender, const std::string& password, const std::string& message) override {
        lastRecipient = recipient;
        lastSender = sender;
        lastPassword = password;
        lastMessage = message;
        std::cout << "[FakeNotifier] Simulated send to " << recipient << ": " << message << std::endl;
    }

    const std::string& getLastMessage() const { return lastMessage; }
    const std::string& getLastRecipient() const { return lastRecipient; }
    const std::string& getLastSender() const { return lastSender; }
    const std::string& getLastPassword() const { return lastPassword; }
};


