# Análise de Complexidade: Algoritmo de Dijkstra em C e JavaScript

Este projeto foi desenvolvido como parte da disciplina de **Teoria da Computação** (Professores Pâmela e Daniel) e tem como objetivo analisar o desempenho do algoritmo de Dijkstra implementado em duas linguagens distintas: **C** e **JavaScript**.

## Objetivo

- Estudar a complexidade teórica do algoritmo de Dijkstra.
- Comparar o desempenho prático entre as linguagens C e JavaScript.
- Discutir a aplicabilidade e limitações do algoritmo.
- Gerar gráficos e tabelas com base em simulações reais e sintéticas.

## Conteúdo do Projeto

- `c/`: Implementação em C.
- `js/`: Implementação em JavaScript.
- `data/`: Scripts e exemplos de entrada (geradores de grafos).
- `results/`: Gráficos, tabelas e dados coletados.
- `report.pdf`: Relatório final completo.
- `presentation.pdf`: Apresentação de 7 minutos.

## Metodologia

- Foram criados grafos de diferentes tamanhos e densidades (pequeno, médio, grande).
- Cada entrada foi executada entre **15 e 30 vezes** para obter **tempo médio e desvio padrão**.
- A análise comparativa foi feita com base nos tempos de execução medidos e na complexidade teórica esperada (O((V + E) log V)).

## Resultados

- Os tempos de execução mostraram diferença significativa entre C (compilado) e JavaScript (interpretado).
- A complexidade observada se manteve próxima da prevista teoricamente para os casos testados.
- Os gráficos comparam tempo vs número de vértices, além da sobreposição com as curvas teóricas.

## Temas abordados

- Complexidade Assintótica: O, Ω e Θ
- Análise de melhor, pior e caso médio
- Classe de complexidade (P vs NP)
- Aplicabilidade prática e limitações do algoritmo de Dijkstra

## Como executar

### C

```bash
cd c/
gcc dijkstra.c -o dijkstra
./dijkstra input.txt
cd js/
node dijkstra.js input.json
```

## Equipe
Kaique Alves
Lucca Gomes
Maria Júlia Pessoa
