#include <iostream>
#include <chrono>
#include <thread>

int Sum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    for(int i = 0 ; i < 5; ++i)
        std::cout << std::this_thread::get_id() << " Sum  i = " << i <<'\n';
    return a + b;
}

int main() {
    int result = 0;
    std::thread t([&result ](){ result = Sum(2,5); } );

    for(int i = 0 ; i < 5; ++i) {
        std::cout << std::this_thread::get_id() << " main  i = " << i <<'\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    t.join();
    std::cout << "result = " << result;

}