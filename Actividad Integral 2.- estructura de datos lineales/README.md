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

Aquí lo que haremos es particularizar en el análisis de los algoritmos de la estructura lineal:
