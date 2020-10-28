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
#include "bst.h"

using namespace std;

void leer();
void menu();
void originales();
string nombre(string);
string altura(int);

//Variables globales 
vector<string> datos_csv;
BST<float> bst;
string alturas="";
string texto="";

int main(){
	float pos,alt; string pos2,alt2;
	int borrados=0;
	leer();
	cout<<"\n"<<"\t"<<"Se ha leido con exito el archivo de alturas de las personas"<<"\n"<<"\t"<<"y se han introducido en un arbol BST"<<"\n"<<"\n";
	cout<<"  Que quisieras hacer?"<<"\n"<<"\n";
	char inchar;
	while(true){
		//Menu nos muestra las opciones de interaccion con el usuario
		menu();
		cin>>inchar;
		//Opc 4 sale del programa
		if(inchar=='6')break;
		switch(inchar){
			// Opc 1 nos imprime los registros originales
			case '1':
				originales();
			break; 
			// Opc 2 actualiza un registro
			case '2':
				cout<<"Altura a modificar (input): ";
				cin>>pos2;
				pos=stof(pos2);
				cout<<"Altura nueva [deben ser 3 digitos a la izquierda\ndel punto y 1 a la derecha, ejemplo '123.4'] (input): ";
				cin>>alt2;
				alt=stof(alt2);
				bst.update(pos,alt);
				for(int j=0;j<datos_csv.size();j++){
					if(datos_csv[j]==pos2){
						datos_csv[j]=alt2;}
				}
			break; 
			//Opc 3 Borra algun registro
			case '3':
				cout<<"Altura a borrar (input): ";
				cin>>pos2;
				pos=stof(pos2);
				bst.remove(pos);
				borrados++;
			break;
			//Opc 4 Encontrar en que capa esta algun registro
			case '4':
				cout<<"Altura a encontrar (input): ";
				cin>>pos2;
				pos=stof(pos2);
				cout<<"Nivel de arbol: "<<bst.whatlevelamI(pos)<<endl;
			break;
			//Opc 5 Muestra los registros actualizados
			case '5':
				cout<<"\nDe que modo desea mostrar los registros actualizados?\n";
				cout<<"\tOpciones:\n1. preorder\n2. inorder\n3. postorder\n4. levelorder\nOpcion (input): ";
				cin>>inchar;
				cout<<"\n\t(Output):\n";
				switch(inchar){
					case '1':
						alturas=bst.preorder();
						for(int j=0;j<(datos_csv.size()-(2*borrados))/2;j++){
							texto=texto+nombre(altura(j))+" "+altura(j)+"\n";
						} 
						cout<<texto; texto="";
					break;
					case '2':
						alturas=bst.inorder();
						for(int j=0;j<(datos_csv.size()-(2*borrados))/2;j++){
							texto=texto+nombre(altura(j))+" "+altura(j)+"\n";
						} 
						cout<<texto; texto="";
					break;
					case '3':
						alturas=bst.postorder();
						for(int j=0;j<(datos_csv.size()-(2*borrados))/2;j++){
							texto=texto+nombre(altura(j))+" "+altura(j)+"\n";
						} 
						cout<<texto; texto="";
					break;
					case '4':
						alturas=bst.levelorder();
						for(int j=0;j<(datos_csv.size()-(2*borrados))/2;j++){
							texto=texto+nombre(altura(j))+" "+altura(j)+"\n";
						} 
						cout<<texto; texto="";
					break;
				}
			break;
		}
	}
	return 0;
}	

string altura(int pos){
	string alt="";
	for(int i=0;i<5;i++){
		alt=alt+alturas[5*pos+i];
	}
	return alt;
}

string nombre(string alt){
	for(int i=0;i<datos_csv.size();i++){
		if(datos_csv[i]==alt){
			return datos_csv[i-1];
		}
	}
	return "";
}

//Construccion de la funcion leer
void leer(){
	int i=0;
	ifstream infile("personas.csv");
	string line="";
	while(getline(infile,line)){
		stringstream strstr(line);
		string word="";
		while(getline(strstr,word,',')){
			datos_csv.push_back(word);
			if(i%2!=0){
				bst.add(stof(word));
			}
			i++;
		}
	}
}

void originales(){
	cout<<"\n\t(output):\n";
					int i=0;
					ifstream infile("personas.csv");
					string line="";
					while(getline(infile,line)){
						stringstream strstr(line);
						string word="";
						while(getline(strstr,word,',')){
							if(i%2==0){
								cout<<word<<" ";}
							if(i%2!=0){
								cout<<word<<"\n";}
							i++;
						}
					}
}

//Definicion de la funcion menu
void menu(){
	cout<<"\n"<<"\n\tOpciones principales:\n"<<"1. Ver los registros originales"<<"\n"<<"2. Actualizar"<<"\n"<<"3. Borrar"<<"\n";
	cout<<"4. Saber la capa de arbol del registro"<<"\n"<<"5. Mostrar registros actualizados"<<"\n"<<"6. Salir"<<"\n"<<"Opcion (input): ";
}