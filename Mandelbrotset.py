import numpy as np
import matplotlib.pyplot as plt

def mandelbrot(c, max_iter):
    z = 0
    n = 0
    while abs(z) <= 2 and n < max_iter:
        z = z*z + c
        n += 1
    return n

def generate_mandelbrot(xmin, xmax, ymin, ymax, width=3000, height=3000, max_iter=200):
    x, y = np.linspace(xmin, xmax, width), np.linspace(ymin, ymax, height)
    C = np.array([x + 1j*yi for yi in y])
    
    iteration_counts = np.zeros((height, width))
    for i in range(height):
        for j in range(width):
            iteration_counts[i, j] = mandelbrot(C[i, j], max_iter)
    
    plt.figure(figsize=(10, 8))
    plt.imshow(iteration_counts, extent=[xmin, xmax, ymin, ymax], cmap='hot', interpolation='nearest')
    plt.colorbar()
    plt.title('Mandelbrot Set')
    plt.xlabel('Re')
    plt.ylabel('Im')
    plt.show()

generate_mandelbrot(-2.5, 1.5, -1, 1)

zoom_xmin, zoom_xmax = -1.5, -1.0
zoom_ymin, zoom_ymax = 0, 0.5
generate_mandelbrot(zoom_xmin, zoom_xmax, zoom_ymin, zoom_ymax)