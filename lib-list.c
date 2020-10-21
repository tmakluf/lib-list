
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <math.h>

//DEFINI��O DA ESTRUTURA 'LIVRO' E OS RESPECTIVOS CAMPOS
 typedef struct livro{
     char titulo[50];
     char autor[50];
     char data[20];
     char editora[50];
     char registro[50];
     struct livro* next;
     int size;
   }Livro;

   //HEADERS/CABE�ALHO DAS FUN��ES E PROCEDIMENTOS DO PROGRAMA

    Livro* insert_livro(Livro* l);        //fun��o que insere um livro na lista (retorna um ponteiro do tipo 'Livro')
    void print_livro(Livro* l);          //fun��o que imprime a lista e recebe a lista 'l' como argumento (sem retorno)
    Livro* delete_livro(Livro* l);      //fun��o que exclu� um livro da lista (retorna um ponteiro do tipo 'Livro')
    void edit_livro(Livro* l);         //fun��o que edita um livro da lista (e recebe a lista 'l' como argumento (sem retorno)
    Livro* esvazia_lista (Livro* l);  //fun��o que esvazia a lista encadeada
    int list_size(Livro*l);          //fun��o com estrutura de itera��o que varre a lista e busca a quantidade de registros
    Livro* consulta_livro(Livro *l);//fun��o que permite a consulta individual de um adastro e exibe todos os campos do livro

                        //IN�CIO DA CONSTRU��O DA L�GICA E ESTRUTURA��O DAS FUN��ES E PROCEDIMENTOS DO PROGRAMA:

//FUN��O QUE VARRE, CONTA E RETORNA O TAMANHO DA LISTA
  int list_size(Livro*l){
  Livro livro;
  Livro *atual = l;

  int size=0; //declara e equaciona a vari�vel que ir� receber a quantidade de registro na lista

  while(atual!=NULL){ //la�o de itera��o para o ponteiro auxiliar (varre a lista)

    size++; //incrementa a vari�vel a cada itera��o
    atual=atual->next; //varre a lista
  }

  return size; //retorna o tamanho da lista (ser� exibido o tamanho na tela principal do programa e na fun��o que imprime a lista)
  }

//FUN��O QUE INSERE UM LIVRO NA LISTA
   Livro* insert_livro (Livro *l){
   Livro livro;
   Livro *atual= l;
   Livro *anterior=NULL;

   setlocale(LC_ALL, "Portuguese"); //procedimento que permite a inser��o de caracteres especiais no programa (fora inclu�da em todas as fun��es).

   //L� os dados inseridos pelo usu�rio
     printf("\n");
     printf("  T�tulo da Obra: ");
     fflush (stdin); fgets( livro.titulo, 50, stdin); printf ("\n");
     printf("  Autor: ");
     fflush (stdin); fgets(livro.autor, 50, stdin); printf ("\n");
     printf("  Data de Publica��o: ");
     fflush (stdin); fgets(livro.data, 20, stdin); printf ("\n");
     printf("  Editora: ");
     fflush (stdin); fgets(livro.editora, 50, stdin); printf ("\n");
     printf("  Registro: ");
     fflush (stdin); fgets(livro.registro, 50, stdin); printf ("\n");

         //declarando a vari�vel 'NovoLivro' do tipo struct 'Livro' e alocando espa�o na mem�ria
         //copiando as strings para as novas posi��es
         Livro* NovoLivro=(Livro*) malloc (sizeof(Livro));
         strcpy(NovoLivro->titulo, livro.titulo);
         strcpy(NovoLivro->autor, livro.autor);
         strcpy(NovoLivro->data, livro.data);
         strcpy(NovoLivro->editora, livro.editora);
         strcpy(NovoLivro->registro, livro.registro);

         NovoLivro->next= l;

         //confirma��o de cadastro do livro
        printf("--------------------------\n\n");
        printf(" Livro cadastrado com sucesso!");
        printf("\n\n Pressione uma tecla para retornar.");

        if (atual==NULL) return NovoLivro; //se a lista estiver vazia ir� receber o novo livro (elemento)

        //Principal artif�cio do programa, utilizando o m�todo que realiza a compara��o das strings referente ao 'T�tulo da Obra' para ordenar os elementos na lista em ordem alfab�tica.
        while((atual!=NULL) && strcasecmp (NovoLivro->titulo, atual->titulo)>0){

        anterior = atual;    //armazena a refer�ncia anterior
        atual=atual->next;   //aponta para o ponteiro do pr�ximo elemento
        }
                //O programa emite um ALERTA caso o livro j� exista com o mesmo nome, entretanto n�o impede seu cadastro
                if(strcasecmp (NovoLivro->titulo, atual->titulo)==0){
                printf("\n\nALERTA: Esse livro j� foi cadastrado com o mesmo t�tulo\n\n");
                }

            if(anterior==NULL){
                NovoLivro ->next = atual;
                return NovoLivro;
            }

            NovoLivro->next=anterior->next;
            anterior->next=NovoLivro;

            return l;
     }

