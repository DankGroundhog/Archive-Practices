#include<iostream>
#include<cstdlib>
#include "Queue.h"
#include <typeinfo>
#include <queue>

using namespace std;
namespace ListaQueue {

	using namespace ListaQueue;

	//constructor
	template<class TypeElemento>
	Queue<TypeElemento>::Queue():delantera(NULL), posterior(NULL) {// Crea la lista enlazada simple
		cabeza = NULL;
	}

	//destructor
	template<class TypeElemento>
	Queue<TypeElemento>::~Queue(){ // Elimina la lista enlazada simple
		Nodo<TypeElemento>* nodoActual;
		Nodo<TypeElemento>* sig;
		nodoActual = delantera;

		while(nodoActual != NULL){
			sig = nodoActual->siguiente;
			delete nodoActual;
			nodoActual = sig;
		}
	}

	template<class TypeElemento>
	TypeElemento Queue<TypeElemento>::Peek(){
	// 
		TypeElemento valor;

		if(delantera==NULL){
			cout<<"Fila para avengers vacia.\n"; ///////////////////////////////////////////////////////////////
		}
		else{
			valor=delantera->dato;
		}
		return valor;
	}

	template<class TypeElemento>
	/*bool*/void Queue<TypeElemento>::Agrega(TypeElemento elemento){
		
		if(Vacia())
		{
			delantera =  new Nodo<TypeElemento>;
			delantera ->dato = elemento;
			//cout << delantera ->dato << endl;//
			delantera ->siguiente = NULL;
			cabeza = delantera;
			//delete delantera;
		}
		else //////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{
			Nodo<TypeElemento>* temp_ptr;

			temp_ptr = new Nodo<TypeElemento>;
			//temp_ptr = cabeza;
			temp_ptr->dato = elemento;
			//cout << temp_ptr ->dato << endl; //
			temp_ptr->siguiente = NULL;
			cabeza ->siguiente = temp_ptr;
			cabeza = temp_ptr;
			//delete temp_ptr;
			numNodos++;
		} 
		
		
		//return;
	}

	/*template<class TypeElemento>
	void Queue<TypeElemento>::Pop (){
	// Si el elemento pertenece al QueueADT se elimina. La operación modifica al QueueADT
	// Devuelve true si lo pudo eliminar, 
	// Y flase si no lo pudo eliminar.
		Nodo<TypeElemento>* temp_ptr;
		if(cabeza==NULL)
		{
			cout<<"Pila vacia.\n";
		}

		else{
			temp_ptr= cabeza;
			cabeza =cabeza->siguiente;
			delete temp_ptr;
			numNodos--;
		}
	}*/
	template<class TypeElemento>
	TypeElemento Queue<TypeElemento>::Extrae(){
		TypeElemento valor; 
		if(Vacia()){
			cout<<"Fila para avengers vacia.\n"; 
			return 0;
		}
			valor = delantera ->dato;

			Nodo<TypeElemento>* descarta;
			descarta = delantera;
			delantera = delantera ->siguiente; 
			if(delantera == NULL)
				posterior = NULL;
			delete descarta;
			return valor;
			
	}

	template<class TypeElemento>
	bool Queue<TypeElemento>::Vacia (){
	// Verifica si el QueueADT no tiene elementos, en cuyo caso devuelve cierto, en caso contrario devuelve falso
		if (delantera == NULL){
			return true;
		}
		else{
			return false;
		};
		//return (cabeza == NULL);
	}
	template<class TypeElemento>
	bool Queue<TypeElemento>::VaciaLoop(){
	// Verifica si el QueueADT no tiene elementos, en cuyo caso devuelve cierto, en caso contrario devuelve falso
		if (cabeza != NULL){
			delantera = delantera ->siguiente;
			return true;
		}
		else{
			//delantera = delantera ->siguiente;
			return false;
		};
		//return (cabeza == NULL);
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
	template<class TypeElemento>
	TypeElemento Queue<TypeElemento>::ExtraeBono(int Num)
	{
		TypeElemento valor; 
		if(Vacia()){
			cout<<"Fila para avengers vacia.\n"; 
			return 0;
		}
			valor = delantera ->dato;

			Nodo<TypeElemento>* descarta;
			descarta = delantera;
			delantera = delantera ->siguiente; 
			if(delantera == NULL)
				posterior = NULL;
			delete descarta;
			return valor;

			/*if(Num == 1)
				cout << "Fila: 1 - ";
			else if(Num == 2)
				cout << ""*/
			
	}

	template<class TypeElemento>
	bool Queue<TypeElemento>::BonoVacio()
	{
		if(delantera == NULL)
			return true;
		else 
			return false;
	}

	template<class TypeElemento>
	void Queue<TypeElemento>::Bono(TypeElemento elemento, int fila)
	{
		Nodo<TypeElemento>* temp;
		temp = new Nodo<TypeElemento>;
		temp -> dato = elemento;
		temp -> fila = fila;
		temp -> siguiente = delantera; 
		delantera = temp;
	}

	template<class TypeElemento>
	void Queue<TypeElemento>::EscribirBono(int total)
	{
		int n = 1;
		Nodo<TypeElemento>* temp;
		if(BonoVacio())
		{
			cout << "No hay nadie en la tanda.\n";
			return;
		}
		else 
			for(temp = delantera; total >= n; temp = temp -> siguiente)
			{
				cout << n << ": " << temp -> dato << " fila " << temp -> fila << endl;
				n++;
			}
		return;
	}

	template<class TypeElemento>
	void Queue<TypeElemento>::AgregaBono(TypeElemento elemento, int& fila)
	{
		
		/*if(Vacia())
		{
			delantera =  new Nodo<TypeElemento>;
			delantera ->dato = elemento;
			//cout << delantera ->dato << endl;//
			delantera ->siguiente = NULL;
			cabeza = delantera;
			//delete delantera;
		}
		else //////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{*/
			Nodo<TypeElemento>* temp_ptr;

			temp_ptr = new Nodo<TypeElemento>;
			//temp_ptr = cabeza;
			temp_ptr->dato = elemento;
			//cout << temp_ptr ->dato << endl; //
			temp_ptr->fila = fila;
			temp_ptr->siguiente = NULL;
			temp_ptr ->siguiente = delantera;
			delantera = temp_ptr;
			//delete temp_ptr;
			numNodos++;

			/*Nodo<TypeElemento>* temp_ptr;

			temp_ptr = new Nodo<TypeElemento>;
			//temp_ptr = cabeza;
			temp_ptr->dato = elemento;
			//cout << temp_ptr ->dato << endl; //
			temp_ptr->siguiente = NULL;
			cabeza ->siguiente = temp_ptr;
			cabeza = temp_ptr;
			//delete temp_ptr;
			numNodos++;*/
		//} 
		/*if(fila == 0)
			fila = 1;
		else if(fila == 2)
			fila = 2;*/
		
		
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*template<class TypeElemento>
	int Queue<TypeElemento>::Count (){
	// Devuelve el número de elementos del QueueADT;
		return numNodos;
	}*/
}

