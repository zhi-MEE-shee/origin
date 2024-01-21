#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogToFile : public LogCommand {
public:

    LogToFile(const std::string& file) : file_name(file) {}

    void print(const std::string& message) override 
    {
        std::ofstream logMessage (file_name, std::ios::app);
        if (logMessage.is_open())
        {
            logMessage << message << std::endl;
            logMessage.close();
        }
        else 
        {
            std::cerr << "Failed to open file: " << file_name << std::endl;
        }
    }  
private:
    std::string file_name;
};

class LogToConsole : public LogCommand {
   
    void print(const std::string& message) override 
    {
        std::cout << message << std::endl;
    }

};

void print(LogCommand& c, const std::string& message){
    c.print(message);
}

int main() {
    LogToConsole mess1;
    LogToFile mess2("file.txt");
    
    print(mess1, "Greetings to console!");
    print(mess2, "Greetings to file!");
}


