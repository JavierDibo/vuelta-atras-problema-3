#include <stdio.h>
#include "ivector.h"

int esVocal(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void imprimirSolucion(ivector solucionParcial, int tamSolucion) {
    for (int i = 0; i < tamSolucion; ++i) {
        if (solucionParcial[i] != '0') {
            printf("%c ", solucionParcial[i]);
        }
    }
    printf("\n");
}

void backtracking(ivector vecSimbolos, int numSimbolos, ivector solucionParcial, int tamSolucion, int puesta,
                  int numVocales) {

    if (puesta == tamSolucion || numVocales == 2) {
        imprimirSolucion(solucionParcial, tamSolucion);
        return;
    }

    for (int i = 0; i < numSimbolos; i++) {
        solucionParcial[puesta] = vecSimbolos[i];
        if (esVocal(vecSimbolos[i]) == 1) {
            backtracking(vecSimbolos, numSimbolos, solucionParcial, tamSolucion, puesta + 1, numVocales + 1);
        } else {
            backtracking(vecSimbolos, numSimbolos, solucionParcial, tamSolucion, puesta + 1, numVocales);
        }
        solucionParcial[puesta] = 0;
    }
}


int main() {

    int numSimbolos = 8;
    int tamSolucion = 5;
    ivector vecSimbolos = icreavector(numSimbolos);
    ivector solucionParcial = icreavector(tamSolucion);

    vecSimbolos[0] = '1';
    vecSimbolos[1] = '2';
    vecSimbolos[2] = '3';
    vecSimbolos[3] = 'A';
    vecSimbolos[4] = 'E';
    vecSimbolos[5] = 'I';
    vecSimbolos[6] = 'O';
    vecSimbolos[7] = 'U';

    for (int i = 0; i < tamSolucion; ++i) {
        solucionParcial[i] = '0';
    }

    backtracking(vecSimbolos, numSimbolos, solucionParcial, tamSolucion, 0, 0);

    ifreevector(&vecSimbolos);
    ifreevector(&solucionParcial);

    return 0;
}
