#ifndef NOTIFIER_HPP
#define NOTIFIER_HPP
#include <string>
class Notifier {
public:
    virtual void send(const std::string& recipient, const std::string& sender, const std::string& password, const std::string& message) = 0;
    virtual ~Notifier() {}
};
#endif