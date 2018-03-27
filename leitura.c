/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

/* ************************************************* */
/* Leitura                                           */
/* Conjunto de funções que lidam com a inicialização */
/* dos os dados da lista de corpos                   */
/*                                                   */
/* Para a documentação de cada função veja leitura.h */
/* ************************************************* */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "xwc.h"
#include "SpaceWar.h"
#include "leitura.h"
#define SEN225 0.38268343236 /*Seno de 22,5 graus*/
#define COS225 0.92387953251 /*Cosseno de 22,5 graus*/
#define SEN45 0.70710678118 /*Seno de 45 graus*/ 
#define COS45 0.70710678118 /*Cosseno de 45 graus*/

int id;

/* Para documentação veja leitura.h */
void CriaTiro(corpo* nave) {
    int aux, velocidade, distancia;
    velocidade = 175;
    distancia = 45;
    corpo *novo;
    corpo *temp;
    novo = malloc (sizeof (corpo));
    novo->massa = massaTiros;
    novo->ID = id++;
    novo->tempoDeVida = tempoDeVida;
    if (nave->ID == 1) {
        for(aux = 0; aux < 16; aux++) {
            novo->imagem[aux] = imagemTirosA[aux];
            novo->msk[aux] = mskTirosA[aux];
        }
    }
    else {
        for(aux = 0; aux < 16; aux++) {
            novo->imagem[aux] = imagemTirosB[aux];
            novo->msk[aux] = mskTirosB[aux];
        } 
    }

    /* Escolhe a posição e a volocidade dependendo do estado,
       velocidade e posicao da nave                           */
    switch(nave->estado) {
        case 0:
            novo->posicao[0] = nave->posicao[0] -16 + 24;
            novo->posicao[1] = nave->posicao[1] -16 - distancia;
            novo->velocidade[0] = nave->velocidade[0];
            novo->velocidade[1] = nave->velocidade[1] - (velocidade);
            break;
        case 1:
            novo->posicao[0] = nave->posicao[0] -16 - (distancia*SEN225) + 12;
            novo->posicao[1] = nave->posicao[1] -16 - (distancia*COS225);
            novo->velocidade[0] = nave->velocidade[0] - (velocidade*SEN225);
            novo->velocidade[1] = nave->velocidade[1] - (velocidade*COS225);
            break;
        case 2:
            novo->posicao[0] = nave->posicao[0] -16 - (distancia*SEN45);
            novo->posicao[1] = nave->posicao[1] -16 - (distancia*COS45);
            novo->velocidade[0] = nave->velocidade[0] - (velocidade*SEN45);
            novo->velocidade[1] = nave->velocidade[1] - (velocidade*COS45);
            break;
        case 3:
            novo->posicao[0] = nave->posicao[0] -16 - (distancia*COS225);
            novo->posicao[1] = nave->posicao[1] -16 - (distancia*SEN225) + 12;
            novo->velocidade[0] = nave->velocidade[0] - (velocidade*COS225);
            novo->velocidade[1] = nave->velocidade[1] - (velocidade*SEN225);
            break;
        case 4:
            novo->posicao[0] = nave->posicao[0] -16 - distancia;
            novo->posicao[1] = nave->posicao[1] -16 + 24;
            novo->velocidade[0] = nave->velocidade[0] - (velocidade);
            novo->velocidade[1] = nave->velocidade[1];
            break;
        case 5:
            novo->posicao[0] = nave->posicao[0] -16 - (distancia*COS225);
            novo->posicao[1] = nave->posicao[1] -16 + (distancia*SEN225) + 36;
            novo->velocidade[0] = nave->velocidade[0] - (velocidade*COS225);
            novo->velocidade[1] = nave->velocidade[1] + (velocidade*SEN225);
            break;
        case 6:
            novo->posicao[0] = nave->posicao[0] -16 - (distancia*SEN45);
            novo->posicao[1] = nave->posicao[1] -16 + (distancia*COS45) + 48;
            novo->velocidade[0] = nave->velocidade[0] - (velocidade*SEN45);
            novo->velocidade[1] = nave->velocidade[1] + (velocidade*COS45);
            break;
        case 7:
            novo->posicao[0] = nave->posicao[0] -16 - (distancia*SEN225) + 12;
            novo->posicao[1] = nave->posicao[1] -16 + (distancia*COS225) + 48;
            novo->velocidade[0] = nave->velocidade[0] - (velocidade*SEN225);
            novo->velocidade[1] = nave->velocidade[1] + (velocidade*COS225);
            break;
        case 8:
            novo->posicao[0] = nave->posicao[0] -16 + 24;
            novo->posicao[1] = nave->posicao[1] -16 + distancia + 48;
            novo->velocidade[0] = nave->velocidade[0];
            novo->velocidade[1] = nave->velocidade[1] + (velocidade);
            break;
        case 9:
            novo->posicao[0] = nave->posicao[0] -16 + (distancia*SEN225) + 36;
            novo->posicao[1] = nave->posicao[1] -16 + (distancia*COS225) + 48;
            novo->velocidade[0] = nave->velocidade[0] + (velocidade*SEN225);
            novo->velocidade[1] = nave->velocidade[1] + (velocidade*COS225);
            break;
        case 10:
            novo->posicao[0] = nave->posicao[0] -16 + (distancia*SEN45) + 48;
            novo->posicao[1] = nave->posicao[1] -16 + (distancia*COS45) + 48;
            novo->velocidade[0] = nave->velocidade[0] + (velocidade*SEN45);
            novo->velocidade[1] = nave->velocidade[1] + (velocidade*COS45);
            break;
        case 11:
            novo->posicao[0] = nave->posicao[0] -16 + (distancia*COS225) + 48;
            novo->posicao[1] = nave->posicao[1] -16 + (distancia*SEN225) + 36;
            novo->velocidade[0] = nave->velocidade[0] + (velocidade*COS225);
            novo->velocidade[1] = nave->velocidade[1] + (velocidade*SEN225);
            break;
        case 12:
            novo->posicao[0] = nave->posicao[0] -16 + distancia + 48;
            novo->posicao[1] = nave->posicao[1] -16 + 24;
            novo->velocidade[0] = nave->velocidade[0] + (velocidade);
            novo->velocidade[1] = nave->velocidade[1];
            break;
        case 13:
            novo->posicao[0] = nave->posicao[0] -16 + (distancia*COS225) + 48;
            novo->posicao[1] = nave->posicao[1] -16 - (distancia*SEN225) + 12;
            novo->velocidade[0] = nave->velocidade[0] + (velocidade*COS225);
            novo->velocidade[1] = nave->velocidade[1] - (velocidade*SEN225);
            break;
        case 14:
            novo->posicao[0] = nave->posicao[0] -16 + (distancia*SEN45) + 48;
            novo->posicao[1] = nave->posicao[1] -16 - (distancia*COS45);
            novo->velocidade[0] = nave->velocidade[0] + (velocidade*SEN45);
            novo->velocidade[1] = nave->velocidade[1] - (velocidade*COS45);
            break;
        case 15:
            novo->posicao[0] = nave->posicao[0] -16 + (distancia*SEN225) + 36;
            novo->posicao[1] = nave->posicao[1] -16 - (distancia*COS225);
            novo->velocidade[0] = nave->velocidade[0] + (velocidade*SEN225);
            novo->velocidade[1] = nave->velocidade[1] - (velocidade*COS225);
            break;
    }

    /*Insercao na lista */
    temp = cabeca->prox;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novo;
    novo->prox = NULL;
    
}


