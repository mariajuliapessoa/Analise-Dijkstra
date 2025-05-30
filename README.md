# Análise de Complexidade: Algoritmo de Dijkstra em C e Python

Este projeto foi desenvolvido como parte da disciplina de **Teoria da Computação** (Professores Pâmela e Daniel) e tem como objetivo analisar o desempenho do algoritmo de Dijkstra implementado em duas linguagens distintas: **C** e **Python**.

## Objetivo

- Estudar a complexidade teórica do algoritmo de Dijkstra.
- Comparar o desempenho prático entre as linguagens C e Python.
- Gerar gráficos e tabelas com base em simulações reais e sintéticas.

## Conteúdo do Projeto

- `main.c`: Implementação em C.
- `exemplo_dijkstra.py`: Implementação em Python.
- `results/`: Gráficos, tabelas e dados coletados.

## Metodologia

- Foram criados grafos de diferentes tamanhos e densidades.
- Cada entrada foi executada **20 vezes** para obter **tempo médio e desvio padrão**.
- A análise comparativa foi feita com base nos tempos de execução medidos e na complexidade teórica esperada (O((V + E) log V)).

## Como executar

Claro, aqui está a seção "Como executar" em texto plano, sem emojis:

---

### Como Executar

#### C (via CLion ou terminal)

Pré-requisitos:

* CLion instalado (ou apenas um compilador GCC como `gcc` via terminal).
* Projeto criado em CLion ou com os arquivos `.c` e `.h` no diretório `c/`.

Via CLion:

1. Abra o projeto no CLion.
2. Certifique-se de que o arquivo `main.c` está configurado como ponto de entrada.
3. Clique em "Run" ou pressione `Shift + F10`.

Via terminal (Linux, Mac ou WSL):

```bash
gcc -o dijkstra main.c -O2 -lm
./dijkstra
```

Para Windows, você pode usar o terminal Git Bash ou o PowerShell com o MinGW instalado. O comando será semelhante.

#### Python (via VSCode, terminal ou Google Colab)

Pré-requisitos:

* Python 3.8 ou superior instalado.
* Bibliotecas necessárias: `networkx`, `matplotlib`, `pandas`, `seaborn`, `numpy`.

Instale as dependências:

```bash
pip install -r py/requirements.txt
```

Execute o script:

```bash
python main.py
```

Via VSCode:

1. Abra o arquivo `exemplo_dijkstra.py` no VSCode.
2. Selecione um interpretador Python válido.
3. Execute o script pressionando `F5` ou clicando em "Run".

Via Google Colab:

1. Abra o notebook `Dijkstra.ipynb`.
2. Execute célula por célula para reproduzir os experimentos e visualizar os gráficos.

## Equipe

- Kaique Alves
  
- Lucca Gomes

- Maria Júlia Pessoa
