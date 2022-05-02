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

    u32* coloreo = Bipartito(G);

    // Este test se corre con grafos bipartitos
    assert(coloreo != NULL);
    assert(EsColoreoBipartito(n, coloreo));
    assert(EsColoreoPropio(G, coloreo));

    DestruccionDelGrafo(G);
    free(coloreo);

    return EXIT_SUCCESS;
}
