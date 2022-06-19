#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <list>

constexpr int _t = 1000000;

std::random_device rd; //seed
std::mt19937 gen(rd()); //seed for rd(Mersenne twister)
std::uniform_int_distribution<> rng_coin(0, 28); //rng1 range

int main()
{     
    const auto start = std::chrono::high_resolution_clock::now();
    std::array<uint_fast8_t,29>Deck = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,6
    };
    int ap=0;
    uint_fast32_t __t = _t;
    for (; --__t;)
    {
        std::vector<int>Hand{};
        for (int i = 7; --i;)
        {
            const uint_fast8_t k = Deck[rng_coin(gen)];
            Hand.push_back(k);            
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
