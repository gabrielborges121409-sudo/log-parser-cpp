/*
para lermos o arquivo e quebrar o texto, usaremos o std::ifstream (para abrir o arquivo) 
e o std::stringstream (para dividir a linha pelas vírgulas).
*/

#include "../include/log_parser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

namespace LogSystem{

    std::vector<LogEntry> LogParser::parseFile(const std::string& filename) {
        std::vector<LogEntry> entries;
        std::ifstream file(filename);

        // Verifica se o arquivo abriu corretamente
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
            return entries; // Retorna o vetor vazio
        }

        std::string line;
        // Lê o arquivo linha por linha
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string timestamp, level, service_name, temp_time;

            // Extrai cada campo separado por vírgula
            if (std::getline(ss, timestamp, ',') &&
                std::getline(ss, level, ',') &&
                std::getline(ss, service_name, ',') &&
                std::getline(ss, temp_time, ',')) {

                // Cria um objeto LogEntry com os dados lidos
                LogEntry entry;
                entry.timestamp = timestamp;
                entry.level = level;
                entry.service_name = service_name;
                
                // Converte a string do tempo de execução para double
                entry.execution_time_ms = std::stod(temp_time);

                // Adiciona o log na nossa lista (vector)
                entries.push_back(entry);
            }
        }

        file.close();
        return entries;
    }

    std::vector<LogEntry> LogParser::filtrarPorTipo(const std::vector<LogEntry>& todosOsLogs, const std::string& tipo) {
    std::vector<LogEntry> logsFiltrados;
    
    for (const auto& log : todosOsLogs) {
        // Se o level do log (INFO, ERROR, WARN) for igual ao tipo que queremos filtrar
        if (log.level == tipo) {
            logsFiltrados.push_back(log);
        }
    }
    
    return logsFiltrados;
}

} // namespace LogSystem