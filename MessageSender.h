#ifndef MESSAGE_SENDER_H
#define MESSAGE_SENDER_H

#include "notifier.h"
#include <vector>
#include <string>
#include <iostream>

class MessageSender {
private:
    Notifier* strategy;
    std::vector<std::string> logs;

public:
    MessageSender(Notifier* notifier);
    void setStrategy(Notifier* notifier);
    void sendNotification(const std::string& recipient, const std::string& sender,
                          const std::string& password, const std::string& message);
    void showLogs() const;
    std::string getLogsAsString() const;
};

#endif