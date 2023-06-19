#import numpy as np
#import matplotlib.pyplot as plt

def next_frac(z_0: complex, c: complex):
    """
    Fractal evolution given a complex number
    z_0: starting complex number
    c: arbitrary constant
    z_1:generated comlex number in the sequence
    """
    z_1 = z_0**2 + c
    return z_1

#to get square modulus of a complex number in python abs()**2
def iteration(z_0: complex, c: complex, n_iterations:int):
    zn = z_0
    a = []
    it = 0
    while ((it<n_iterations) and (abs(zn)**2 < 2)):
        a.append(zn)
        zn = next_frac(zn, c)
        it += 1
    return a

print(iteration(1j, 0.01-0.02j, 100))
    

