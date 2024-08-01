#include <iostream>
#include <thread>

void print_thread_id(int thread_id) {
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread " << thread_id << " - Iteration "  << std::endl;
    }
}

int main() {
    // Create two threads
    std::thread t1(print_thread_id, 1);
    std::thread t2(print_thread_id, 2);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    return 0;
}

