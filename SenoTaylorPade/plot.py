
# Constantes
import math
import matplotlib.pylab as plt
import numpy as np
from ctypes import *


ccode = cdll.LoadLibrary("./sen.so")
taylor = ccode.taylor
taylor.argtypes = [c_double]
taylor.restype = c_double

pade = ccode.pade
pade.argtypes = [c_double]
pade.restype = c_double

libc_sin = ccode.libc_sin
libc_sin.argtypes = [c_double]
libc_sin.restype = c_double

x = np.linspace(-(math.pi)/4, (math.pi/4), 50)
real = [libc_sin(z) for z in x]
t = [taylor(z) for z in x]
p = [pade(z) for z in x]

taylorError = np.abs(np.subtract(real, t))
padeError = np.abs(np.subtract(real, p))

plt.plot(x, taylorError, 'b.-', label='T(x)')
plt.plot(x, padeError, 'g.--', label='R(x)' )
plt.xlabel('x (rad)')
plt.ylabel('Erro absoluto')
plt.legend()
plt.axis('tight')
plt.show()




