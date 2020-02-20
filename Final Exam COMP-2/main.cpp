#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "Queue.cpp"
#include "Queue.h"

using namespace std;
using namespace ListaQueue;

template <class T>
void Opciones(Queue<T> queue1,Queue<T> queue2, Nodo<T> lista1, Nodo<T> lista2/*, string str*/)
{
	ifstream inputfile1, inputfile2;
	
	inputfile1.open("cola1E.txt");
	if(inputfile1.fail())
	{
		cout << "Error: No se pudo abrir archivo #1.\n";
		exit(1);
	}
	inputfile2.open("cola2E.txt");
	if(inputfile2.fail())
	{
		cout << "Error: No se pudo abrir archivo #2.\n";
		exit(2);
	}
	
	
	T input1 /*= NULL*/, input2 /*= NULL*/;
	T mockinput1, mockinput2;
	Queue<T> MockObj1, MockObj2, ObjBono;
	
	Nodo<T> Mocklista1, Mocklista2, ListaBono;
	bool flag = true;
	int opcion, counter1 = 0, counter2 = 0; //counters para personas en general
	int countFil1 = 0, countFil2 = 0; // Counters para los restantes en las filas
	int NumFil, BonoCounter = 0;


	while(!inputfile1.eof())
	{
		inputfile1 >> lista1.dato;
		Mocklista1.dato = lista1.dato;
		queue1.Agrega(lista1.dato);
		MockObj1.Agrega(Mocklista1.dato);
		counter1++;
		countFil1++;
		
		
	}
	cout << "\nDatos de fila 1 de avengers recolectada.\n";
	while(!inputfile2.eof())
	{		
		inputfile2 >> lista2.dato;
		Mocklista2.dato = lista2.dato;
		queue2.Agrega(lista2.dato);
		MockObj2.Agrega(Mocklista2.dato);/////////////////////////////////////
		counter2++;
		countFil2++;
	
	}
	cout << "\nDatos de fila 2 de avengers recolectada.\n";
	do
	{			 												
		cout << " -------------------------------" << endl;
		cout << "|\t\tMENU  \t\t|" << endl;
		
		cout << " -------------------------------" << endl;
		cout << "1: Pasar 1 persona a la sala de Endgame." << endl; //push
		cout << "2: Escribir lista de personas en las filas." << endl;
		cout << "3: Escribir personas que ya pasaron a la sala." << endl; //////////////////////////////////////////////
		cout << "4: Volver a menu de tipo.\n"
			<< "5: Salir del programa."
			 << endl;
		cout << "Opcion #";
		cin >> opcion;
		cout << endl;


		switch (opcion)
		{

		case 1:


				if(MockObj1.Vacia() && MockObj2.Vacia())
				{
					cout << "\t\t*Chasquido del tunas*\n";
					cout << "Filas #1 y #2 vacias." << endl << endl;
				}
				else if(MockObj2.Vacia())
				{
					lista1.dato = queue1.Extrae();
					MockObj1.Extrae();
					NumFil = 1;////////////////////////////////////
					ListaBono.dato = lista1.dato;/////////////////////////////////
					ObjBono.AgregaBono(ListaBono.dato, NumFil);///////////////////////////////
					
					cout << "\t\t*Chasquido del tunas*\n";
					cout << "\t\t:Entra persona:\n\n";
					cout << "Edad: " << lista1.dato << endl;
					cout << "Fila #2 ahora vacia." << endl;
					
				
					cout << "Fila: 1 " << endl;
					countFil1--;
					
					BonoCounter++; //////////////////////////////////////////////
				}
				else if(MockObj1.Vacia())
				{
					lista2.dato = queue2.Extrae();
					MockObj2.Extrae();
					NumFil = 2; ////////////////////////////////////////////
					ListaBono.dato = lista2.dato;/////////////////////////
					ObjBono.AgregaBono(ListaBono.dato, NumFil);////////////////////////
					
					cout << "\t\t*Chasquido del tunas*\n";
					cout << "\t\t:Entra persona:\n\n";
					cout << "Edad: " << lista2.dato << endl;
					cout << "Fila #1 ahora vacia." << endl;
					
					cout << "Fila: 2 " << endl;
					countFil2--;
					
					BonoCounter++; //////////////////////////////////////////////
				}
				else if(MockObj1.Peek() >= MockObj2.Peek())
				{
					mockinput1 = queue1.Extrae();
					NumFil = 1; //////////////////////////////////////
					Nodo<T> temp;///////////////////////////////////////////////////
					temp.dato = MockObj1.Extrae();///////////////////////////////////
					ListaBono.dato = temp.dato;//////////////////////////////////
					ObjBono.AgregaBono(ListaBono.dato, NumFil);//////////////////////////////////
					
					
					cout << "\t\t*Chasquido del tunas*\n";
					cout << "\t\t:Entra persona:\n\n";
					cout << "Edad: " << mockinput1 << endl;
					
					
					cout << "Fila: 1" << endl;
					
					countFil1--;
					
					BonoCounter++; /////////////////////////
				}
				else
				{
					Nodo<T> temp2;//////////////////////////////////////

					NumFil = 2;

					temp2.dato = MockObj2.Extrae();////////////////////////////
					ListaBono.dato = temp2.dato;////////////////////////////////
					ObjBono.AgregaBono(ListaBono.dato, NumFil);/////////////////////////////

					mockinput2 = queue2.Extrae();
					cout << "\t\t:Entra persona:\n\n";
					cout << "Edad: " << mockinput2 << endl;
					
					cout << "Fila: 2" << endl;
					countFil2--;
					BonoCounter++; ////////////////////////////////////////////
					
				}
					
			break;
		case 2:
		
			if(countFil1 > countFil2)
			{
				
				cout << "Fila #1 contiene " << countFil1 << " personas." << endl;
				
				if(countFil2 == 0)
					cout << "Fila #2 vacia." << endl;
				else
					cout << "Fila #2 contiene " << countFil2 << " personas." << endl;

				cout << "Fila #1 contiene la mayor cantidad de personas = " << countFil1 << endl << endl;
			}
				
			else if (countFil1 < countFil2)
			{
				if(countFil1 == 0)
					cout << "Fila #1 vacia." << endl;
				else
					cout << "Fila #1 contiene " << countFil1 << " personas." << endl;

				cout << "Fila #2 contiene " << countFil2 << " personas." << endl;
				cout << "Fila #2 contiene la mayor cantidad de personas = " << countFil2 << endl << endl;
			}
				
			else if (countFil1 == 0 && countFil2 == 0)
				cout << "Filas #1 y #2 estan vacias." << endl << endl;
			else 
				cout << "Filas #1 y #2 contienen la misma cantidad de personas = " << countFil1 << endl << endl;
			
			break;
		case 3:
			cout << "\n~[Lista en orden Reciente -> Antiguo]~\n";
			cout << "~[Personas ya en la sala]~\n";
			ObjBono.EscribirBono(BonoCounter);

			break;
		case 4:
			cout<<"Volviendo a menu de tipo, si quiere salir oprima #3 de nuevo.\n";
			flag = false;
			break;

		case 5:
			flag = false;
			cout<<"Volviendo a menu de tipo, si quiere salir oprima #3 para salir del programa.\n";
			break;
		}
	} while (flag);
	system("CLS");//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	inputfile1.close();
	inputfile2.close();
}

