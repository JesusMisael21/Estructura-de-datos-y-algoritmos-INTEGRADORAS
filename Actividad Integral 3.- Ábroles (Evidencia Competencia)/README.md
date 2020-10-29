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

