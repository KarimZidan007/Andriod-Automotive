#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

std::vector<int> results(4); // To store the results
std::recursive_mutex mtx;
std::condition_variable_any cv;
bool ready = false;

// Function to calculate Fibonacci numbers
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate and store Fibonacci numbers
void calculate_fibo(int index, int n)
{
    std::lock_guard<std::recursive_mutex> lock(mtx);
    results[index] = fibonacci(n);
}

// Function to print the results
void print_results()
{
    std::unique_lock<std::recursive_mutex> lock(mtx);
    cv.wait(lock, []
            { return ready; });
    int sum = 0;
    for (int res : results)
    {
        std::cout << res << " ";
        sum += res;
    }
    std::cout << "\nSum: " << sum << std::endl;
}

int main()
{
    // Threads for calculating Fibonacci numbers
    std::thread t1(calculate_fibo, 0, 4);
    std::thread t2(calculate_fibo, 1, 9);
    std::thread t3(calculate_fibo, 2, 14);
    std::thread t4(calculate_fibo, 3, 17);

    // Thread for printing results
    std::thread print_thread(print_results);

    // Wait for calculation threads to finish
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // Notify the print thread that results are ready
    {
        std::lock_guard<std::recursive_mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();

    // Wait for the print thread to finish
    print_thread.join();

    return 0;
}
