#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> keepBeeping(true);

void beepEveryThreeSeconds(int delayInSeconds)
{
    while (keepBeeping)
    {
        std::this_thread::sleep_for(std::chrono::seconds(delayInSeconds));
        if (keepBeeping)
        {
            std::cout << "SOUND" << '\a' << std::endl; // Beep sound
        }
    }
}

int main()
{
    std::thread beepThread(beepEveryThreeSeconds, 3);

    std::cout << "Press Enter to stop the beep...\n";
    std::cin.get(); // Wait for the user to press Enter

    keepBeeping = false; // Signal the thread to stop
    beepThread.join();   // Wait for the thread to finish

    std::cout << "Beep stopped.\n";
    return 0;
}
