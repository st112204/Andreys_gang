#include <iostream>
#include <string>

struct TextEditor
{
	std::string text;
	int size;
	int pos;

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
			<< "text: " << text << "\n"
			<< "size: " << size << "\n"
			<< "position: " << pos << "\n\n";
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

	void interface();
};

int main()
{
	int left = 8;
	int right = 2;
	int del = 1;
	std::string add = "GHI";

	TextEditor T("abcdef");
	T.output();

	std::cout
		<< "added text: " << add << "\n\n";
	T.addText(add);
	T.output();

	std::cout
		<< "required delete: " << del << "\n"
		<< "deleted: " << T.deleteText(del) << "\n\n";
	T.output();

	std::cout
		<< "required move left: " << left <<"\n"
		<< "text before new position: " << T.cursorLeft(left) << "\n\n";
	T.output();

	std::cout
		<< "required move right: " << right << "\n"
		<< "text after new position: " << T.cursorRight(right) << "\n\n";
	T.output();

	return 0;
}

//int main()
//{
//	TextEditor T("abcdef");
//	T.output();
//
//	T.cursorLeft(9);
//	T.output();
//
//	T.cursorRight(6);
//	T.output();
//
//	T.cursorLeft(5);
//	T.output();
//
//	T.deleteText(3);
//	T.output();
//
//	T.addText("A");
//	T.output();
//
//	T.deleteText(3);
//	T.output();
//
//	T.cursorRight(5);
//	T.output();
//
//	T.deleteText(5);
//	T.output();
//
//	T.addText("Privet");
//	T.output();
//
//	return 0;
//}