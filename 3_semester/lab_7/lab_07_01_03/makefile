# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Подпапка для объектных файлов
OBJDIR = out
# Общие объектные файлы
OBJS := $(OBJDIR)/element.o $(OBJDIR)/elements.o

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_key.o $(OBJDIR)/check_mysort.o $(OBJDIR)/check_main.o

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(OBJS) $(UNITS)
	$(CC) $^ -o $@ -lcheck

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/element.o : element.c element.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/elements.o : elements.c element.h elements.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/main.o : main.c element.h elements.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_key.o : $(UNITDIR)/check_key.c check_key.h elements.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mysort.o : $(UNITDIR)/check_mysort.c check_mysort.h elements.h element.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_key.h check_mysort.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

.PHONY : clean func unit
clean :
	rm -f $(OBJDIR)/*.o *.exe

func :
	@if [ -f app.exe ]; then cd func_tests; sh all_tests.sh; fi

unit : unit_tests.exe
	./unit_tests.exe
