#include <iostream>
#include <string>

struct TextEditor
{
	std::string data;
	int count;
	int position;

	TextEditor()
	{
		data = "";
		count = 0;
		position = 1;
	}

	TextEditor(const std::string data, const int count, const int position)
	{
		this->data = data;
		this->count = count;
		this->position = position;
	}

	TextEditor(const TextEditor& T)
	{
		data = T.data;
		count = T.count;
		position = T.position;
	}

	TextEditor& operator=(const TextEditor& T)
	{
		if (&T != this)
		{
			data = T.data;
			count = T.count;
			position = T.position;
		}
		return *this;
	}

	~TextEditor() {};

	void output()
	{
		std::cout 
			<< "data: " << data << "\n"
			<< "count: " << count << "\n"
			<< "position: " << position << "\n\n";
	}

	void addText(std::string text);
	// Добавляет текст на позицию курсора

	int deleteText(int k);
	// Удаляет k символов слева от курсора
	// Возвращает количество символов, которое было удалено

	std::string cursorLeft(int k);
	// Смещает курсор на k символов влево
	// Возвращает все символы, которые находятся левее курсора

	std::string cursorRight(int k);
	// Смещает курсор на k символов вправо
	// Возвращает все символы, которые находятся правее курсора
};

int main()
{
	TextEditor T1{ "Privet", 6, 7 };
	T1.output();

	TextEditor T2;
	T2 = T1;
	T2.output();
	
	return 0;
}