import cython
import time
import random
import matpython

def generate(size):
    return [[random.randint(0, 50) for y in range(size)] for x in range(size)]

test1 = generate(1000)
test2 = generate(1000)

print("C time: ")

a = time.time()
cython.matc(test1, test2)
b = time.time()
print(b - a)

print("Python time: ")

a = time.time()
matpython.matrixmul(test1, test2)
b = time.time()
print(b - a)