//FUN��O PARA IMPRIMIR A LISTA
void print_livro (Livro* l){
     Livro* atual;//Ponteiro para percorrer a lista sem perder a refer�ncia do primeiro elemento da lista.

        setlocale(LC_ALL, "Portuguese");

        printf("\n\n  LIVROS NA LISTA: %d\n", list_size(l)); //invoca fun��o que recebe o tamanho da lista (quantidade de registros)
        printf("--------------------------\n\n");

     //Fazendo a impress�o das estruturas de todos os livros existentes na lista
     for(atual= l ; atual!= NULL; atual= atual->next){
        printf("\n  T�tulo da Obra: ");
        printf("%s", atual->titulo);
        printf("\n  Autor: ");
        printf("%s", atual->autor);
        printf("\n  Data de Publica��o: ");
        printf("%s", atual->data);
        printf("\n  Editora: ");
        printf("%s", atual->editora);
        printf("\n  Registro: ");
        printf("%s", atual->registro);
        printf("\n\n");
        printf("--------------------------\n\n");}

     if(l==NULL){       //condi��o que verifica se a lista est� vazia
     printf("\n");
     printf("  Nenhum livro cadastrado.");
     printf("\n\n Pressione uma tecla para retornar.");}

    }

//FUN��O PARA EXCLUIR UM LIVRO DA LISTA
Livro* delete_livro(Livro *l){

    setlocale(LC_ALL, "Portuguese");

     char titulo[50];
     Livro *anterior= NULL;   //Ponteiro auxiliar 'anterior' que verifica quem � o elemento antes do elemento atual
     Livro *atual= l; //Ponteiro auxiliar 'atual' que percorre toda a lista sem perder a refer�ncia do primeiro elemento

     printf("\n");
     printf("  Insira o t�tulo da obra que deseja excluir: ");
     fflush (stdin); fgets(titulo, 50, stdin);

     while(atual!= NULL && strcasecmp(atual->titulo, titulo)!=0){  //ENQUANTO: 'atual' n�o apontar para nulo E o titulo do 'atual' for diferente do titulo inserido pelo usu�rio
        anterior= atual; //guarda a refer�ncia
        atual= atual->next; //percorre a lista
     }

     if(atual==NULL){ //Condi��o: se a lista for vazia, imprima:
        printf("\n");
        printf("\n  Livro n�o encontrado no sistema.");
        printf("\n\n  Pressione uma tecla para retornar.");
        return l;
     }

     if(anterior==NULL){ //condi��o que exclui o primeiro registro da lista

      printf("\n\n          Livro %s", atual->titulo);
      printf("       exclu�do com sucesso!\n");
        l= atual->next;

     }else{ //condi��o que exclui um registro no meio da lista

      printf("\n\n          Livro %s", atual->titulo);
      printf("       exclu�do com sucesso!\n");
        anterior->next= atual->next;
     }

     free(atual); //Liberando o espa�o na mem�ria previamente alocado
     printf("--------------------------\n\n");
     printf("\n\n  Pressione uma tecla para retornar.");
     return l;
}

