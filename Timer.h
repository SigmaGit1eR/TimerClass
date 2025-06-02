#pragma once
#include <SFML/System.hpp>
#include <string>
class Timer
{
public:
    Timer();

    // ������ �������
    double getTime() const;                  // �������� ��� � ��������
    void start();                            // ������ �������
    void pause();                            // ����� �������
    void reset();                            // �������� �������
    bool toggle();                           // ��������� �����/�����

    // �������� �������
    void adjustTime(double seconds);         // ³����� ���
    void setTime(double seconds);            // ���������� ���������� ���

private:
    bool isRun;
    sf::Clock timer;
    double currentTime;
    double pausedTime;
};