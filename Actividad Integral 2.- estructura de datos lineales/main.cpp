/*
 * main.cpp
 *
 *  Created on: 19/09/2020
 *      Author: Jesus Misael R.C.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include "sorts.h"
#include "list.h"

using namespace std;

//Declaracion de las funciones auxiliares
void leer();
void almacenar(vector<string>&);
void menu();

//Variables globales 
List<string> datos;
List<string> datOrde;
vector<string> datos_csv;
vector<string> datOrdenados;
vector<string> datBuscados;

int main(){
	
	Sorts<string> sorts;
	//Leer el archivo y guardar en una lista
	leer();
	//Obtener los registros ordenados, usando el algoritmo de tipo "selection sort"
	datOrdenados=sorts.ordenar(datos_csv);
	//Almacenar datos ordenados en un nuevo archivo .csv 
	almacenar(datOrdenados);
	for(int i=0;i<datOrdenados.size();i++){
		datOrde.add(datOrdenados[i]);
	}
	cout<<"\n"<<"\t"<<"Se ha leido con exito el archivo de alturas de las personas"<<"\n"<<"\t"<<"y se ha ordenado ascendentemente por alturas"<<"\n"<<"\n";
	cout<<"  Que quisieras hacer?"<<"\n"<<"\n";
	char inchar;
	while(true){
		//Menu nos muestra las opciones de interaccion con el usuario
		menu();
		cin>>inchar;
		//Opc 4 sale del programa
		if(inchar=='4')break;
		switch(inchar){
			// Opc 1 nos imprime los registros originales
			case '1':
				for(int i=0;i<datos_csv.size();i++){
					cout<<datos.posic(i)<<"\n";
				}
			break;
			//Opc 2 nos imprime los registros ordenados
			case '2':
				for(int i=0;i<datOrdenados.size();i++){
					cout<<datOrde.posic(i)<<"\n";}
			break;
			//Opc 3 nos da la busqueda por rangos, con el algoritmo de busqueda secuencial
			case '3':
				int min,max;string min2,max2;
				cout<<"Ingresa altura minima: ";
				cin>>min2;
				min=stoi(min2);
				cout<<"Ingresa altura maxima: ";
				cin>>max2;
				max=stoi(max2);
				datBuscados=sorts.Busqueda(datOrdenados,min,max);
				cout<<"\n"<<"\t"<<"Busqueda:"<<"\n"<<"\n";
				for(int i=0;i<datBuscados.size();i++){
					cout<<datBuscados[i]<<"\n";}
				cout<<"\n"<<"\t"<<"Fin de la busqueda."<<"\n";
			break;
		}
	}
	return 0;
}
//Construccion de la funcion leer
void leer(){
	ifstream infile("personas.csv");
	string line="";
	while(getline(infile,line)){
		stringstream strstr(line);
		string word="";
		while(getline(strstr,word,',')){
			datos_csv.push_back(word);
			datos.add(word);
		}
	}
}

//Construccion de la funcion almacenar
void almacenar(vector<string>&datOrdenados){
	vector<string> datos(datOrdenados);
	ofstream myFile;
	myFile.open("Datos_Alturas_Ordenadas.csv");
	int j=0;
	for(int i=0;i<datos.size();i++){
		if(j%2==0){myFile<<datos[i]<<",";}
		else{myFile<<datos[i]<<endl;}
		j++;
	}
}

//Construccion de la funcion menu
void menu(){
	cout<<"\n"<<"1. Ver los registros originales"<<"\n"<<"2. Ver los registros ordenados"<<"\n"<<"3. Hacer busqueda por rango"<<"\n"<<"4. Salir"<<"\n";
	cout<<"Opcion (input): ";
}