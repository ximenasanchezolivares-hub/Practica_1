# Práctica 1: Análisis de Registros de Ataques

Programa desarrollado en el lenguaje C que procesa registros simulados de acceso a un servidor para detectar comportamientos sospechosos (intentos reiterados de acceso no autorizado, como contraseñas incorrectas o usuarios inexistentes) mediante el uso de arreglos, funciones y apuntadores.

## Características Técnicas Implementadas
* **Arreglos Unidimensionales:** Almacenamiento secuencial de la bitácora de eventos (equipos y tipos de eventos).
* **Arreglo Bidimensional (Matriz):** Resumen de frecuencia de eventos por equipo.
* **Funciones con Paso por Valor:** Validación de códigos de eventos.
* **Funciones con Paso por Referencia:** Actualización directa de contadores en memoria mediante apuntadores.
* **Aritmética de Apuntadores:** Recorrido y manipulación de estructuras de datos.
* **Regla de Detección:** Clasificación de equipos como `NORMAL` o `SOSPECHOSO` en función de un umbral de intentos fallidos ($X = 3$).


 **Compilador** 
   gcc practica-1.c -o practica-1
