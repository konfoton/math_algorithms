import cython
import time
import random

def generate(size):
    return [[random.randint(50) for y in range(size)] for x in range(size)]

test1 = generate(100)
test2 = generate(100)


