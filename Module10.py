from matplotlib import pyplot as plt
from matplotlib.pyplot import *
import numpy as np
from scipy.stats import linregress
from scipy.optimize import curve_fit
import math


def linea(x, a, b):
    return  a*x + b
def sqrt_line(x, a, b):
    return (a*x + b)**(1/2)
def polynomial(x, a, b, c, d, e, f):
    return a + (b*x) + (c*x**2) + (d*x**3) + (e*x**4) + (f*x**5)
    


Dias = [31, 62, 93, 99, 107, 113, 121, 127, 148, 161, 180, 214, 221, 307, 320]
Peso = [6.25, 10, 23, 27.6, 29.8, 31.6, 37.2, 42.2, 48.7, 54, 63, 66, 72, 72.2, 72]

Dias = np.array(Dias)
Peso = np.array(Peso)

plt.title("Dog Weight Predictions", fontsize = 16)
plt.xlabel('Dias', fontsize = 16)
plt.ylabel('Peso (lbs)', fontsize = 16)
plt.tight_layout()
plt.xticks(np.arange(30,330,10))
plt.yticks(np.arange(10,90,5))
plt.ylim(0,80)
plt.grid()

popt,pcov = curve_fit(linea, Dias, Peso)
sopt,scov = curve_fit(sqrt_line, Dias, Peso)
copt,ccov = curve_fit(polynomial, Dias, Peso)

a = popt[0]
b = popt[1]

(slope, intercept, rvalue, pvalue, stderr) = linregress(Dias, Peso)

xfine = np.linspace(20, 330)

plt.scatter(Dias, Peso, color = 'b', marker = 'o', label = 'Raw Weight', linewidths = 8)

plt.plot(Dias, linea(Dias, popt[0], popt[1]), color = 'r', label = 'Optimal Weight (Linear Regression)')
plt.plot(Dias, sqrt_line(Dias, sopt[0], sopt[1]), color = 'g', label = 'Optimal Weight (Square Root Regression)')
plt.plot(Dias, polynomial(Dias, copt[0], copt[1], copt[2], copt[3], copt[4], copt[5]), color = 'k', label = 'Optimal Weight (Polynomial Regression (3rd Grade))')

plt.legend(fontsize = 20, loc = 'best')

print("\nCorrolation coefficient: {}\n".format(round(rvalue, 4)))
print("Standard error: {}\n".format(round(stderr, 4)))

"""
In this program I fitted 3 plots with different methods of regression.
Linear, Square Root and Polynomial regression were plotted against data
collected of a dog's weight over some amount of days. We can see that the
polynomial plot is the most accurate of all the regression estimates. From
here we can say, the greater the grade of the polynomial, the more accurate 
the prediction fit will be.

One could say that the polynomial plot is the optimal weight for the dog in
that time frame. Steady and continuos growth until it comes to level itself out at around
72 pounds by the end of the time period.
"""