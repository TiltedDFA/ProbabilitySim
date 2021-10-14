#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <chrono>


int main()
{     
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int>Deck;    
    float ap=0;
    float times = 100000;
    for (int i = 26; --i;) { Deck.push_back(1); }
    for (int i = 5; --i;) { Deck.push_back(6); }
    Deck.shrink_to_fit();
    for (; --times;)
    {
        std::vector<int>Hand;
        
        for (int i = 6; i--;)
        {
            int k = Deck[rand() % 28];
            Hand.push_back(k);            
            if (k == 6)
                ++ap;
        }              
    }
    float percent = ((ap / 100000) * 100);
    std::cout << percent << "%\n";
    std::cout << ap << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << duration.count();
    system("PAUSE>0");
}
