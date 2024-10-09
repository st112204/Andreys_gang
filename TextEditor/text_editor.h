#pragma once

#include <iostream>
#include <string>
#include <termios.h> // linux library
#include <unistd.h> // linux library

char _getch(); // linux _getch() function

class TextEditor
{

private:

	std::string text;
	int size;
	int pos;

public:

	TextEditor();

	TextEditor(const std::string text);

	TextEditor(const TextEditor& T);

	TextEditor& operator=(const TextEditor& T);

	~TextEditor();

	void output();

	void addText(std::string text);

	int deleteText(int k);

	std::string cursorLeft(int k);

	std::string cursorRight(int k);
};

void help();

void interface();