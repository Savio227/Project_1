/* Nome:S�vio Fernandes Viiera
   Matr�cula:UC21106911
   Curso:Engenharia de Software */
#include <stdio.h>//biblioteca de entrada e sa�da de dados
#include <locale.h>//biblioteca de linguagem
#include<string.h>//biblioteca de string
#include<ctype.h>//biblioteca de uso de toupper e tolower
#include<stdlib.h>//biblioteca para usar o system"pause"
/*Um cinema de Bras�lia est� interessado em descobrir o perfil das pessoas que frequentam
suas sess�es de filmes e para isso, necessita realizar algumas verifica��es nas informa��es prestadas. Devem 
ser solicitados a quantidade de sess�es que ser�o realizadas, o nome do filme, a quantidade de pessoas que 
assistiram o filme, assim como o sexo e a idade. No entanto, para cada um deles, h� uma valida��o que deve ser 
feita:*/

int main()
{
  setlocale(LC_ALL, "Portuguese");
 //declara��o de vari�veis
 int sess/*sess�es*/, pessoas/*n�mero de pessoas que assistiram o filme*/, c;//contador
 char sexo, filme[35];/*nome do filme*/
 char buff[35]; //buffer de leituras
 int quantF=0/*quantidade de pessoas do sexo feminino*/, quantM=0/*quantidade de pessoas do sexo masculino*/,quantMaiorF=0/*maiores de idade feminino*/,quantMaiorM=0;/*maiores de idade masculino*/
 int quantCria=0, quantAdol=0, quantAdultos=0, quantVelhos=0;
 int quantMaioresF=0, quantMaioresM=0;
 int idade, Valorpipoca;//pre�o da pipoca salgada
 
 printf("\n================== Bem vindo ao cinema de Bras�lia! ====================");
	 do{
	    
		printf("\nPor favor, informe o n�mero de sess�es:");// \n:quebra de linha e solicita��o da vari�vel sess
	    scanf("%i", &sess);//atribui��o do valor digitado pelo usu�rio na vari�vel sess
	    if(sess>2 || sess<2){//limitando o n�mero de sess�es em 2
	    printf("N�mero de sess�es inv�lido, por favor tente novamente.\n");}//Condi��o que limita o n�mero de sess�es a 2 sess�es
	    else{//sen�o, continuidade ao c�digo
	    printf("N�mero de sess�es inseridas com sucesso!\n");}/*chave do else*/ }//chave do "do"                                      
	while(sess>2||sess<2);
	 
	do{
	
	   printf("\nPor favor, Informe o nome do filme:");
	   fflush(stdin);//limpeza do buffer da mem�ria
	   fgets(filme,35,stdin);//leitura de string
	   if(strlen(filme)<=2)//limita� do que o usu�rio pode digitar
	   printf("Nome inv�lido, insira o nome corretamente.\n");
	   else//sen�o
	   printf("Nome encontrado com sucesso!\n");}
	while(strlen(filme)<2);//estrutura de repeti��o que limita o que o usu�rio pode digitar
	
	do{
	
	   printf("\nDigite agora o n�mero de pessoas que viram o filme:");
	   scanf("%i", &pessoas);//atribu��o da vari�vel pessoas
	   fflush(stdin);
	   if(pessoas<10)
	   printf("\nN�mero de pessoas inv�lido, � necess�rio pelo menos 10 pessoas.\n");
	   else
	   printf("N�mero de pessoas inseridos com sucesso!\n");}
	while(pessoas<10);//funciona enquanto o n�mero de pessoas n�o for maior ou igual a dez

	/*Para cada pessoa que assistiu ao filme dever� ser solicitado e validado o sexo (M - masculino, F -
Feminino) e a idade (de 3 a 100 anos). */
   for(c=0; c<pessoas;c++){	
		do{
		   printf("\nInforme a idade da %d pessoa:", c+1);
		   scanf("%i", &idade);
		   fflush(stdin);
		   if(idade<3 || idade>100)//Limitando a idade que o usu�rio pode botar
		   printf("S� s�o permitidas pessoas com 3 a 100 anos.");
		   
		    if(idade>=3 && idade<=13){//especificando a classe das crian�as
				quantCria=quantCria+1;
			}else if(idade>=14 && idade<=17){//especificando a idade dos adolescentes
				quantAdol=quantAdol+1;
			}
			else if(idade>=18 && idade<=64){//especificando a idade dos adultos
				quantAdultos=quantAdultos+1;
			}
			else if(idade>=65 && idade<=100){//especificando a idade dos idosos
				quantVelhos=quantVelhos+1;
			}
			
		}while(idade<3 || idade>100);//estrutura de repeti��o while que impede o usu�rio de sair do loop caso digite algo dentro da condi��o

		do{
			
		   printf("Informe o sexo da %d pessoa, F para feminino e M para masculino:", c+1);//c+1 para come�ar a contagem do 1
		   fflush(stdin);
		   scanf("%c", &sexo);//atribui��o da vari�vel sexo
		   sexo=toupper(sexo);
		   if(sexo=='F'){
		   		quantF=quantF+1;//realizando o calculo de pessoas do sexo feminino
		
		    }else{
				quantM=quantM+1;//realizando o calculo de pessoas do sexo masculino
			}
		
		}while(sexo!='F' && sexo!='M'); printf("\n");//impedindo o usu�rio de digitar algo que n comece com M ou F
		
		if(sexo=='F' && (idade>=18 && idade<=100)){
			quantMaioresF=quantMaioresF+1;//relizando o c�lculo para encontar o n�mero de pessoas maiores de idade do sexo feminino
		}else if(sexo=='M' && (idade>=18 && idade<=100))
			quantMaioresM=quantMaioresM+1;//relizando o c�lculo para encontar o n�mero de pessoas maiores de idade do sexo masculino
		
	}	
	system("cls");
  
   
   	printf("\nO nome do filme �: %s", filme);//escrevendo na tela o nome do filme
    printf("A quantidade de pessoas do sexo feminino �: %i\n", quantF);//escrevendo na tela a quantidade de pessoas do sexo feminino
    printf("A quantidade de pessoas do sexo masculino �: %i\n", quantM);//escrevendo na tela a quantidade de pessoas do sexo masculino
    
    printf("\nA quantidade de crian�as �: %i\n", quantCria);//escrevendo na tela a quantidade de crina�as
    printf("A quantidade de adolescentes �: %i\n", quantAdol);//escrevendo na tela a quantidade de adolescentes
    printf("A quantidade de adultos �: %i\n", quantAdultos);//escrevendo na tela a quantidade de adultos
    printf("A quantidade de idosos �: %i\n", quantVelhos);//escrevendo na tela a quantidade de idosos
		
   	system("pause");//pausando a tela para o usu�rio apertar qualquer tecla para continuar
	system("cls");//limpeza da tela
	printf("\nA quantidade de Maiores de idade do sexo masculino �: %i\n", quantMaioresM);//escrevendo na tela a quantidade de pessoas maiores de idade do sexo masculino
	printf("A quantidade de Maiores de idade do sexo feminino �: %i", quantMaioresF);//escrevendo na tela a quantidade de pessoas maiores de idade do sexo feminino
	Valorpipoca=15*pessoas;
	printf("\nO pre�o total de pipoca comprada, caso cada um comprasse uma pipoca grande salgada seria: %iR$.", Valorpipoca);
return 0;//retorno da fun��o
}

