#pragma once
#include <SFML/System.hpp>
#include <string>
class Timer
{
public:
    Timer();

    // Timer functions
    double getTime() const;                 //returns the time that has already elapsed
    void start();                           //starts the timer                                         
    void pause();                           //stops the timer                    
    void reset();                           //resets the timer
    bool toggle();                          //switches the timer state (start/pause)
    void adjustTime(double seconds);        //changes the time on the timer
    void setTime(double seconds);           //sets the time on the timer
private:
    bool isRun;
    sf::Clock timer;
    double currentTime;
    double pausedTime;
};
