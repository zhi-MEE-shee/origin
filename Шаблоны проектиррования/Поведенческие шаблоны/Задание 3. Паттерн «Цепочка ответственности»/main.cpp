#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector> 


class LogMessage {
public:
    enum class Type {
        Warning,
        Error,
        FatalError,
        UnknowMessage,
    };

    LogMessage(Type type, const std::string msg) : type_(type), msg_(msg) {}
   
    virtual Type type() const = 0;
    virtual const std::string& message() const { return msg_; };

private:
    Type type_;
    std::string msg_;
};


class WarningMessage : public LogMessage {
public:
    WarningMessage(const std::string& msg) : LogMessage(Type::Warning, msg) {}
    Type type() const override { return Type::Warning; }
    const std::string& message() const override {
        return LogMessage::message();
    }
};
class ErrorMessage : public LogMessage {
public:
    ErrorMessage(const std::string& msg) : LogMessage(Type::Error, msg) {}
    Type type() const override { return Type::Error; }
    const std::string& message() const override {
        return LogMessage::message();
    }
};
class FatalErrorMessage : public LogMessage {
public:
    FatalErrorMessage(const std::string& msg) : LogMessage(Type::FatalError, msg) {}
    Type type() const { return Type::FatalError; }
    const std::string& message() const {
        return LogMessage::message();
    }
};
class UnkownMessage : public LogMessage {
public:
    UnkownMessage(const std::string& msg) : LogMessage(Type::UnknowMessage, msg) {}
    Type type() const { return Type::UnknowMessage; }
    const std::string& message() const  {
        return LogMessage::message();
    }
};




class MessageHandler {
public:
    virtual void handleMessage(const LogMessage& message) = 0;
};


// Обработчик фатальной ошибки должен выбросить исключение с текстом сообщения, 
// предполагается, что программа должна прекратить выполнение после возникновения фатальной ошибки.
class FatalErrorHandler : public MessageHandler {
public:
    void handleMessage(const LogMessage& msg) override {
        if (msg.type() == LogMessage::Type::FatalError) {
            throw std::runtime_error(msg.message());
        }
    }
};


// Обработчик обычной ошибки должен записать её в файл по указанному пути.
class ErrorHandler : public MessageHandler {
public:
    ErrorHandler(const std::string& file) : file_name(file) {}

    void handleMessage(const LogMessage& msg) override{
        if (msg.type() == LogMessage::Type::Error) {
            std::ofstream logMessage(file_name, std::ios::app);
            if (logMessage.is_open()) {
                logMessage << msg.message() << std::endl;
                logMessage.close();
            }
            else {
                std::cout << "Failed to open file: " << file_name << std::endl;
            }
        }
    }
private:
    std::string file_name;
};


// Обработчик предупреждения должен напечатать сообщение в консоль.
class WarningHandler : public MessageHandler {
public:
    void handleMessage(const LogMessage& msg) override {
        if (msg.type() == LogMessage::Type::Warning) {
           std::cout << msg.message() << std::endl;
        }
    }
};


//Обработчик неизвестного сообщения должен выбросить исключение с текстом о необработанном сообщении.
class UnknownMsgHandler : public MessageHandler {
public:
    void handleMessage(const LogMessage& msg) override {
        if (msg.type() == LogMessage::Type::UnknowMessage) {
            throw std::runtime_error("Unknown message type: " + msg.message());
        }
    }
};

class ChainMaker {
public:
    ChainMaker() {
        msg_order.push_back(std::make_unique<FatalErrorHandler>());
        msg_order.push_back(std::make_unique<ErrorHandler>("error.txt"));
        msg_order.push_back(std::make_unique<WarningHandler>());
        msg_order.push_back(std::make_unique<UnknownMsgHandler>());
    }

    void handling(const LogMessage& msg) {
        for (const auto& it : msg_order) {
            it->handleMessage(msg);
        }
    }

private:
    std::vector<std::unique_ptr<MessageHandler>> msg_order;
};

int main() {
    
    std::unique_ptr<LogMessage> msg1 = std::make_unique<FatalErrorMessage>("Fatal error message");
    std::unique_ptr<LogMessage> msg2 = std::make_unique<ErrorMessage>("Some error message");
    std::unique_ptr<LogMessage> msg3 = std::make_unique<WarningMessage>("Warning message");
    std::unique_ptr<LogMessage> msg4 = std::make_unique<UnkownMessage>("undefined");

    ChainMaker chain;
    chain.handling(*msg2);

    return 0;
}

