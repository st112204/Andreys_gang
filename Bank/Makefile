# Определение компилятора
CXX = g++
# Определение флагов компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Определение целевого исполняемого файла
TARGET = bank

# Определение объектных файлов
OBJS = main.o bank.o

# Правило для сборки целевого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@$(MAKE) clean

# Правило для сборки объектного файла из main.cpp
main.o: main.cpp bank.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Правило для сборки объектного файла из bank.cpp
bank.o: bank.cpp bank.h
	$(CXX) $(CXXFLAGS) -c bank.cpp

# Правило для удаления объектных файлов
clean:
	rm -f $(OBJS)
