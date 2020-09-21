Esta actividad será respecto a registros de tipos de automoviles deportivos, que como atributo, aparte del nombre, será la velocidad máxima.

Primeramente, para su funcionamiento se tienen que descargar los 3 archivos en la misma carpeta o lugar de dirección.
Para obtener el ejecutable solamente se tiene que compilar el "main.cpp", no hace falta incluir en la compilación al "sort.h" porque el main ya lo incluye.
ejemplo si se está compilando desde un OS windows (compilación desde la terminal): G++ main.cpp -o main.exe
Al correr el programa se generará un cuarto archivo, aquí se almacena los registros ordenados.

# Funcionamiento y análisis de complejidad

En aspectos generales, el main.cpp contiene el menú de operación y las llamadas de las funciones del sort.h donde este contiene los metodos que realizan el algoritmo de ordenamiento y de busqueda.

Particularizando. El main primeramente hace la lectura del registro y lo guarda en un vector, para este proceso tiene una complejidad temporal asíntótica lineal O(n) ya que recorre individualmente cada registro.

Como segundo paso se ordena el registro por velocidades máximas con una llamada del sort.h y lo guardamos en otro vector, este proceso se realiza con el método SelectionSort cual complejidad temporal asintótica es O(n^2). Especialmente se escogió este tipo de algoritmo de ordenamiento porque el escenario en el que nos movemos, que son los tipos de autos deportivos, no requiere de un análsis no tan complejo como el que pudiese ser el MergeSort que va dirigido a almacenamientos sumumamente mas grandes. Al igual se escogió este algoritmo por su forma no tan compleja para adaptarlo en el escenario y poder dividir por atributos y ocupar el atributo que necesitavamos que es la velocidad máxima. Para este último se comprende de un análisis de complejidad temporal asintótica lineal O(n) ya que recorre solo una vez por cada registro, así dividiendolo por atributo.

Para el tercer paso recurrimos a almacenar los datos ordenados en un archivo nuevo, en este caso es un archivo en formato de bitacora o .csv 
En caso de no contar con este archivo en la carpeta el mismo programa crea uno nuevo llamado "Datos_Carros_Ordenados.csv". Para este proceso se tiene que recorrer registro por registro de forma ascendente lo que el análisis nos indica que la complejidad temporal asintótica es lineal O(n).

Para el cuarto paso, por parte de una de las opciones (opción 3) que puede tener el usuario que es el buscar por rangos, tenemos que el usuario ingresa la velocidad mínima y la máxima y de acuerdo a esto hace la busqueda de los carros que estén entre esos valores de velocidad. El algoritmo que se usa aquí es busqueda binaria en forma secuencial
