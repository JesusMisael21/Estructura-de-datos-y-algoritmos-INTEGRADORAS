En esta entrega se hizo con respecto a un registro donde como atributos se encuentran los nombres y las alturas (estaturas) de dichas personas.

Primeramente, para su funcionamiento se tienen que descargar los 5 archivos (main.cpp, sort.h, list.h, exception.h y personas.csv) en la misma carpeta o lugar de dirección. Para obtener el ejecutable solamente se tiene que compilar el "main.cpp", no hace falta incluir en la compilación a cualquier otra librería" porque el main ya lo incluye. Ejemplo si se está compilando desde un OS windows (compilación desde la terminal): G ++ main.cpp -o main.exe

Al ejecutar el programa se generará un cuarto archivo, ahí se almacenan los registros ordenados.

# Métodos/algoritmos  análisis de complejidad

Antes de interactuar con las 6 opciones con las que cuenta el menú, el programa por si solo añade (usando el algoritmo add de lista) a una estructura lineal (lista) la información del registro de los nombres y alturas de las personas desde el archivo “personas.csv”, posteriormente las ordena por alturas ascendentemente con un algoritmo de ordenamiento adecuado (algoritmo ordenar que es secuencial) y las guarda en otro archivo llamado “Datos_Alturas_Ordenadas.csv”.

Despues de ejecutarse automáticamente el anterior proceso, el usuario tiene un menú con 6 opciones que puede interactuar desde la consola:

1. Ver los registros originales
2. Ver los registros ordenados
3. Hacer busqueda de alturas por rango
4. Actualizar registro
5. Borrar registro
6. Salir del programa

Para saber como acceder a estas 6 opciones y visualizar cuales son sus salidas, revisar el documento adjunto llamado "Descripcion algoritmos de la estructura (casos de prueba con ejemplos).pdf"

Aquí lo que haremos es particularizar el análisis de los algoritmos/metodos para manipular la estructura lineal usada (listas) la cual accedo y manipulo a ella desde las opciones anteriormente mencionadas.

## add

Este es una función o en este caso como se trabaja con orientado a objetos, es un método que como algoritmo se encarga de añadir elementos a una lista al final del último elemento. Para encontrar su complejidad temporal asintótica debamos identificar n, para este caso hay dos opciones para tomar n, primeramente la tomaremos como la cantidad de elementos ya insertados con la que cuenta la lista, por lo tanto, al ingresar otro elemento este tiene que recorrer elemento por elemento hasta llegar al elemento nulo, es decir, al principio de la lista por lo que tenemos una complejidad temporal asintótica O(n). Ahora, si n es la cantidad de elementos que debemos insertar en una lista, como cada elemento insertado tiene que pasar por cada uno de los que ya se insertaron, este tiende a ser mayor a una complejidad lineal para el peor de los casos, y siguiendo la jerarquía nos demanda a una complejidad asintótica de O(n^2).

## ordenar

Algoritmo que ordena el registro por alturas de manera ascendente con una llamada del sort.h, y lo guardamos en otro vector, este proceso se realiza con la abstracción del SelectionSort cual complejidad temporal asintótica es O (n ^ 2). Especialmente se escogió este tipo de algoritmo de ordenamiento porque el escenario en el que nos movemos, que son personas de una región en específico, no requiere de un análisis no tan complejo como el que pudiese ser el MergeSort que va dirigido a almacenamientos sumumamente mas grandes. Al igual se escogió este algoritmo por su forma no tan compleja para adaptarlo en el escenario y poder dividir por atributos y ocupar el atributo que necesitavamos que es la altura. Para este se comprende de un análisis de complejidad temporal asintótica lineal O (n) que se ejecuta antes del ordenamiento, y es lineal ya que recorre solo una vez por cada registro, así dividiendolo por atributo. Este algoritmo se encuentra en el programa de sort.

## find

Este método recibe el vector con la información ya ordenada y las dos cantidades de las alturas como limites del rango, este regresa otro vector con la información específica de acuerdo al rango introducido. El algoritmo que se usa es busqueda binaria en forma secuencial que nos da una complejidad asintótica logaritmica O (log (n)). Esto se hace en dos ocasiones, una para encontrar la posición del elemento inferior del rango y otra para encontrar la posición del elemento superior del rango. Por lo tanto, O (log (n ^ 2)) según la jerarquía de complejidades.

## update

Para este método se necesita un argumento de dos elementos, recibe la posición a actualizar y el elemento que se va a insertar en dicha posición. El algoritmo que cuenta es parecido al de find (busqueda secuencial), tiene que pasar por cada una de las posiciones empezando desde la posición 0 hasta llegar a la posición deseada. Entonces, para el peor de los casos es cuando se quiera actualizar el elemento final de la lista, así teniendo una complejidad temporal asintótica O(n).

## remove

En este metodo se recibe la posición del elemento a eliminar haciendo la lista más chica en 1 cada ves que se utilice (siempre y cuando la cantidad de elementos de la lista sea diferente de cero). Para eliminar la posición deseada se tiene que pasar por cada una de las anteriores, entonces para el peor de los casos es que se quisiera eliminar el elemento final de la lista, así teniendo la complejidad temporal asintótica O(n). Tengamos en cuenta que tenemos una k sumandose a la temporalidad, esta representa la cantidad de pasos en la que redirecciona los enlaces de los nodos, sin embargo esta no se cuenta en nuestra complejidad , por lo que se descarta.

# Documentación de los algoritmos que manipulan la estructura (casos de prueba con ejemplos)

La documentación de los casos de prueba se encuentran en el archivo "Descripcion algoritmos de la estructura (casos de prueba con ejemplos).pdf"
