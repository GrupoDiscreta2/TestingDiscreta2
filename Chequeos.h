#ifndef __CHEQUEOS_H
#define __CHEQUEOS_H

#include "stdbool.h"

#include "types.h"
#include "AniquilamientoPositronicoIonizanteGravitatorio.h"


/* Calcula la cantidad de colores de un colore de tamaño n
 * Básicamente calcula el máximo elemento mas 1
 * 
 * O sea que si hay un color en el medio que no se usa, igual lo cuenta
 */
u32 CantidadDeColores(u32 n, const u32* coloreo);


/* Chequea si el coloreo es propio */
bool EsColoreoPropio(Grafo G, const u32* coloreo);

/* Chequea si un colreo aprovecha la cantidad de coloreo, es decir,
 * verifica que no haya un color menor al color maximo que no se use
 *
 * O sea, verifica que:
 *     ∃r < n : ⟨∀i < n : coloreo[i] < r⟩ ∧ ⟨∀c < r : ⟨∃i < n : coloreo[i] = c⟩⟩
 */
bool EsColoreoEficiente(u32 n, const u32* coloreo);


#endif