#include "FigureExeption.h"

FigureExeption::FigureExeption(const string& message) : err_message{ message } {}

const char* FigureExeption::what() const noexcept
{
    return err_message.c_str();     // получаем из std::string строку const char*
}
