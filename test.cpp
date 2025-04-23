#include "MessageSender.hpp"
#include "fakeNotifier.cpp"
#include <cassert>
#include <iostream>
#include <fstream>

bool fileContains(const std::string& filename, const std::string& content) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(content) != std::string::npos) return true;
    }
    return false;
}

int main() {
    FakeNotifier fake;
    MessageSender sender(&fake);

    std::string recipient = "test@example.com";
    std::string senderAddress = "noreply@example.com";
    std::string password = "secret123";
    std::string message = "Test message content";

    sender.sendNotification(recipient, senderAddress, password, message); //polimorfizmas

    assert(fake.getLastRecipient() == recipient);
    assert(fake.getLastSender() == senderAddress);
    assert(fake.getLastPassword() == password);
    assert(fake.getLastMessage() == message);

    assert(fileContains("test_output.txt", recipient));
    assert(fileContains("test_output.txt", senderAddress));
    assert(fileContains("test_output.txt", password));
    assert(fileContains("test_output.txt", message));


    std::string logs = sender.getLogsAsString();
    assert(logs.find("Sent: " + message + " to " + recipient) != std::string::npos);

    std::cout << "TEST PASSED: All FakeNotifier methods and logging verified.\n";
    return 0;
}
