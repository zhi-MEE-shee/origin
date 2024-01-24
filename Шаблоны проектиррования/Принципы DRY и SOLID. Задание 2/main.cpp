#include <iostream>
#include <fstream>
#include <string>

class Print {
public:
    virtual ~Print() = default;
    virtual const std::string print(const std::string& data) const = 0;
};

class PrintAsHTML : public Print {
    const std::string print(const std::string& data) const override {
        return "<html>" + data + "</html>";
    }
};

class PrintAsText : public Print {
    const std::string print(const std::string& data) const override {
        return data;
    }
};

class PrintAsJSON : public Print {
    const std::string print(const std::string& data) const override {
        return "{ \"data\": \"" + data + "\"}";
    }
};



class Data
{
public:

    Data(std::string data, Print& print)
        : data_(data), printAs_(print) {}

    std::string print(){
        return printAs_.print(data_);
    }

private:
    std::string data_;
    Print& printAs_;

};

void saveAs(std::ofstream& stream, Data& data) {
    stream << data.print() + '\n';
}


int main() {

    PrintAsHTML html;
    PrintAsText text;
    PrintAsJSON json;
  
    Data str_html("hello world!", html);
    std::cout << str_html.print() + '\n';

    Data str_txt("hello world!", text);
    std::cout << str_txt.print() + '\n';

    Data str_json("hello world!", json);
    std::cout << str_json.print() + '\n';

    std::ofstream file_html("file.html", std::ios::app);
    std::ofstream file_txt("file.txt", std::ios::app);
    std::ofstream file_json("file.json", std::ios::app);

    saveAs(file_txt, str_txt);
    saveAs(file_json, str_json);
    saveAs(file_html, str_html);

    return 0;
}


