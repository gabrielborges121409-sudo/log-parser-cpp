[README.md](https://github.com/user-attachments/files/29168232/README.md)
# Analisador de Logs & Analytics em C++

Este é um sistema desenvolvido em **C++17** projetado para ler, processar e analisar arquivos de log de servidores de forma extremamente rápida. O software possui um modelo modular (separando arquivos de cabeçalho `.hpp` e implementações `.cpp`) para garantir organização e desenvolvimento.

##  Funcionalidades do Sistema
* **Leitura e Parsing Avançado:** Varre arquivos de log complexos utilizando `std::stringstream` para recortar delimitadores.
* **Filtro de Erros Críticos:** Separa e exibe em tempo real logs do tipo `ERROR`.
* **Módulo de Analytics:** Calcula o tempo médio de resposta de todo o ecossistema.
* **Detecção de Gargalos:** Identifica automaticamente qual serviço causou a maior lentidão no servidor.
* **Relatório Automatizado:** Gera um arquivo físico chamado `relatorio.txt` contendo o resumo executivo da análise.

## Tecnologias Utilizadas
* **Linguagem:** C++17
* **Compilador:** GCC / G++
* **Estruturas de Dados:** `std::vector`, `std::string`, `struct` personalizadas.
* **I/O Manipulação:** Biblioteca `<fstream>` para leitura e escrita de arquivos em disco rígido.

## Como Compilar e Rodar

Se você quiser testar o projeto localmente, rode o seguinte comando no seu terminal(VSCODE):

```bash
g++ -std=c++17 src/log_parser.cpp src/analytics.cpp src/main.cpp -I include -o ./log_parser.exe