//FUN��O PARA EDITAR UM CADASTRO DE LIVRO
void edit_livro(Livro* l){

    setlocale(LC_ALL, "Portuguese");

     char autor_novo[50],data_nova[20],editora_nova[50],registro_novo[50]; //declara as vari�veis que ser�o utilizadas para a substitui��o das atuais
     char titulo[50];
     Livro* atual=l;
     Livro* anterior=NULL;
     Livro* NovoLivro;

     printf("\n");
     printf("Insira o t�tulo da obra que deseja editar: ");
     fflush (stdin); fgets(titulo, 50, stdin);

     while(atual!= NULL && strcasecmp(atual->titulo, titulo)!=0){ //ENQUANTO: 'atual' n�o apontar para nulo E o titulo do 'atual' for diferente do titulo inserido pelo usu�rio (Procurando o registro na lista)
        atual= atual->next; //'atual' ir� apontar para o ponteiro do pr�ximo ao 'atual'
     }

     if(atual!=NULL){ //Condi��o para editar os campos do livro � partir do c�digo inserido pelo usu�rio e copia as strings inseridas para as novas posi��es de substitui��o

       //exibe o t�tulo do livro que ser� editado (o t�tulo de um livro n�o poder� ser alterado)
        printf("\n");
        printf("\t\tT�tulo da Obra: %s", atual->titulo);
        printf("\n");

        //atualiza os campos do livro copiando as strings inseridas para as novas posi��es
        printf("\n  Novo Autor: ");
        fflush (stdin); fgets(autor_novo, 50, stdin); printf ("\n");
        strcpy(atual->autor,autor_novo);
        printf("\n  Nova Data de Publica��o: ");
        fflush (stdin); fgets(data_nova, 20, stdin); printf ("\n");
        strcpy(atual->data,data_nova);
        printf("\n  Nova Editora: ");
        fflush (stdin); fgets(editora_nova, 50, stdin); printf ("\n");
        strcpy(atual->editora,editora_nova);
        printf("\n  Novo Registro: ");
        fflush (stdin); fgets(registro_novo, 50, stdin); printf ("\n");
        strcpy(atual->registro,registro_novo);
        printf("  Livro alterado com sucesso!");

     }else{ //caso o c�digo buscado n�o exista na lista, imprima:
        printf("\n");
        printf("\n  Livro n�o localizado no sistema.");
     }
     printf("\n\n\n  Pressione uma tecla para retornar.");

}

//FUN��O PARA CONSULTAR UM CADASTRO INDIVIDUALMENTE
  Livro* consulta_livro(Livro *l){

      setlocale(LC_ALL, "Portuguese");

     char titulo[50];
     Livro *anterior= NULL;   //Ponteiro auxiliar 'anterior' que verifica quem � o elemento antes do elemento atual
     Livro *atual= l; //Ponteiro auxiliar 'atual' que percorre toda a lista sem perder a refer�ncia do primeiro elemento

     printf("\n");
     printf("  Insira o t�tulo da obra que deseja consultar: ");
     fflush (stdin); fgets(titulo, 50, stdin);

        while(atual!= NULL && strcasecmp(atual->titulo, titulo)!=0){  //ENQUANTO: 'atual' n�o apontar para nulo E o titulo do 'atual' for diferente do titulo inserido pelo usu�rio
        anterior= atual; //guarda a refer�ncia
        atual= atual->next; //percorre a lista
     }

       if(atual==NULL){ //Condi��o: se a lista for vazia, imprima:
        printf("\n");
        printf("\n  Livro n�o encontrado no sistema.");
        printf("\n\n  Pressione uma tecla para retornar.");
        return l;

     }else{
        printf("\n--------------------------\n");
        printf("\n  T�tulo da Obra: ");
        printf("%s", atual->titulo);
        printf("\n  Autor: ");
        printf("%s", atual->autor);
        printf("\n  Data de Publica��o: ");
        printf("%s", atual->data);
        printf("\n  Editora: ");
        printf("%s", atual->editora);
        printf("\n  Registro: ");
        printf("%s", atual->registro);
        printf("\n");
        printf("--------------------------\n\n");}

     printf("\n\n  Pressione uma tecla para retornar.");

        return l;
  }

