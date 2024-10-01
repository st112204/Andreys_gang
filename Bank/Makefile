
# Имя исполняемого файла
TARGET = Bank

# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Исходные файлы
SRCS = Bank.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило для сборки объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки
clean:
	rm -f $(OBJS) $(TARGET)

#Test: test.o
#	gcc test.o -o Test
#
#test.o: test.cpp
#       gcc -c test.cpp -o test.o

#TextEditor : main.o
#	gcc main.o -o TextEditor

#main.o : main.cpp
#	gcc -c main.cpp -o main.o
