En esta entrega se hizo con respecto a un registro de un grupo de personas en particular, donde como atributos se encuentran los nombres y las alturas (estaturas) de dichas personas.

**Nota:** Primeramente, para su funcionamiento se tienen que descargar los 3 archivos (main.cpp, bst.h y personas.csv) en la misma carpeta o lugar de dirección. Para obtener el ejecutable solamente se tiene que compilar el "main.cpp", no hace falta incluir en la compilación a cualquier otra librería" porque el main ya lo incluye. Ejemplo si se está compilando desde un OS windows (compilación desde la terminal): **g++ main.cpp -o main.exe**

# Métodos/algoritmos análisis de complejidad

Antes de interactuar con las 6 opciones con las que cuenta el menú, el programa por si solo añade (usando el algoritmo add de un BST) a una estructura de árbol (BST) la información del registro de los nombres y alturas de las personas desde el archivo “personas.csv”. 

Despues de ejecutarse automáticamente el anterior proceso, el usuario tiene un menú con 6 opciones que puede interactuar desde la consola:
1. Ver los registros originales
2. Actualizar
3. Borrar
4. Saber la capa de arbol del registro
5. Mostrar registros actualizados
6. Salir del programa

Para saber como acceder a estas 6 opciones y visualizar cuales son sus salidas, revisar el documento adjunto llamado "Descripcion algoritmos de la estructura (casos de prueba con ejemplos).pdf"

A continuación, lo que haremos es particularizar el análisis de los algoritmos/metodos para manipular la estructura de árbol (bst) la cual accedo y manipulo a ella desde las opciones anteriormente mencionadas.

# add

La inserción se puede dar una solución tanto iterativa como recursiva, en esta aplicación se hace recursiva. Si tenemos inicialmente como parámetro un árbol vacío se crea un nuevo nodo como único contenido el elemento a insertar. Si no lo está, se comprueba si el elemento dado es menor que la raíz del árbol inicial con lo que se inserta en el subárbol izquierdo y si es mayor se inserta en el subárbol derecho. Para el peor de los casos es que el árbol se a degenerado, así teniendo una complejidad temporal asintótica de O(n).

# update

Este es el algoritmo para actualizar, lo que se hace es una adaptación de un algoritmo de busqueda, que consiste en acceder a la raíz del árbol, si el elemento a localizar coincide con este la búsqueda ha concluido con éxito, si el elemento es menor se busca en el subárbol izquierdo y si es mayor en el derecho, hasta que se encuentra el dato a modificar es que se hace la actualización. Si se alcanza un nodo hoja y el elemento no ha sido encontrado es que no existe en el árbol. 
Cabe destacar que la búsqueda en este tipo de árboles es muy eficiente, representa una función logarítmica. El máximo número de comparaciones que necesitaríamos para saber si un elemento se encuentra en un árbol binario de búsqueda estaría entre [log2(n+1)] y n, siendo N el número de nodos. Claro, este tiempo anterior para casos promedio, pero como en el algoritmo anterior de inserción, este puede caer en un árbol degenerado en el que tenga que pasar recursivamente nodo por nodo linealmente, entonces, decimos que en una complejidad temporal asintótica su ejecución es de O(n).

# visit

Este método lo manda a llamar el usuario y de manera conjunta llama a las siguientes (diferentes maneras de mostrar el contenido de un árbol):

## preorder

En este método de recorrido, primero se visita el nodo raíz, luego el subárbol izquierdo y finalmente el subárbol derecho. Esto de manera recursiva. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

## inorder

En este método de recorrido, primero se visita el subárbol izquierdo, luego la raíz y luego el subárbol derecho. Siempre debemos recordar que cada nodo puede representar un subárbol en sí mismo, la salida producirá valores clave ordenados en orden ascendente. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

## postorder

En este método transversal, el nodo raíz se visita en último lugar, de ahí el nombre. Primero atravesamos el subárbol izquierdo, luego el subárbol derecho y finalmente el nodo raíz. Para el peor de los casos es que tenga que recorrer un árbol degenerado, por lo que su complejidad temporál asintótica es O(n).

## level by level

Muestra los nodos en todos los niveles uno por uno comenzando desde la raíz y después con los subárboles de izquierda a derecha. Se usa un for para llamar n veces a una función que recorre los n elementos del árbol, por lo que su complejidad temporál asintótica es O(n^2).

# height

Regresa la profundida máxima del árbol en donde la raíz es 1. Toma el subárbol más profundo para regresar dicho nivel. Puede haber un caso en el que haya un árbol degenerado en el que los pasos de recorrido en la profundida sea igual a la cantidad de elementos, ante esto nos encontramos con una complejidad temporal asintótica O(n).

# ancestors

Desplegará los ancestros de un dato (todos los nodos arriba de n hasta llegar a la raiz). Permanece la abstracción que para el peor de los casos es cuando se tenga un árbol degenerado y tenga que pasar por los n elementos para llegar al dato, por eso su complejidad temporál asintótica es O(n).

# whatlevelamI

Regresará un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST. Para cuando se tenga un árbol degenerado y se quiera buscar el elemento más profundo, los pasos de recorrido serán igual a la acantidad de elementos dentro del árbol, así teniendo una complejidad temporal asintótica O(n).
