/* ********************************************** */
/* Nomes: Camila Naomi, F�bio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

#ifndef SPACEWAR_H 
#define SPACEWAR_H


/* ******* Structs ******* */

struct planeta {
    double raio;
    double massa;
    double posicao[2]; /* posicao[0] = Eixo x; posicao[1] = Eixo y */
    char caminhoPlaneta[100]; /* caminho relativo do arquivo do planeta */ 
    PIC BackGround;
};
typedef struct planeta planeta;

struct corpo {
    char* nome; /* Tamanho m�ximo do nome: 100 caracteres */
    double massa;
    double posicao[2]; /* Idem a posicao da struct planeta*/
    double velocidade[2]; /* Analogo � posicao[] */
    double forca[2]; /* Analogo � posicao[] */
    int tempoDeVida;
    int ID; /* Utilizado para diferenciar os projeteis */
    struct corpo* prox;

    PIC imagem[16];
    MASK msk[16];
    int estado; /* Come�ando para cima e indo no sentido anti-hor�rio,
                   represente as possiveis dire��es que o objeto pode ter */
};
typedef struct corpo corpo;

/* ******* Vari�veis Globais ******* */

planeta Earth;
double massaPlaneta;
double raioPlaneta;

double massaNaves;
double posicaoInicialNaves[2];
double velocidadeInicialNaves[2];

double tempoDeVida;
double massaTiros;
MASK mskTirosA[16];
PIC imagemTirosA[16];
MASK mskTirosB[16];
PIC imagemTirosB[16];

int frames;
corpo *cabeca; /* Cabe�a da lista de corpos */
WINDOW *w1; /* Janela utilizada */
int FimDeJogo; /* Indica se o jogo acabou */
int p1Venceu, p2Venceu;
#endif
