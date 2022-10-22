# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Подпапка для объектных файлов
OBJDIR = out
# Общие объектные файлы
OBJS := $(OBJDIR)/list.o $(OBJDIR)/node.o

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_find.o $(OBJDIR)/check_insert.o $(OBJDIR)/check_copy.o $(OBJDIR)/check_sorted_insert.o $(OBJDIR)/check_sort.o $(OBJDIR)/check_main.o

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(OBJS) $(UNITS)
	$(CC) $^ -o $@ -lcheck

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/node.o : node.c node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/list.o : list.c list.h node.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/main.o : main.c list.h node.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_find.o : $(UNITDIR)/check_find.c check_find.h list.h node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_insert.o : $(UNITDIR)/check_insert.c check_insert.h list.h node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_copy.o : $(UNITDIR)/check_copy.c check_copy.h list.h node.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_sorted_insert.o : $(UNITDIR)/check_sorted_insert.c check_sorted_insert.h list.h node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_sort.o : $(UNITDIR)/check_sort.c check_sort.h list.h node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_find.h check_insert.h check_copy.h check_sorted_insert.h check_sort.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@


.PHONY : clean func unit
clean :
	rm -f $(OBJDIR)/*.o *.exe

func :
	@if [ -f app.exe ]; then cd func_tests; sh all_tests.sh; fi

unit : unit_tests.exe
	./unit_tests.exe
