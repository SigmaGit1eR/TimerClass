#include <SFML/System.hpp>
#include <iostream>
#include <thread>      // For std::this_thread::sleep_for
#include <chrono>      // For std::chrono::seconds
#include "Timer.h"   // Assuming your Timer class is in a separate file

int main()
{
    Timer timer;  // Create a Timer object

    std::cout << "Starting the timer...\n";
    timer.start();  // Start the timer

    // Simulate some work by sleeping for 2 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Pausing the timer after 2 seconds...\n";
    timer.pause();  // Pause the timer

    // Show the elapsed time (should be ~2.0 seconds)
    std::cout << "Elapsed time: " << timer.getTime() << " seconds\n";

    // Adjust the timer by -1 second (should now show ~1.0)
    std::cout << "Subtracting 1 second from the timer...\n";
    timer.adjustTime(-1.0);

    std::cout << "New time: " << timer.getTime() << " seconds\n";

    // Resume the timer
    std::cout << "Resuming the timer...\n";
    timer.start();

    // Simulate more work
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Show the updated time
    std::cout << "Current time after 1 more second: " << timer.getTime() << " seconds\n";

    // Set time manually to 10 seconds
    std::cout << "Manually setting time to 10 seconds...\n";
    timer.setTime(10.0);

    std::cout << "Time after setTime: " << timer.getTime() << " seconds\n";

    // Reset the timer
    std::cout << "Resetting the timer...\n";
    timer.reset();

    std::cout << "Time after reset: " << timer.getTime() << " seconds\n";

    // Toggle test: start -> pause -> start
    std::cout << "Toggling the timer (start)...\n";
    timer.toggle();  // Starts the timer

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Toggling the timer (pause)...\n";
    timer.toggle();  // Pauses the timer

    std::cout << "Final elapsed time: " << timer.getTime() << " seconds\n";

    return 0;
}
