#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <atomic> // Include the atomic library

class Spinlock
{
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT; // Initialize the flag

public:
    Spinlock() = default;

    void Spin_Acq()
    {

        while (flag.test_and_set(std::memory_order_acquire))
        {
        }
    }
    void Spin_Rel()
    {

        flag.clear(std::memory_order_release);
    }
    ~Spinlock() = default;
};

Spinlock spinlock;

void multiply(int &var)
{
    spinlock.Spin_Acq();
    var = var * 2;
    spinlock.Spin_Rel();
}
void Divide(int &var)
{
    spinlock.Spin_Acq();
    var = var / 2;
    spinlock.Spin_Rel();
}

int var{1};
int main()
{
    std::thread obj1(multiply, std::ref(var));
    std::thread obj2(Divide, std::ref(var));
    obj1.join();
    obj2.join();

    std::cout << var;
    return 0;
}