/* Para documentação veja leitura.h */
void leitura (int modeloNave1, int modeloNave2, int modeloPlaneta) {
    int aux;
    int i, j;
    double massaPadrao = 50000000000000000;
    
    /* vetor dos planetas e seus atributos*/
    planeta planetas[10] = {
                        {.raio = 121, .massa = massaPadrao, .caminhoPlaneta = "./imagens/planeta_original.xpm"},
                        {.raio = 128, .massa = massaPadrao/1.5, .caminhoPlaneta = "./imagens/planeta_deathstar.xpm"},
                        {.raio = 100, .massa = massaPadrao/2, .caminhoPlaneta = "./imagens/planeta_coruscant.xpm"},
                        {.raio = 128, .massa = massaPadrao*3, .caminhoPlaneta = "./imagens/planeta_mustafar.xpm"},
                        {.raio = 150, .massa = massaPadrao*2, .caminhoPlaneta = "./imagens/planeta_tatooine.xpm"}
                                                                                                            };
    /* vetor da parte do caminho para o arquivo das naves*/
    char caminhoNaves1[10][100] = {"./imagens/naveA", "./imagens/o/obi-wan-starfighter",
                                 "./imagens/m/milleniumfalcon", "./imagens/i/imperialdestroyer",
                                 "./imagens/t/Tie-Fighter", "./imagens/x/x-wing"};
    char caminhoNaves2[10][100] = {"./imagens/naveB", "./imagens/o/obi-wan-starfighter",
                                 "./imagens/m/milleniumfalcon", "./imagens/i/imperialdestroyer",
                                 "./imagens/t/Tie-Fighter", "./imagens/x/x-wing"};
  
    char primeiraParte1[100];
    char primeiraParte2[100];
    char segundaParte[5] = ".xpm";
    char fileName1[100];
    char fileName2[100];
    char buffer[4];
    printf ("%d %d\n", modeloNave1, modeloNave2);
    strcpy (primeiraParte1, caminhoNaves1[modeloNave1]);
    strcpy (primeiraParte2, caminhoNaves2[modeloNave2]);

    corpo* nave1;
    corpo* nave2;
    nave1 = malloc (sizeof (corpo));
    nave2 = malloc (sizeof (corpo));
    

    /* planeta */
    Earth.raio = planetas[modeloPlaneta].raio;
    Earth.massa = planetas[modeloPlaneta].massa;
    strcpy (Earth.caminhoPlaneta, planetas[modeloPlaneta].caminhoPlaneta);
    Earth.posicao[0] = 640;
    Earth.posicao[1] = 360;
    Earth.BackGround = ReadPic(w1, "./imagens/fundo.xpm", NULL);

    /* nave 1 e 2 */
    nave1->nome = "Coracao de Ouro";
    nave2->nome = "Yamato";
    nave1->ID = 1;
    nave2->ID = 2;
    nave1->massa = nave2->massa = massaNaves;
    nave1->posicao[0] = posicaoInicialNaves[0];
    nave1->posicao[1] = posicaoInicialNaves[1];
    nave2->posicao[0] = 1280 - posicaoInicialNaves[0];
    nave2->posicao[1] = 720 - posicaoInicialNaves[1];
    nave1->velocidade[0] = velocidadeInicialNaves[0];
    nave1->velocidade[1] = velocidadeInicialNaves[1];
    nave2->velocidade[0] = -1*velocidadeInicialNaves[0];
    nave2->velocidade[1] = -1*velocidadeInicialNaves[1];
    nave1->estado = 0;
    nave2->estado = 0;

    /* Imagens da nave 1 */
    for(aux = 0; aux < 16; aux++) {
        nave1->msk[aux] = NewMask(Earth.BackGround, 64, 64);

        for (i = 0, j = 0; primeiraParte1[i] != '\0'; i++, j++) fileName1[j] = primeiraParte1[i];
        sprintf (buffer, "%d", aux);
        for (i = 0; buffer[i] != '\0'; i++, j++) fileName1[j] = buffer[i];
        for (i = 0; segundaParte[i] != '\0'; i++, j++) fileName1[j] = segundaParte[i];
        fileName1[j] = '\0';

        nave1->imagem[aux] = ReadPic(w1, fileName1, nave1->msk[aux]);
    }
    
    /* Imagens da nave 2 */
    for(aux = 0; aux < 16; aux++) {
        nave2->msk[aux] = NewMask(Earth.BackGround, 64, 64);

        for (i = 0, j = 0; primeiraParte2[i] != '\0'; i++, j++) fileName2[j] = primeiraParte2[i];
        sprintf (buffer, "%d", aux);
        for (i = 0; buffer[i] != '\0'; i++, j++) fileName2[j] = buffer[i];
        for (i = 0; segundaParte[i] != '\0'; i++, j++) fileName2[j] = segundaParte[i];
        fileName2[j] = '\0';

        nave2->imagem[aux] = ReadPic(w1, fileName2, nave2->msk[aux]);
    }

    /* Imagens do tiro da nave 1 */
    for(aux = 0; aux < 8; aux++)
        mskTirosA[aux] = NewMask(Earth.BackGround, 16, 16);

    imagemTirosA[0] = ReadPic(w1, "./imagens/tiroA0.xpm", mskTirosA[0]);
    imagemTirosA[1] = ReadPic(w1, "./imagens/tiroA1.xpm", mskTirosA[1]);
    imagemTirosA[2] = ReadPic(w1, "./imagens/tiroA2.xpm", mskTirosA[2]);
    imagemTirosA[3] = ReadPic(w1, "./imagens/tiroA3.xpm", mskTirosA[3]);
    imagemTirosA[4] = ReadPic(w1, "./imagens/tiroA4.xpm", mskTirosA[4]);
    imagemTirosA[5] = ReadPic(w1, "./imagens/tiroA5.xpm", mskTirosA[5]);
    imagemTirosA[6] = ReadPic(w1, "./imagens/tiroA6.xpm", mskTirosA[6]);
    imagemTirosA[7] = ReadPic(w1, "./imagens/tiroA7.xpm", mskTirosA[7]);
    imagemTirosA[8] = ReadPic(w1, "./imagens/tiroA0.xpm", mskTirosA[0]);
    imagemTirosA[9] = ReadPic(w1, "./imagens/tiroA1.xpm", mskTirosA[1]);
    imagemTirosA[10] = ReadPic(w1, "./imagens/tiroA2.xpm", mskTirosA[2]);
    imagemTirosA[11] = ReadPic(w1, "./imagens/tiroA3.xpm", mskTirosA[3]);
    imagemTirosA[12] = ReadPic(w1, "./imagens/tiroA4.xpm", mskTirosA[4]);
    imagemTirosA[13] = ReadPic(w1, "./imagens/tiroA5.xpm", mskTirosA[5]);
    imagemTirosA[14] = ReadPic(w1, "./imagens/tiroA6.xpm", mskTirosA[6]);
    imagemTirosA[15] = ReadPic(w1, "./imagens/tiroA7.xpm", mskTirosA[7]);

    /* Imagens do tiro da nave 2 */
    for(aux = 0; aux < 8; aux++)
        mskTirosB[aux] = NewMask(Earth.BackGround, 16, 16);

    imagemTirosB[0] = ReadPic(w1, "./imagens/tiroB0.xpm", mskTirosB[0]);
    imagemTirosB[1] = ReadPic(w1, "./imagens/tiroB1.xpm", mskTirosB[1]);
    imagemTirosB[2] = ReadPic(w1, "./imagens/tiroB2.xpm", mskTirosB[2]);
    imagemTirosB[3] = ReadPic(w1, "./imagens/tiroB3.xpm", mskTirosB[3]);
    imagemTirosB[4] = ReadPic(w1, "./imagens/tiroB4.xpm", mskTirosB[4]);
    imagemTirosB[5] = ReadPic(w1, "./imagens/tiroB5.xpm", mskTirosB[5]);
    imagemTirosB[6] = ReadPic(w1, "./imagens/tiroB6.xpm", mskTirosB[6]);
    imagemTirosB[7] = ReadPic(w1, "./imagens/tiroB7.xpm", mskTirosB[7]);
    imagemTirosB[8] = ReadPic(w1, "./imagens/tiroB0.xpm", mskTirosB[0]);
    imagemTirosB[9] = ReadPic(w1, "./imagens/tiroB1.xpm", mskTirosB[1]);
    imagemTirosB[10] = ReadPic(w1, "./imagens/tiroB2.xpm", mskTirosB[2]);
    imagemTirosB[11] = ReadPic(w1, "./imagens/tiroB3.xpm", mskTirosB[3]);
    imagemTirosB[12] = ReadPic(w1, "./imagens/tiroB4.xpm", mskTirosB[4]);
    imagemTirosB[13] = ReadPic(w1, "./imagens/tiroB5.xpm", mskTirosB[5]);
    imagemTirosB[14] = ReadPic(w1, "./imagens/tiroB6.xpm", mskTirosB[6]);
    imagemTirosB[15] = ReadPic(w1, "./imagens/tiroB7.xpm", mskTirosB[7]);

    cabeca->prox = nave1;
    nave1->prox = nave2;
    nave2->prox = NULL;
    id = 3;

}
