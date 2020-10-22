#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*2- Faça um programa para criar uma agenda de contatos onde cada contato. 
   Cada contato contém as seguintes informações:*/

typedef struct agenda {
    char nome[80];
    int telefone;
    char email[80];
    agenda *prox;
} contato;

/*Declarando os Métodos*/
contato * incluir(contato *lista, contato *contatoNovo);
contato * excluir(contato *lista);
void listar(contato *lista);
void pesquisar(contato *lista);
contato * criarContato();
void menu();
void gerarCabecalho();

contato *primeiroElemento;
int qtde;

main() {
   primeiroElemento = NULL;
	
	menu();
	return 0;
}

void menu(){
   gerarCabecalho();

   int op=0;

   while(op!=5){
      scanf("%d",&op);
      system ("CLS");;
   switch(op) {
      case 1:                
         primeiroElemento = incluir(primeiroElemento, criarContato()); 
		   menu();
      break;
              
      case 2: 
         listar(primeiroElemento);
		   menu();
      break;
      
      case 3: 
         pesquisar(primeiroElemento);
         menu();
      break;    
            
      case 4: 
         primeiroElemento = excluir(primeiroElemento);
		   menu();
      break;
       
      case 5: 
         printf("\n\nObrigada!");
      break; 

      default:
         printf("\nDigite uma opção válida, por favor.\n");
			menu();
      break;          
      }
   }
}

void gerarCabecalho(){
    puts("-------------AGENDA-----------");
    puts("1- Incluir um Contato");
    puts("2- Listar os Contatos");
    puts("3- Consultar um Contato");
    puts("4- Remover um Contato");
    puts("5- Sair ");
  
   }

contato * incluir (contato * lista, contato * contatoNovo){
   if (lista == NULL){
      lista = contatoNovo;

      contatoNovo->prox = NULL;
   } else
   {
      contatoNovo->prox = lista;
      lista = contatoNovo;
   }
   return lista;
}

contato * excluir(contato *lista) { 
	contato *aux;
	aux = lista;
	
   char op;
	printf("\nDeseja mesmo excluir o contato?\n\--> S\n\--> N\n\n");
	scanf(" %c", &op);
   if (op == 'S' or op == 's') {
		for (int i = 0; i < qtde; i++){		
			if (i == (qtde-1)) {
				aux->prox = NULL;
				printf("Contato %s removido com sucesso!!", aux->nome);
				
            qtde--;
				return lista;
			}			
		aux = aux->prox;	
		}	
	printf("Agenda vazia.!!!\n");
	return lista;
   }else{
      return lista;
   }
}

void listar(contato *lista){
   contato *aux;
   aux = lista;

   printf("*---------LISTA DE CONTATOS----------*\n\n");

   for (int i = 0; i < qtde; i++){	
	
		printf("\n Nome: %s\n", aux->nome);
		printf("Telefone: %d\n", aux->telefone);
		printf("E-mail: %s\n", aux->email);
		printf("---------------------------------------\n\n");		 
		aux = aux->prox;		
	}
}

void pesquisar(contato *lista){

   contato *aux;
	aux = lista;
	int telefone;
	
	printf("Digite o telefone que deseja buscar: \n");
	scanf("%d", &telefone);
	
	for (int i = 0; i < qtde; i++){	
		if (aux->telefone == telefone) {
			printf("\nNome: %s\n", aux->nome);
			printf("Telefone: %d\n", aux->telefone);
			printf("E-mail: %s\n", aux->email);
			return;
		}		 
		aux = aux->prox;		
	}
	printf("Contato não existe! Tente novamente.\n");
}

contato *criarContato(){
   contato *novoContato = (contato*) malloc(sizeof(contato));
	
	printf("Entre com o Nome: ");
	scanf("%s", &novoContato->nome);
		
	printf("Entre com o telefone: ");
	scanf("%d", &novoContato->telefone);
		
	printf("Entre com o E-mail: ");
	scanf("%s", &novoContato->email);
	
	qtde++;
	return novoContato;
}