/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_PRODUTOS 50

struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

struct Carrinho {
    struct Produto produtos[MAX_PRODUTOS];
    int quantidade;
};

void adicionarProduto(struct Carrinho *carrinho) {
    if ((*carrinho).quantidade < MAX_PRODUTOS) {
        struct Produto novoProduto;
        printf("Digite o código do produto: ");
        scanf("%d", &novoProduto.codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Digite o preço do produto: ");
        scanf("%f", &novoProduto.preco);

        (*carrinho).produtos[(*carrinho).quantidade] = novoProduto;
        (*carrinho).quantidade++;

        printf("Produto adicionado com sucesso!\n");
    } else {
        printf("A capacidade máxima de produtos foi atingida.\n");
    }
}

void listarProdutos(struct Carrinho carrinho) {
    if (carrinho.quantidade == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }

    printf("Produtos no carrinho:\n");
    printf("Código | Nome | Preço\n");
    for (int i = 0; i < carrinho.quantidade; i++) {
        printf("%d | %s | R$ %.2f\n", carrinho.produtos[i].codigo, carrinho.produtos[i].nome, carrinho.produtos[i].preco);
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Adicionar Produto\n");
    printf("2. Listar Produtos no Carrinho\n");
    printf("3. Escolher Forma de Pagamento\n");
    printf("4. Mostrar Dados do Carrinho\n");
    printf("5. Gerar Nota Fiscal\n");
    printf("6. Sair\n");
}

void mostrarNotaFiscal(struct Carrinho carrinho, int formaPagamento) {
    printf("======= Nota Fiscal =======\n");
    printf("Produtos:\n");
    for (int i = 0; i < carrinho.quantidade; i++) {
        printf("Código: %d | Nome: %s | Preço: R$ %.2f\n", carrinho.produtos[i].codigo, carrinho.produtos[i].nome, carrinho.produtos[i].preco);
    }
    printf("\nTotal de Produtos: %d\n", carrinho.quantidade);

    printf("\nForma de Pagamento: ");
    if (formaPagamento == 1) {
        printf("Cartão\n");
    } else if (formaPagamento == 2) {
        printf("Dinheiro\n");
    } else {
        printf("Não definida\n");
    }
    printf("==========================\n");
}

int main() {
    struct Carrinho meuCarrinho = { .quantidade = 0 };
    int formaPagamento = 0; 

    int escolha;
    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarProduto(&meuCarrinho);
                break;
            case 2:
                listarProdutos(meuCarrinho);
                break;
            case 3:
                printf("Escolha a forma de pagamento (1 - Cartão, 2 - Dinheiro): ");
                scanf("%d", &formaPagamento);
                if (formaPagamento != 1 && formaPagamento != 2) {
                    printf("Opção inválida.\n");
                    formaPagamento = 0;
                } else {
                    printf("Forma de pagamento escolhida com sucesso!\n");
                }
                break;
            case 4:
                printf("Forma de pagamento escolhida: ");
                if (formaPagamento == 1) {
                    printf("Cartão\n");
                } else if (formaPagamento == 2) {
                    printf("Dinheiro\n");
                } else {
                    printf("Não escolhida\n");
                }
                listarProdutos(meuCarrinho);
                break;
            case 5:
                if (meuCarrinho.quantidade == 0 || formaPagamento == 0) {
                    printf("Erro! Carrinho vazio ou forma de pagamento não definida.\n");
                } else {
                    mostrarNotaFiscal(meuCarrinho, formaPagamento);
                    printf("Compra confirmada! Obrigado pela compra!\n");
                    meuCarrinho.quantidade = 0;
                    formaPagamento = 0;
                }
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}
