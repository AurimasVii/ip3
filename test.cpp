#include "MessageSender.h"
#include <cassert>
#include <iostream>
#include <fstream>

/*
    Dar viena klase galetu buti skirta siusti zinutes/pranesimus i faila ir tuo paciu metu i konsole.
    Klase paveldetu 'Notifier' klase ir implementuotu 'send' metoda.

    Bazine klase:
    'Notifier' klase apibrėžia visų pranešimų siuntimo strategijų sąsają. Ji turi šiuos grynus virtualius metodus:
        - void send(const std::string& recipient, const std::string& sender, const std::string& password, const std::string& message)

    Nauja klase turetu implementuoti:
    - 'FileAndConsoleNotifier' turetu implementuoti 'send' metoda, kuris:
        1. Iraso zinute i nurodyta faila.
        2. Isveda zinute i konsole.

    Testavimas:
        Toliau pateikti testai patikrina 'FileAndConsoleNotifier' klasės veikimą. Jei klasė yra teisingai įgyvendinta, šis testų failas turėtų kompiliuotis ir sėkmingai veikti, išvesdamas "TEST PASSED".

*/

bool fileContains(const std::string& filename, const std::string& content) { //funkcija tikrina ar failas turi nurodyta turini
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(content) != std::string::npos) return true;
    }
    return false;
}

int main() {
    // Test FileAndConsoleNotifier taip galetu buti pavadinta nauja klase, kuri paveldi 'Notifier' klase
    // ir implementuoja 'send' metoda, kuris iraso zinute i faila ir isveda i konsole.
    const std::string testFile = "test_output.txt";
    FileAndConsoleNotifier fileAndConsoleNotifier(testFile);
    MessageSender sender(&fileAndConsoleNotifier);

    std::string recipient = "test@example.com";
    std::string senderAddress = "noreply@example.com";
    std::string password = "secret123";
    std::string message = "Test message content";

    // Send notification
    sender.sendNotification(recipient, senderAddress, password, message);

    // Verify file content
    assert(fileContains(testFile, "Recipient: " + recipient));
    assert(fileContains(testFile, "Sender: " + senderAddress));
    assert(fileContains(testFile, "Message: " + message));

    // Verify console output (manual verification required)
    std::cout << "Check console output for correctness.\n";

    // Verify logs
    std::string logs = sender.getLogsAsString();
    assert(logs.find("Sent: " + message + " to " + recipient) != std::string::npos);

    std::cout << "TEST PASSED: FileAndConsoleNotifier methods verified.\n";
    return 0;
}
