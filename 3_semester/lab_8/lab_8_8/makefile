# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Подпапка для объектных файлов
OBJDIR = out
# Общие объектные файлы
OBJS := $(OBJDIR)/mtr_mem.o $(OBJDIR)/mtr_cut.o $(OBJDIR)/mtr_in_out.o $(OBJDIR)/mtr_inc.o $(OBJDIR)/mtr_mult.o

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_mtr_exp.o $(OBJDIR)/check_mtr_mult.o $(OBJDIR)/check_mtr_cut.o $(OBJDIR)/check_main.o

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(OBJS) $(UNITS)
	$(CC) $^ -o $@ -lcheck

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/mtr_mem.o : mtr_mem.c mtr_mem.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/mtr_cut.o : mtr_cut.c mtr_cut.h matrix.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/mtr_in_out.o : mtr_in_out.c mtr_in_out.h errors.h mtr_mem.h matrix.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/mtr_inc.o : mtr_inc.c mtr_inc.h errors.h mtr_mem.h matrix.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/mtr_mult.o : mtr_mult.c mtr_mult.h mtr_mem.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/main.o : main.c mtr_cut.h mtr_in_out.h mtr_inc.h mtr_mem.h mtr_mult.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mtr_exp.o : $(UNITDIR)/check_mtr_exp.c check_mtr.h mtr_mult.h mtr_mem.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mtr_mult.o : $(UNITDIR)/check_mtr_mult.c check_mtr.h mtr_mult.h mtr_mem.h matrix.h errors.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mtr_cut.o : $(UNITDIR)/check_mtr_cut.c check_mtr.h matrix.h
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
