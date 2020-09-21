Esta actividad será respecto a registros de tipos de automoviles deportivos, que como atributo, aparte del nombre, será la velocidad máxima.

Primeramente, para su funcionamiento se tienen que descargar los 3 archivos en la misma carpeta o lugar de dirección.
Para obtener el ejecutable solamente se tiene que compilar el "main.cpp", no hace falta incluir en la compilación al "sort.h" porque el main ya lo incluye.
ejemplo si se está compilando desde un OS windows (compilación desde la terminal): G++ main.cpp -o main.exe

# Funcionamiento y análisis de complejidad

En aspectos generales, el main.cpp contiene el menú de operación y las llamadas de las funciones del sort.h donde este contiene los metodos que realizan el algoritmo de ordenamiento y de busqueda.

Particularizando. El main primeramente hace la lectura del registro y lo guarda en un vector, para este proceso tiene una complejidad temporal asíntótica lineal O(n) ya que recorre individualmente cada registro.

Como segundo paso ordena el registro con una llamada del sort.h con el método SelectionSort cual complejidad temporal asintótica es O(n^2). Especialmente se escogió este tipo de algoritmo de ordenamiento porque el escenario en el que nos movemos, que son los tipos de autos deportivos, no requiere de un análsis no tan complejo como el que pudiese ser el MergeSort que va dirigido a almacenamientos sumumamente mas grandes. Al igual se escogió este algoritmo por su forma no tan compleja para adaptarlo en el escenario y poder dividir por atributos y ocupar solamente el que necesitavamos que es la velocidad máxima. Para este último se comprende de un análisis de complejidad temporal lineal O(n) ya que recorre solo una vez por cada registro, así dividiendolo por atributo.
