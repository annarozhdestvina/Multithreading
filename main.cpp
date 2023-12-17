#include <iostream>
#include <chrono>
#include <thread> 

void Do(int fuck, int you) {
    for (;you < fuck; you++) {
        std::cout << std::this_thread::get_id() << " do " << you <<'\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main() {

    std::thread th(Do, 4, 0);

    for (int i = 0; i < 5; i++) {

        std::cout << std::this_thread::get_id() << " main " << i <<'\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    
    th.join();

    return 0;
}