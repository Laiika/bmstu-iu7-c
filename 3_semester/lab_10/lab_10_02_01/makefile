# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Подпапка для объектных файлов
OBJDIR = out
# Общие объектные файлы
OBJS := $(OBJDIR)/list_node.o $(OBJDIR)/list.o

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_list_add_end.o $(OBJDIR)/check_list_calc_polyn.o $(OBJDIR)/check_list_calc_dx.o $(OBJDIR)/check_lists_calc_sum.o $(OBJDIR)/check_list_get_by_cond.o $(OBJDIR)/check_main.o

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(OBJS) $(UNITS)
	$(CC) $^ -o $@ -lcheck

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/list_node.o : list_node.c list_node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/list.o : list.c list.h list_node.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/main.o : main.c list_node.h list.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_list_add_end.o : $(UNITDIR)/check_list_add_end.c check_list_add_end.h list.h list_node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_list_calc_polyn.o : $(UNITDIR)/check_list_calc_polyn.c check_list_calc_polyn.h list.h list_node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_list_calc_dx.o : $(UNITDIR)/check_list_calc_dx.c check_list_calc_dx.h list.h list_node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_lists_calc_sum.o : $(UNITDIR)/check_lists_calc_sum.c check_lists_calc_sum.h list.h list_node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_list_get_by_cond.o : $(UNITDIR)/check_list_get_by_cond.c check_list_get_by_cond.h list.h list_node.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_list_add_end.h check_list_calc_polyn.h check_list_calc_dx.h check_lists_calc_sum.h check_list_get_by_cond.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

.PHONY : clean func unit
clean :
	rm -f $(OBJDIR)/*.o *.exe

func :
	@if [ -f app.exe ]; then cd func_tests; sh all_tests.sh; fi

unit : unit_tests.exe
	./unit_tests.exe
