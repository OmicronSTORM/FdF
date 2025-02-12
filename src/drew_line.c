/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:27:42 by jowoundi          #+#    #+#             */
/*   Updated: 2025/02/12 17:48:06 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int tracerSegment(int x1, int y1, int x2, int y2)
{ est
	déclarer entier dx, dy;
  
  si (dx ← x2 - x1) ≠ 0 alors
    si dx > 0 alors
      si (dy ← y2 - y1) ≠ 0 alors
        si dy > 0 alors
          // vecteur oblique dans le 1er quadrant
          
          si dx ≥ dy alors
            // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octant
            déclarer entier e ;
            dx ← (e ← dx) × 2 ; dy ← dy × 2 ;  // e est positif
            boucle sans fin  // déplacements horizontaux
              tracePixel(x1, y1) ;
              interrompre boucle si (x1 ← x1 + 1) = x2 ;
              si (e ← e - dy) < 0 alors
                y1 ← y1 + 1 ;  // déplacement diagonal
                e ← e + dx ;
              fin si ;
            fin boucle ;
          sinon
            // vecteur oblique proche de la verticale, dans le 2d octant
            déclarer entier e ;
            dy ← (e ← dy) × 2 ; dx ← dx × 2 ;  // e est positif
            boucle sans fin  // déplacements verticaux
              tracePixel(x1, y1) ;
              interrompre boucle si (y1 ← y1 + 1) = y2 ;
              si (e ← e - dx) < 0 alors
                x1 ← x1 + 1 ;  // déplacement diagonal
                e ← e + dy ;
              fin si ;
            fin boucle ;
          fin si ;
          
        sinon  // dy < 0 (et dx > 0)
          // vecteur oblique dans le 4e quadrant
          
          si dx ≥ -dy alors
            // vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
            déclarer entier e ;
            dx ← (e ← dx) × 2 ; dy ← dy × 2 ;  // e est positif
            boucle sans fin  // déplacements horizontaux
              tracePixel(x1, y1) ;
              interrompre boucle si (x1 ← x1 + 1) = x2 ;
              si (e ← e + dy) < 0 alors
                y1 ← y1 - 1 ;  // déplacement diagonal
                e ← e + dx ;
              fin si ;
            fin boucle ;
          sinon  // vecteur oblique proche de la verticale, dans le 7e octant
            déclarer entier e ;
            dy ← (e ← dy) × 2 ; dx ← dx × 2 ;  // e est négatif
            boucle sans fin  // déplacements verticaux
              tracePixel(x1, y1) ;
              interrompre boucle si (y1 ← y1 - 1) = y2 ;
              si (e ← e + dx) > 0 alors
                x1 ← x1 + 1 ;  // déplacement diagonal
                e ← e + dy ;
              fin si ;
            fin boucle ;
          fin si ;
          
        fin si ;
      sinon  // dy = 0 (et dx > 0)
        
        // vecteur horizontal vers la droite
        répéter
          tracePixel(x1, y1) ;
        jusqu’à ce que (x1 ← x1 + 1) = x2 ;
        
      fin si ;
    sinon  // dx < 0
      si (dy ← y2 - y1) ≠ 0 alors
        si dy > 0 alors
          // vecteur oblique dans le 2d quadrant
          
          si -dx ≥ dy alors
            // vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
            déclarer entier e ;
            dx ← (e ← dx) × 2 ; dy ← dy × 2 ;  // e est négatif
            boucle sans fin  // déplacements horizontaux
              tracePixel(x1, y1) ;
              interrompre boucle si (x1 ← x1 - 1) = x2 ;
              si (e ← e + dy) ≥ 0 alors
                y1 ← y1 + 1 ;  // déplacement diagonal
                e ← e + dx ;
              fin si ;
            fin boucle ;
          sinon
            // vecteur oblique proche de la verticale, dans le 3e octant
            déclarer entier e ;
            dy ← (e ← dy) × 2 ; dx ← dx × 2 ;  // e est positif
            boucle sans fin  // déplacements verticaux
              tracePixel(x1, y1) ;
              interrompre boucle si (y1 ← y1 + 1) = y2 ;
              si (e ← e + dx) ≤ 0 alors
                x1 ← x1 - 1 ;  // déplacement diagonal
                e ← e + dy ;
              fin si ;
            fin boucle ;
          fin si ;
          
        sinon  // dy < 0 (et dx < 0)
          // vecteur oblique dans le 3e quadrant
          
          si dx ≤ dy alors
            // vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
            déclarer entier e ;
            dx ← (e ← dx) × 2 ; dy ← dy × 2 ;  // e est négatif
            boucle sans fin  // déplacements horizontaux
              tracePixel(x1, y1) ;
              interrompre boucle si (x1 ← x1 - 1) = x2 ;
              si (e ← e - dy) ≥ 0 alors
                y1 ← y1 - 1 ;  // déplacement diagonal
                e ← e + dx ;
              fin si ;
            fin boucle ;
          sinon  // vecteur oblique proche de la verticale, dans le 6e octant
            déclarer entier e ;
            dy ← (e ← dy) × 2 ; dx ← dx × 2 ;  // e est négatif
            boucle sans fin  // déplacements verticaux
              tracePixel(x1, y1) ;
              interrompre boucle si (y1 ← y1 - 1) = y2 ;
              si (e ← e - dx) ≥ 0 alors
                x1 ← x1 - 1 ;  // déplacement diagonal
                e ← e + dy ;
              fin si ;
            fin boucle ;
          fin si ;
          
        fin si ;
      sinon  // dy = 0 (et dx < 0)
        
        // vecteur horizontal vers la gauche
        répéter
          tracePixel(x1, y1) ;
        jusqu’à ce que (x1 ← x1 - 1) = x2 ;
        
      fin si ;
    fin si ;
  sinon  // dx = 0
    si (dy ← y2 - y1) ≠ 0 alors
      si dy > 0 alors
        
        // vecteur vertical croissant
        répéter
          tracePixel(x1, y1) ;
        jusqu’à ce que (y1 ← y1 + 1) = y2 ;
        
      sinon  // dy < 0 (et dx = 0)
        
        // vecteur vertical décroissant
        répéter
          tracePixel(x1, y1) ;
        jusqu’à ce que (y1 ← y1 - 1) = y2 ;
        
      fin si ;
    fin si ;
  fin si ;
  // le pixel final (x2, y2) n’est pas tracé.
fin procédure ;
}
