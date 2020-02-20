#ifndef QUEUE_H
#define QUEUE_H

	#include <iostream>
	#include <string>
	#include <queue>
	using namespace std;

namespace ListaQueue {
	
	template<class TypeElemento>
	struct Nodo {
		TypeElemento dato;
		int fila;
		Nodo *siguiente;
	};
	template<class TypeElemento>
	class Queue {
	// La clase Conjunto utilizando listas enlazadas simples y plantillas (templates) para definir conjuntos cuyos elementos 
	// pueden ser de cualquiera de los tipo de datos entero, real o caracter.
	// El programa debe proveer un menú que permita al usuario seleccionar el tipo de datos con el que desea trabajar.
			
		public:

			//	Medoto Constructor
			Queue(); // Crea la lista enlazada simple

			// Método Destructor
			~Queue(); // Elimina la lista enlazada simple
			
			/*bool*/void Agrega(TypeElemento elemento);
			// Funciones miembras

			TypeElemento Extrae();
			
			
			void Bono(TypeElemento elemento, int fila);
			void EscribirBono(int total); //////////////////////////////////////////////////////////////
			bool BonoVacio(); 

			TypeElemento ExtraeBono(int Num); //////////////////////////////////////////////////

			//bool Push (TypeElemento elemento);
			// Agregar elemento por cabeza
			bool Vacia();
			bool VaciaLoop();
			void Opciones(Queue<TypeElemento> queue1, Queue<TypeElemento> queue2, TypeElemento valor1, TypeElemento valor2/*, string str*/);
			void MenuOpciones();
			TypeElemento Peek();
			
			void AgregaBono(TypeElemento, int& Num); ///////////////////////////////////////////////////
			
			//void Pop();
			// Elimina al primer elemento (cabeza)

			//TypeElemento Peek();
			// Retorna el primer elemento de la pila

			//bool EstaVacio();
			// Verifica si el conjunto no tiene elementos, en cuyo caso devuelve cierto, en caso contrario devuelve falso

			//void IntercambiarElemento ();
			// Intercambia primeros dos elementos

			//int Count ();
			//Retorna el tamano de la pila
			
			/*template<class T>
			struct Nodo {
				TypeElemento dato;
				Nodo *siguiente;
			};*/
			Nodo<TypeElemento>* cabeza;	//Apuntador a la cabeza de la lista
			int numNodos;
			Nodo<TypeElemento>* delantera; //////////////////////////////////////////////////////////
			Nodo<TypeElemento>* posterior;
		private:
			/*struct Nodo {
				TypeElemento dato;
				Nodo *siguiente;
			};*/

			//typedef Nodo* Nodo<TypeElemento>;

			/*Nodo cabeza;	//Apuntador a la cabeza de la lista
			int numNodos;
			Nodo<TypeElemento> delantera = cabeza;
			Nodo<TypeElemento> posterior;*/

	};

}
#endif
