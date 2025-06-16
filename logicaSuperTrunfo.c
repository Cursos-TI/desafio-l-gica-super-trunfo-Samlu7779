#include <stdio.h>
#include <string.h>

int main() {
    // Declaração das variáveis para as duas cartas
    char estado1[50], cidade1[50], codigo1[50];
    int turisticos1, populacao1;
    float pib1, km1;
    
    char estado2[50], cidade2[50], codigo2[50];
    int turisticos2, populacao2;
    float pib2, km2;
    
    int opcao;
    float densidade1, densidade2;

    // Entrada de dados - Carta 1
    printf("=== Carta 1 ===\n");
    printf("Digite o nome do estado:\n");
    scanf("%49s", estado1);
    printf("Digite o nome da cidade:\n");
    scanf("%49s", cidade1);
    printf("Digite o código da cidade:\n");
    scanf("%49s", codigo1);
    printf("Digite a quantidade da população:\n");
    scanf("%d", &populacao1);
    printf("Digite a quantidade de pontos turísticos:\n");
    scanf("%d", &turisticos1);
    printf("Digite o valor do PIB:\n");
    scanf("%f", &pib1);
    printf("Digite o tamanho da área em km²:\n");
    scanf("%f", &km1);

    // Entrada de dados - Carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Digite o nome do estado:\n");
    scanf("%49s", estado2);
    printf("Digite o nome da cidade:\n");
    scanf("%49s", cidade2);
    printf("Digite o código da cidade:\n");
    scanf("%49s", codigo2);
    printf("Digite a quantidade da população:\n");
    scanf("%d", &populacao2);
    printf("Digite a quantidade de pontos turísticos:\n");
    scanf("%d", &turisticos2);
    printf("Digite o valor do PIB:\n");
    scanf("%f", &pib2);
    printf("Digite o tamanho da área em km²:\n");
    scanf("%f", &km2);

    // Cálculo da densidade demográfica
    densidade1 = (km1 > 0) ? (float)populacao1 / km1 : 0;
    densidade2 = (km2 > 0) ? (float)populacao2 / km2 : 0;

    // Menu 
    printf("\n=== Escolha o atributo para comparação ===\n");
    printf("1. População\n");
    printf("2. Área (km²)\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &opcao);

    //  cartas
    printf("\n=== Comparação ===\n");
    printf("Carta 1 - Estado: %s, Cidade: %s\n", estado1, cidade1);
    printf("Carta 2 - Estado: %s, Cidade: %s\n", estado2, cidade2);

    //  comparação 
    switch (opcao) {
        case 1: // População
            printf("\nAtributo: População\n");
            printf("Carta 1: %d\n", populacao1);
            printf("Carta 2: %d\n", populacao2);
            if (populacao1 > populacao2) {
                printf("%s venceu!\n", estado1);
            } else if (populacao2 > populacao1) {
                printf("%s venceu!\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("\nAtributo: Área\n");
            printf("Carta 1: %.2f km²\n", km1);
            printf("Carta 2: %.2f km²\n", km2);
            if (km1 > km2) {
                printf("%s venceu!\n", estado1);
            } else if (km2 > km1) {
                printf("%s venceu!\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("\nAtributo: PIB\n");
            printf("Carta 1: %.2f\n", pib1);
            printf("Carta 2: %.2f\n", pib2);
            if (pib1 > pib2) {
                printf("%s venceu!\n", estado1);
            } else if (pib2 > pib1) {
                printf("%s venceu!\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("\nAtributo: Pontos turísticos\n");
            printf("Carta 1: %d\n", turisticos1);
            printf("Carta 2: %d\n", turisticos2);
            if (turisticos1 > turisticos2) {
                printf("%s venceu!\n", estado1);
            } else if (turisticos2 > turisticos1) {
                printf("%s venceu!\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade demográfica 
            printf("\nAtributo: Densidade demográfica\n");
            printf("Carta 1: %.2f hab/km²\n", densidade1);
            printf("Carta 2: %.2f hab/km²\n", densidade2);
            if (densidade1 < densidade2 && densidade1 > 0) {
                printf("%s venceu!\n", estado1);
            } else if (densidade2 < densidade1 && densidade2 > 0) {
                printf("%s venceu!\n", estado2);
            } else if (densidade1 == densidade2 || (densidade1 == 0 && densidade2 == 0)) {
                printf("Empate!\n");
            } else {
                printf("Comparação inválida (área zero detectada)!\n");
            }
            break;

        default:
            printf("\nOpção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    return 0;
}