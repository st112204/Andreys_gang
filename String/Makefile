# Определение компилятора
CXX = g++
# Определение флагов компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Определение целевого исполняемого файла
TARGET = string

# Определение объектных файлов
OBJS = main.o string.o

# Правило для сборки целевого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@$(MAKE) clean

# Правило для сборки объектного файла из main.cpp
main.o: main.cpp string.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Правило для сборки объектного файла из string.cpp
text_editor.o: string.cpp string.h
	$(CXX) $(CXXFLAGS) -c string.cpp

# Правило для удаления объектных файлов и целевого файла
clean:
	rm -f $(OBJS)