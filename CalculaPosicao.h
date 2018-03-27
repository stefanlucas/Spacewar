/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

#ifndef CALCULAPOSICAO_H 
#define CALCULAPOSICAO_H


/* Retira da lista de corpos o corpo objeto */
void ApagaCorpo (corpo* anterior, corpo* objeto);

/* Funcao que dado uma Lista de corpos e um id (um corpo espcifico)
   calcula a forca gravitacional resultante dele com os outros corpos
   e o planeta Earth                                                  */
void Resultante (int id, corpo* objeto);

/* Utilizando a forca em um corpo, atualiza sua velocidade e posicão */
void Atualiza (corpo *anterior, corpo *objeto);

/* Função de embrulho que chama Resultante e Atualiza para todos os
   corpos da lista                                                  */
void CalculaPosicao();

#endif
