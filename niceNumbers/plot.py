
# Constantes
import matplotlib.pylab as plt
import numpy as np
from ctypes import *


ccode = cdll.LoadLibrary("./lnx.so")
lnx = ccode.ln_x
lnx.argtypes = [c_float]
lnx.restype = c_float

libcln = ccode.libc_ln
libcln.argtypes = [c_float]
libcln.restype = c_float


x = np.linspace(1, 257)

real = [libcln(z) for z in x]

nice_numbers = [lnx(z) for z in x]

erro = np.abs(np.subtract(real, nice_numbers))

plt.plot(x, erro, 'r-', marker=',')
plt.xlabel('x')
plt.ylabel('Erro absoluto')
plt.axis('tight')
plt.show()
