/*
 * sorts.h
 *
 *  Created on: 07/10/2020
 *      Author: Jesus Misael R.C.
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>
#include <iostream>
#include <string>

template <class T>
class Sorts {
private:
	// Metodos privados son auxiliares o de ayuda para los publicos
	void swap(std::vector<T>&, int, int,std::vector<T>&);
	void separar_atributos(std::vector<T>&,std::vector<T>&,std::vector<T>&);
	std::vector<T> unir_atributos(std::vector<T>&,std::vector<T>&);
	
	
public:
	// Metodo de ordenamiento llamados por el main (usuario)
	std::vector<T> ordenar(const std::vector<T>&);
};

// Declaración del swap
template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j,std::vector<T> &n) {
	T aux2=n[i];
	n[i]=n[j];
	n[j]=aux2;
	
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

// Declaración del separar_atributos
template <class T>
void Sorts<T>::separar_atributos(std::vector<T>&valor_numerico,std::vector<T>&nombre,std::vector<T>&datos){
	int l=0;
	for(int k=0;k<datos.size();k++){
		if(l%2!=0){valor_numerico.push_back(datos[k]);}
		else{nombre.push_back(datos[k]);}
		l++;
	}
}

// Declaración del metodo unir_atributos
template <class T>
std::vector<T> Sorts<T>::unir_atributos(std::vector<T>&valor_numerico,std::vector<T>&nombre){
	std::vector<T> datos_ordenados;
	for(int m=0;m<valor_numerico.size();m++){
		datos_ordenados.push_back(nombre[m]);
		datos_ordenados.push_back(valor_numerico[m]);
	}
	return datos_ordenados;
}

// Declaración del metodo ordenaSeleccion "algoritmo de ordenamiento"
template <class T>
std::vector<T> Sorts<T>::ordenar(const std::vector<T> &source) {
	std::vector<T> datos(source);
	std::vector<T> nombre;
	std::vector<T> valor_numerico;
	separar_atributos(valor_numerico,nombre,datos);
	int pos;

	for (int i = valor_numerico.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (valor_numerico[j] > valor_numerico[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(valor_numerico, i, pos, nombre);
		}
	}
	return unir_atributos(valor_numerico,nombre);
}

#endif /* SORTS_H_ */