import cython
import time
import random
import matpython

def generate(size):
    return [[random.randint(0, 50) for y in range(size)] for x in range(size)]

test1 = generate(1000)
test2 = generate(1000)
with open("results.txt", "a") as f:
    for x in range(100, 1300, 100):
        test1 = generate(x)
        test2 = generate(x)
        f.write(f"two matrixes {x} x {x}\n")
        f.write("C time: \n")
        a = time.time()
        cython.matc(test1, test2)
        b = time.time()
        f.write(f"time in seconds: {b-a}\n")
        f.write("Python time: \n")
        a = time.time()
        matpython.matrixmul(test1, test2)
        b = time.time()
        f.write(f"time in seconds: {b-a}\n")
        f.write("\n")