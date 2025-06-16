#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[50];
    char cidade[50];
    char codigo[50];
    int populacao;
    int turisticos;
    float pib;
    float km;
    float densidade;
} Carta;

// Função para exibir o menu de atributos
void exibirMenu(int atributoExcluido) {
    printf("\n=== Escolha o atributo ===\n");
    int opcao = 1;
    if (atributoExcluido != 1) printf("%d. População\n", opcao++);
    if (atributoExcluido != 2) printf("%d. Área (km²)\n", opcao++);
    if (atributoExcluido != 3) printf("%d. PIB\n", opcao++);
    if (atributoExcluido != 4) printf("%d. Pontos turísticos\n", opcao++);
    if (atributoExcluido != 5) printf("%d. Densidade demográfica\n", opcao);
    printf("Digite sua opção: ");
}

// Função para obter o valor do atributo selecionado
float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.km;
        case 3: return carta.pib;
        case 4: return (float)carta.turisticos;
        case 5: return carta.densidade;
        default: return 0;
    }
}

// Função para obter o nome do atributo
const char* obterNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área (km²)";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade demográfica";
        default: return "Desconhecido";
    }
}

// Função para exibir o resultado da comparação
void exibirResultado(Carta carta1, Carta carta2, int attr1, int attr2, float valor1_attr1, float valor2_attr1, float valor1_attr2, float valor2_attr2) {
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\n=== Resultado da Comparação ===\n");
    printf("Carta 1 - Estado: %s, Cidade: %s\n", carta1.estado, carta1.cidade);
    printf("Carta 2 - Estado: %s, Cidade: %s\n", carta2.estado, carta2.cidade);
    printf("\nAtributo 1: %s\n", obterNomeAtributo(attr1));
    printf("Carta 1: %.2f\n", valor1_attr1);
    printf("Carta 2: %.2f\n", valor2_attr1);
    printf("%s: %s\n", obterNomeAtributo(attr1), 
           (attr1 == 5 ? (valor1_attr1 < valor2_attr1 && valor1_attr1 > 0 ? carta1.estado : valor2_attr1 < valor1_attr1 && valor2_attr1 > 0 ? carta2.estado : "Empate") :
                          (valor1_attr1 > valor2_attr1 ? carta1.estado : valor2_attr1 > valor1_attr1 ? carta2.estado : "Empate")));
    printf("\nAtributo 2: %s\n", obterNomeAtributo(attr2));
    printf("Carta 1: %.2f\n", valor1_attr2);
    printf("Carta 2: %.2f\n", valor2_attr2);
    printf("%s: %s\n", obterNomeAtributo(attr2), 
           (attr2 == 5 ? (valor1_attr2 < valor2_attr2 && valor1_attr2 > 0 ? carta1.estado : valor2_attr2 < valor1_attr2 && valor2_attr2 > 0 ? carta2.estado : "Empate") :
                          (valor1_attr2 > valor2_attr2 ? carta1.estado : valor2_attr2 > valor1_attr2 ? carta2.estado : "Empate")));
    printf("\nSoma dos atributos:\n");
    printf("Carta 1: %.2f\n", soma1);
    printf("Carta 2: %.2f\n", soma2);
    printf("\nResultado final: %s\n", soma1 > soma2 ? carta1.estado : soma2 > soma1 ? carta2.estado : "Empate!");
}

int main() {
    Carta carta1, carta2;
    int attr1, attr2, opcao;
    int maxOpcao;

    // Entrada de dados - Carta 1
    printf("=== Carta 1 ===\n");
    printf("Digite o nome do estado: ");
    scanf("%49s", carta1.estado);
    printf("Digite o nome da cidade: ");
    scanf("%49s", carta1.cidade);
    printf("Digite o código da cidade: ");
    scanf("%49s", carta1.codigo);
    printf("Digite a quantidade da população: ");
    scanf("%d", &carta1.populacao);
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta1.turisticos);
    printf("Digite o valor do PIB: ");
    scanf("%f", &carta1.pib);
    printf("Digite o tamanho da área em km²: ");
    scanf("%f", &carta1.km);

    // Entrada de dados - Carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Digite o nome do estado: ");
    scanf("%49s", carta2.estado);
    printf("Digite o nome da cidade: ");
    scanf("%49s", carta2.cidade);
    printf("Digite o código da cidade: ");
    scanf("%49s", carta2.codigo);
    printf("Digite a quantidade da população: ");
    scanf("%d", &carta2.populacao);
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta2.turisticos);
    printf("Digite o valor do PIB: ");
    scanf("%f", &carta2.pib);
    printf("Digite o tamanho da área em km²: ");
    scanf("%f", &carta2.km);

    // Cálculo da densidade demográfica
    carta1.densidade = (carta1.km > 0) ? (float)carta1.populacao / carta1.km : 0;
    carta2.densidade = (carta2.km > 0) ? (float)carta2.populacao / carta2.km : 0;

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        scanf("%d", &opcao);
        maxOpcao = 5;
        switch (opcao) {
            case 1: attr1 = 1; break;
            case 2: attr1 = 2; break;
            case 3: attr1 = 3; break;
            case 4: attr1 = 4; break;
            case 5: attr1 = 5; break;
            default:
                printf("Opção inválida! Escolha um número entre 1 e %d.\n", maxOpcao);
                attr1 = 0;
        }
    } while (attr1 == 0);

    // Escolha do segundo atributo (excluindo o primeiro)
    do {
        exibirMenu(attr1);
        scanf("%d", &opcao);
        maxOpcao = 4; // Um atributo a menos
        switch (opcao) {
            case 1: attr2 = (attr1 != 1) ? 1 : 0; break;
            case 2: attr2 = (attr1 != 2) ? 2 : 0; break;
            case 3: attr2 = (attr1 != 3) ? 3 : 0; break;
            case 4: attr2 = (attr1 != 4) ? 4 : 0; break;
            case 5: attr2 = (attr1 != 5) ? 5 : 0; break;
            default:
                printf("Opção inválida! Escolha um número entre 1 e %d.\n", maxOpcao);
                attr2 = 0;
        }
        if (attr2 == 0 && opcao <= maxOpcao) {
            printf("Atributo já selecionado! Escolha outro.\n");
        }
    } while (attr2 == 0);

    // Obter valores dos atributos selecionados
    float valor1_attr1 = obterValorAtributo(carta1, attr1);
    float valor2_attr1 = obterValorAtributo(carta2, attr1);
    float valor1_attr2 = obterValorAtributo(carta1, attr2);
    float valor2_attr2 = obterValorAtributo(carta2, attr2);

    // Exibir resultado
    exibirResultado(carta1, carta2, attr1, attr2, valor1_attr1, valor2_attr1, valor1_attr2, valor2_attr2);

    return 0;
}