//FUN��O QUE ESVAZIA A LISTA ENCADEADA
Livro* esvazia_lista(Livro* l){

Livro* atual=l;

while (atual!=NULL){ //la�o que remove cada elemento da lista e imprime o nome dos livros removidos

   printf("\n->Livro: %sremovido\n", atual->titulo);

    Livro* anterior=atual->next;
    free(atual);
    atual=anterior;
}

     if(l==NULL){       //condi��o que verifica se a lista est� vazia
     printf("\n");
     printf("  Nenhum livro cadastrado.");
     printf("\n\n Pressione uma tecla para retornar.");
     return l;
}
    return;
}

//PROGRAMA PRINCIPAL
main()
{
   //VARI�VEIS DECLARADAS
   Livro *l= NULL; //inicia a lista apontando para NULL (vazia)
   char option; //char para alternar entre as op��es do menu

   setlocale(LC_ALL, "Portuguese");


   while(option!='7') //Itera��o para repetir o programa
   {

       system("cls");

     //MENU DA TELA PRINCIPAL COM AS OPERA��ES DISPON�VEIS

      printf("");printf("       |CADASTRO DE LIVROS|");printf("\n\n");

      printf("\t|MENU PRINCIPAL|");printf("\t\t\t    \n \n\n");

      printf("   | (1)  Cadastrar Livro   |\n");

      printf("   | (2)  Exibir Cadastros  |\n");

      printf("   | (3)  Excluir Cadastro  |\n");

      printf("   | (4)  Editar Cadastro   |\n");

      printf("   | (5)  Consultar Livro   |\n");

      printf("   | (6)  Esvaziar Lista    |\n");


      printf("   | (7)  Sair              |\n");

      printf("\n\n");
      printf("      |Livros na Lista: %d|", list_size(l)); //exibe na tela principal o tamanho da lista

      printf("\n\n\n");
      printf("Desenvolvido por Thiago Makluf Barbosa");

      fflush(stdin);
      option= getch();

     //M�todo 'switch' para operar dependendo da op��o selecionada
      switch(option)
      {
         case '1': //Ir� invocar a fun��o para inserir um livro

              fflush(stdin);
              system("cls");

              printf(" ");printf("\t|CADASTRAR NOVO LIVRO|     ");printf("\t\t\t      \n");

              l= insert_livro(l);

         getch();
         system("cls");
         break;

         case '2': //Ir� invocar a fun��o para imprimir a lista

              system ("cls");

              printf("");printf("\t|LIVROS CADASTRADOS|");printf("\t\t\t\n");

              print_livro(l);

         getch();
         system("cls");
         break;

         case '3': //Ir� invocar a fun��o para excluir um livro

              system ("cls");

              printf("");printf("\t|EXCLUIR CADASTRO EXISTENTE| ");printf("\t\t\t \n");

              l= delete_livro(l);

         getch();
         system("cls");
         break;

         case '4': //Ir� invocar a fun��o para editar um livro

              system ("cls");

              printf("");printf("\t|EDITAR CADASTRO|");printf("\t\t\t\n");

              edit_livro(l);

         getch();
         system("cls");
         break;

        case '5': //Ir� invocar a fun��o para realizar consulta individual

              system ("cls");

              printf("");printf("\t|CONSULTAR UM LIVRO|");printf("\t\t\t\n");

             l=consulta_livro(l);

         getch();
         system("cls");
         break;

                  case '6': //Ir� invocar a fun��o para esvaziar a lista

              system ("cls");

              printf("");printf("\t|ESVAZIAR A LISTA|");printf("\t\t\t\n");

             l=esvazia_lista(l);

         getch();
         system("cls");
         break;

         case '7':

              option='7'; //Ir� encerrar o programa

         system("cls");
         printf("|ENCERRANDO...|\n");
         exit(1);

         default:
            printf("\n\n\nOp��o inv�lida\n");
      }
   }
} //FINAL DA EXECU��O DO PROGRAMA
