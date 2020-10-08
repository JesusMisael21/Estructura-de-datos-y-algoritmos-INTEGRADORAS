En esta entrega se hizo con respecto a un registro donde como atributos se encuentran los nombres y las alturas (estaturas) de dichas personas.

Primeramente, para su funcionamiento se tienen que descargar los 5 archivos (main.cpp, sort.h, list.h, exception.h y personas.csv) en la misma carpeta o lugar de dirección. Para obtener el ejecutable solamente se tiene que compilar el "main.cpp", no hace falta incluir en la compilación a cualquier otra librería" porque el main ya lo incluye. Ejemplo si se está compilando desde un OS windows (compilación desde la terminal): G ++ main.cpp -o main.exe

Al ejecutar el programa se generará un cuarto archivo, ahí se almacenan los registros ordenados.

# Funcionamiento y análisis de complejidad

Antes de interactuar con las 6 opciones con las que cuenta el menú, el programa por si solo añade (usando el algoritmo add de lista) a una estructura lineal (lista) la información del registro de los nombres y alturas de las personas desde el archivo “personas.csv”, posteriormente las ordena por alturas ascendentemente con un algoritmo de ordenamiento adecuado (algoritmo ordenar que es secuencial) y las guarda en otro archivo llamado “Datos_Alturas_Ordenadas.csv”.
