
// Author: Jesús Misael Reséndiz Cruz

#ifndef DISJOINSET_H
#define DISJOINSET_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// empieza la clase de la estructura
class DisjointSet { 
   unordered_map<int, int> parent;
   
   public:
   
   void create(vector<int> const &datos){
		// crea n disjoint sets
      for (int i : datos) 
      parent[i] = i;
   }
   // Funcion find para encontrar la raiz del grupo
   int Find(int l) { 
      if (parent[l] == l) 
         return l;
      return Find(parent[l]); 
   }
   // Union de dos subconjuntos
   void Union(int m, int n) { 
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
   }
   // se obtiene el numero de conjuntos total
   int conj(vector<int> const &universe, DisjointSet &dis) {
	   int counter=0;
	   int i=0;
	   vector<int> conju={};
	   for (int i : universe){
			conju.push_back(dis.Find(i));
			int a=0;
			for(int j=0;j<conju.size()-1;j++){
				if(i==conju[j]){
					a=1;}
			}
			if(a==0) counter++;}
	   return counter;
}
};

#endif