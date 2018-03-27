/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

/* ************************************************* */
/* Imagens                                           */
/* Conjunto e funções que lidam com a parte de       */
/* desenhar na janela w1                             */
/*                                                   */
/* Para a documemtação de cada função veja imagens.h */
/* ************************************************* */

#include <stdio.h>
#include "xwc.h"
#include "SpaceWar.h" /* Struct: corpo */
#include "imagens.h"
#include "OperacoesMat.h" /* Função: Angulo */


/* Para documentação veja imagens.h */
static void validaPosicao (corpo *Objeto) {
    /* Objeto saiu da tela pela direita */
    if (Objeto->posicao[0] > 1280) {
        Objeto->posicao[0] = 0;
    }
    /* Objeto saiu da tela pela esquerda */
    else if (Objeto->posicao[0] < 0) {
        Objeto->posicao[0] = 1280;
    }
    /* Objeto saiu da tela por cima */
    if (Objeto->posicao[1] > 720) {
        Objeto->posicao[1] = 0;
    }
    /* Objeto saiu da tela por baixo */
    else if (Objeto->posicao[1] < 0) {
        Objeto->posicao[1] = 720;
    }
}

/* Para documentação veja imagens.h */
void DesenhaFundo () {

    PutPic(w1, Earth.BackGround, 0, 0, 1280, 720, 0, 0);
}

/* Para documentação veja imagens.h */
void DesenhaNave (corpo* Objeto) {
    validaPosicao (Objeto);
    SetMask (Earth.BackGround, Objeto->msk[Objeto->estado]);
    PutPic (Earth.BackGround, Objeto->imagem[Objeto->estado], 0, 0, 64, 64, Objeto->posicao[0] - 32, Objeto->posicao[1] - 32);
}

/* Para documentação veja imagens.h */
void VerificaPos (int i, int quadr, corpo* Objeto) {
    /* Primeiro e Terceiro quadrantes */
    if (quadr == 0) {
        switch (i) {
            case 1:
                Objeto->estado = 7;
                break;
            case 2:
                Objeto->estado = 6;
                break;
            case 3:
                Objeto->estado = 5;
                break;
            case -1:
                Objeto->estado = 4;
                break;
            default:
                Objeto->estado = 0;
                break;
        }
    }
    /* Segundo e Quarto quadrantes */
    else {
        switch (i) {
            case 1:
                Objeto->estado = 1;
                break;
            case 2:
                Objeto->estado = 2;
                break;
            case 3:
                Objeto->estado = 3;
                break;
            case -1:
                Objeto->estado = 4;
                break;
            default:
                Objeto->estado = 0;
                break;
        }
    }
    SetMask (Earth.BackGround, Objeto->msk[Objeto->estado]);
    PutPic (Earth.BackGround, Objeto->imagem[Objeto->estado], 0, 0, 16, 16, Objeto->posicao[0] - 16, Objeto->posicao[1] - 16);
}

/* Para documentação veja imagens.h */
void DesenhaTiro (corpo* Objeto) {
    validaPosicao (Objeto);
    double x, y;
    int i;
    x = Objeto->velocidade[0];
    y = Objeto->velocidade[1];
    /* Primeiro Quadrante */
    if (x >= 0 && y >= 0) {
        i = Angulo (x, y);
        VerificaPos (i, 1, Objeto);
    }
    /* Terceiro Quadrante */
    else if (x < 0 && y < 0) {
        i = Angulo (-x, -y);
        VerificaPos (i, 1, Objeto);
    }
    /* Segundo Quadrante */
    else if (x >= 0 && y < 0) {
        i = Angulo (x, -y);
        VerificaPos (i, 0, Objeto);
    }
    /* Quarto Quadrante */
    else {    /* Quarto Quadrante */
        i = Angulo (-x, y);
        VerificaPos (i, 0, Objeto);
    }
}

/* Para documentação veja imagens.h */
void GeraImagem () {
    corpo* aux = cabeca->prox;
    while (aux != NULL) {
        if (aux->ID > 2) DesenhaTiro(aux);
        else DesenhaNave(aux);
        aux = aux->prox;
    }

    DesenhaFundo();
}

/* Para documentação veja imagens.h */
void DesenhaImagem (PIC fundo) {
    UnSetMask(Earth.BackGround);
    PutPic(Earth.BackGround, fundo, 0, 0, 1280, 720, 0, 0);

    PIC planeta = ReadPic(w1, Earth.caminhoPlaneta, NULL);
    PutPic (Earth.BackGround, planeta, 0, 0, Earth.raio*2, Earth.raio*2, 640 - Earth.raio, 360 - Earth.raio);
}

void DesenhaTutorial (int tutorial) {
    if (tutorial == 1) {
        PIC tutorial = ReadPic(w1, "./imagens/tutorial1.xpm", NULL);
        PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
    }
    else {
        PIC tutorial = ReadPic(w1, "./imagens/tutorial2.xpm", NULL);
        PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
    }
}

void DesenhaOpcoesNave (int jogador) {
    if (jogador == 1) {
        PIC tutorial = ReadPic(w1, "./imagens/opcaojogador1.xpm", NULL);
        PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
    }
    else {
        PIC tutorial = ReadPic(w1, "./imagens/opcaojogador2.xpm", NULL);
        PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
    }
}

void DesenhaOpcoesPlanetas () {
    PIC tutorial = ReadPic(w1, "./imagens/opcoesplaneta.xpm", NULL);
    PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
}

void DesenhaGameOver () {
    if (!p1Venceu && !p2Venceu) {
        PIC tutorial = ReadPic(w1, "./imagens/gameover_empate.xpm", NULL);
        PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
    }
    else if (p1Venceu) {
        PIC tutorial = ReadPic(w1, "./imagens/gameover1.xpm", NULL);
        PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
    }
    else {
        PIC tutorial = ReadPic(w1, "./imagens/gameover2.xpm", NULL);
        PutPic(w1, tutorial, 0, 0, 1280, 720, 0, 0);
    }
} 
