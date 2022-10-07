#include <stdio.h>
#include <stdlib.h>

struct produto
{
	int cod, qtde;
	float valor;
	char nome[30];
};

int main()
{
	int n, redim, i, pos;
	float maiorPreco;
	struct produto *f1;
	char op;
	
	printf("Digite a quantidade de produtos a serem cadastrados: ");
	scanf("%d", &n); 
	
	f1 = (struct produto*) malloc(n * sizeof(struct produto));
	for(i = 0; i < n; i++){
		
		printf("\n DADOS DO PRODUTO %d", i + 1);
		
		printf("\n Digite o nome do produto: ");
		scanf("%s", f1[i].nome);
		
		printf("\n Digite o valor do produto R$: ");
		scanf("%f", &f1[i].valor);
		
		printf("\n Digite o codigo do produto: ");
		scanf("%d", &f1[i].cod);
		
		printf("\n Digite a quantidade do produto: ");
		scanf("%d", &f1[i].qtde);
	}
		
	printf("\n Deseja alterar a quantidade de produtos? (s/n) ");
	scanf(" %c", &op);
	
	if(op == 's' || op == 'S')
	{
		printf("\n Digite um nro positivo OU negativo para a nova quantidade de produtos que deseja incluir OU excluir ");
		scanf("%d", &redim);
		if(n + redim == 0)
		{
			printf(" Nao sobrou produto cadastrado! ");
			exit(1);
		}
		else if(n + redim < 0)
		{
			printf(" ERRO ");
		}
		else // Redimensionar o vetor
		{
			f1 = (struct produto *) realloc(f1, (n + redim) * sizeof(struct produto));
			if(redim > 0)
			{
				for(i = n; i < (n + redim); i++)
				{
						printf("\n DADOS DO PRODUTO %d", i + 1);
			
 						printf("\n Digite o nome do produto: ");
						scanf("%s", f1[i].nome);
		
						printf("\n Digite o valor do produto R$: ");
						scanf("%f", &f1[i].valor);
		
						printf("\n Digite o codigo do produto: ");
						scanf("%d", &f1[i].cod);
		
						printf("\n Digite a quantidade do produto: ");
						scanf("%d", &f1[i].qtde);
				}
                n = n+redim;
				
	   	   }  
 	   }	
   }
	
	maiorPreco = f1[0].valor;
	pos = 0;
	
	for(i = 1; i < n; i++){
		if(f1[i].valor > maiorPreco){
				maiorPreco = f1[i].valor;
				pos = i;
		}
	}
	printf("\nO maior preco foi R$ %.2f ~ O produto e: %s ", maiorPreco, f1[pos].nome);
	
	
	return 0;
}