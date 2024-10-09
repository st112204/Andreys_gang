# Определение компилятора
CXX = g++
# Определение флагов компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Определение целевого исполняемого файла
TARGET = text_editor

# Определение объектных файлов
OBJS = main.o text_editor.o

# Правило для сборки целевого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@$(MAKE) clean

# Правило для сборки объектного файла из main.cpp
main.o: main.cpp text_editor.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Правило для сборки объектного файла из text_editor.cpp
text_editor.o: text_editor.cpp text_editor.h
	$(CXX) $(CXXFLAGS) -c text_editor.cpp

# Правило для удаления объектных файлов и целевого файла
clean:
	rm -f $(OBJS)
