# Explicación

En esta entrega se hizo con respecto a la simulación de un mapa. El concepto de grafo se aterrizó en este programa, el grafo representará el mapa, en donde los nodos serán los lugares y las arístas los caminos para llegar a dicho lugar. En este caso los lugares se identificarán a través de un ID.

El archivo “mapa.txt” tiene coordenadas, en donde el primer elemento de cada coordenada indica el lugar para ser enlazado y el segundo elemento de la misma indica el lugar al que se enlazará. El contenido de dicho archivo se almacena en una Lista de Adjacencias por parte del grafo.

**Nota:** Primeramente, para su funcionamiento se tienen que descargar los 3 archivos (main.cpp, graph.h y mapa.txt) en la misma carpeta o lugar de dirección. Para obtener el ejecutable solamente se tiene que compilar el "main.cpp", no hace falta incluir en la compilación a cualquier otro programa". Ejemplo si se está compilando desde un OS windows (compilación desde la terminal): g++ main.cpp -o main.exe

Antes de interactuar con las 5 opciones, el programa por si solo añade el archivo “mapa.txt” a un grafo, internamente hace las conexiones (crea las aristas). 

Despues de ejecutarse automáticamente el anterior proceso, el usuario tiene un menú con 5 opciones que puede interactuar desde la consola:

1. Ver las conexiones entre lugares
2. Usando el recorrido DFS, mostrar los adyacentes visitados entre dos lugares
3. Usando el recorrido BFS, mostrar los adyacentes visitados entre dos lugares
4. Mostrar el camino mas corto entre dos lugares
5. Salir

Al finalizar el programa, se arrojará un archivo de texto llamado "consultas.txt" de todas las consultas que se hicieron para tener un historial.

Para saber como acceder a estas 5 opciones y visualizar cuales son sus salidas, revisar el documento adjunto llamado "Descripcion algoritmos de la estructura (casos de prueba con ejemplos).pdf"

A continuación, lo que haremos es particularizar el análisis de los algoritmos/metodos que acceden a la estructura del grafo y así me den la funcionalidad de las opciones anteriormente mencionadas.

# Métodos/algoritmos análisis de complejidad

## loadGraphList

Esta función carga las arístas y los almacena en una lista de adyacencia. Recibe el nombre del archivo y 2 enteros. El nuevo valor de los nodos es el número de vértices. Su omplejidad: O (n) Lineal. n -> número de líneas. Porque el número de ejecuciones es igual al número de conexiónes.

## DFS (Deep First Search)

Es un algoritmo de búsqueda no informada utilizado para recorrer todos los nodos de un grafo o árbol (teoría de grafos) de manera ordenada, pero no uniforme. Su funcionamiento consiste en ir expandiendo todos y cada uno de los nodos que va localizando, de forma recurrente, en un camino concreto. Cuando ya no quedan más nodos que visitar en dicho camino, regresa (Backtracking), de modo que repite el mismo proceso con cada uno de los hermanos del nodo ya procesado. Esta visita cada vértice una vez y comprueba todas las arístas del gráfico una vez. Por lo tanto, la complejidad de DFS es O (V + E) siendo V los vertices y E las arístas.

## BFS (Breadth First Search)

Es un algoritmo de búsqueda no informada utilizado para recorrer o buscar elementos en un grafo (usado frecuentemente sobre árboles). Intuitivamente, se comienza en la raíz (eligiendo algún nodo como elemento raíz en el caso de un grafo) y se exploran todos los vecinos de este nodo. A continuación para cada uno de los vecinos se exploran sus respectivos vecinos adyacentes, y así hasta que se recorra todo el árbol. La primera búsqueda tiene un tiempo de ejecución de O (V + E), siendo V los vertices y E las arístas, ya que cada vértice y cada arista se comprobará una vez.

## printVisited

Esta función imprime todos los elementos que fueron visitados en orden. Es usado para mostrar los adyacentes de las búsquedas DFS y BFS. Análisis de complejidad temporál asintótica: O (n) Lineal.

## printPath

Esta función imprime la ruta desde el nodo inicial hasta el objetivo. Retrocede para encontrar la ruta y luego la imprime con una pila. Es usada para encontrar el camino más corto, se hace la comparación del path del DFS y del BSF, el que tenga menos lugares por en medio es el camino más corto. Complejidad temporál asintótica: O(2n).
