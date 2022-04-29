#include "Chequeos.h"

#include "stdbool.h"

#include "types.h"
#include "AniquilamientoPositronicoIonizanteGravitatorio.h"



bool EsColoreoPropio(Grafo G, u32* coloreo) {
    bool coloreoPropio = true;
    u32 n = NumeroDeVertices(G);

    for (u32 i = 0; i < n && coloreoPropio; i++) {
        u32 grado = Grado(i, G);
        u32 color = coloreo[i];

        for (u32 j = 0; j < grado && coloreoPropio; j++) {
            coloreoPropio = (color != coloreo[IndiceONVecino(j, i, G)]);
        }
    }

    return coloreoPropio;
}

