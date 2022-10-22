# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Подпапка для объектных файлов
OBJDIR = out
# Общие объектные файлы
OBJS := $(OBJDIR)/my_string.o

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_my_snprintf.o $(OBJDIR)/check_main.o

unit_tests.exe : $(OBJS) $(UNITS)
	$(CC) $^ -o $@ -lcheck

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/my_string.o : my_string.c my_string.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_my_snprintf.o : $(UNITDIR)/check_my_snprintf.c check_my_snprintf.h my_string.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_my_snprintf.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

.PHONY : clean unit
clean :
	rm -f $(OBJDIR)/*.o *.exe

unit : unit_tests.exe
	./unit_tests.exe
