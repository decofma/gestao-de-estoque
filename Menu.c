#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

#define MAX 100

int defineVersao(){
	printf("versao: 0.02");
};

int cont;

struct cadastra{
    int estoque;
    char descricao[30];
    char codigo[6];
    char nome[30];
    float preco;
};

struct cadastra cad[MAX];
int quantp=0;

void cadastraProduto(struct cadastra produto){
    cad[quantp]=produto;
    quantp++;
}

struct cadastra leDados(){
    char xx,qp[10];
    int w,i,c;
    do{
        xx='n';
        fflush(stdin);
        printf("Digite o nome do produto: \n");
        scanf("%s",cad[quantp].nome);
        printf("Digite o codigo do produto: \n");
        scanf("%s",cad[quantp].codigo);
        printf("Digite a descricao do produto: \n");
        scanf("%s",cad[quantp].descricao);
        do{
            c=0;w=0;
            fflush(stdin);
            printf("Quantide de produtos para o estoque\n");
            scanf("%s",&qp);
            if(c==0)
                cad[quantp].estoque = atoi(qp);
            else {
                printf("Isso Nao eh Numero, Digite Certo.\n");
                w=1;
            }
        }while( w );
        fflush(stdin);
        w=1;
        do{
            w=0;c=0;
            fflush(stdin);
            printf("Digite o preco do produto\n");
            scanf("%s",&qp);
            if(c==0)
                cad[quantp].preco = atoi(qp);
            else {
                printf("Isso Nao eh Numero, Digite Certo.\n");
                w=1;
            }
        }while( w );
        fflush(stdin);
        quantp++;
        printf("Quer Cadastrar Outro Produto  S/N   e nao precisa de enter\n\n");
        xx=getch();
    }while(xx=='s');
    system("CLS");
}

void buscar(){
    int i,opica;
    char nome[30];
        do{
            printf("MENU DE BUSCA\n");
            printf("1- Mostrar lista de produtos\n");
            printf("2- Buscar pelo nome produto\n");;
            printf("3- Sair do menu busca\n");
            printf("Digite o numero da opicao desejada \n");
            scanf("%d",&opica);
            system("CLS");
            switch(opica){
                case 1:
                    printf("Lista de produtos cadastrados\n");
                    for(i=0;i<quantp;i++){
                        printf("Produto %d \n",i+1);
                        printf("+++++++++++++++++++++++\n");
                        printf("Nome do produto:       %s\n",cad[i].nome);
                        printf("Codigo do produto:     %s\n",cad[i].codigo);
                        printf("Descricao do produto:  %s\n",cad[i].descricao);
                        printf("Quantidade no estoque:    %d\n",cad[i].estoque);
                        printf("Preco do produto:      %.2f\n",cad[i].preco);
                        printf("+++++++++++++++++++++++\n");
                    }
                    break;
                case 2:
                    printf("Digite o nome do produto\n");
                    scanf("%s",&nome);
                    for(i=0;i<quantp;i++){
                        if(strcmp (nome, cad[i].nome) == 0) {
                            printf("+++++++++++++++++++++++\n");
	                        printf("Nome do produto:       %s\n",cad[i].nome);
	                        printf("Codigo do produto:     %s\n",cad[i].codigo);
	                        printf("Descricao do produto:  %s\n",cad[i].descricao);
	                        printf("Quantidade no estoque:    %d\n",cad[i].estoque);
	                        printf("Preco do produto:      %.2f\n",cad[i].preco);
	                        printf("+++++++++++++++++++++++\n");
                        }
                    }
                    break;
                case 3:
                    break;
            }
        }while(opica!=3);
        system("CLS");
}

void remover () {
	int i,j,cont=0;
	int codigo_busc;
	printf("veja numero do produto que você deseja remover\n");
	buscar();                   // Chama a função listar para que seja visto qual codigo relacionado ao produto
	printf("Informe o Codigo do Produto que se Deseja Excluir: "); // Pede o codigo para busca
	scanf("%i",&codigo_busc);
	for(i = 0 ; i < quantp ; i++){
		if (cad[i].codigo == codigo_busc) {  // Compara o codigo relacionado e exclui
                    for(j=i;j<quantp;j++){
			    cad[j] = cad[j+1];                // Realoca a Memória
                    }
                    quantp--;                         // decrementa o indice do vetor para que ocupe o cadastro removido
                    cont++;
                    break;
		}
	}
	if(cont>0){
        printf ("\n\nPRODUTO EXCLUIDO COM SUCESSO !");
        printf ("\nPressione ENTER Para Continuar !");
        setbuf(stdin,NULL);
        getchar ();
        system ("cls");
    }else {
        printf("Esse numero de codigo nao existe\n");
    }
}

int menu_principal_opcoes(){
	int opcao;
	system("cls");
	defineVersao();
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Sair");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;
}

int menu_gerenciar_produto_opcoes(){
	int opcao;
	system("cls");	
	printf("\n######################");
	printf("\nGerenciar Produto");
	printf("\n######################\n");
	printf("\n(1) Incluir");
	printf("\n(2) Alterar");
	printf("\n(3) Excluir");
	printf("\n(4) Consultar");
	printf("\n(5) Listar");
	printf("\n(6) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;

}

int menu_gerenciar_pedido_opcoes(){
	int opcao;
	struct cadastra novoProduto;
	system("cls");	
	printf("\n######################");
	printf("\nGerenciar Pedido");
	printf("\n######################\n");	
	printf("\n(1) Adicionar produto no carrinho");
	printf("\n(2) Consultar carrinho de compras");
	printf("\n(3) Excluir produto do carrinho");
	printf("\n(4) Alterar quantidade do produto do carrinho");	
	printf("\n(5) Finalizar Pedido");	
	printf("\n(6) Esvaziar carrinho de compras");
	printf("\n(7) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;
}

void gerenciar_menu_produto(){
	int opcao;
	struct cadastra novoProduto;
	do{	
		opcao = menu_gerenciar_produto_opcoes();		
		switch(opcao){
			case 1:
				novoProduto=leDados();
				break;
			case 2:
				printf("Alterar Produto");
				break;								
			case 3:
				remover();
				break;
			case 4:
				printf("Consultar Produto");				
				getch();
				break;
			case 5:
				printf("Listar Produto");
				getch();
				break;								
			case 6:
				printf("Voltar");
				break;
			default:
				printf("Opcao Invalida!");
				getch();		
		}
	}while(opcao != 6);
	
}

void gerenciar_menu_pedido(){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_pedido_opcoes();		
		switch(opcao){
			case 1:
				printf("Adicionar produto no carrinho");				
				getch();
				break;
			case 2:
				printf("Consultar carrinho de compras");
				getch();
				break;								
			case 3:
				printf("Excluir produto do carrinho");
				sair = 1;
				break;
			case 4:
				printf("Alterar quantidade do produto do carrinho");				
				getch();
				break;
			case 5:
				printf("Finalizar Pedido");
				getch();
				break;								
			case 6:
				printf("Esvaziar carrinho de compras");
				getch();
				break;								
			case 7:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

void gerenciar_menu_principal(){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_principal_opcoes();		
		switch(opcao){
			case 1:				
				gerenciar_menu_produto();
				getch();
				break;
			case 2:			
				gerenciar_menu_pedido();
				getch();
				break;								
			case 3:
				printf("Sair");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

int main(int argc, char *argv[]) {
	gerenciar_menu_principal();	
	return 0;
}

