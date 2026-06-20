#include "../include/analytics.hpp"
#include <iostream>

namespace LogSystem {

    // 1. Função que calcula o tempo médio de execução de todos os logs
    double Analytics::calcularTempoMedio(const std::vector<LogEntry>& logs) {
        // Se a lista de logs estiver vazia, a média é zero (evita divisão por zero)
        if (logs.empty()) {
            return 0.0;
        }

        double somaTempos = 0.0;

        // Passa de linha em linha acumulando o tempo de execução
        for (const auto& log : logs) {
            somaTempos += log.execution_time_ms;
        }

        // Divide o tempo total pela quantidade de logs para achar a média
        return somaTempos / logs.size();
    }

    // 2. Função que descobre qual foi o serviço mais lento de todos
    LogEntry Analytics::encontrarMaiorGargalo(const std::vector<LogEntry>& logs) {
        // Se não houver logs, retorna um objeto vazio para não quebrar o programa
        if (logs.empty()) {
            return LogEntry();
        }

        // Começamos assumindo que o primeiro log da lista é o mais lento
        LogEntry maiorGargalo = logs[0];

        // Varremos o resto da lista comparando os tempos
        for (size_t i = 1; i < logs.size(); ++i) {
            // Se o log atual demorou mais que o nosso "campeão" de lentidão...
            if (logs[i].execution_time_ms > maiorGargalo.execution_time_ms) {
                // ...o log atual vira o novo maior gargalo!
                maiorGargalo = logs[i];
            }
        }

        // No final do loop, retornamos o log que ganhou a disputa de mais lento
        return maiorGargalo;
    }

} // namespace LogSystem