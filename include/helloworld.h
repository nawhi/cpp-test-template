#include <string>

class HelloWorld {
public:
    HelloWorld(const std::string msg): message(msg) {}
    std::string getMessage() const;

private:
    const std::string message;
};