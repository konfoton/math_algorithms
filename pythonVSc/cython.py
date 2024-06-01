import ctypes

lib = ctypes.CDLL('./matmul.so')
class Dynamic(ctypes.Structure):
    pass

Dynamic._fields_ = [
    ("row", ctypes.c_int),
    ("col", ctypes.c_int),
    ("array", ctypes.POINTER(ctypes.POINTER(ctypes.c_int)))
]

lib.matrixmul.restype = ctypes.POINTER(Dynamic)
lib.matrixmul.argtypes = [ctypes.POINTER(Dynamic), ctypes.POINTER(Dynamic)]
lib.generate.restype = ctypes.POINTER(Dynamic)
lib.generate.argtypes = [ctypes.c_int, ctypes.c_int]

def python_to_c(a):
    temp = lib.generate(len(a), len(a[0]))
    for x, row in enumerate(a):
        for y, col in enumerate(row):
            temp.contents.array[x][y] = col
    return temp

def c_to_python(a):
    temp = [[a.contents.array[i][j] for j in range(a.contents.col)] for i in range(a.contents.row)]
    return temp

'''Testing...'''
if __name__ == "__main__":
    test1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

    test2 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

    test1_c = python_to_c(test1)

    test2_c = python_to_c(test2)

result_c = lib.matrixmul(test1_c, test2_c)

result = c_to_python(result_c)

print(result)