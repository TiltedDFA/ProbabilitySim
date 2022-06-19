#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <list>

constexpr int _t = 1000000000;

int main()
{     
    const auto start = std::chrono::high_resolution_clock::now();
    std::array<int_fast8_t,30>Deck = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,6
    };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rng_coin(0, 29);
    int ap=0;
    int_fast32_t __t = _t;
    for (; --__t;)
    {
        for (int i = 7; --i;)
        {
            const int_fast8_t k = Deck[rng_coin(gen)];                       
            if (k == 6)
                ++ap;
        }              
    }
    auto percent = (ap / _t);
    std::cout << percent << "%\n";
    std::cout << ap << std::endl;
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << duration.count() << " MilliSeconds\n";
    system("PAUSE>0");
}
