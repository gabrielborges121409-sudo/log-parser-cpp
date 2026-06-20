//definir como a memória vai guardar cada linha do log. Evite criar classes pesadas aqui
//struct para ganho de performance.

#ifndef LOG_PARSER_HPP 
#define LOG_PARSER_HPP
//Esses dois evitam erros de redefinição SE esse arquivo for incluído em mais de um lugar

#include <string>
#include <vector>

namespace LogSystem {

    struct LogEntry {
        std::string timestamp;
        std::string level;// INFO, WARN, ERROR
        std::string service_name;
        double execution_time_ms;
    };



class LogParser {
public:

//Função que recebe o caminho do arquivo e retorna um vetor com todos os logs lidos
std::vector<LogEntry> parseFile(const std::string& filename);

//Filtra o vetor de logs gerado pelo parseFile e pega só um tipo (ex: "ERROR")
std::vector<LogEntry> filtrarPorTipo(const std::vector<LogEntry>& todosOsLogs, const std::string& tipo);
};

}//namespace LogSystem

#endif// LOG_PARSER_HPP