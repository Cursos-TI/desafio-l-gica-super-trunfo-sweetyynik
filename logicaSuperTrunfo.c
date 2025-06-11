#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char estado1[3], codigo1[4], nomeCidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;

    // Dados da Carta 2
    char estado2[3], codigo2[4], nomeCidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;

    // Entrada de dados
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (ex: RJ): ");
    scanf(" %2s", estado1);
    printf("Codigo (ex: A01): ");
    scanf(" %3s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("Populacao: ");
    scanf("%lu", &populacao1);
    printf("Area (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (ex: SP): ");
    scanf(" %2s", estado2);
    printf("Codigo (ex: B02): ");
    scanf(" %3s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Populacao: ");
    scanf("%lu", &populacao2);
    printf("Area (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    int op1, op2;
    float valor1_attr1, valor2_attr1, valor1_attr2, valor2_attr2;
    char nomeAttr1[30], nomeAttr2[30];

    // Menu 1
    printf("\nEscolha o 1º atributo para comparacao:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n6 - PIB per capita\n");
    scanf("%d", &op1);

    // Menu 2 (evitando repetição)
    do {
        printf("\nEscolha o 2º atributo (diferente do primeiro):\n");
        printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n6 - PIB per capita\n");
        scanf("%d", &op2);
        if (op2 == op1) printf("Atributo repetido! Escolha outro.\n");
    } while(op2 == op1);

    // Função para obter valor e nome do atributo
    #define GET_ATTR(op, val1, val2, nome) \
        switch(op) { \
            case 1: val1 = populacao1; val2 = populacao2; strcpy(nome, "Populacao"); break; \
            case 2: val1 = area1; val2 = area2; strcpy(nome, "Area"); break; \
            case 3: val1 = pib1; val2 = pib2; strcpy(nome, "PIB"); break; \
            case 4: val1 = pontosTuristicos1; val2 = pontosTuristicos2; strcpy(nome, "Pontos Turisticos"); break; \
            case 5: val1 = densidade1; val2 = densidade2; strcpy(nome, "Densidade Demografica"); break; \
            case 6: val1 = pibPerCapita1; val2 = pibPerCapita2; strcpy(nome, "PIB per capita"); break; \
            default: printf("Opcao invalida!\n"); return 1; \
        }

    // Obter valores e nomes dos atributos
    GET_ATTR(op1, valor1_attr1, valor2_attr1, nomeAttr1);
    GET_ATTR(op2, valor1_attr2, valor2_attr2, nomeAttr2);

    // Lógica de comparação para cada atributo
    int venceu1_attr1 = (op1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    int venceu1_attr2 = (op2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);

    // Soma total (não invertida)
    float soma1 = ((op1 == 5) ? (1 / valor1_attr1) : valor1_attr1) + ((op2 == 5) ? (1 / valor1_attr2) : valor1_attr2);
    float soma2 = ((op1 == 5) ? (1 / valor2_attr1) : valor2_attr1) + ((op2 == 5) ? (1 / valor2_attr2) : valor2_attr2);

    printf("\n--- Comparacao Final ---\n");
    printf("%s vs %s\n", nomeCidade1, nomeCidade2);

    printf("%s:\n", nomeAttr1);
    printf("Carta 1: %.2f | Carta 2: %.2f -> %s venceu\n", valor1_attr1, valor2_attr1,
        venceu1_attr1 ? nomeCidade1 : (valor1_attr1 == valor2_attr1 ? "Empate" : nomeCidade2));

    printf("%s:\n", nomeAttr2);
    printf("Carta 1: %.2f | Carta 2: %.2f -> %s venceu\n", valor1_attr2, valor2_attr2,
        venceu1_attr2 ? nomeCidade1 : (valor1_attr2 == valor2_attr2 ? "Empate" : nomeCidade2));

    printf("\nSoma dos atributos:\nCarta 1: %.2f | Carta 2: %.2f\n", soma1, soma2);

    // Resultado Final
    printf("\nResultado Final: ");
    if (soma1 > soma2) {
        printf("Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
