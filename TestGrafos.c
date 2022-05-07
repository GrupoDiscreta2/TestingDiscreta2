#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    u32 k = 1;
    u32 colores[k];

    for (u32 i = 0; i < k; i++) {

        // Medir tiempo
        clock_t t = clock();

        colores[i] = Greedy(G, orden, coloreo);

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

        printf("Colores %u° greedy: %u (tiempo %fs)\n", i + 1, colores[i], time_taken);

        assert(EsColoreoPropio(G, coloreo));
        assert(EsColoreoEficiente(n, coloreo));

        { // Test de recoloreos
            u32* nuevoColoreo = PermutarColores(n, coloreo, rand());
            assert(EsColoreoPropio(G, nuevoColoreo));
            assert(EsColoreoEficiente(n, nuevoColoreo));

            u32* coloreoDecreciente = RecoloreoCardinalidadDecrecienteBC(n, coloreo);
            assert(EsColoreoPropio(G, coloreoDecreciente));
            assert(EsColoreoEficiente(n, coloreoDecreciente));
            free(coloreoDecreciente);

            coloreoDecreciente = RecoloreoCardinalidadDecrecienteBC(n, nuevoColoreo);
            assert(EsColoreoPropio(G, coloreoDecreciente));
            assert(EsColoreoEficiente(n, coloreoDecreciente));

            free(coloreoDecreciente);

            free(nuevoColoreo);
        }

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