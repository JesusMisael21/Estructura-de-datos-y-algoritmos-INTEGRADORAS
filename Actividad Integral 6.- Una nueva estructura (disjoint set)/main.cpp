/*
 * main.cpp
 *
 *  Created on: 30/10/2020
 *      Author: Jesús Misael Reséndiz Cruz
 */

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include "disjointSet.h"

using namespace std;

vector<int> datos={};
void menu();

int main() {
	string ini, dest;
	ofstream archivo;
	// creacion del archivo en donde se guardan las consultas
	archivo.open("consultas.txt",ios::out);
	//items of whole set
	ifstream ids ("ID_Estudiantes.txt");
	string line; 
	if (ids.is_open()){
		int i=0;
		while (getline(ids, line)){
			datos.push_back(stoi(line));
		}
		ids.close(); 
	} else {
		cout << "Unable to open file"; 
	}
	DisjointSet dis;
	dis.create(datos); // crear la estructura con
	cout<<"\n"<<"\t"<<"Se ha leido con exito el archivo de los ID's de los estudiantes"<<"\n"<<"\t"<<"y se han introducido los ID's en una estructura de disjointSet"<<"\n"<<"\n";
    cout<<"  Que quisieras hacer?"<<"\n"<<"\n";
	char inchar;
	while(true){
		menu();
		cin>>inchar;
		//Opc 5 sale del programa
		if(inchar=='5')break;
		switch(inchar){
			// Opc 1 muestra los ID's de los estudiantes
			case '1':
				archivo<<"\n\n\t\tOpcion para mostrar los ID's de los estudiantes.\n";
				archivo<<"\toutput:\n";
				cout<<"\t"<<"\toutput:\n";
				for(int i=0;i<datos.size();i++){
					cout<<datos[i]<<endl;
					archivo<<datos[i]<<"\n";}
			break;
			// Opc 2 para agrupar estudiantes por conjuntos
			case '2':
				archivo<<"\n\n\t\tOpcion para agrupar estudiantes por conjuntos.\n";
				cout<<"Conjunto del estudiante (input): ";
				archivo<<"\nConjunto del estudiante (input): ";
				cin>>ini;
				archivo<<ini;
				cout<<"Se agrupa con el conjunto del estudiante (input): ";
				archivo<<"\nSe agrupa con el conjunto del estudiante (input): ";
				cin>>dest;
				archivo<<dest<<"\n";
				dis.Union(stoi(ini),stoi(dest));
			break;
			// Opc 3 para mostrar el representante de algun estudiante
			case '3':
				archivo<<"\n\n\t\tOpcion para mostrar el representante de algun estudiante.\n";
				cout<<"Representante del estudiante (input): ";
				archivo<<"\nRepresentante del estudiante (input): ";
				cin>>ini;
				archivo<<ini<<"\n";
				archivo<<"\toutput:\n";
				cout<<"\t"<<"\toutput:\n";
				cout<<dis.Find(stoi(ini));
				archivo<<dis.Find(stoi(ini))<<"\n";
			break;
			// Opc 4 muestra el numero total de conjuntos agrupados
			case '4':
				archivo<<"\n\n\t\tOpcion para mostrar el numero total de conjuntos agrupados.\n";
				archivo<<"\toutput:\n";
				cout<<"\t"<<"\toutput:\n";
				archivo<<"Conjuntos actuales: "<<dis.conj(datos, dis)<<"\n";
				cout<<"Conjuntos actuales: "<<dis.conj(datos, dis)<<"\n";
			break;
		}
		
	}
	archivo.close();
}

//Definicion de la funcion menu
void menu(){
	cout<<"\n"<<"\n\tOpciones principales:\n"<<"1. Ver los ID's de los estudiantes"<<"\n"<<"2. Agrupar estudiantes por conjuntos"<<"\n";
	cout<<"3. Mostrar el representante de algun estudiante\n"<<"4. Mostrar el numero total de conjuntos"<<"\n"<<"5. Salir"<<"\n"<<"Opcion (input): ";
}