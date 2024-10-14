#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstddef>  // size_t
#include <cstring>  // strlen, strcpy

struct String
{
public:
    String(const char* str = "");
    String(size_t n, char c);
    ~String();

    String(const String& other);
    String& operator=(const String& other);

    void append(const String& other);

    struct SubstrHelp
    {
    public:
        SubstrHelp(const String& originalString, size_t firstIndex)
            : originalString(originalString), firstIndex(firstIndex) {}

        // right [][]
        String operator[](size_t lastIndex) const;

    private:
        const String& originalString;
        size_t firstIndex;
    };

    // left [][]
    SubstrHelp operator[](size_t firstIndex) const;
    
    // output()
    void output() const;

private:
    size_t size;
    char* str;
};