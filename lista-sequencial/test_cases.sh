#!/bin/bash

# Compilar o programa
make

# Executar o programa
./lista_sequencial > output.txt

# Verificar a saída
if grep -q "Elemento na posição 2: 20" output.txt &&
   grep -q "Elemento na posição 2 após modificação: 25" output.txt &&
   grep -q "Elemento na posição 2 após remoção: 30" output.txt &&
   grep -q "Tamanho da lista: 2" output.txt; then
    echo "Todos os testes passaram."
else
    echo "Algum teste falhou."
fi

# Limpar os arquivos compilados
make clean
