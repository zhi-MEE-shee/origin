#include <algorithm>
#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reverse : public DecoratedText {
public:
    explicit Reverse(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string s = data;
        std::reverse(s.begin(), s.end());
        text_->render(s);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text2) :  DecoratedText(text2) {}
    void render(const std::string& link, const std::string& data) const {
        std::cout << "<a href=\"";
        text_->render(link);
        std::cout << "\">";
        text_->render(data);
        std::cout << "</a>";
    }
};


int main() {

    auto text_block = new Paragraph(new Text());
    text_block->render("Hello world");
    std::cout << "\n";
    auto text_block2 = new Reverse(new Text());
    text_block2->render("Hello world");
    std::cout << "\n";
    auto text_block3 = new Link(new Text());
    text_block3->render("netology.ru", "Hello world");

    return 0;
}