/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

/* ******************************************************** */
/* Space War                                                */
/* Esse programa é um jogo de tiro no espaço                */
/* Para informacões de como rodar o programa leia o Manual  */
/* do Usuario.                                              */
/* ******************************************************** */

#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "xwc.h"
#include "SpaceWar.h" /* Struct: planeta, corpo 
                         Variaveis Globais: frames, duracao, cabeca, w1, Earth */
#include "CalculaPosicao.h" /* Funções: Resultante, Atualiza */
#include "leitura.h" /* Função: leitura */
#include "imagens.h" /* Funções: DesenhaFundo, DesenhaNave, DesenhaTiro */
#include "controle.h" /* Funções: LeituraTeclado */
#define ESC 9

int main (int numarg, char* arg[]) {
    massaNaves = 1000;
    posicaoInicialNaves[0] = 150;
    posicaoInicialNaves[1] = 360;
    velocidadeInicialNaves[0] = 0;
    velocidadeInicialNaves[1] = 75;
    frames = 60;
    tempoDeVida = 3 * frames;
    massaTiros = 100;   
    FimDeJogo = 0;
    p1Venceu = p2Venceu = 0;
    
    int aux, modeloNave1, modeloNave2, modeloPlaneta;
    PIC fundo;
    w1 = InitGraph(1280, 720, "SpaceWar");
    InitKBD(w1);
    fundo = ReadPic(w1, "./imagens/fundo.xpm", NULL);

    cabeca = malloc (sizeof (corpo));

    DesenhaTutorial (1);
    aux = WGetKey (w1);
    DesenhaTutorial (2);
    aux = WGetKey (w1);

    DesenhaOpcoesNave (1);
    aux = 0;
    while (aux < 10 || aux > 15) {
        aux = WGetKey (w1);
    }
    modeloNave1 = aux;

    DesenhaOpcoesNave (2);
    aux = 0;
    while (aux < 10 || aux > 15) {
        aux = WGetKey (w1);
    }
    modeloNave2 = aux;

    DesenhaOpcoesPlanetas ();
    aux = 0;
    while (aux < 10 || aux > 14) {
        aux = WGetKey (w1);
    }
    modeloPlaneta = aux;

    leitura (modeloNave2-10, modeloNave1-10, modeloPlaneta-10);

    while (FimDeJogo == 0) {

        /* Verifica se uma tecla foi pressionada e age de acordo */
        LeituraTeclado (w1, cabeca->prox, (cabeca->prox)->prox);

        /* Desenho dos Objetos */
        GeraImagem();

        /* Atualização das posições dos objetos */
        DesenhaImagem(fundo);
        CalculaPosicao();        
        usleep(1000000/frames);
    }

    usleep(400000);
    DesenhaGameOver ();

    aux = WGetKey(w1);
    while (aux != ESC) {
        aux = WGetKey(w1);
    }
    
    CloseGraph();
    return 0;
}
