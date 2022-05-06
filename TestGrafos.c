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

    for (u32 i = 0; i < n; i++) {
        orden[i] = i;
    };

    // Aplicar greedy multipes veces
    u32 k = 10;
    u32 colores[k];

    for (u32 i = 0; i < k; i++) {
        colores[i] = Greedy(G, orden, coloreo);

        printf("Colores %u° greedy: %u\n", i + 1, colores[i]);

        assert(EsColoreoPropio(G, coloreo));
        assert(EsColoreoEficiente(n, coloreo));

        OrdenFromKey(n, coloreo, orden);
        assert(OrdenEsPermutacion(n, orden));
    }

    // Chequear que la cantidad de colores haya disminuido
    for (u32 i = 1; i < k; i++) {
        assert(colores[i] <= colores[i - 1]);
    }

    DestruccionDelGrafo(G);
    free(coloreo);
    free(orden);

    return EXIT_SUCCESS;
}