#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//i = numero de doadores cadastrados
//ts = vetor para armazenar o tipo de sangue dos doadores cadastrados(em numeros listados na tabela)
int i=0,ts[30];
//Tabela das estatisticas
int estatisticas[2][8];

struct doadores{
	int rg;
	char sexo;
	char tiposanguineo[3];
	int idade;
};

struct doadores c[30];

void cadastro ();    						//	1
void listadoadores();						//	2
void buscardoadores(int ftiposanguineo);	//	3 
void estatisticasDoadores(); 				//	4
void salvararquivo();						//	5
void femininomasculino(int fm);

int main(){
	//mudando cor
	system("color 4F");
	//zerando matriz das estatisticas
	int l,c;
	
	for(l=0;l<30;l++){
		for(c=0;c<30;c++){
			estatisticas[l][c]=0;
		}
	}
	
	//fts é uma variavel para armazenar o tipo de sangue
	int opcao,sair=0,fts;
	
	setlocale(LC_CTYPE,"ptb");
	
	printf("                _________  \n");
	printf("              _|    _    |_  \n");
	printf("            _|   __| |__   |_  \n");
	printf("           |    |__   __|    | \n");
	printf("           |       |_|       | \n");
	printf("     ______|    BLOODSPOT    |______\n");
	printf("    |  Banco de sangue de Bragança  | \n");
	
	while(sair==0){
		printf("   ____________________________________\n");
		printf("  /______________/Menu/______________ /|\n");
		printf("  |1|Novo cadastro___________________|@|\n");
		printf("  |2|Listar todos doadores___________|@|\n");
		printf("  |3|Buscar doador___________________|@|\n");
		printf("  |4|Exibir Estatísticas_____________|@|\n");
		printf("  |5|Salvar dados em arquivo de texto|@|\n");
		printf("  |6|Sair____________________________|@|\n");
		printf(" /__________________________________/@@| \n");
		printf("/__________________________________/@@@| \n\n");
		printf("|---------------------------------------------------|\n\n");
		printf("  Escolha uma opção: ");	
		scanf("%d",&opcao);	
		
		switch(opcao){
		
			case 1 :
				cadastro();
				printf("\n|---------------------------------------------------|\n\n");
				i++	;
				break;
			case 2 :
				listadoadores();
				printf("|\n---------------------------------------------------|\n\n");
				break;
			case 3 :
				printf(" _____\n");
				printf("|1|A+ |\n");
				printf("|2|A- |\n");
				printf("|3|B+ |\n");
				printf("|4|B- |\n");
				printf("|5|O+ |\n");
				printf("|6|O- |\n");
				printf("|7|AB+|\n");
				printf("|8|AB-|\n\n");
				printf("  Digite o tipo de sangue que deseja buscar: \n");
				scanf("%d",&fts);
				buscardoadores(fts);
				printf("\n|---------------------------------------------------|\n\n");
				break;
			case 4 :
				estatisticasDoadores();
				break;
			case 5 :
				salvararquivo();
				printf("\n  Os arquivos foram salvos com sucesso");
				printf("\n|---------------------------------------------------|\n\n");
				break;
			case 6 :
				sair++;
				printf("\n|---------------------------------------------------|\n\n");
				break;
		}
	}
}

void cadastro (){
	
	//Tabela condições
	//condicao0 RG
	//condicao1 sexo
	//condicao2 TipoSanguineo
	//condicao3 idade
	
	int condicao0=0,condicao1=0,condicao2=0,condicao3=0;
	
	setlocale(LC_CTYPE,"ptb");
	
	printf("\n|---------------------------------------------------|\n\n");
	//lendo RG
	while(condicao0==0){
	printf("  Insira o número do RG: ");
	scanf("%d",&c[i].rg);
	printf("\tConfirme se é seu RG: %d \n\tSe não for digite (0),se for digite (1): ",c[i].rg);
	scanf("%d",&condicao0);
	}
	printf("\n|---------------------------------------------------|\n\n");
	//Lendo sexo
	while(condicao1==0){
		printf("  Digite o sexo (m) para masculino (f) para feminino: ");
		fflush(stdin);
		scanf("%c", &c[i].sexo);
		fflush(stdin);
		if(c[i].sexo=='m'||c[i].sexo=='M'){
			printf("  Seu sexo é : Masculino\n");
			condicao1++;
			estatisticas[1][0]++;
			break;
		}
		if(c[i].sexo=='f'||c[i].sexo=='F'){
			printf("  Seu sexo é : Feminino\n");
			estatisticas[1][1]++;
			break;
		}
		printf("  Sexo invalido Digite novamente\n");
	}
	printf("\n|---------------------------------------------------|\n\n");
	//lendo Tipo Sanguíneo
	while(condicao2==0){
		printf(" _____\n");
		printf("|1|A+ |\n");
		printf("|2|A- |\n");
		printf("|3|B+ |\n");
		printf("|4|B- |\n");
		printf("|5|O+ |\n");
		printf("|6|O- |\n");
		printf("|7|AB+|\n");
		printf("|8|AB-|\n");
		printf("\n|---------------------------------------------------|\n\n");
		printf("  Escolha o tipo sanguíneo: ");
		scanf("%d",&ts[i]);
	
		switch(ts[i]){
			case 1:
				c[i].tiposanguineo[0]='A';
				c[i].tiposanguineo[1]='+';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][0]++;
				break;
			case 2:
				c[i].tiposanguineo[0]='A';
				c[i].tiposanguineo[1]='-';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][1]++;
				break;
			case 3:
				c[i].tiposanguineo[0]='B';
				c[i].tiposanguineo[1]='+';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][2]++;
				break;
			case 4:
				c[i].tiposanguineo[0]='B';
				c[i].tiposanguineo[1]='-';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][3]++;
				break;
			case 5:
				c[i].tiposanguineo[0]='O';
				c[i].tiposanguineo[1]='+';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][4]++;
				break;
			case 6:
				c[i].tiposanguineo[0]='O';
				c[i].tiposanguineo[1]='-';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][5]++;
				break;
			case 7:
				c[i].tiposanguineo[0]='A';
				c[i].tiposanguineo[1]='B';
				c[i].tiposanguineo[2]='+';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][6]++;
				break;
			case 8:
				c[i].tiposanguineo[0]='A';
				c[i].tiposanguineo[1]='B';
				c[i].tiposanguineo[2]='-';
				printf("  Seu tipo sanguíneo é: %s(%d)\n",c[i].tiposanguineo,ts[i]);
				condicao2++;
				estatisticas[0][7]++;
				break;
			default:
				printf("  Tipo de sangue invalido Digite novamente\n");
		}
	}
	printf("\n|---------------------------------------------------|\n\n");
	//lendo idade
	while(condicao3==0){
		int id;
		
		printf("  Digite a idade: ");
		scanf("%d",&c[i].idade);
		if(c[i].idade>=16&&c[i].idade<=69){
			printf("\tConfirme sua idade: %d\n\tSe não for digite (0),se for digite (1): ",c[i].idade);
			scanf("%d",&condicao3);
		}else{
			printf("  Desculpe! O doador deve ter idade maior que 16 anos e menor que 69 anos.");
		}
	}
	printf("\n|---------------------------------------------------|\n\n");
	femininomasculino(i);
}

