/* Nome:Sávio Fernandes Viiera
   Matrícula:UC21106911
   Curso:Engenharia de Software */
#include <stdio.h>//biblioteca de entrada e saída de dados
#include <locale.h>//biblioteca de linguagem
#include<string.h>//biblioteca de string
#include<ctype.h>//biblioteca de uso de toupper e tolower
#include<stdlib.h>//biblioteca para usar o system"pause"
/*Um cinema de Brasília está interessado em descobrir o perfil das pessoas que frequentam
suas sessões de filmes e para isso, necessita realizar algumas verificações nas informações prestadas. Devem 
ser solicitados a quantidade de sessões que serão realizadas, o nome do filme, a quantidade de pessoas que 
assistiram o filme, assim como o sexo e a idade. No entanto, para cada um deles, há uma validação que deve ser 
feita:*/

int main()
{
  setlocale(LC_ALL, "Portuguese");
 //declaração de variáveis
 int sess/*sessões*/, pessoas/*número de pessoas que assistiram o filme*/, c;//contador
 char sexo, filme[35];/*nome do filme*/
 char buff[35]; //buffer de leituras
 int quantF=0/*quantidade de pessoas do sexo feminino*/, quantM=0/*quantidade de pessoas do sexo masculino*/,quantMaiorF=0/*maiores de idade feminino*/,quantMaiorM=0;/*maiores de idade masculino*/
 int quantCria=0, quantAdol=0, quantAdultos=0, quantVelhos=0;
 int quantMaioresF=0, quantMaioresM=0;
 int idade, Valorpipoca;//preço da pipoca salgada
 
 printf("\n================== Bem vindo ao cinema de Brasília! ====================");
	 do{
	    
		printf("\nPor favor, informe o número de sessões:");// \n:quebra de linha e solicitação da variável sess
	    scanf("%i", &sess);//atribuição do valor digitado pelo usuário na variável sess
	    if(sess>2 || sess<2){//limitando o número de sessões em 2
	    printf("Número de sessões inválido, por favor tente novamente.\n");}//Condição que limita o número de sessões a 2 sessões
	    else{//senão, continuidade ao código
	    printf("Número de sessões inseridas com sucesso!\n");}/*chave do else*/ }//chave do "do"                                      
	while(sess>2||sess<2);
	 
	do{
	
	   printf("\nPor favor, Informe o nome do filme:");
	   fflush(stdin);//limpeza do buffer da memória
	   fgets(filme,35,stdin);//leitura de string
	   if(strlen(filme)<=2)//limitaç do que o usuário pode digitar
	   printf("Nome inválido, insira o nome corretamente.\n");
	   else//senão
	   printf("Nome encontrado com sucesso!\n");}
	while(strlen(filme)<2);//estrutura de repetição que limita o que o usuário pode digitar
	
	do{
	
	   printf("\nDigite agora o número de pessoas que viram o filme:");
	   scanf("%i", &pessoas);//atribução da variável pessoas
	   fflush(stdin);
	   if(pessoas<10)
	   printf("\nNúmero de pessoas inválido, é necessário pelo menos 10 pessoas.\n");
	   else
	   printf("Número de pessoas inseridos com sucesso!\n");}
	while(pessoas<10);//funciona enquanto o número de pessoas não for maior ou igual a dez

	/*Para cada pessoa que assistiu ao filme deverá ser solicitado e validado o sexo (M - masculino, F -
Feminino) e a idade (de 3 a 100 anos). */
   for(c=0; c<pessoas;c++){	
		do{
		   printf("\nInforme a idade da %d pessoa:", c+1);
		   scanf("%i", &idade);
		   fflush(stdin);
		   if(idade<3 || idade>100)//Limitando a idade que o usuário pode botar
		   printf("Só são permitidas pessoas com 3 a 100 anos.");
		   
		    if(idade>=3 && idade<=13){//especificando a classe das crianças
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
			
		}while(idade<3 || idade>100);//estrutura de repetição while que impede o usuário de sair do loop caso digite algo dentro da condição

		do{
			
		   printf("Informe o sexo da %d pessoa, F para feminino e M para masculino:", c+1);//c+1 para começar a contagem do 1
		   fflush(stdin);
		   scanf("%c", &sexo);//atribuição da variável sexo
		   sexo=toupper(sexo);
		   if(sexo=='F'){
		   		quantF=quantF+1;//realizando o calculo de pessoas do sexo feminino
		
		    }else{
				quantM=quantM+1;//realizando o calculo de pessoas do sexo masculino
			}
		
		}while(sexo!='F' && sexo!='M'); printf("\n");//impedindo o usuário de digitar algo que n comece com M ou F
		
		if(sexo=='F' && (idade>=18 && idade<=100)){
			quantMaioresF=quantMaioresF+1;//relizando o cálculo para encontar o número de pessoas maiores de idade do sexo feminino
		}else if(sexo=='M' && (idade>=18 && idade<=100))
			quantMaioresM=quantMaioresM+1;//relizando o cálculo para encontar o número de pessoas maiores de idade do sexo masculino
		
	}	
	system("cls");
  
   
   	printf("\nO nome do filme é: %s", filme);//escrevendo na tela o nome do filme
    printf("A quantidade de pessoas do sexo feminino é: %i\n", quantF);//escrevendo na tela a quantidade de pessoas do sexo feminino
    printf("A quantidade de pessoas do sexo masculino é: %i\n", quantM);//escrevendo na tela a quantidade de pessoas do sexo masculino
    
    printf("\nA quantidade de crianças é: %i\n", quantCria);//escrevendo na tela a quantidade de crinaças
    printf("A quantidade de adolescentes é: %i\n", quantAdol);//escrevendo na tela a quantidade de adolescentes
    printf("A quantidade de adultos é: %i\n", quantAdultos);//escrevendo na tela a quantidade de adultos
    printf("A quantidade de idosos é: %i\n", quantVelhos);//escrevendo na tela a quantidade de idosos
		
   	system("pause");//pausando a tela para o usuário apertar qualquer tecla para continuar
	system("cls");//limpeza da tela
	printf("\nA quantidade de Maiores de idade do sexo masculino é: %i\n", quantMaioresM);//escrevendo na tela a quantidade de pessoas maiores de idade do sexo masculino
	printf("A quantidade de Maiores de idade do sexo feminino é: %i", quantMaioresF);//escrevendo na tela a quantidade de pessoas maiores de idade do sexo feminino
	Valorpipoca=15*pessoas;
	printf("\nO preço total de pipoca comprada, caso cada um comprasse uma pipoca grande salgada seria: %iR$.", Valorpipoca);
return 0;//retorno da função
}

