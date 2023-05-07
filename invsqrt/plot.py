
# Constantes
import math
import matplotlib.pylab as plt
import numpy as np
from ctypes import *


ccode = cdll.LoadLibrary("./comp.so")
newtonRaphson = ccode.newtonRaphson
newtonRaphson.argtypes = [c_float]
newtonRaphson.restype = c_float

invNewtonRaphson = ccode.invNewtonRaphson
invNewtonRaphson.argtypes = [c_float]
invNewtonRaphson.restype = c_float

garyTarolli = ccode.garyTarolli
garyTarolli.argtypes = [c_float]
garyTarolli.restype = c_float

libc_invsqrt = ccode.libc_invsqrt
libc_invsqrt.argtypes = [c_float]
libc_invsqrt.restype = c_float

x = np.linspace(1, 200, 50)

real = [libc_invsqrt(z) for z in x]

newtonSimples = [newtonRaphson(z) for z in x]
newtonInversa = [invNewtonRaphson(z) for z in x]
gary = [garyTarolli(z) for z in x]

erroNewtonSimples = np.abs(np.subtract(real, newtonSimples))
erroNewtonInversa = np.abs(np.subtract(real, newtonInversa))
erroGary = np.abs(np.subtract(real, gary))

plt.plot(x, erroNewtonSimples, 'r-.', marker=',',
         label='Newton-Raphson da raiz quadrada')
plt.plot(x, erroNewtonInversa, 'b--', marker=',',
         label='Newton-Raphson da raiz quadrada inversa')
plt.plot(x, erroGary, 'g.-', marker=',', label='Gary Tarolli')
plt.xlabel('x')
plt.ylabel('Erro absoluto')
plt.legend()
plt.axis('tight')
plt.show()
