# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Подпапка для объектных файлов
OBJDIR = out
# Общие объектные файлы
OBJS := $(OBJDIR)/matrix.o

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_mtr_sum.o $(OBJDIR)/check_mtr_mult.o $(OBJDIR)/check_mtr_calc_det.o $(OBJDIR)/check_main.o

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(OBJS) $(UNITS)
	$(CC) $^ -o $@ -lcheck

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/matrix.o : matrix.c matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/main.o : main.c matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mtr_sum.o : $(UNITDIR)/check_mtr_sum.c check_mtr.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mtr_mult.o : $(UNITDIR)/check_mtr_mult.c check_mtr.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mtr_calc_det.o : $(UNITDIR)/check_mtr_calc_det.c check_mtr.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_mtr.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

.PHONY : clean func unit
clean :
	rm -f $(OBJDIR)/*.o *.exe

func :
	@if [ -f app.exe ]; then cd func_tests; sh all_tests.sh; fi

unit : unit_tests.exe
	./unit_tests.exe
