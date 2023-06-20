import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
#since the condition on the mandelbrot fractal is indipendent of the class I can write it outside


def next_f(z0: complex, c: complex):
    """
    Functions that computes the netx element in the recursive formula:
    zn+1 = zn*zn + c
    z0: should almost always be initialized to 0
    c   is a comlex constant
    """
    #NOTE for isacco: maybe this can be implemented via lambda
    z1 = z0**2 + c
    return z1

def n_iter(z0: complex, c: complex, max_iter: int, thresh = 4):
    """
    Returns the number of iterations before z diverges (given a treshold)
    """
    zn = z0
    it = 0
    while ((abs(zn)**2 < thresh) and it < max_iter):
        zn = next_f(zn, c)
        it += 1
    return it
        
class fractal_board:
    """
    board to rapresent the Mandelbrot set
    """
    def __init__(self, dim):
        self.dim = dim
        self.board = np.full((self.dim, self.dim), 1., dtype = float)

    """
    keep in mind that The left-most extent of the set ends with the spike 
    at x = -2, and the right side extends out to approximately x = 0.47. 
    The top and bottom are at approximately y = ± 1.12
    """
    def coloring_board(self):
        """
        function that colors each pixel the board basing on number of iters
        """
        z_real_bound = 2.48/(self.dim-1)
        z_im_bound = 2.26/(self.dim-1)
        #lamda func that maps the coordinates into the rescaled ones
        f = lambda z_real, z_im:(z_real*z_real_bound - 2, z_im*z_im_bound - 1.13)
        for x in range(self.dim):
            for y in range(self.dim):
                number_iterations = n_iter(0, complex(*f(x,y)), 500)
                self.board[y][x] = (1-number_iterations/500)

    def plotter(self):
        """
        shows the fractal
        """

        # construct DataFrame from Numpy Array
        zoomed_board = self.board[self.dim//8*5 : self.dim//8*6 , self.dim//8*4 : self.dim//8*5] 

        my_data = pd.DataFrame(data = zoomed_board)

        # create the plot
        fig, heat_plot = plt.subplots()
        heat_plot = sns.heatmap(data=my_data,cmap='plasma' )
        heat_plot.set_title("Heatmap plot (w Seaborn)");
        plt.show()

a =  fractal_board(10000)
a.coloring_board()
a.plotter()
