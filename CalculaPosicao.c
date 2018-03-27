/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

/* ************************************************** */
/* Calcula Posicao                                    */
/* Esse programa e um conjunto de funcoes que alteram */
/* os vetores posicao, velocidade e forca das structs */
/*                                                    */
/* Para a documentação de cada função veja            */
/* CalculaPosicao.h                                   */
/* ************************************************** */


#include "xwc.h"
#include "SpaceWar.h" /* Struct: corpo */
#include "OperacoesMat.h" /* Funcoes: Forca, Distancia */
#include "CalculaPosicao.h"

/* Para documentação veja CalculaPosicao.h */
void ApagaCorpo (corpo* anterior, corpo* objeto) {
    anterior->prox = objeto->prox;
}

/* Para documentação veja CalculaPosicao.h */
void Resultante (int id, corpo* objeto) {
    int raioDaHitbox = 16;
    corpo* aux = cabeca->prox;
    double F, distancia;
    objeto->forca[0] = objeto->forca[1] = 0;

    /* Em relacao aos outros corpos */
    while (aux != NULL) {
        distancia = Distancia(objeto->posicao, aux->posicao);

        if (id <= 2 && aux->ID != id) {
            if (aux->ID > 2 && distancia <= raioDaHitbox + 8) {
                if (id == 1) p1Venceu = 1;
                else p2Venceu = 1;
                FimDeJogo = 1;
                return;
            }
            else if (aux->ID <= 2 && distancia <= raioDaHitbox*2) {
                FimDeJogo = 1;
                return;
            }
        }

        if (distancia != 0) {
            F = Forca(objeto->massa, aux->massa, distancia);
            objeto->forca[0] += F * (aux->posicao[0] - objeto->posicao[0]) / distancia;
            objeto->forca[1] += F * (aux->posicao[1] - objeto->posicao[1]) / distancia;
        }


        aux = aux->prox;
    }

    /* Em relacao ao planeta */
    distancia = Distancia(objeto->posicao, Earth.posicao);
    if (id > 2) {
        if (distancia <= Earth.raio + 8)
            objeto->tempoDeVida = 0;
    }
    else if (distancia <= Earth.raio + raioDaHitbox) {
        if (id == 1) p1Venceu = 1;
        else p2Venceu = 1;
        FimDeJogo = 1;
        return;
    }


    F = Forca (objeto->massa, Earth.massa, distancia);
    objeto->forca[0] += F * (Earth.posicao[0] - objeto->posicao[0]) / distancia;
    objeto->forca[1] += F * (Earth.posicao[1] - objeto->posicao[1]) / distancia;

}


/* Para documentação veja CalculaPosicao.h */
void Atualiza (corpo *anterior, corpo *objeto) {
    
    if (objeto->ID > 2 && objeto->tempoDeVida == 0) {
        ApagaCorpo (anterior, objeto);
        return;
    }


    /*atualizacao de posicao */
    objeto->posicao[0] += (objeto->velocidade[0]/frames) + (objeto->forca[0]/(objeto->massa*frames*frames));
    objeto->posicao[1] += (objeto->velocidade[1]/frames) + (objeto->forca[1]/(objeto->massa*frames*frames));



    /*Atualizacão de velocidade */
    objeto->velocidade[0] += objeto->forca[0]/(objeto->massa * frames);
    objeto->velocidade[1] += objeto->forca[1]/(objeto->massa * frames);

    objeto->tempoDeVida--;
}

/* Para documentação veja CalculaPosicao.h */
void CalculaPosicao() {
    corpo* aux = cabeca->prox;
    corpo* anterior = cabeca;
    while (aux != NULL) {
        Resultante (aux->ID, aux);
        Atualiza (anterior, aux);
        anterior = aux;
        aux = aux->prox;
    }
}

