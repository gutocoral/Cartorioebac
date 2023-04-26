#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavél por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
   // início criação de variáveis/ strings
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // final da criação de variáveis/ strings
   
   printf("Digite o CPF a ser cadastrado: "); //coletando info do usuário
   scanf("%s", cpf); //%s seria para armazenar string
   
   strcpy(arquivo, cpf); //Responsável por copiar os valores da string
   
   FILE *file; //cria o arquivo 
   file = fopen(arquivo, "w"); //cria o arquivo e "w" significa criar e escrever
   fprintf(file,cpf); //salva o valor da variável
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
   
   system("pause"); //pausa, da tempo do usuário ler o que aparece na tela
   
}
int consulta()
{
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

   char cpf[40]; //variável em caractere (abrange números) para salvar o cpf digitado
   char conteudo[200]; //variável para armazenar os dados cadastrados
   
   printf("Digite o CPF a ser consultado: "); //mensagem para usuário
   scanf("%s", cpf); //armazena o CPF digitado em string
   
   FILE *file; //comando para criar arquivo
   file = fopen(cpf, "r"); //abre o arquivo e o "r" faz a leitura do arquivo
   
   if(file == NULL) //condição (se), se nulo (sem registro previamente), faz a ação seguinte
   {
   	   printf("Não foi possivel abrir o arquivo, não localizado!. \n"); //mensagem mostrada se caso a resposta for nula
   }
   
   while(fgets(conteudo, 200, file) != NULL) //condição (enquanto), conteudo for diferente de nulo
   {
   	   printf("\nEssas são as informações do usuário: "); //mensagem para o usuário
   	   printf("%s", conteudo); //mostra o que esta salvo no conteudo
   	   printf("\n\n"); //espaço de linhas
   }
   
   system("pause"); //pausa, da tempo do usuário ler o que aparece na tela
}

int deletar() //variável para deletar o usuário
{
   char cpf[40];
   
   printf("Digite o CPF do usuário a ser deletado: ");
   scanf("%s", cpf);
   
   remove(cpf); //função pronta para deletar o CPF salvo
   
   FILE *file; //cria arquivo
   file = fopen(cpf, "r"); //abre o arquivo e "r" faz a leitura
   
   if(file == NULL); //condição (se), se arquivo for igual a nulo, mostra a mensagem seguinte:
   {
   	   printf("O usuário não se encontra no sistema!.\n"); //mensagem mostrada
   	   system("pause"); //tempo para usuário ler
   }
}

int main()
{
   int opcao=0; //Definindo variáveis
   int laco=1;
   
   for(laco=1;laco=1;)
   {
   
   
      system("cls"); //Limpa a tela anterior
      
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   
      printf("### Cartório da EBAC ###\n\n"); //Início do menu
      printf("Escolha a opção desejada do menu:\n\n");
      printf("\t1 - Registrar nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n"); 
      printf("\t4 - Sair do sistema\n\n");
      printf("Opção: "); //Fim do menu
   
      scanf("%d", &opcao); //Armazendando a escolha do usuário (%d armazena inteiro
   
      system("cls"); //Limpa a tela anterior
      
      switch(opcao) //início da seleção do menu
      {
      	  case 1:
      	  	registro(); //chamada de funções
   	        break; //necessário após usar o case, parar o esse case
   	        
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
   	        
   	      
		  default: //se não for nenhuma das opções anteriores
   	      	printf("Essa opção não está disponível!\n");
   	        system("pause");
   	        break;
   	  }
   
   }
}
   

