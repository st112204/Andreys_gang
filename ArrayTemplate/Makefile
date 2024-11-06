# Определение компилятора
CXX = g++
# Определение флагов компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Определение целевого исполняемого файла
TARGET = array_template

# Определение объектных файлов
OBJS = main.o array_template.o

# Правило для сборки целевого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@$(MAKE) clean

# Правило для сборки объектного файла из main.cpp
main.o: main.cpp array_template.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Правило для сборки объектного файла из array_template.cpp
array_template.o: array_template.cpp array_template.h
	$(CXX) $(CXXFLAGS) -c array_template.cpp

# Правило для удаления объектных файлов и целевого файла
clean:
	rm -f $(OBJS)
