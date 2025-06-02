#pragma once
#include <SFML/System.hpp>
#include <string>
class Timer
{
public:
    Timer();

    // Основні функції
    double getTime() const;                  // Поточний час у секундах
    void start();                            // Запуск таймера
    void pause();                            // Пауза таймера
    void reset();                            // Скидання таймера
    bool toggle();                           // Перемикач старт/пауза

    // Додаткові функції
    void adjustTime(double seconds);         // Відняти час
    void setTime(double seconds);            // Встановити конкретний час

private:
    bool isRun;
    sf::Clock timer;
    double currentTime;
    double pausedTime;
};