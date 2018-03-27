#ifndef OPERACOES_H 
#define OPERACOES_H

/* Constante Gravitacional */
double G;

/* Recebe dois vetores posicão e retorna a distância (euclidiana) entre eles */
double Distancia (double posicao1[], double posicao2[]);

/* Retorna a forca gravitacional (F) entre dois corpo */
double Forca (double massa1, double massa2, double distancia); 

/* Dados um cateto oposto, CatOp, e um cateto adjacente, CatAdj, retorna a
   hipotenusa calculada por Pitagoras                                      */
double PitagorasHipotenusa (double CatOp, double CatAdj);

/* Recebe dois catetos, um cateto oposto, CatOp, e um cateto adjacente, CatAdj,
   calcula entao o seno do angulo formado pelo triangulo reto, devolve:
    -3, se a hipotenusa dos catetos for 0;
    -2, se o seno estiver entre o seno dos angulos 0 e 11,25
    -1, se o seno estiver entre o seno dos angulos 78.75 e 90
     1, se o seno estiver entre o seno dos angulos 11,25 e 33.75
     2, se o seno estiver entre o seno dos angulos 33.75 e 56.25
     3, se o seno estiver entre o seno dos angulos 56.25 e 78.75
   IMPORTANTE: Os CatOp e CatAdj devem ser sempre positivos                     */
int Angulo (double catOp, double catAdj);

#endif
