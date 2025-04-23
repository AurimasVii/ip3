#include "MessageSender.hpp"
#include "emailNotifier.cpp"
#include "smsNotifier.cpp"

int main() {
    std::string yourEmail = "";
    std::string yourAppPassword = "";
    std::string recipientEmail = "";

    std::string sid = "";
    std::string token = "";
    std::string recipientNumber = "";

    EmailNotifier emailStrategy;
    SMSNotifier smsStrategy;

    MessageSender sender(&emailStrategy);
    sender.sendNotification(recipientEmail, yourEmail, yourAppPassword, "Hello from C++ Email!"); //polimorfizmas

    sender.setStrategy(&smsStrategy);
    sender.sendNotification(recipientNumber, sid, token, "Hello from C++ SMS"); //polimorfizmas

    sender.showLogs();


    return 0;
}
