#include <stdio.h> //biblioteca de comunica�ao com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];  
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s se refere a strings
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria arquivo
	fprintf(file, cpf);
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	

	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O Arquivo n�o foi localizado, tente novamente!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa�es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	} 
	
	
	
	
	
	
	
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	
	printf("Digite o CPF do usu�rio que quer deletar: ");
	
	scanf("%s", cpf);
	
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}                    //pause � responsavel pelo congelamento da tela no parametro desejado
}


int main()
{
	int opcao = 0; //Definindo vari�veis
	int x = 1;
	
	for(x = 1;x = 1;)
	{
	
	
		system("cls"); //cls � respons�vel para resetar a tela do sistema
	
	
	// Definindo a linguagem	
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cart�rio da EBAC ### \n\n");
	// Inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
	// Escolhas do usuario
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls");
		
		
			switch(opcao)
		{
			case 1:
			registro();
			break;
				
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();	
			break;
			
				
			default:
				printf("Est� op��o n�o est� disponivel\n");
				system("pause");
			break;
		}
		//fim da sele��o
		
	//	printf("\n\nEsse Software � Pertencente � Richard Felipe");
	}
}


