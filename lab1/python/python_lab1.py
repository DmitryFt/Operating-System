from ctypes import windll, byref, Structure, Array, wintypes

class ULONGLONG(Structure):
    _fields_ = [("RAM", wintypes.ULONG)]
    
# создаём переменную, являющуюся экзкмпляром класса ULONGLONG
si = ULONGLONG()

# загружаем динамическую библиотеку kernel32.dll
kernel32 = windll.kernel32

# вызываем функцию GetPhysicallyInstalledSystemMemory, передавая ей переменную si по ссылке 
kernel32.GetPhysicallyInstalledSystemMemory(byref(si))
print("R_A_M: ", si.RAM/1024,"MB")