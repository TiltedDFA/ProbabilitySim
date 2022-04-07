#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

constexpr int _t = 100000000;

int main()
{     
    const auto start = std::chrono::high_resolution_clock::now();
    std::vector<uint_fast8_t>Deck;    
    uint_fast32_t ap=0;

    srand(time(NULL));

 
    for (int i = 26; --i;)
        Deck.push_back(1);

    for (int i = 5; --i;)  
        Deck.push_back(6);

    Deck.shrink_to_fit();
    uint_fast32_t __t = _t;

    for (; --__t;)
    {
        std::vector<int>Hand;
        
        for (int i = 7; --i;)
        {
            const uint_fast8_t k = Deck[rand() % 28];
            Hand.push_back(k);            
            if (k == 6)
                ++ap;
        }              
    }
    const double percent = ap / _t;
    std::cout << percent << "%\n";
    std::cout << ap << std::endl;
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << duration.count() << " MilliSeconds\n";
    system("PAUSE>0");
}
