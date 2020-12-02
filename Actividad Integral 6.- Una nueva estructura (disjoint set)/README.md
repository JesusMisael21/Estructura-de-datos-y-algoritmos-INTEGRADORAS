# Explicación

En esta entrega se hizo con respecto a la simulación de grupos de estudiantes en los que hacen equipos para la ralización de cualqiuer proyecto o trabajo. El concepto de disjoin set se aterrizó en este programa, la estructura representa todos los subconjuntos que se puedan formar, en donde la raíz representa el lider o representante del equipo o subconjunto.

El archivo "ID_Estudiantes.txt" contiene las matriculas de cada estudiante quienes formarán los conjuntos.

**Nota:** Primeramente, para su funcionamiento se tienen que descargar los 3 archivos (main.cpp, disjointSet.h y ID_Estudiantes.txt) en la misma carpeta o lugar de dirección. Para obtener el ejecutable solamente se tiene que compilar el "main.cpp", no hace falta incluir en la compilación a cualquier otro programa ". Ejemplo si se está compilando desde un OS windows (compilación desde la terminal): g ++ main.cpp - o main.exe

Antes de interactuar con las 5 opciones, el programa por si solo añade el archivo “ID_Estudiantes.txt” a una estructura de disjoint set, internamente hace las conexiones (crea las aristas). El archivo “ID_Estudiantes.txt” tiene las matrículas de cada estudiante a ser agrupado a un conjunto.

Después de ejecutarse automáticamente el proceso anterior, el usuario tiene un menú con 5 opciones que puede interactuar desde la consola:

1. Ver los ID's de los estudiantes
2. Agrupar estudiantes por conjuntos
3. Mostrar el representante de algun estudiante
4. Mostrar el numero total de conjuntos
5. Salir

**Al finalizar el programa, arrojará un archivo de texto llamado "consultas.txt" de todas las consultas que se hicieron, para tener un historial.

Para saber como acceder a estas 5 opciones y visualizar cuales son sus salidas, revisar el documento adjunto llamado "Descripcion (casos de prueba con ejemplos).pdf"

A continuación, lo que haremos es particularizar el análisis de los algoritmos/metodos que acceden a la estructura del grafo y así me den la funcionalidad de las opciones mencionadas anteriormente.

# Métodos/algoritmos análisis de complejidad

Si bien hay varias formas de implementar estructuras de datos de conjuntos disjuntos, en la práctica a menudo se identifican con una implementación particular llamada bosque de conjuntos disjuntos. Este es un tipo de bosque especializado que realiza uniones y se encuentra en un tiempo amortizado casi constante. Para realizar una secuencia de m operaciones de unión o búsqueda en un bosque de conjuntos disjuntos con n nodos se requiere un tiempo total O(m α(n)) , donde α(n) es la función de Ackermann inversa de crecimiento extremadamente lento. 

En lo siguiente se describen los algoritmos que se usaron en lo particular para mi implementación:

## Union

La operación Unión (x,y) reemplaza el conjunto que contiene "x" y el conjunto que contiene "y" con su unión. Si las raíces son las mismas, no hay nada más que hacer. De lo contrario, los dos árboles deben fusionarse. Esto se realiza ya sea estableciendo el puntero del padre de X a Y , o establecer el puntero de matriz de y para x. En esta implementación este algoritmo toma un tiempo logarítmico asintótico de O(n).

## Find

Hay varios algoritmos para Find que logran la complejidad de tiempo óptima asintóticamente. Una familia de algoritmos, conocida como compresión de ruta, hace que cada nodo entre el nodo de consulta y la raíz apunte a la raíz. La compresión de ruta se puede implementar usando una recursividad simple como la que se usó en esta implementación. Casi todo el tiempo son tiempos logarítmicos, sin embargo cuando no se tienen conjunsiones, en tal situación, las operaciones de búsqueda requieren O(n) en tiempo asintótico. 

## create

En particular, la inicialización de esta estructura de conjuntos con n nodos requiere O(n) en tiempo asintótico, ya que cada uno representaría inicialmente una raíz independiente.

## conj

Este es un algoritmo particular de la implementación, este algoritmo se desarrolló para la opción 4 de usuario. Esta toma todos los conjuntos distintos que pueda haber y toma la raíz para desplegar los representantes o líderes de cada conjunto. Este para el peor de los casos tiende a ser un tiempo asintótico O(n^2) ya que analiza cada elemento n, en n veces para asegurar que no se repite un lider en un vector que guarda las personas.
