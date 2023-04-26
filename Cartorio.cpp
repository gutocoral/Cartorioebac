#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsav�l por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
   // in�cio cria��o de vari�veis/ strings
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // final da cria��o de vari�veis/ strings
   
   printf("Digite o CPF a ser cadastrado: "); //coletando info do usu�rio
   scanf("%s", cpf); //%s seria para armazenar string
   
   strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
   
   FILE *file; //cria o arquivo 
   file = fopen(arquivo, "w"); //cria o arquivo e "w" significa criar e escrever
   fprintf(file,cpf); //salva o valor da vari�vel
   fclose(file); //fecha o arquivo
   
   file = fopen(arquivo, "a"); //o "a" inclui no arquivo ja criado, atualiza o "w"
   fprintf(file, ","); // , para separar os dados
   fclose(file); //fechar o arquivo
   
   printf("Digite o nome a ser cadastrado "); //mensagem para coletar a info "nome"
   scanf("%s", nome); //salva o "nome" na string
   
   file = fopen(arquivo, "a"); // abre o arquivo e "a" atualiza os dados
   fprintf(file, nome); //armazena em "nome"
   fclose(file); //fecha o arquivo
   
   file = fopen(arquivo, "a"); //abre e atualiza
   fprintf(file, ","); //usado para separar a info
   fclose(file); //fecha o arquivo
   
   printf("Digite o sobrenome a ser cadastrado: "); //mensagem para coletar a info "sobrenome"
   scanf("%s", sobrenome); //salva na string "sobrenome"
   
   file = fopen(arquivo, "a"); //abre e atualiza a info
   fprintf(file, sobrenome); //armazena em "sobrenome"
   fclose(file); //fecha o arquivo
   
   file = fopen(arquivo, "a"); //abre e atualiza
   fprintf(file, ","); //usado para separar a info
   fclose(file); //fecha o arquivo
   
   printf("Digite o cargo a ser cadastrado: "); //mensagem para coletar a info "cargo"
   scanf("%s", cargo); //salva na string "cargo"
   
   file = fopen(arquivo, "a"); //abre e atualiza a info
   fprintf(file, cargo); //armazena em "cargo"
   fclose(file); //fecha o arquivo
   
   system("pause"); //pausa, da tempo do usu�rio ler o que aparece na tela
   
}
int consulta()
{
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

   char cpf[40]; //vari�vel em caractere (abrange n�meros) para salvar o cpf digitado
   char conteudo[200]; //vari�vel para armazenar os dados cadastrados
   
   printf("Digite o CPF a ser consultado: "); //mensagem para usu�rio
   scanf("%s", cpf); //armazena o CPF digitado em string
   
   FILE *file; //comando para criar arquivo
   file = fopen(cpf, "r"); //abre o arquivo e o "r" faz a leitura do arquivo
   
   if(file == NULL) //condi��o (se), se nulo (sem registro previamente), faz a a��o seguinte
   {
   	   printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); //mensagem mostrada se caso a resposta for nula
   }
   
   while(fgets(conteudo, 200, file) != NULL) //condi��o (enquanto), conteudo for diferente de nulo
   {
   	   printf("\nEssas s�o as informa��es do usu�rio: "); //mensagem para o usu�rio
   	   printf("%s", conteudo); //mostra o que esta salvo no conteudo
   	   printf("\n\n"); //espa�o de linhas
   }
   
   system("pause"); //pausa, da tempo do usu�rio ler o que aparece na tela
}

int deletar() //vari�vel para deletar o usu�rio
{
   char cpf[40];
   
   printf("Digite o CPF do usu�rio a ser deletado: ");
   scanf("%s", cpf);
   
   remove(cpf); //fun��o pronta para deletar o CPF salvo
   
   FILE *file; //cria arquivo
   file = fopen(cpf, "r"); //abre o arquivo e "r" faz a leitura
   
   if(file == NULL); //condi��o (se), se arquivo for igual a nulo, mostra a mensagem seguinte:
   {
   	   printf("O usu�rio n�o se encontra no sistema!.\n"); //mensagem mostrada
   	   system("pause"); //tempo para usu�rio ler
   }
}

int main()
{
   int opcao=0; //Definindo vari�veis
   int laco=1;
   
   for(laco=1;laco=1;)
   {
   
   
      system("cls"); //Limpa a tela anterior
      
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   
      printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
      printf("Escolha a op��o desejada do menu:\n\n");
      printf("\t1 - Registrar nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n"); 
      printf("\t4 - Sair do sistema\n\n");
      printf("Op��o: "); //Fim do menu
   
      scanf("%d", &opcao); //Armazendando a escolha do usu�rio (%d armazena inteiro
   
      system("cls"); //Limpa a tela anterior
      
      switch(opcao) //in�cio da sele��o do menu
      {
      	  case 1:
      	  	registro(); //chamada de fun��es
   	        break; //necess�rio ap�s usar o case, parar o esse case
   	        
   	      case 2:
   	        consulta();
      	    break;
      	    
      	  case 3:
      	  	deletar();
   	        break;
   	        
   	      case 4:
   	        printf("Obrigado por utilizar o sistema!\n");
   	        return 0;
   	        break;
   	        
   	      
		  default: //se n�o for nenhuma das op��es anteriores
   	      	printf("Essa op��o n�o est� dispon�vel!\n");
   	        system("pause");
   	        break;
   	  }
   
   }
}
   

