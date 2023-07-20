#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro()  //fun��o respons�vel por cadastrar o usu�rio no sistema
{
	
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo Idioma
	
	//in�cio da cria��o de vari�veis/string
 	char arquivo[40];
	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	//final da cria��o de vari�veis/strings
 	
 	printf("Digite o CPF a ser cadastrado: "); //coletando as informa��es do usu�rio
 	scanf("%s",cpf); //o %S refere-se a strings
 	
 	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
 	
 	FILE *file; //cria o arquivo no banco de dados
 	file = fopen(arquivo, "w"); //cria o arquivo "w" para escrever
 	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salva o valor da vari�vel
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo "a" para atualizar
 	fprintf(file, "\n"); //nova informa��o de pular linha "\n"
 	fclose(file); //fecha o arquivo
 	
 	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
 	scanf("%s",nome); //salvando na string
 	
 	file = fopen(arquivo, "a"); //abre o arquivo atualizando uma informa��o
 	fprintf(file, "Nome: "); //nova informa��o "Nome:"
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo atualizando uma informa��o
 	fprintf(file, nome); //salva o valor da vari�vel
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo atualizando uma informa��o
 	fprintf(file,"\n"); //pular linha
 	fclose(file); //fecha o arquivo
 	
 	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
 	scanf("%s",sobrenome); //salvando na string
 	
 	file = fopen(arquivo, "a"); //abre o arquivo para atualizar 
 	fprintf(file, "Sobrenome: "); //nova informa��o "Sobrenome:"
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
 	fprintf(file, sobrenome); //salva valor da vari�vel
 	fclose(file); //fecha o arquivo
	 
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,"\n"); //pular linha
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //salva na string
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, "Cargo: "); //criando nova informa��o 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo para atualizar
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela 
	
	 	


}

int consulta() //fun�a� para consultar as informa��es do usu�rio
{
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo Idioma
	
	//in�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis/strings
	
		printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
		scanf("%s", cpf); //o %S salva na string 
	
	FILE *file; //chama o arquivo
	file = fopen(cpf,"r"); //abre o arquivo CPF com "r" para leitura do arquivo
	
		printf("\nEssas s�o as informa��es do usu�rio:\n\n"); 
	
	
	if(file == NULL) //cria uma valida��o em caso de arquivo nulo, n�o exista
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); 
		
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) //cria um la�o de repeti�ao
	{
		printf("%s", conteudo); //o %s salva na string
		printf("\n\n");
	}
	fclose (file);
	system("pause"); //pausa a tela
}

int deletar() //fun��o para deletar o usu�rio
{
	char cpf[40]; //cria��o de vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando a informa��o do usu�rio
	scanf("%s",cpf); //salvando na string
	
	remove(cpf); //deleta o usu�rio
	
	FILE *file; //chama o arquivo
	file= fopen(cpf,"r"); //abre o arquivo CPF para leitura "r"
	
	printf("\n");
	printf("Usu�rio deletado com sucesso!\n");
	printf("\n\n");
	
	
	if(file == NULL) //cria valida��o em caso de usu�rio inexistente
	{
		printf("O usu�rio n�o encontrado no sistema!\n");
		printf("\n");		
	}
	system("pause"); //pausa a tela
	
}



int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	 system("cls");
	
	 setlocale(LC_ALL, "PORTUGUESE"); //Definindo Idioma
	
	 printf("\t*** Cart�rio da EBAC ***\n\n"); //In�cio do Menu
	 printf("Escolha a Op��o Desejada do Menu:\n\n");
	 printf("\t1 - Registrar Nomes\n");
	 printf("\t2 - Consultar Nomes\n");
	 printf("\t3 - Deletar Nomes\n\n");
	 printf("\t4 - Sair do Sistema\n\n"); 
	 printf("Op��o: "); //Fim do Menu
	
	 scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	 system("cls"); //respons�vel por limpar a tela
	 
	 
	 switch(opcao) //in�cio da sele��o do Menu
	 {
	 	case 1:
	 	   registro(); //chamada de fun��es
	 	   break;
	 	   
	 	case 2:
	 		consulta(); //chamada de fun��es
		    break;
		    
		case 3:
			deletar(); //chamada de fun��es
		    break;
		    
		 case 4:
		 	printf("Obrigado por utilizar o sistema!\n");
			 return 0;
			 break;
			 
			    
		    default:
			printf("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break;
		    //fim da sele��o do Menu
      } 
	 
    } 
    
}
