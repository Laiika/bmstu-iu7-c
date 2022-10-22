# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

OBJDIR = out

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_arr_fill_fib_nums.o $(OBJDIR)/check_arr_copy_first.o $(OBJDIR)/check_main.o

unit_tests.exe : $(UNITS) arr.dll
	$(CC) $(UNITS) -L. -larr -lcheck -o $@

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

arr.dll : $(OBJDIR)/arr_lib.o
	$(CC) -shared $< -Wl,--subsystem,windows -o $@

$(OBJDIR)/arr_lib.o : arr_lib.c arr_lib.h
	$(CC) $(CFLAGS) -Iinc -D ARRAY_EXPORTS -c $< -o $@

$(OBJDIR)/check_arr_fill_fib_nums.o : $(UNITDIR)/check_arr_fill_fib_nums.c check_arr_lib.h arr_lib.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_arr_copy_first.o : $(UNITDIR)/check_arr_copy_first.c check_arr_lib.h arr_lib.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_arr_lib.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@


.PHONY : clean start unit
clean :
	rm -f $(OBJDIR)/*.o *.dll *.exe

start : arr.dll
	python app.py

unit : unit_tests.exe
	./unit_tests.exe
