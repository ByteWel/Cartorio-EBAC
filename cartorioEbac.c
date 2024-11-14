#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //bilioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string
int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite  CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Esse cara � o responsavel por criar o valor das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //aqui eu salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite um nome  ser cadstrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
}

int consulta()

{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquiv, nao localizado! \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa�oes do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
	

	
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
    system("pause");
}


int main()
	{
		int opcao =0; //Definindo vari�veis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao;

		
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Login de Administrador!\n\nDigite a sua senha: ");
		scanf("%s", senhadigitada);
	
		comparacao = strcmp(senhadigitada, "admin");
		if(comparacao == 0)
		{
			for(laco=1;laco=1;)
			{
				system("cls");
  				setlocale(LC_ALL, "Portuguese");
    	
    			printf("### Cart�rio da EBAC ###\n\n");
    			printf("Escolha a op��o desejada do menu: \n\n");
    			printf("\t1 - Registrar nomes\n");
    			printf("\t2 - Consultar nomes\n");
    			printf("\t3 - Deletar nomes\n\n");
    			printf("\t4 - Sair do programa\n\n");
    			printf("Op��o: "); //Fim do menu
    	
    			scanf("%d", &opcao); //Armazena a escolha do usu�rio
    	
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
        	
        			case 4:
       				 printf("Obrigado por utilizar o sistema\n\n");
      				  return 0;
      				  break;
        
    				default:
    				printf("Esta op��o n�o est� dispon�vel!\n");
    				system("pause");
    				break;
   				}//fim da fun��o
			}
		}
	
		else
			printf("Senha incorreta!");
	}