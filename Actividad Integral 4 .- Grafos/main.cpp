/*
 * main.cpp
 *
 *  Created on: 30/10/2020
 *      Author: clase
 */

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include "graph.h"

using namespace std;
// constructor de la funcion menú
void menu();

int main(int argc, char* argv[]) {
	// declaracion de variables locales
	string ini, dest,visit,v_aux,p_dfs,p_bfs;
	vector<string> vi;
	// creo mi grafo mapa
    Graph mapa;
	// cargo el archivo de mapas
	// y le digo que serán 8 nodos y sus 8 conexiones
	mapa.loadGraphList("mapa.txt", 8, 8);
	cout<<"\n"<<"\t"<<"Se ha leido con exito el archivo del mapa"<<"\n"<<"\t"<<"y se han introducido los lugares en un grafo"<<"\n"<<"\n";
    cout<<"  Que quisieras hacer?"<<"\n"<<"\n";
	char inchar;
	while(true){
		menu();
		cin>>inchar;
		//Opc 5 sale del programa
		if(inchar=='5')break;
		switch(inchar){
			// Opc 1 muestra las conexiones entre lugares
			case '1':
				cout<<"\t"<<"output:"<<"\n"<<mapa.printAdjList();
			break;
			// Opc 2 mustrar los adyacentes visitados entre dos lugares con DFS
			case '2':
				// se piden los dos lugares
				vi.clear();
				cout<<"Lugar inicial (input): ";
				cin>>ini;
				cout<<"Lugar destino (input): ";
				cin>>dest;
				// se busca con DFS
				visit=mapa.DFS(stoi(ini),stoi(dest));
				cout<<"\t"<<"output:"<<"\n";
				for(int i=0;i<visit.size();i++){
					v_aux=visit[i];
					vi.push_back(v_aux);
					if(vi[i]!="E"){
						cout<<vi[i];}
					else{break;}
				}
			break;
			// Opc 3 mustrar los adyacentes visitados entre dos lugares con BFS
			case '3':
				// se piden los dos lugares
				vi.clear();
				cout<<"Lugar inicial (input): ";
				cin>>ini;
				cout<<"Lugar destino (input): ";
				cin>>dest;
				// se busca con BFS
				visit=mapa.BFS(stoi(ini),stoi(dest));
				cout<<"\t"<<"output:"<<"\n";
				for(int i=0;i<visit.size();i++){
					v_aux=visit[i];
					vi.push_back(v_aux);
					if(vi[i]!="E"){
						cout<<vi[i];}
					else{break;}
				}
			break;
			// Opc 4 encuentra el camino más corto entre dos lugares
			case '4':
				// se piden los dos lugares
				cout<<"Lugar inicial (input): ";
				cin>>ini;
				cout<<"Lugar destino (input): ";
				cin>>dest;
				visit=mapa.DFS(stoi(ini),stoi(dest));
				int a=0;
				p_dfs="";
				cout<<"\t"<<"output:"<<"\n";
				// proceso para encontrar el camino más cerca entre los path's de DFS y BFS
				for(int i=0;i<visit.size();i++){
					v_aux=visit[i];
					if(v_aux=="E")a=1;
					if(a==1) p_dfs=p_dfs+v_aux;
				}
				a=0;
				visit=mapa.BFS(stoi(ini),stoi(dest));
				p_bfs="";
				for(int i=0;i<visit.size();i++){
					v_aux=visit[i];
					if(v_aux=="E")a=1;
					if(a==1) p_bfs=p_bfs+v_aux;
				}
				// se compara cual path tiene menos lugares intermediarios
				// el que tiene menos lugares por visitar por en medio será el mas corto
				if(p_dfs>p_bfs){cout<<p_bfs;}
				else{cout<<p_dfs;}
			break;
		}
		
	}
}
 
//Definicion de la funcion menu
void menu(){
	cout<<"\n"<<"\n\tOpciones principales:\n"<<"1. Ver las conexiones entre lugares"<<"\n"<<"2. Usando el recorrido DFS, mostrar los adyacentes visitados entre dos lugares"<<"\n";
	cout<<"3. Usando el recorrido BFS, mostrar los adyacentes visitados entre dos lugares"<<"\n"<<"4. Mostrar el camino mas corto entre dos lugares"<<"\n"<<"5. Salir"<<"\n"<<"Opcion (input): ";
}