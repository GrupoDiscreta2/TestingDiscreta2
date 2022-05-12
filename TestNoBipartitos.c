#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

#include "AlduinPaarthurnaxIrileth.h"
#include "AniquilamientoPositronicoIonizanteGravitatorio.h"

#include "Chequeos.h"

int main(void) {
    Grafo G = ConstruccionDelGrafo();

    u32* coloreo = Bipartito(G);

    // Este test se corre con grafos no bipartitos
    assert(coloreo == NULL);

    DestruccionDelGrafo(G);

    return EXIT_SUCCESS;
}
