# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Подпапка для объектных файлов
OBJDIR = out
# Общие объектные файлы
OBJS := $(OBJDIR)/node.o $(OBJDIR)/stack.o $(OBJDIR)/queue.o

UNITDIR = unit_tests
UNITS := $(OBJDIR)/check_queue_push.o $(OBJDIR)/check_main.o

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(OBJS) $(UNITS)
	$(CC) $^ -o $@ -lcheck

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/node.o : node.c node.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/stack.o : stack.c stack.h node.h return_codes.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/queue.o : queue.c queue.h stack.h return_codes.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o : main.c queue.h return_codes.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/check_queue_push.o : $(UNITDIR)/check_queue_push.c check_queue_push.h queue.h return_codes.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_queue_push.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm $(OBJDIR)/*.o *.exe
