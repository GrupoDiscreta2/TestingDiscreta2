#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

#include "AlduinPaarthurnaxIrileth.h"
#include "AniquilamientoPositronicoIonizanteGravitatorio.h"

#include "Chequeos.h"



int main(void) {

    Grafo G = NULL;

    G = ConstruccionDelGrafo();

    u32 n = NumeroDeVertices(G);

    u32* coloreo = calloc(sizeof(u32), n);

    u32* orden = calloc(sizeof(u32), n);

    for(u32 i = 0; i < n; i++){
        orden[i] = i;
    };

    u32 colores = Greedy(G, orden, coloreo);

    printf("Colores 1er greedy: %u\n", colores);

    OrdenFromKey(n, coloreo, orden);

    colores = Greedy(G, orden, coloreo);

    printf("Colores 2do greedy: %u\n", colores);

    OrdenFromKey(n, coloreo, orden);

    colores = Greedy(G, orden, coloreo);

    printf("Colores 3er greedy: %u\n", colores);

    assert(EsColoreoPropio(G, coloreo));
    DestruccionDelGrafo(G);
    free(coloreo);
    free(orden);

}