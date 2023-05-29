#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define n 5
//// FILA
// Declara��o da estrutura de Fila

typedef struct {
    int elementoF[2*n];
    int inicio;
    int fim;
} Fila;

// Declara��o da fun��o de Inicializar/criar Fila

void inicializaFila(Fila* f) {
    f->inicio = 0;
    f->fim = -1;
}

// Declara��o da fun��o de Inserir n�meros na Fila

void enfilerar(Fila* f, int resto) {
        f->fim++;
 		f->elementoF[f->fim] = resto;
}

// Declara��o da fun��o de Retirar n�meros na Fila

void retirarfila(Fila* f) {   
    if (f->inicio > f->fim) 
	{
        puts("Fila Vazia!\n");
    } else {
        f->inicio++;
    }
}

// Declara��o da fun��o de Mostrar a Fila

void mostrarFila(Fila f) {
    int i;
    for (i = f.inicio; i <= f.fim; i++) 
	{
        printf(" %d\n", f.elementoF[i]);
    }
}
///////////////// PILHA 
// Declara��o da estrutura de Pilha

typedef struct {
    int elementoP[n];
    int topo;
} Pilha;

// Declara��o da fun��o de Inicializar/criar Pilha

void inicializaPilha(Pilha* p) {
    p->topo = -1;
} 

// Declara��o da fun��o de Inserir n�meros na Pilha

void pushpilha(Pilha* p, int l) {
  	    p->topo++;
 		p->elementoP[p->topo] = l;
}

// Declara��o da fun��o de Retirar n�meros na Pilha

void poppilha(Pilha * p) {
    if (p->topo == -1) 
	{
        puts("Pilha Vazia!\n");
    } else {
        p->topo--;
    }
}

// Declara��o da fun��o de Mostrar a Pilha

void mostrarPilha(Pilha p) {
    int i;
	for (i = p.topo; i >= 0; i--) 
	{
        printf(" %d\n", p.elementoP[i]);
    }
}

// Estrutura Principal do Programa

int main() {
    setlocale(LC_ALL, "Portuguese");
    Fila f;
	Fila f2;
    Pilha p;
    int i, op, a;

    inicializaFila(&f);
    inicializaPilha(&p);

    puts("Trabalho de Sistema de Fila + Pilha!");
    puts("Seja bem-vindo!!!");

// 	CRUD
	
    do {
        puts("Escolha sua Op��o:");
        puts("1 - Inserir na Fila");
        puts("2 - Inserir na Pilha");
        puts("3 - Mostrar Fila");
        puts("4 - Mostrar Pilha");
        puts("5 - Gerar Fila Nova");
        puts("6 - Sair do Programa");
        printf("Sua Op��o: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            	// Metodo para Inserir n�mero na fila
               	if (f.fim < n - 1) {
  						printf("Digite o Numero que deseja colocar: ");
       					scanf("%d", &i); 
         				enfilerar(&f, i);
   						puts("N�mero Salvo!");
						   			} else 
	  	  	  {	
	  	  	  	// Quando a fila estiver com 5 n�meros inserido o metodo coloca fila cheia
						puts("Fila Cheia!");
			}
                break;
            case 2:
            	// Metodo para Inserir n�mero na Pilha
                if (p.topo < n - 1) {
   						printf("Digite o Numero que deseja colocar: ");
					    scanf("%d", &i);
  						pushpilha(&p, i);
						puts("N�mero Salvo!");
				} 
				else {
					// Quando a pilha estiver com 5 n�meros inserido o metodo coloca pilha cheia
						puts("Pilha Cheia!");
				}
                break;
            case 3:
                mostrarFila(f);
                break;
            case 4:
                mostrarPilha(p);
                break;
            case 5:
            	// Inicializa��o da fila NOVA
	        	inicializaFila(&f2);
				while (p.topo >= 0) {
				    a = p.elementoP[p.topo];
                    poppilha(&p);
                    enfilerar(&f2, a);
                }
				while (f.inicio <= f.fim) {
				    a = f.elementoF[f.inicio];
                    retirarfila(&f);
                    enfilerar(&f2, a);
                }
				puts("\nFila Nova Criado com Sucesso!");
				puts("Nova Fila:");
				// Fila nova � criada e mostrada com 10 n�meros ( 5 da pilha + 5 da Fila).
	            mostrarFila(f2);
				puts("");
                break;
            case 6:
                puts("Obrigado, at� logo!\n");
                break;
            default:
                puts("Op��o inv�lida\n");
        }
    } while (op != 6);
    return 0;
}