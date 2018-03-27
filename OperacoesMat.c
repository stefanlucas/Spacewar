/* ********************************************** */
/* Nomes: Camila Naomi, Fábio Tanaka, Lucas Abe   */
/* N Usp: 4266602, 9297982, 8531612               */
/* ********************************************** */

/* ********************************************** */
/* Operacoes Mat                                  */
/* Conjunto de funcoes que cuidam dos calculos    */
/* Matematicos ou Fisicos                         */
/*                                                */
/* Para a documentação de cada função veja        */
/* OperacoesMat.h                                 */
/* ********************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "OperacoesMat.h" /* Variavel Global: G */
#define SEN7875 0.9807852804 /* seno de 78.75 */
#define SEN5625 0.8314696123 /* seno de 56.25 */
#define SEN3375 0.55557023302 /* seno de 33.75 */
#define SEN1125 0.19509032201 /* seno de 11.25 */

double G = 0.0000000000667;
/* Para documentação veja OperacoesMat.h */
double Distancia (double posicao1[], double posicao2[]) {
    double x, y, distancia;
    x = posicao1[0] - posicao2[0];
    y = posicao1[1] - posicao2[1];
    distancia = sqrt ((x * x) + (y * y));
    return distancia;
}

/* Para documentação veja OperacoesMat.h */
double Forca (double massa1, double massa2, double distancia) {
    double F;
    F = (G * (massa1) * (massa2)) / (distancia*distancia);
    return F;
}

/* Para documentação veja OperacoesMat.h */
double PitagorasHipotenusa (double CatOp, double CatAdj) {
    return sqrt((CatOp * CatOp) + (CatAdj * CatAdj));
}

/* Para documentação veja OperacoesMat.h */
int Angulo (double catOp, double catAdj) {
    double hip, sen;
    hip = PitagorasHipotenusa (catOp, catAdj);
    if (hip == 0) return -3; /* Caso não haja V */
    sen = (catOp / hip);
    if (sen > SEN7875) return -1;
    else if (sen > SEN5625) return 3;
    else if (sen > SEN3375) return 2;
    else if (sen > SEN1125) return 1;
    return -2;
}

