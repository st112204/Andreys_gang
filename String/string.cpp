#include "string.h"

String::String(const char* str) {
    size = strlen(str);
    this->str = new char[size + 1];
    for (size_t i = 0; i <= size; ++i)
        this->str[i] = str[i];
}

String::String(size_t n, char c) : size(n), str(0)
{
    this->str = new char[size + 1];
    for (int i = 0; i < size; this->str[i] = c, ++i);
    str[size] = '\0';
}

String::~String()
{
    delete[] str;
}

String::String(const String& other) :size(other.size)
{
    str = new char[size + 1];
    strcpy(str, other.str);
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        delete[] this->str;
        this->size = other.size;
        this->str = new char[this->size + 1];
        strcpy(this->str, other.str);
    }

    return *this;
}

void String::append(const String& other)
{
    size += other.size;
    char* new_str = new char[size + 1];
    strcpy(new_str, str);
    strcat(new_str, other.str);
    delete[] str;
    str = new_str;
}

// left [][] 
String::SubstrHelp String::operator[](size_t firstIndex) const
{
    return SubstrHelp(*this, firstIndex);
}

// right [][]
String String::SubstrHelp::operator[](size_t lastIndex) const
{
    String s;

    if (firstIndex >= lastIndex)
        return s;

    if (lastIndex > originalString.size - 1)
        lastIndex = originalString.size;

    if (firstIndex >= lastIndex)
        return s;

    s.size = lastIndex - firstIndex;
    s.str = new char[s.size];

    for (size_t i = 0; i < s.size; ++i)
        s.str[i] = originalString.str[firstIndex + i];

    return s;
}

// output()
void String::output() const
{
    for (size_t i = 0; i < size; ++i)
        std::cout << str[i];
    std::cout << "\n\n";
    return;
}