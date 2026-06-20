#include "../include/log_parser.hpp"
#include "../include/analytics.hpp"
#include <iostream>
#include <fstream> // biblioteca incluída para criar e salvar arquivos de texto
#include <vector>

int main() {
    // Criamos as ferramentas que vão trabalhar para nós
    LogSystem::LogParser parser;
    LogSystem::Analytics analitico;
    
    std::string caminho = "dados.log";

    // 1. Processa o arquivo completo e guarda na nossa lista organizada
    std::vector<LogSystem::LogEntry> todosOsLogs = parser.parseFile(caminho);
    
    // Imprime na tela do terminal para acompanharmos
    std::cout << "Total de logs lidos com sucesso: " << todosOsLogs.size() << std::endl;

    std::cout << "\n--- Procurando por Erros Criticos ---" << std::endl;
    std::vector<LogSystem::LogEntry> erros = parser.filtrarPorTipo(todosOsLogs, "ERROR");
    std::cout << "Quantidade de erros encontrados: " << erros.size() << std::endl;
    
    for (const auto& erro : erros) {
        std::cout << "[ALERTA] Servico: " << erro.service_name 
                  << " | Hora: " << erro.timestamp 
                  << " | Tempo: " << erro.execution_time_ms << "ms" << std::endl;
    }

    std::cout << "\n--- Painel de Estatisticas (Analytics) ---" << std::endl;
    double media = analitico.calcularTempoMedio(todosOsLogs);
    std::cout << "Tempo medio de resposta do sistema: " << media << "ms" << std::endl;

    LogSystem::LogEntry piorServico = analitico.encontrarMaiorGargalo(todosOsLogs);
    std::cout << "Maior Gargalo Detectado -> Servico: " << piorServico.service_name 
              << " (" << piorServico.execution_time_ms << "ms)" << std::endl;


    // =========================================================================
    // =========================================================================
    
    // arquivo chamado "relatorio.txt" para escrita
    std::ofstream arquivoRelatorio("relatorio.txt");

    // Verifica se o sistema operacional permitiu criar o arquivo corretamente
    if (arquivoRelatorio.is_open()) {
        
        // Escrevendo o cabeçalho dentro do arquivo
        arquivoRelatorio << "==================================================\n";
        arquivoRelatorio << "        RELATORIO DE PERFORMANCE E ERROS          \n";
        arquivoRelatorio << "==================================================\n\n";

        arquivoRelatorio << "Total de logs processados: " << todosOsLogs.size() << "\n\n";

        arquivoRelatorio << "--- ERROS CRITICOS DETECTADOS ---\n";
        arquivoRelatorio << "Quantidade: " << erros.size() << "\n";
        for (const auto& erro : erros) {
            arquivoRelatorio << " -> Servico: " << erro.service_name 
                             << " | Hora: " << erro.timestamp 
                             << " | Tempo: " << erro.execution_time_ms << "ms\n";
        }
        
        arquivoRelatorio << "\n--- METRICAS DE LENTIDAO (ANALYTICS) ---\n";
        arquivoRelatorio << " -> Tempo medio de resposta global: " << media << "ms\n";
        arquivoRelatorio << " -> Pior gargalo do sistema: " << piorServico.service_name 
                         << " demorou " << piorServico.execution_time_ms << "ms\n\n";

        arquivoRelatorio << "==================================================\n";
        arquivoRelatorio << "Relatorio gerado automaticamente pelo LogParser.\n";

        // Fecha o arquivo para salvar as alterações no disco rígido
        arquivoRelatorio.close();

        std::cout << "\n[SUCESSO] O arquivo 'relatorio.txt' foi gerado com sucesso na pasta!" << std::endl;
    } else {
        std::cerr << "\n[ERRO] Nao foi possivel criar o arquivo de relatorio." << std::endl;
    }

    return 0;
}