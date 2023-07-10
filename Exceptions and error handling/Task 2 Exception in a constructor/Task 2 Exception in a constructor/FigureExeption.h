#pragma once
#include <exception>
#include <string>
using namespace std;


class FigureExeption : public exception
{
public:
    FigureExeption(const std::string& message);

    const char* what() const noexcept override;

private:
    std::string err_message;    // сообщение об ошибке
};