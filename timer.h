#include <chrono>
/**
 * @file timer.h
 * Čia apibrėžta laiko skaičiavimui skirtas klasė.
 */
class Timer {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
    /// @brief Funkcija gauna kompiuterio dabartinį laiką skaičiavimo pradžiai.
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    /// @brief Funkcija gauna kompiuterio dabartinį laiką skaičiavimo pabaigai.
    void reset() {
      start = std::chrono::high_resolution_clock::now();
    }
    /// @brief Apskaičiuoja kiek laiko praėjo tarp dviejų laiko momentų.
    /// @return Praėjusį laiką.
    double elapsed() const {return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
    }
};
