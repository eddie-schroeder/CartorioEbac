#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro()  //função responsável por cadastrar o usuário no sistema
{
	
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo Idioma
	
	//início da criação de variáveis/string
 	char arquivo[40];
	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	//final da criação de variáveis/strings
 	
 	printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usuário
 	scanf("%s",cpf); //o %S refere-se a strings
 	
 	strcpy(arquivo, cpf); //responsável por copiar os valores das string
 	
 	FILE *file; //cria o arquivo no banco de dados
 	file = fopen(arquivo, "w"); //cria o arquivo "w" para escrever
 	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salva o valor da variável
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo "a" para atualizar
 	fprintf(file, "\n"); //nova informação de pular linha "\n"
 	fclose(file); //fecha o arquivo
 	
 	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
 	scanf("%s",nome); //salvando na string
 	
 	file = fopen(arquivo, "a"); //abre o arquivo atualizando uma informação
 	fprintf(file, "Nome: "); //nova informação "Nome:"
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo atualizando uma informação
 	fprintf(file, nome); //salva o valor da variável
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo atualizando uma informação
 	fprintf(file,"\n"); //pular linha
 	fclose(file); //fecha o arquivo
 	
 	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
 	scanf("%s",sobrenome); //salvando na string
 	
 	file = fopen(arquivo, "a"); //abre o arquivo para atualizar 
 	fprintf(file, "Sobrenome: "); //nova informação "Sobrenome:"
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
 	fprintf(file, sobrenome); //salva valor da variável
 	fclose(file); //fecha o arquivo
	 
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,"\n"); //pular linha
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //salva na string
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, "Cargo: "); //criando nova informação 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo para atualizar
	fprintf(file, cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela 
	
	 	


}

int consulta() //funçaõ para consultar as informações do usuário
{
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo Idioma
	
	//início da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis/strings
	
		printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
		scanf("%s", cpf); //o %S salva na string 
	
	FILE *file; //chama o arquivo
	file = fopen(cpf,"r"); //abre o arquivo CPF com "r" para leitura do arquivo
	
		printf("\nEssas são as informações do usuário:\n\n"); 
	
	
	if(file == NULL) //cria uma validação em caso de arquivo nulo, não exista
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); 
		
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) //cria um laço de repetiçao
	{
		printf("%s", conteudo); //o %s salva na string
		printf("\n\n");
	}
	fclose (file);
	system("pause"); //pausa a tela
}

int deletar() //função para deletar o usuário
{
	char cpf[40]; //criação de variável/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando a informação do usuário
	scanf("%s",cpf); //salvando na string
	
	remove(cpf); //deleta o usuário
	
	FILE *file; //chama o arquivo
	file= fopen(cpf,"r"); //abre o arquivo CPF para leitura "r"
	
	printf("\n");
	printf("Usuário deletado com sucesso!\n");
	printf("\n\n");
	
	
	if(file == NULL) //cria validação em caso de usuário inexistente
	{
		printf("O usuário não encontrado no sistema!\n");
		printf("\n");		
	}
	system("pause"); //pausa a tela
	
}



int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	 system("cls");
	
	 setlocale(LC_ALL, "PORTUGUESE"); //Definindo Idioma
	
	 printf("\t*** Cartório da EBAC ***\n\n"); //Início do Menu
	 printf("Escolha a Opção Desejada do Menu:\n\n");
	 printf("\t1 - Registrar Nomes\n");
	 printf("\t2 - Consultar Nomes\n");
	 printf("\t3 - Deletar Nomes\n\n");
	 printf("\t4 - Sair do Sistema\n\n"); 
	 printf("Opção: "); //Fim do Menu
	
	 scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	 system("cls"); //responsável por limpar a tela
	 
	 
	 switch(opcao) //início da seleção do Menu
	 {
	 	case 1:
	 	   registro(); //chamada de funções
	 	   break;
	 	   
	 	case 2:
	 		consulta(); //chamada de funções
		    break;
		    
		case 3:
			deletar(); //chamada de funções
		    break;
		    
		 case 4:
		 	printf("Obrigado por utilizar o sistema!\n");
			 return 0;
			 break;
			 
			    
		    default:
			printf("Essa opção não está disponível!\n");
		    system("pause");
		    break;
		    //fim da seleção do Menu
      } 
	 
    } 
    
}
