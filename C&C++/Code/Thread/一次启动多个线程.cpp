#include <stdio.h>
#include <stdlib.h>
#include <iostream> // std::cout
#include <thread>   // std::thread
int main()
{
    int num_threads;
    std::thread t[num_threads];
    std::cin >> num_threads;
    // Launch a group of threads һ߳
    for (int i = 0; i < num_threads; ++i)
    {
        t[i] = std::thread(call_from_thread);
    }
    std::cout << "Launched from the mainn";
    // Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i)
    {
        t[i].join();
    }
    return 0;
}
