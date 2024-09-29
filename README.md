# 🎲 Juego de Mesa: Cubiletes

👨‍🎓 Desarrollado por: Patricio Adulfo Villanueva Gío y María Paula Pérez Romo
📚 Carrera: Ingeniería en Ciencia de Datos (5to semestre)

## 📝 Descripción
Este código simula el famoso juego de mesa "Cubiletes", donde dos jugadores lanzan cinco dados y compiten para obtener la mejor combinación de resultados. El juego se desarrolla mediante el uso de funciones que gestionan las tiradas, determinan las combinaciones, y resuelven cualquier empate entre los jugadores.

## 🔍 Funciones Principales
El código consta de tres funciones principales, además de la función main, las cuales son:

### 1. calcular_combinacion 📊
Esta función tiene como objetivo analizar la frecuencia de los valores obtenidos en los dados de un jugador y determinar qué combinación representa dicha tirada.

- 📥 Parámetros:
  - Recibe una lista de enteros de tamaño 6, donde cada elemento cuenta cuántas veces apareció un valor específico en la tirada (valores que van del 9 al As).
- ⚙️ Proceso:
  - Calcula cuántas veces se repite cada valor para encontrar la cantidad máxima de repeticiones (masRepetido).
  - Comprueba las diferentes combinaciones posibles, tales como Quintilla, Póker, Full house, Tercia, Dos pares, Un par, o Nada.
- 📤 Valor de Retorno:
  - Devuelve un número entero representando la combinación obtenida, donde:
    - 0 es Nada (también llamado "Pachuca") 
    - 6 es Quintilla 

### 2. imprimir_resultados 🖨️
Esta función imprime los resultados de la tirada de un jugador, incluyendo los valores obtenidos en los dados y la combinación que representan.

- 📥 Parámetros:
  + El nombre del jugador.
  + Un arreglo con los resultados de los cinco dados lanzados.
  + El tipo de combinación obtenida.
  + Un arreglo de cadenas que contiene los nombres de los valores de las cartas (del "9" al "As").
- ⚙️ Proceso:
  - Imprime los valores obtenidos en la tirada e imprime el nombre de la combinación correspondiente utilizando un switch basado en el valor de combinacion.
  
(Yo sé que no lo hemos visto en clase y que podría perfectamente ser reemplazado con if else, pero se veía lindo). 😅

### 3. desempatar 🤜🤛
(Antes de explicar esta función... Para qué le miento, profe, primero no pensamos en que los usuarios pudieran empatar, así que luego nos dimos cuenta de que si ambos sacaban la misma puntuación debíamos comparar las cartas, así que la creamos). 🙃

Esta función maneja los casos de empate entre dos jugadores cuando ambos obtienen la misma combinación de dados. Dependiendo de la combinación obtenida, se aplican diferentes reglas de desempate.

- 📥 Parámetros:
  - Una lista de enteros que representa la frecuencia de cada valor en los dados del jugador 1.
  - Una lista de enteros similar para el jugador 2.
  - Un entero que indica la combinación obtenida por ambos jugadores (ya que están empatados en este punto).
- ⚙️ Proceso:
  - Para cada combinación posible (Un par, Dos pares, Tercia, Full house), se evalúan las reglas de desempate.
  - Por ejemplo, si ambos jugadores tienen un par, se compara el valor del par más alto. Si ambos tienen el mismo par, se considera el dado más alto individual.
- 📤 Valor de Retorno:
  - Devuelve un entero que representa el resultado del desempate:
    - 1: Gana el jugador 1 🏆
    - 2: Gana el jugador 2 🏆
    - 0: Empate 🤝

---

### ▶️ Ejecución del Juego (flujo main)
El flujo del juego es gestionado en la función main, que se encarga de:
- 📝 Solicitar los nombres de los dos jugadores.
- 🎲 Generar aleatoriamente los valores de los cinco dados para cada jugador.
- 📊 Calcular las combinaciones mediante calcular_combinacion.
- 🖨️ Imprimir los resultados utilizando imprimir_resultados.
- 🏅 Determinar el ganador o aplicar las reglas de desempate mediante desempatar.
- 🔄 Permitir a los jugadores decidir si quieren jugar otra vez.

---

## Estructura de los archivos
```bash
|-Cubiletes
|
|--archivosC
|----cubiletes.c
|
|--ejecutables
|----cubiletes
````

## Forma de ejecucion
Clonar el repositorio
```bash
git clone https://github.com/ioSoyPato/Cubiletes.git
```
Abrir la carpeta clonada
```bash
cd Cubiletes/archivosC
```
Compilar el archivo C en la carpeta ejecutables
```bash
gcc -o ../ejecutables/cubiletes cubiletes.c
```
Cambiar a la carpeta ejecutables
```bash
cd ../ejecutables
```
Ejecutar el programa
```bash
./cubiletes
```