#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_CARTAS 32

typedef struct {
    char nome[50];
    char codigo[4];        // Ex: A01 até H04
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    // Propriedades calculadas
    float densidade;
    float pibPerCapita;
} Carta;

/* ================= VALIDA CODIGO ================= */
int codigoValido(char codigo[]) {
    char estado = codigo[0];
    int cidade = (codigo[1] - '0') * 10 + (codigo[2] - '0');

    if (estado < 'A' || estado > 'H')
        return 0;

    if (cidade < 1 || cidade > 4)
        return 0;

    return 1;
}

/* ================= CADASTRAR CARTA ================= */
void cadastrarCarta(Carta *c) {
    printf("\nNome da cidade: ");
    scanf(" %[^\n]", c->nome);

    do {
        printf("Codigo da carta (A01 ate H04): ");
        scanf("%s", c->codigo);
        c->codigo[0] = toupper(c->codigo[0]);

        if (!codigoValido(c->codigo))
            printf("❌ Codigo invalido! Tente novamente.\n");

    } while (!codigoValido(c->codigo));

    printf("Populacao: ");
    scanf("%d", &c->populacao);

    printf("Area: ");
    scanf("%f", &c->area);

    printf("PIB: ");
    scanf("%f", &c->pib);

    printf("Pontos Turisticos: ");
    scanf("%d", &c->pontosTuristicos);

    // Cálculos automáticos
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

/* ================= EXIBIR CARTA ================= */
void exibirCarta(Carta c, int indice) {
    printf("\n[%d] %s (%s)\n", indice, c.nome, c.codigo);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f\n", c.densidade);
    printf("PIB per Capita: %.6f\n", c.pibPerCapita);
}

/* ================= SUPER PODER ================= */
float superPoder(Carta c) {
    return c.populacao +
           c.area +
           c.pib +
           c.pontosTuristicos +
           c.pibPerCapita -
           c.densidade;
}

/* ================= COMPARAR ================= */
void compararCartas(Carta a, Carta b) {
    printf("\n===== COMPARACAO =====\n");

    printf("Populacao: %s vence\n", (a.populacao > b.populacao) ? a.nome : b.nome);
    printf("Area: %s vence\n", (a.area > b.area) ? a.nome : b.nome);
    printf("PIB: %s vence\n", (a.pib > b.pib) ? a.nome : b.nome);
    printf("Pontos Turisticos: %s vence\n",
           (a.pontosTuristicos > b.pontosTuristicos) ? a.nome : b.nome);
    printf("Densidade: %s vence\n",
           (a.densidade < b.densidade) ? a.nome : b.nome);
    printf("PIB per Capita: %s vence\n",
           (a.pibPerCapita > b.pibPerCapita) ? a.nome : b.nome);

    float spA = superPoder(a);
    float spB = superPoder(b);

    printf("\nSuper Poder:\n");
    printf("%s: %.2f\n", a.nome, spA);
    printf("%s: %.2f\n", b.nome, spB);

    printf("🏆 Vencedor Final: %s\n", (spA > spB) ? a.nome : b.nome);
}

/* ================= MAIN ================= */
int main() {
    Carta cartas[MAX_CARTAS];
    int total = 0, opcao;

    do {
        printf("\n=== SUPER TRUNFO - PAISES ===\n");
        printf("1 - Cadastrar carta\n");
        printf("2 - Listar cartas\n");
        printf("3 - Comparar cartas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1 && total < MAX_CARTAS) {
            cadastrarCarta(&cartas[total]);
            total++;
        }
        else if (opcao == 2) {
            for (int i = 0; i < total; i++)
                exibirCarta(cartas[i], i);
        }
        else if (opcao == 3 && total >= 2) {
            int a, b;
            printf("Escolha a PRIMEIRA carta pelo NUMERO da lista:(ex se voce colo a02 e 2) ");
            scanf("%d", &a);

            printf("Escolha a SEGUNDA carta pelo NUMERO da lista: (ex se voce colo b02 e 2) ");
            scanf("%d", &b);

            if (a >= 0 && a < total && b >= 0 && b < total)
                compararCartas(cartas[a], cartas[b]);
            else
                printf("❌ Indices invalidos!\n");
        }

    } while (opcao != 0);

    return 0;
}
/* então eu ja tinha feito esse projeto no mes pasado (:P por causa que voces liberaram eu so adpatei)
 * ai eu deccidi tbm inves de colocar os dados direto o proprio usuario colocar... motivo? pra o cidigo nao ficar mais longo
 * do que ja tava */