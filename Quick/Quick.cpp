#include <iostream>
#include <array>
#include <cstdlib>
#include <chrono>
#include <random>
#include <thread>
#include <future>

constexpr long long int _t = 1'000'000'000;

int fun_1() noexcept{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rng_coin(0, 29);
    std::array<int,30>deck = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6
    };
    int ap = 0;
    long long int __t = (_t / 10);
    while ( --__t)
    {
        for (unsigned short i = 7; --i;)
        {
            const int_fast8_t k = rng_coin(gen);
            if (deck[k] == 6)
            {
                ++ap;                
                deck[k] = 1;
            }
        }
        deck = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6
        };
    }
    return ap;
}
int main()
{     
    const auto start = std::chrono::high_resolution_clock::now();
   
    auto f1 = std::async(fun_1);
    auto f2 = std::async(fun_1);
    auto f3 = std::async(fun_1);
    auto f4 = std::async(fun_1);
    auto f5 = std::async(fun_1);
    auto f6 = std::async(fun_1);
    auto f7 = std::async(fun_1);
    auto f8 = std::async(fun_1);
    auto f9 = std::async(fun_1);
    auto f10 = std::async(fun_1);
    std::cout << (f1.get() + f2.get() + f3.get() + f4.get() + f5.get() + f6.get() + f7.get() + f8.get() + f9.get() + f10.get()) << std::endl;

    const auto stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << duration.count() << " MilliSeconds\n";
    system("PAUSE>0");
    return 0;
}
