#ifndef __CHEQUEOS_H
#define __CHEQUEOS_H

#include <stdbool.h>

#include "AniquilamientoPositronicoIonizanteGravitatorio.h"
#include "types.h"

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

/* Verifica que un coloreo esté compuesto solo de 1's y 2's
 * O sea, como lo que tiene que devolver la función Bipartito
 *
 * No verifica que el coloreo sea propio
 */
bool EsColoreoBipartito(u32 n, const u32* coloreo);

/* Verifica que orden sea una permutación de los números 0, 1, …, n-1
 */
bool OrdenEsPermutacion(u32 n, u32* orden);

#endif