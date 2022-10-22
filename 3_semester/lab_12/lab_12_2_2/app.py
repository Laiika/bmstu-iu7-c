import ctypes
from tkinter import *
from tkinter import messagebox as mb

lib = ctypes.CDLL('./arr.dll')

# int arr_fill_fib_nums(int *arr, size_t n)
_fill = lib.arr_fill_fib_nums
_fill.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t)
_fill.restype = ctypes.c_int

def fill(len):
    if len > 0:
        arr = (ctypes.c_int * len)()

        if 0 == _fill(arr, len):
            return list(arr)

    return list()

# int arr_copy_first(const int *src, size_t src_len, int *dst, size_t *dst_len)
_copy = lib.arr_copy_first
_copy.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_size_t))
_copy.restype = ctypes.c_int

def copy(src):
    src_len = len(src)
    src_arr = (ctypes.c_int * src_len)(*src)

    # 1 - память с запасом
    #dst = (ctypes.c_int * src_len)()
    #dst_len = ctypes.c_int(src_len)

    # 2 - сначала вызов функции (узнать размер)
    dst = None
    dst_len = ctypes.c_size_t(0)

    if 1 == _copy(src_arr, src_len, dst, dst_len):
        dst = (ctypes.c_int * dst_len.value)()
        _copy(src_arr, src_len, dst, dst_len)

        return list(dst)
    
    return list()


# Функция, проверяющая, что строка содержит целое число
def is_number(st):
    if st.isdigit() or (st[0] == '-' and st[1:].isdigit()):  # Строка содержит целое число
        return True

# Функция, выводящая список чисел Фибоначчи
def display_answer1():
    n = num.get()

    if not is_number(n):  # Проверка, что введено число
        mb.showerror("Ошибка", "Должно быть введено целое число")
        return

    if int(n) <= 0:
        mb.showerror("Ошибка", "Размер массива должен быть больше 0")
        return

    nums = fill(int(n))
    text.delete(1.0, END)
    text.insert(1.0, ' '.join(list(map(str, nums))))  # Вывод ответа

# Функция, выводящая список первых вхождений каждого числа в исходный массив
def display_answer2():
    nums = list(map(str, array.get().split()))  # Введенный массив

    for num in nums:
        if not is_number(num):  # Проверка, что введено число
            mb.showerror("Ошибка", "Должен быть введен массив целых чисел")
            return

    nums = list(map(int, nums))
    nums = copy(nums)
    text2.delete(1.0, END)
    text2.insert(1.0, ' '.join(list(map(str, nums))))  # Вывод ответа


window = Tk()
window.geometry('800x500')
window.title('П')

num = StringVar()  # Строка для ввода количества элементов в массиве
# Создание поясняющего текста для ввода
label1 = Label(text='Введите количество элементов в массиве ', font='3')
label1.pack(padx=10, pady=10)
# Создание поля для ввода числа
entry1 = Entry(textvariable=num, font='3')
entry1.pack(padx=10, pady=10)
# Поле для вывода ответа
text = Text(width=150, height=5)
text.pack(padx=10, pady=10)

frame = Frame()
frame.pack()
Button(frame, text="Заполнить массив числами Фибоначчи ", command=display_answer1).pack(padx=10, pady=10)

array = StringVar()  # Строка для ввода массива
# Создание поясняющего текста для ввода
label2 = Label(text='Введите первый массив ', font='3')
label2.pack(padx=10, pady=10)
# Создание поля для ввода чисел
entry2 = Entry(textvariable=array, width=150, font='3')
entry2.pack(padx=10, pady=10)
# Поле для вывода ответа
text2 = Text(width=150, height=5)
text2.pack(padx=10, pady=10)

frame2 = Frame()
frame2.pack()
Button(frame2, text="Вывести первое вхождение каждого числа ", command=display_answer2).pack(padx=10, pady=10)

window.mainloop()
