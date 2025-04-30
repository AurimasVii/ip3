#ifndef NOTIFIER_H
#define NOTIFIER_H
#include <string>
class Notifier {
public:
    virtual void send(const std::string& recipient, const std::string& sender, const std::string& password, const std::string& message) = 0;
    virtual ~Notifier() {}
};

#endif