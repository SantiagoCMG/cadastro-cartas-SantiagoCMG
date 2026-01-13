  #include <stdio.h>

  // Desafio Super Trunfo - Países
  // Tema 1 - Cadastro das cartas
  // Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

  int main() {
    struct Carta {
      char estado;
      char codigo[4];
      char nomeCidade[50];
      int populacao;
      float area;
      float pib;
      int pontosTuristicos;
    };
    struct Carta carta1 = {
      'A',
      "A01",
      "São Paulo",
      12325000,
      1521.11,
      699.28,
      50
  };

    struct Carta carta2 = {
      'B',
      "B02",
      "Rio de Janeiro",
      6748000,
      1200.25,
      300.50,
      30
  };
//

  return 0;
  }
