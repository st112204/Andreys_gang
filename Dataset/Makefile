# Компилятор и флаги компиляции
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Исходный файл
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

# Имя исполняемого файла
TARGET = dataset

# Правила по умолчанию
all: $(TARGET)

# Правило для компиляции исходных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для линковки исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	rm -f $(OBJ)

# Очистка
clean:
	rm -f $(OBJ) $(TARGET)

# Правило для пересборки
rebuild: clean all