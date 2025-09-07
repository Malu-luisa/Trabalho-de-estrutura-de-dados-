📌 Descrição

Este projeto implementa a multiplicação de matrizes em linguagem C, utilizando funções recursivas para calcular o produto escalar entre linhas e colunas.
O programa suporta preenchimento manual ou geração aleatória das matrizes, além de utilizar alocação dinâmica de memória.

🚀 Funcionalidades

Multiplicação de duas matrizes A (m x n) e B (n x r).

Uso de recursão para calcular cada elemento da matriz resultante C (m x r).

Preenchimento das matrizes de duas formas:

Manual: usuário digita os valores.

Automática: valores aleatórios entre 0 e 9.

Exibição formatada das matrizes no terminal.

Liberação correta da memória com free().

🛠️ Tecnologias Utilizadas

Linguagem: C

Bibliotecas:

stdio.h → entrada e saída

stdlib.h → alocação dinâmica

time.h → geração de números aleatórios

📂 Estrutura do Código

produto_escalar_recursivo → calcula recursivamente o produto escalar entre linha e coluna.

calcular_matriz → percorre as posições da matriz C e chama a função recursiva.

exibir_matriz → imprime a matriz de forma tabular.

preencher_matriz → preenche manualmente ou aleatoriamente a matriz.

main → organiza o fluxo principal do programa.
