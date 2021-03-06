/*
 * list.h
 *  Created on: 26/09/2020
 *      Author: Jesús Misael Reséndiz Cruz
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "exception.h"

template <class T> class List;

// Clase Link, me permite crear los nodos
template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

//Clase List, en ella se crearán los nodos
template <class T>
class List {
public:
	//Prototipo de los constructores, es sobrecarga
	List();  
	List(const List<T>&) throw (OutOfMemory);
	~List();
	// Prototipo de los metodos/funciones para manipular la lista
	void addFirst(T) throw (OutOfMemory);
	void add(T) throw (OutOfMemory);
	std::vector<T> find(const std::vector<T>&,int,int);
	T posic(int);
	bool update(int, T) throw (IndexOutOfBounds);
	T    removeFirst() throw (NoSuchElement);
	T    remove(int) throw (IndexOutOfBounds);
	bool empty() const;
	void clear();
	std::string toString() const;
	// Variables y metodos que no me interesan que el usuario vea (auxiliares)
private:
	int bsMIN_seq(const std::vector<int>&, int size, int val);
	int bsMAX_seq(const std::vector<int>&, int size, int val);
	void separar_atributos(std::vector<T>&,std::vector<T>&,std::vector<T>&);
	std::vector<int> str_int(std::vector<std::string>&);
	Link<T> *head;
	int 	size;
};

// Definición de los constructores
template <class T>
List<T>::List() : head(0), size(0) {}
// Sobrecarga, dependiendo de la creación de una lista o nodos
template <class T>
List<T>::~List() {
	clear();
}
// Definición del addFirst (añade elemento despues del nodo head)
template <class T>
void List<T>::addFirst(T val) throw (OutOfMemory) {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}
	newLink->next = head;
	head = newLink;
	size++;
}
// Definición del add (añade elemento a la ultima posicion de la lista)
template <class T>
void List<T>::add(T val) throw (OutOfMemory) {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}
	
	if (empty()) {
		addFirst(val);
		return;
	}

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}
// Declaración del separar_atributos
template <class T>
void List<T>::separar_atributos(std::vector<T>&valor_numerico,std::vector<T>&nombre,std::vector<T>&datos){
	int l=0;
	for(int k=0;k<datos.size();k++){
		if(l%2!=0){valor_numerico.push_back(datos[k]);}
		else{nombre.push_back(datos[k]);}
		l++;
	}
}
// Definición del find (algoritmo de busqueda adecuado para este escenario)
template <class T>
std::vector<T> List<T>::find(const std::vector<T>&source,int min,int max){
	std::vector<T> datos(source);
	std::vector<T> nombre;
	std::vector<T> valor_numerico;
	separar_atributos(valor_numerico,nombre,datos);
	std::vector<int> vel;
	vel=str_int(valor_numerico);
	int posI=bsMIN_seq(vel,vel.size(),min);
	int posF=bsMAX_seq(vel,vel.size(),max);
	if(min==max){
		max++;
		posF=bsMIN_seq(vel,vel.size(),max);
	}
	std::vector<T> datosBuscados;
	for(int i=posI;i<=posF;i++){
		datosBuscados.push_back(nombre[i]+" "+valor_numerico[i]);
	}
	return datosBuscados;
}
//Declaración del metodo bs_seqMIN (busca la posicion del valor mas chico del rango)
template <class T>
int List<T>::bsMIN_seq(const std::vector<int>&arr, int size, int val){
	int mid;
	int low = 0;
	int high = size - 1;

	while (low < high) {
		mid = (high + low) / 2;
		if (val == arr[mid]) {
			return mid;
		} else if (val < arr[mid]) {
			high = mid - 1;
		} else if (val > arr[mid]) {
			low = mid + 1;
		}
	}
	return low;
}

//Declaración del metodo bs_seqMAX (busca la posicion del valor mas grande del rango)
template <class T>
int List<T>::bsMAX_seq(const std::vector<int>&arr, int size, int val){
	int mid;
	int low = 0;
	int high = size - 1;

	while (low < high) {
		mid = (high + low) / 2;
		if (val == arr[mid]) {
			return mid;
		} else if (val < arr[mid]) {
			high = mid - 1;
		} else if (val > arr[mid]) {
			low = mid + 1;
		}
	}
	return low-1;
}
// Definición de update (actualiza la posicion deseada con el valor introducido)
template <class T>
bool List<T>::update(int index, T val) throw (IndexOutOfBounds) {
	int pos;
	Link<T> *p;
	if (index<0 || index>=size){
		throw IndexOutOfBounds();
	}

	p=head;
	pos=0;
	while (pos!=index){
		p=p->next;
		pos++;
	}
	p->value=val;
	return true;
}
// Definición de removeFirst (elimina el nodo al que apunta el head)
template <class T>
T List<T>::removeFirst() throw (NoSuchElement) {
	T val;
	Link<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;

	head = p->next;
	val = p->value;

	delete p;
	size--;

	return val;
}
// Definición de remove (elinina el nodo en la posición deseada)
template <class T>
T List<T>::remove(int index) throw (IndexOutOfBounds) {
	int pos;
	T val;
	Link<T> *p,*q;
	
	if(index<0 || index >= size){
		throw IndexOutOfBounds();
	}
	
	if(index==0){
		return removeFirst();
	}
	
	q=0;
	p=head;
	pos=0;
	while(pos!=index){
		q=p;
		p=p->next;
		pos++;
	}
	
	val=p->value;
	q->next =p->next;
	size--;
	
	delete p;
	
	return val;
}
// Definición de empy (para saber si hay elementos en la lista)
template <class T>
bool List<T>::empty() const {
	return (head == 0);
}
// Definición de clear (elimina todos los nodos de la lista)
template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

// Definición de remove (elinina el nodo en la posición deseada)
template <class T>
T List<T>::posic(int index){
	int pos;
	Link<T> *p;
	if (index<0 || index>=size){
		throw IndexOutOfBounds();
	}

	p=head;
	pos=0;
	while (pos!=index){
		p=p->next;
		pos++;
	}
	return p->value;
}
// Declaración del metodo srt_int (transformar de vector string a int)
template <class T>
std::vector<int> List<T>::str_int(std::vector<std::string>&source){
	std::vector<T> datos(source);
	std::vector<int> vel;
	for(int i=0;i<datos.size();i++){
		vel.push_back(stoi(datos[i]));
	}
	return vel;
}
// Definición de toString (se usa para leer la lista en forma de array)
template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}


#endif /* LINKEDLIST_H_ */