import numpy as np
import matplotlib.pyplot as plt

class fractal_board:
    """
    board to rapresent the Mandelbrot set
    """
    def __init__(self, dim):
        self.board = np.full((dim, dim), 256)

a = fractal_board(1000)

print(a.board)
