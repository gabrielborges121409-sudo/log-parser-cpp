#ifndef ANALYTICS_HPP
#define ANALYTICS_HPP

#include "log_parser.hpp"
#include <vector>

namespace LogSystem {

    class Analytics {
    public:
        // Declaração: Só avisa que a função existe
        double calcularTempoMedio(const std::vector<LogEntry>& logs);

        // Declaração: Só avisa que a função existe
        LogEntry encontrarMaiorGargalo(const std::vector<LogEntry>& logs);
    };

} // namespace LogSystem

#endif