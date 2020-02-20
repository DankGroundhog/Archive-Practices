import pandas as pd
from matplotlib import pyplot
from matplotlib.pyplot import *

def Menu():
    opcion = int(input("\t\t\t~MENU~\n 1- Mostrar datos generales\n 2- Mostrar datos especificos\n 3- Graficar datos generales\n 4- Graficar datos especificos\n\nOpcion: "))
    return opcion

def Menu_2(opcion):
    if(opcion == 2 or opcion == 4):
        opcion_m_2 = int(input("\t\t\t~SUB-MENU~\n 1- Temperatura\n 2- Humedad\n\nOpcion: "))
        return opcion_m_2

opcion = Menu()
opcion_2 = Menu_2(opcion)
if(opcion_2 == 1):
    opcion_2 = 'Temperature'
elif(opcion_2 == 2):
    opcion_2 = 'Humidity'

df = pd.read_csv('JoinedDataframe.txt')

temp_df_1 = df.loc[opcion_2]['Fecha']

graph_list = []
domain = []

if(opcion == 1):
    temp_df = df
    print(temp_df)
elif(opcion == 2):
    temp_df = df.loc[opcion_2]
    print(temp_df)
elif(opcion == 3):
    df.plot()
elif(opcion == 4):
    temp_df = df.loc[opcion_2]['Reading']
    
    for rows in range(temp_df.size):  
        temp_list = temp_df[rows].split()
        temp_df[rows] = int(temp_list[0])
        graph_list.append(temp_df[rows])
        domain.append(temp_df_1[rows])
        plt.plot(domain, graph_list)
