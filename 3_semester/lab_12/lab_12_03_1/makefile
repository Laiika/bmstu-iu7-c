# Компилятор
CC := gcc
# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

OBJDIR = out

# Подпапка для модульных тестов
UNITDIR = unit_tests
# Объектные файлы модульных тестов
UNITS := $(OBJDIR)/check_key.o $(OBJDIR)/check_mysort.o $(OBJDIR)/check_main.o

vpath %.h inc
vpath %.c src

$(shell mkdir -p $(OBJDIR))

# Динамическая компоновка/загрузка
arr.dll : $(OBJDIR)/arr_dyn_lib.o
	$(CC) -shared $< -Wl,--subsystem,windows -o $@

$(OBJDIR)/arr_dyn_lib.o : arr_dyn_lib.c arr_dyn_lib.h
	$(CC) $(CFLAGS) -Iinc -D ARRAY_EXPORTS -c $< -o $@

# Динамическая компоновка
$(OBJDIR)/main_dyn_link.o : main_dyn_link.c element.h arr_dyn_lib.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

# Динамическая загрузка
$(OBJDIR)/main_dyn_load.o : main_dyn_load.c element.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

# Статическая библиотека
libstat_arr.a : $(OBJDIR)/arr_stat_lib.o
	ar rc $@ $<

$(OBJDIR)/arr_stat_lib.o : arr_stat_lib.c arr_stat_lib.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/main_stat.o : main_stat.c element.h arr_stat_lib.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@


$(OBJDIR)/element.o : element.c element.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@


$(OBJDIR)/check_key.o : $(UNITDIR)/check_key.c check_key.h $(LIB)
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_mysort.o : $(UNITDIR)/check_mysort.c check_mysort.h element.h $(LIB)
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/check_main.o : $(UNITDIR)/check_main.c check_key.h check_mysort.h
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

.PHONY : clean func stat dyn_link dyn_load stat_unit dyn_unit
clean :
	rm -f $(OBJDIR)/*.o *.a *.exe *.dll

func :
	@if [ -f app.exe ]; then cd func_tests; sh all_tests.sh; fi

stat : $(OBJDIR)/main_stat.o $(OBJDIR)/element.o libstat_arr.a
	$(CC) $< $(OBJDIR)/element.o -L. -lstat_arr -o app.exe

dyn_link : $(OBJDIR)/main_dyn_link.o $(OBJDIR)/element.o arr.dll
	$(CC) $< $(OBJDIR)/element.o -L. -larr -o app.exe

dyn_load : $(OBJDIR)/main_dyn_load.o $(OBJDIR)/element.o arr.dll
	$(CC) $< $(OBJDIR)/element.o -o app.exe

stat_unit : LIB := arr_stat_lib.h
stat_unit : $(UNITS) $(OBJDIR)/element.o libstat_arr.a
	$(CC) $(UNITS) $(OBJDIR)/element.o -L. -lstat_arr -lcheck -o unit_tests.exe
	./unit_tests.exe

dyn_unit : LIB := arr_dyn_lib.h
dyn_unit : CFLAGS += -D DYNAMIC
dyn_unit : $(UNITS) $(OBJDIR)/element.o arr.dll
	$(CC) $(UNITS) $(OBJDIR)/element.o -L. -larr -lcheck -o unit_tests.exe
	./unit_tests.exe
