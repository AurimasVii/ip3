#ifndef EMAIL_NOTIFIER_H
#define EMAIL_NOTIFIER_H

#include "notifier.h"
#include <string>

class EmailNotifier : public Notifier {
public:
    void send(const std::string& recipient, const std::string& sender,
              const std::string& password, const std::string& message) override;
};

#endif