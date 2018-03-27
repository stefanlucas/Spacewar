
/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

/* ************************************************** */
/* Controle                                           */
/* Conjunto de funções que lidam com a interpretação  */
/* das teclas do teclado pressionadas                 */
/*                                                    */
/* Para a documentação de cada função veja controle.h */
/* ************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xwc.h"
#include "SpaceWar.h" /* Struct: corpo */
#include "controle.h"
#include "leitura.h" /* Funções: CriaTiro */
#define SEN225 0.38268343236 /*Seno de 22,5 graus*/
#define COS225 0.92387953251 /*Cosseno de 22,5 graus*/
#define SEN45 0.70710678118 /*Seno de 45 graus*/ 
#define COS45 0.70710678118 /*Cosseno de 45 graus*/

int ID;

/* Para documentação veja controle.h */
void interpretaEstado(corpo* nave) {
    int velocidade = 20;
    switch(nave->estado) {
        case 0:
            nave->velocidade[1] -= velocidade;
            break;
        case 1:
            nave->velocidade[0] -= velocidade*SEN225;
            nave->velocidade[1] -= velocidade*COS225;
            break;
        case 2:
            nave->velocidade[0] -= velocidade*SEN45;
            nave->velocidade[1] -= velocidade*COS45;
            break;
        case 3:
            nave->velocidade[0] -= velocidade*COS225;
            nave->velocidade[1] -= velocidade*SEN225;
            break;
        case 4:
            nave->velocidade[0] -= velocidade;
            break;
        case 5:
            nave->velocidade[0] -= velocidade*COS225;
            nave->velocidade[1] += velocidade*SEN225;
            break;
        case 6:
            nave->velocidade[0] -= velocidade*SEN45;
            nave->velocidade[1] += velocidade*COS45;
            break;
        case 7:
            nave->velocidade[0] -= velocidade*SEN225;
            nave->velocidade[1] += velocidade*COS225;
            break;
        case 8:
            nave->velocidade[1] += velocidade;
            break;
        case 9:
            nave->velocidade[0] += velocidade*SEN225;
            nave->velocidade[1] += velocidade*COS225;
            break;
        case 10:
            nave->velocidade[0] += velocidade*SEN45;
            nave->velocidade[1] += velocidade*COS45;
            break;
        case 11:
            nave->velocidade[0] += velocidade*COS225;
            nave->velocidade[1] += velocidade*SEN225;
            break;
        case 12:
            nave->velocidade[0] += velocidade;
            break;
        case 13:
            nave->velocidade[0] += velocidade*COS225;
            nave->velocidade[1] -= velocidade*SEN225;
            break;
        case 14:
            nave->velocidade[0] += velocidade*SEN45;
            nave->velocidade[1] -= velocidade*COS45;
            break;
        case 15:
            nave->velocidade[0] += velocidade*SEN225;
            nave->velocidade[1] -= velocidade*COS225;
            break;
    }
}

/* Para documentação veja controle.h */
void LeituraTeclado (WINDOW* w1, corpo* Nave1, corpo* Nave2) {
    int tecla;
    if (WCheckKBD(w1)) {
        tecla = WGetKey(w1);
        if (tecla == 111)                                    /* Seta para cima */
            interpretaEstado(Nave1);
        else if (tecla == 25)                                /* tecla 'w' */
            interpretaEstado(Nave2);
        else if (tecla == 113)                               /* Seta para a esquerda */
            Nave1->estado = (Nave1->estado + 1 + 16) % 16;
        else if (tecla == 114)                               /* Seta para a direita */
            Nave1->estado = (Nave1->estado - 1 + 16   ) % 16;
        else if (tecla == 38)                                /* tecla 'a' */
            Nave2->estado = (Nave2->estado + 1 + 16) % 16;
        else if (tecla == 40)                                /* tecla 'd' */
            Nave2->estado = (Nave2->estado - 1 + 16) % 16;
        else if (tecla == 116) {                             /* Seta para baixo */
            CriaTiro(Nave1);
        }
        else if (tecla == 39)                                /* tecla 's' */
            CriaTiro(Nave2);
    }

}
