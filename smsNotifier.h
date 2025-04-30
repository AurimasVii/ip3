#ifndef SMS_NOTIFIER_H
#define SMS_NOTIFIER_H

#include "notifier.h"
#include <string>

class SMSNotifier : public Notifier {
public:
    void send(const std::string& recipient, const std::string& sender, const std::string& password, const std::string& message) override;
};

#endif