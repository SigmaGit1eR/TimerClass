#include "Timer.h"

Timer::Timer() :
	isRun(false),
	currentTime(0.0),
	pausedTime(0.0)
{
}

double Timer::getTime() const
{
	return isRun ? double(std::max(currentTime + timer.getElapsedTime().asSeconds(), 0.0)) : double(std::max(currentTime, 0.0));
}

void Timer::start()
{
	if (!isRun) 
	{
		timer.restart();
		isRun = true;
	}
}

void Timer::pause()
{
	if (isRun) {
		currentTime += timer.getElapsedTime().asSeconds();
		isRun = false; 
	}
}

void Timer::reset()
{
	isRun = false;
	currentTime = 0.0;
	pausedTime = 0.0;
}

bool Timer::toggle()
{
	isRun ? pause() : start();
	return isRun;
}


void Timer::adjustTime(double seconds)
{
	if (isRun) {
		currentTime += timer.getElapsedTime().asSeconds();
		currentTime = std::max(0.0, currentTime + seconds);
		timer.restart();
	}
	else {
		currentTime = std::max(0.0, currentTime + seconds);
	}
}

void Timer::setTime(double seconds)
{
	currentTime = std::max(0.0, seconds);
	pausedTime = 0.0;

	if (isRun) {
		timer.restart();  // Якщо таймер активний - перезапускаємо відлік
	}
}