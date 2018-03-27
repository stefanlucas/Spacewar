CFLAGS = -ansi -Wall -O2 -g
CC = gcc

SpaceWar : OperacoesMat.o CalculaPosicao.o leitura.o SpaceWar.o xwc.o imagens.o controle.o
	${CC} ${CFLAGS} -o SpaceWar $^ -lm -lXpm -lX11

OperacoesMat.o : OperacoesMat.c OperacoesMat.h
	${CC} ${CFLAGS} -c OperacoesMat.c

CalculaPosicao.o : CalculaPosicao.c CalculaPosicao.h OperacoesMat.h SpaceWar.h xwc.o
	${CC} ${CFLAGS} -c CalculaPosicao.c -lXpm -lX11

leitura.o : leitura.c leitura.h SpaceWar.h xwc.o
	${CC} ${CFLAGS} -c leitura.c -lXpm -lX11

imagens.o : imagens.c imagens.h SpaceWar.h xwc.o
	${CC} ${CFLAGS} -c imagens.c -lXpm -lX11

controle.o : controle.c controle.h leitura.h SpaceWar.h xwc.o
	${CC} ${CFLAGS} -c controle.c -lXpm -lX11

SpaceWar.o : SpaceWar.c OperacoesMat.h CalculaPosicao.h leitura.h xwc.o controle.o
	${CC} ${CFLAGS} -c SpaceWar.c -lXpm -lX11

xwc.o : xwc.c

clean: 
	rm -f *.o calc

ex: SpaceWar
	./SpaceWar