/* ********************************************** */
/* Nomes: Camila Naomi, F�bio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

#ifndef CONTROLE_H 
#define CONTROLE_H

/* Fun��o que � chamada somente quando a tecla Seta para cima ou 'w'
   s�o pressionada, ela verifica o estado da nave e aumenta o vetor
   velociade dependendo do estado                                    */
void interpretaEstado(corpo* nave);

/* Fun��o que interpreta se alguma tecla do teclado foi pressionada,
   se sim ela verifica qual foi a tecla e age de acordo              */
void LeituraTeclado (WINDOW* w1, corpo* Nave1, corpo* Nave2);

#endif
