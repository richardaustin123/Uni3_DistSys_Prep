
// Simple Counter ///////////////////////////////////

// Run with 
// g++ -std=c++11 Chal_1.cpp -o test
// ./test   

//////////////////// Starter code - Single-threaded ////////////////////
// #include<iostream>
// using namespace std;

// int main() {
//     int counter = 0;
//     for(int i=0; i<1000000; i++) {
//         counter++;
//     }
//     cout << "Counter: " << counter << endl;
//     return 0;
// }

//////////////////// Finished code - Multi-threaded ////////////////////
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<chrono>

using namespace std;

mutex mtx;
int counter = 0;

void increment(int increment_number) {
    for (int i = 0; i < increment_number; i++) {
        mtx.lock();                                     // Lock mutex to ensure only one thread accesses counter at a time
        counter++;
        mtx.unlock();                                   // Unlock mutex 
    }
}

int main() {
    int num_threads = 10;
    int increments_per_thread = 1000000;
    auto start = chrono::high_resolution_clock::now();  // Start clock

    // Create and run threads
    thread threads[num_threads];
    for(int i = 0; i < num_threads; i++) {
        threads[i] = thread(increment, increments_per_thread);
    }

    // Join threads to main thread 
    for (int i = 0; i < num_threads; i++) {
        threads[i].join();
    }

    auto end = chrono::high_resolution_clock::now();    // End clock
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // Calculate the time
    cout << "Time taken: " << duration << " nanoseconds" << endl;
    cout << "Counter: " << counter << endl;

    return 0;
}

//////////////////// Single-threaded time ////////////////////
// #include<iostream>
// #include<chrono>
// using namespace std;

// int main() {
//     int counter = 0;
//     auto start = chrono::high_resolution_clock::now();

//     for(int i=0; i<1000000; i++) {
//         counter++;
//     }

//     auto end = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
//     cout << "Time taken: " << duration << " nanoseconds" << endl;

//     cout << "Counter: " << counter << endl;
//     return 0;
// }