void listadoadores(){
	int l;
	
	setlocale(LC_CTYPE,"ptb");
	
	for(l=0;l<i;l++){
		printf("\n");
		femininomasculino(l);
	}
}

void buscardoadores(int ftiposanguineo){
	//qtad = quantidade de doadores
	int l,qtad=0;
	
	setlocale(LC_CTYPE,"ptb");
	
	for(l=0;l<i;l++){
		switch(ftiposanguineo){
			case 1:
				if(ts[l]==1){
					femininomasculino(l);
					qtad++;
				}
				break;
			case 2:
				if(ts[l]==2){
					femininomasculino(l);
					qtad++;
				}
				break;
			case 3:
				if(ts[l]==3){
					femininomasculino(l);
					qtad++;
				}
				break;
			case 4:
				if(ts[l]==4){
					femininomasculino(l);
					qtad++;
				}
				break;
			case 5:
				if(ts[l]==5){
					femininomasculino(l);
					qtad++;
				}
				break;
			case 6:
				if(ts[l]==6){
					femininomasculino(l);
					qtad++;
				}
				break;
			case 7:
				if(ts[l]==7){
					femininomasculino(l);
					qtad++;
				}
				break;
			case 8:
				if(ts[l]==8){
					femininomasculino(l);
					qtad++;
				}
				break;
		}
		printf("\n");
	}
	printf("\n  Foram encontrados: %d compativeis",qtad);
}

void estatisticasDoadores(){
	int c;
	printf("\n|---------------------------------------------------|\n\n");
	printf("  Quantidade de doadores: %d\n\n",i);
	printf("  Doadores com o tipo de sangue:\n");
	printf("  A+ : %d\n",estatisticas[0][0]);
	printf("  A- : %d\n",estatisticas[0][1]);
	printf("  B+ : %d\n",estatisticas[0][2]);
	printf("  B- : %d\n",estatisticas[0][3]);
	printf("  O+ : %d\n",estatisticas[0][4]);
	printf("  O- : %d\n",estatisticas[0][5]);
	printf("  AB+: %d\n",estatisticas[0][6]);
	printf("  AB-: %d\n\n",estatisticas[0][7]);
	printf("  Doadores de cada sexo :\n");
	printf("  Mulheres: %d\n",estatisticas[1][1]);
	printf("  Homens: %d\n",estatisticas[1][0]);
	printf("\n|---------------------------------------------------|\n\n");
}

void salvararquivo(){
	
	FILE *arquivo;
	arquivo = fopen("registro_cadastro.txt", "a");
	int l;
	
	setlocale(LC_CTYPE,"ptb");
	
	for(l=0;l<i;l++){
		if(c[l].sexo=='m'||c[l].sexo=='M'){
			fprintf(arquivo,"RG: %d\nSexo: Masculino\nTipo sanguíneo: %s\nIdade: %d\n",c[l].rg,c[l].tiposanguineo,c[l].idade);
		}
		if(c[l].sexo=='f'||c[l].sexo=='F'){
			fprintf(arquivo,"RG: %d\nSexo: Feminino\nTipo sanguíneo: %s\nIdade: %d\n",c[l].rg,c[l].tiposanguineo,c[l].idade);
		}
		fprintf(arquivo,"\n");
	}
	fclose(arquivo);
}

void femininomasculino(int fm){
	if(c[fm].sexo=='m'||c[fm].sexo=='M'){
		printf("  RG: %d\n  Sexo: Masculino\n  Tipo sanguíneo: %s\n  Idade: %d\n",c[fm].rg,c[fm].tiposanguineo,c[fm].idade);
	}
	if(c[fm].sexo=='f'||c[fm].sexo=='F'){
		printf("  RG: %d\n  Sexo: Feminino\n  Tipo sanguíneo: %s\n  Idade: %d\n",c[fm].rg,c[fm].tiposanguineo,c[fm].idade);
	}
}
