/* 
=== Структура проекта ===
1) README с описнием задачи, сборки и запуска
2) Makefile для сборки
3) text_editor.h с объявлением класса и его методов
4) text_editor.cpp с определением методов
5) main.cpp в котором проверяется функциональность написанного класса
=========================
Нужно переписать все согласно этой структуре
*/

#include <iostream>
#include <string>

#include <termios.h>
#include <unistd.h>

char _getch()
{
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return buf;
}

class TextEditor
{

private:

	std::string text;
	int size;
	int pos;

public:

	TextEditor()
	{
		text = "";
		size = 0;
		pos = 0;
	}

	TextEditor(const std::string text)
	{
		this->text = text;
		pos = size = text.size();
	}

	TextEditor(const TextEditor& T)
	{
		text = T.text;
		size = T.size;
		pos = T.pos;
	}

	TextEditor& operator=(const TextEditor& T)
	{
		if (this != &T)
		{
			text = T.text;
			size = T.size;
			pos = T.pos;
		}
		return *this;
	}

	~TextEditor() {};

	void output()
	{
		std::cout 
			<< "YOUR DOCUMENT \n" 
			<< "     ";
		for (int i = 0; i < pos; ++i)
			std::cout << " ";
		std::cout << "v" << "\n";
		std::cout
			<< "text: " << text << "\n"
			<< "position: " << pos << "\n"
			<< "size: " << size << "\n\n";

	}

	void addText(std::string text)
	{
		this->text.insert(pos, text);
		size += text.size();
		pos += text.size();
	}

	int deleteText(int k)
	{
		int size0 = size;

		if (k <= 0)
			return 0;

		if (k > pos)
			k = pos;
		text.erase(pos - k, k);
		size = text.size();
		pos = pos - k;

		return size0 - size;
	}

	std::string cursorLeft(int k)
	{
		if (pos == 0)
			return "";

		if (k <= 0)
			return text.substr(0, pos - 1);

		pos = (pos <= k ? 0 : pos - k);
		return text.substr(0, pos - 1);
	}

	std::string cursorRight(int k)
	{
		if (pos == size)
			return "";

		if (k <= 0)
			return text.substr(pos, size);

		pos = (size - pos <= k ? size : pos + k);
		return text.substr(pos, size);
	}
};

void help()
{
	std::cout
		<< "COMMANDS\n"
		<< "a ............... add text \n"
		<< "d ............... delete text \n"
		<< "l ............... cursor left \n"
		<< "r ............... cursor right \n"
		<< "i ............... document status \n"
		<< "c ............... clear screen \n"
		<< "esc ............. exit \n"
		<< "other buttons ... this message \n\n";

	return;
}

void interface()
{
	TextEditor T;
	std::string str;
	char buffer[256];
	int k;

	std::cout << "Welcome to TextEditor! \n\n";
	help();
	T.output();

	while (true)
	{
		char x = _getch();

		switch (x)
		{
		case 'a':
			std::cout << "input text: ";
			std::getline(std::cin, str);
			std::cout << "\n";
			T.addText(str);
			T.output();
			break;

		case 'd':
			std::cout << "input number of characters: ";
			std::cin >> buffer;
			k = atoi(buffer);
			std::cout
				<< "\n"
				<< "needed to be deleted: " << k << "\n"
				<< "deleted: " << T.deleteText(k) << "\n\n";
			T.output();
			break;

		case 'l':
			std::cout << "input left-shift value: ";
			std::cin >> buffer;
			k = atoi(buffer);
			std::cout
				<< "\n"
				<< "text before new position: " << T.cursorLeft(k) << "\n\n";
			T.output();
			break;

		case 'r':
			std::cout << "input right-shift value: ";
			std::cin >> buffer;
			k = atoi(buffer);
			std::cout
				<< "\n"
				<< "text after new position: " << T.cursorRight(k) << "\n\n";
			T.output();
			break;

		case 'i':
			T.output();
			break;

		case 'c':
			system("cls");
			help();
			break;

		case 27:
			return;

		default:
			help();
			break;
		}
	}
}

int main()
{
	interface();

	return 0;
}
