/*
Juego de Mesa: Cubiletes
Desarrollado por: Patricio Adulfo Villanueva Gío y María Paula Pérez Romo
Carrera: Ingeniería en Ciencia de Datos (5to semestre)

Este código simula el famoso juego de mesa "Cubiletes", donde dos jugadores
lanzan cinco dados y compiten para obtener la mejor combinación de resultados.
El juego se desarrolla mediante el uso de funciones que gestionan las tiradas,
determinan las combinaciones, y resuelven cualquier empate entre los jugadores.

El código consta de tres funciones principales, además de la función main, las cuales son:

1. calcular_combinacion.
Esta función tiene como objetivo analizar la frecuencia de los valores obtenidos en los
dados de un jugador y determinar qué combinación representa dicha tirada.

Recibe una lista de enteros de tamaño 6, donde cada elemento cuenta cuántas veces apareció un valor
específico en la tirada (valores que van del 9 al As).

Calcula cuántas veces se repite cada valor para encontrar la cantidad máxima de repeticiones (masRepetido).
Comprueba las diferentes combinaciones posibles, tales como Quintilla, Póker, Full house, Tercia, Dos pares, Un par, o Nada.
Devuelve un número entero representando la combinación obtenida

Donde 0 es pachuca y 6 es quintilla


2. imprimir_resultados
Esta función imprime los resultados de la tirada de un jugador, incluyendo los valores obtenidos en
los dados y la combinación que representan.

Recibe el nombre del jugador, un arreglo con los resultados de los cinco dados lanzados, el tipo de combinación obtenida
y un arreglo de cadenas que contiene los nombres de los valores de las cartas (del "9" al "As")


Imprime los valores obtenidos en la tirada e imprime el nombre de la combinación correspondiente utilizando
un switch basado en el valor de combinacion (Yo se que no lo hemos visto en clase y que puede perfectamente ser remplazado con if else pero se veia lindo).

3. desempatar
(Antes de explicar esta función. Para que le miento profe primero no pensamos en que los usuarios pudieran empatar asi que luego
nos dimos cuenta que si ambos sacaban la misma puntuación debiamos comparar las cartas asi que la creamos)

Esta función maneja los casos de empate entre dos jugadores cuando ambos obtienen la misma combinación de dados.
Dependiendo de la combinación obtenida, se aplican diferentes reglas de desempate.

Recibe Una lista de enteros que representa la frecuencia de cada valor en los dados del jugador 1, una lista de enteros similar
para el jugador 2 y un entero que indica la combinación obtenida por ambos jugadores (ya que están empatados en este punto)

Para cada combinación posible (Un par, Dos pares, Tercia, Full house), se evalúan las reglas de desempate.
Por ejemplo, si ambos jugadores tienen un par, se compara el valor del par más alto. Si ambos tienen el mismo par,
se considera el dado más alto individual. Devuelve un entero que representa el resultado del desempate



Este proyecto esta subido en github: https://github.com/ioSoyPato/Cubiletes
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcular_combinacion(int count[6]);
void imprimir_resultados(char* nombre, int array[5], int combinacion, const char* valores[]);
int desempatar(int count1[6], int count2[6], int combinacion);



// Flujo principal donde incorporamos todas las funciones esperemos diosito funcione porque ya a este punto no lo se
int main() {

    // Declaración de variables que vamos a usar en el programa 
    int array1[5], array2[5];
    int count1[6] = {0}, count2[6] = {0};
    int combinacion1 = 0, combinacion2 = 0;
    char nombre1[20], nombre2[20];
    char respuesta;
    const char* valores[] = {"9", "10", "Joto", "Reina", "Rey", "As"};
    char tecla;

    // Inicializar la semilla del generador de números aleatorios con la libreria tiempo 
    time_t t;
    srand((unsigned int)time(&t));

    // Ponemos respuesta en s para que empiece el while (Nos ahorrariamos esto con un do-while pero le trababa la mente a mi compañere jaja)
    respuesta = 's';

    while (respuesta == 's' || respuesta == 'S') {
        // Resetear contadores para nueva partida
        for (int i = 0; i < 6; i++) {
            count1[i] = 0;
            count2[i] = 0;
        }

        // Nombres
        printf("Introduce el nombre del Jugador 1: ");
        scanf("%19s", nombre1); // Esta funcion sirve para evitar el overflow y que no nos hacken el juego jsjs gracias profe
        printf("Introduce el nombre del Jugador 2: ");
        scanf("%19s", nombre2);

        // Generar los números aleatorios para ambos jugadores con rand e imprimir sus resultados
        printf("\nJugador 1 presiona cualquier tecla para empezar: ");
        scanf("%s",&tecla);
        for (int i = 0; i < 5; i++) {
            array1[i] = rand() % 6 + 1;
            count1[array1[i] - 1]++;
        }
        combinacion1 = calcular_combinacion(count1);
        imprimir_resultados(nombre1, array1, combinacion1, valores);

        printf("\nJugador 2 presiona cualquier tecla para empezar: ");
        scanf("%s",&tecla);
        for (int i = 0; i < 5; i++) {
            array2[i] = rand() % 6 + 1;
            count2[array2[i] - 1]++;
        }
        combinacion2 = calcular_combinacion(count2);
        imprimir_resultados(nombre2, array2, combinacion2, valores);


        // Determinar el ganador basado en las reglas de desempate
        if (combinacion1 > combinacion2) {
            printf("\nEl ganador es %s\n", nombre1);
        } else if (combinacion2 > combinacion1) {
            printf("\nEl ganador es %s\n", nombre2);
        } else {
            int resultado = desempatar(count1, count2, combinacion1);
            if (resultado == 1) {
                printf("\nEl ganador es %s\n", nombre1);
            } else if (resultado == 2) {
                printf("\nEl ganador es %s\n", nombre2);
            } else {
                printf("\nEs un empate\n");
            }
        }

        // Hacer la pregunta para volver a empezar
        printf("\n\n\n¿Quieres jugar otra vez? (s/n): ");
        scanf(" %c", &respuesta);
    }


    return 0;
}


int calcular_combinacion(int count[6]) {
    int masRepetido = 0, tienePar = 0, pares = 0;
    
    for (int i = 0; i < 6; i++) {
        if (count[i] > masRepetido) {
            masRepetido = count[i];
        }
        if (count[i] == 2) {
            pares++;
            tienePar = 1;
        }
    }

    if (masRepetido == 5) {
        return 6; // Quintilla
    } else if (masRepetido == 4) {
        return 5; // Póker
    } else if (masRepetido == 3) {
        if (tienePar) {
            return 4; // Full house
        } else {
            return 3; // Tercia
        }
    } else if (masRepetido == 2) {
        if (pares == 2) {
            return 2; // Dos pares
        } else {
            return 1; // Un par
        }
    } else {
        return 0; // Nada
    }
}


void imprimir_resultados(char* nombre, int array[5], int combinacion, const char* valores[]) {
    printf("%s saco: ", nombre);
    for (int i = 0; i < 5; i++) {
        printf("%s ", valores[array[i] - 1]);
    }
    printf("\nCombinacion de %s: ", nombre);
    switch (combinacion) {
        case 6: printf("Quintilla\n"); break;
        case 5: printf("Póker\n"); break;
        case 4: printf("Full house\n"); break;
        case 3: printf("Tercia\n"); break;
        case 2: printf("Dos pares\n"); break;
        case 1: printf("Un par\n"); break;
        default: printf("Nada\n"); break;
    }
}

int desempatar(int count1[6], int count2[6], int combinacion) {
    switch (combinacion) {
        case 1: { // Un par
            for (int i = 5; i >= 0; i--) {
                if (count1[i] == 2 && count2[i] != 2) return 1;
                if (count2[i] == 2 && count1[i] != 2) return 2;
            }
            for (int i = 5; i >= 0; i--) {
                if (count1[i] == 1 && count2[i] == 1) continue;
                if (count1[i] == 1) return 1;
                if (count2[i] == 1) return 2;
            }
            return 0; // Empate
        }
        case 2: { // Dos pares
            int parMayor1 = 0, parMayor2 = 0, parMenor1 = 0, parMenor2 = 0;
            for (int i = 5; i >= 0; i--) {
                if (count1[i] == 2) {
                    if (parMayor1 == 0) parMayor1 = i + 1;
                    else parMenor1 = i + 1;
                }
                if (count2[i] == 2) {
                    if (parMayor2 == 0) parMayor2 = i + 1;
                    else parMenor2 = i + 1;
                }
            }
            if (parMayor1 != parMayor2) return (parMayor1 > parMayor2) ? 1 : 2;
            if (parMenor1 != parMenor2) return (parMenor1 > parMenor2) ? 1 : 2;
            for (int i = 5; i >= 0; i--) {
                if (count1[i] == 1 && count2[i] != 1) return 1;
                if (count2[i] == 1 && count1[i] != 1) return 2;
            }
            return 0; // Empate
        }
        case 3: { // Tercia
            int valorTercia1 = 0, valorTercia2 = 0;
            for (int i = 5; i >= 0; i--) {
                if (count1[i] == 3) valorTercia1 = i + 1;
                if (count2[i] == 3) valorTercia2 = i + 1;
            }
            if (valorTercia1 != valorTercia2) return (valorTercia1 > valorTercia2) ? 1 : 2;
            for (int i = 5; i >= 0; i--) {
                if (count1[i] == 1 && count2[i] != 1) return 1;
                if (count2[i] == 1 && count1[i] != 1) return 2;
            }
            return 0; // Empate
        }
        case 4: { // Full house
            int valorTercia1 = 0, valorTercia2 = 0;
            for (int i = 5; i >= 0; i--) {
                if (count1[i] == 3) valorTercia1 = i + 1;
                if (count2[i] == 3) valorTercia2 = i + 1;
            }
            return (valorTercia1 > valorTercia2) ? 1 : (valorTercia2 > valorTercia1) ? 2 : 0;
        }
        default:
            return 0; // Empate para combinaciones más altas
    }
}
