/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

#ifndef IMAGENS_H 
#define IMAGENS_H

/* Função que desenha o fundo na tela */
void DesenhaFundo ();

/* Função que desenha uma nave na posição:
   (Objeto->posição[0], Objeto->posição[1]) */
void DesenhaNave (corpo* Objeto);

/* Função que dado um inteiro i, resultado da função Angulo, e um quadr
   desenha o Objeto na posição dada na struct e com a rotação ideal.
   Ver a documentação de DesenhaTiro e Angulo                           */
void VerificaPos (int i, int quadr, corpo *Objeto);

/* Função que serve de embrulho para função VerificaPos, dado o vetor
   velocidade de um Objeto, ela chama a função Angulo e encontra o quadrante
   do velocidade, então passa todos os dados para VerificaPos                */
void DesenhaTiro (corpo* Objeto);

/* Função que varre toda a lista e manda os corpos que são naves para
   DesenhaNave e os que são tiros para DesenhaTiro, depois chama DesenhaFundo */
void GeraImagem ();

/* Função que cria o fundo */
void DesenhaImagem (PIC fundo);

void DesenhaTutorial ();

void DesenhaOpcoesNave (int jogador);

void DesenhaOpcoesJogador (int jogador);

void DesenhaOpcoesPlanetas ();

void DesenhaGameOver ();

#endif