void MenuOpciones()
{
	int tipo;

	do
	{
		cout << "~~~~~:[MENU]:~~~~~" << endl;
		cout << "1: Usar dato enteros." << endl;
		cout << "2: Usar dato string." << endl;
		cout << "3: Salir" << endl;
		cout << "Opcion #";

		cin >> tipo;
		cout << endl;
		
		system("CLS"); //////////////////////////////////////////////////////////
	} while (tipo < 1 || tipo > 3);

	if (tipo == 1)
	{
		Queue<int> queue1, queue2;
		Nodo<int> valor1, valor2;
		Opciones(queue1, queue2, valor1, valor2/*, "Enteros"*/);
		system("CLS"); //////////////////////////////////////////////////////////

		MenuOpciones();
	}
	else if (tipo == 2)
	{
		Queue<string> queue1, queue2;
		Nodo<string> valor1, valor2;
		Opciones(queue1, queue2, valor1, valor2/*, "String"*/);
		system("CLS"); //////////////////////////////////////////////////////////

		MenuOpciones();
	}
	else
	{
		cout << "\nGracias por usar el programa...\nQue disfrute la pelicula, evite spoilers...\nTodavia me lees? Gracias por los 25pts, nos vemos el anio que viene (^___^)\n\n";
		return;
	}
	//system("CLS");
}

int main()
{ 
	//MenuOpciones();
	queue<int> obj;
	obj.push(4);
	cout << obj.pop();
	return 0;
}
