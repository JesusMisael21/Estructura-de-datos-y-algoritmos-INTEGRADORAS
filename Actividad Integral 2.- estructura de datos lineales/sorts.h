/*
 * sorts.h
 *
 *  Created on: 07/09/2020
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
	int bsMIN_seq(const std::vector<int>&, int size, int val);
	int bsMAX_seq(const std::vector<int>&, int size, int val);
	std::vector<int> str_int(std::vector<std::string>&);
	
	
public:
	// Metodo de ordenamiento y de busqueda llamados por el main (usuario)
	std::vector<T> ordenar(const std::vector<T>&);
	std::vector<T> Busqueda(const std::vector<T>&,int,int);
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

// Declaración del metodo ordenaSeleccion
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

//Declaración del metodo bs_seqMIN (busca la posicion del valor mas chico del rango)
template <class T>
int Sorts<T>::bsMIN_seq(const std::vector<int>&arr, int size, int val){
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
int Sorts<T>::bsMAX_seq(const std::vector<int>&arr, int size, int val){
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

//Declaración del metodo Busqueda (busqueda por rangos)
template <class T>
std::vector<T> Sorts<T>::Busqueda(const std::vector<T>&source,int min,int max){
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

// Declaración del metodo srt_int (transformar de vector string a int)
template <class T>
std::vector<int> Sorts<T>::str_int(std::vector<std::string>&source){
	std::vector<T> datos(source);
	std::vector<int> vel;
	for(int i=0;i<datos.size();i++){
		vel.push_back(stoi(datos[i]));
	}
	return vel;
}

#endif /* SORTS_H_ */