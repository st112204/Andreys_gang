
<p></p>  

! проект в процессе разработки

## Считывание набора данных из файла и последующее хранение, изменение, исследование

### Описание задачи:

В этой задаче требовалось реализовать считывание данных из файла и последующее их хранение, изменение, исследование

### Сборка и запуск программы:

Проект реализован для консоли Linux.

Проект состоит из нескольких файлов:
- `dataset.txt` - данные
- `dataset.h` - объявление функций и методов
- `dataset_impl.h` - определение функций и методов, объявленных в `dataset.h`
- `main.cpp` - основная функция `main()`
- `Makefile` - команды сборки файлов

Чтобы скомпилировать и запустить проект, необходимо, находясь в директории проекта, выполнить две команды:

```
make
./dataset
```

После завершения сборки проекта `Makefile` автоматически удалит файлы `.o` (выполнит команду `make clean`), однако исполняемый файл удален не будет.

### Работа программы:

В функции `main()` инициализируется объект класса `Dataset` на файла с данными `dataset.txt`

### Автор: Игорь Коровин

<p></p>