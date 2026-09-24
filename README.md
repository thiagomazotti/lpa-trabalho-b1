# Trabalho B1 - Lógica de Programação e Algoritmos

**Aluno(a):** [SEU NOME]
**Disciplina:** Lógica de Programação e Algoritmos — 1º bimestre

## Descrição

Programa em C, executado em terminal, que simula o cálculo do valor de entregas locais
de uma empresa fictícia. Para cada entrega, o usuário informa distância, peso,
modalidade, serviço de proteção e tentativas adicionais. O programa valida os dados,
calcula e mostra o valor final. Ao encerrar a sessão, apresenta um resumo.

## Funcionalidades

- Processamento de várias entregas na mesma execução.
- Validação de distância (> 0), peso (> 0), modalidade (1 a 3), proteção (0 ou 1),
  tentativas adicionais (inteiro >= 0) e opção de continuar (0 ou 1).
- Cálculo do valor-base por faixa de distância mais R$ 1,20 por km.
- Adicionais de peso e de modalidade, ambos sobre o subtotal inicial.
- Proteção (R$ 7,50) e tentativas adicionais (R$ 4,00 cada).
- Resumo final: quantidade, total, média, quantidade por modalidade, maior e menor valor.

## Organização da solução

- `ler_distancia`, `ler_peso`, `ler_modalidade`, `ler_protecao`,
  `ler_tentativas_adicionais`, `ler_continuar`: leem e validam cada dado com `do-while`
  e retornam o valor válido.
- `valor_base_distancia`: recebe a distância e retorna o valor-base da faixa.
- `percentual_peso` e `percentual_modalidade`: retornam o percentual de adicional.
- `calcular_valor_final`: recebe os dados da entrega e retorna o valor final.
- `exibir_resumo`: imprime o resumo da sessão a partir dos contadores e acumuladores.
- `main`: coordena o laço principal e atualiza contadores, acumuladores, maior e menor valor.

## Compilação

```
gcc -Wall -Wextra -o simulador src/main.c
```

## Execução

```
./simulador
```

## Uso de Inteligência Artificial

[PREENCHA COM SINCERIDADE. O roteiro exige: ferramenta utilizada; finalidade; exemplos
dos prompts relevantes; quais sugestões foram aproveitadas; quais alterações ou
correções você fez depois.]

Exemplo de estrutura:
- Ferramenta: Claude (Anthropic).
- Finalidade: [ex.: gerar uma versão inicial do programa e explicar a lógica].
- Prompts relevantes: [cole aqui os seus].
- Sugestões aproveitadas: [ex.: divisão em funções, uso de do-while nas validações].
- Alterações feitas por mim: [descreva o que você mudou ou corrigiu].

## Fontes consultadas

Roteiro do trabalho fornecido pela professora.
