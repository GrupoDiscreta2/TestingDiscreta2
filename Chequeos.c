#include "Chequeos.h"

#include <stdbool.h>

#include "AniquilamientoPositronicoIonizanteGravitatorio.h"
#include "types.h"

u32 CantidadDeColores(u32 n, const u32* coloreo) {
    u32 r = 0;
    if (n != 0) {
        for (u32 i = 0; i < n; i++) {
            r = max(r, coloreo[i]);
        }
        r++;
    }

    return r;
}

bool EsColoreoPropio(Grafo G, const u32* coloreo) {
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

bool EsColoreoEficiente(u32 n, const u32* coloreo) {
    u32 r = CantidadDeColores(n, coloreo);

    if (r > n) {
        return false;
    }

    bool coloresUsados[r];
    for (u32 c = 0; c < r; c++) {
        coloresUsados[c] = false;
    }

    for (u32 i = 0; i < n; i++) {
        coloresUsados[coloreo[i]] = true;
    }

    for (u32 c = 0; c < r; c++) {
        if (!coloresUsados[c]) {
            return false;
        }
    }

    return true;
}

bool EsColoreoBipartito(u32 n, const u32* coloreo) {
    for (u32 i = 0; i < n; i++) {
        if (coloreo[i] != 1 && coloreo[i] != 2) {
            return false;
        }
    }

    return true;
}
