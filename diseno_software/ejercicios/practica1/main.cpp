#include "interface.h"
#include <iostream>
using namespace std;


int main()
{
    int difficulty = get_difficulty();
    int number_of_matches = get_number_of_matches();
    play(difficulty, number_of_matches);
    return 0;
}

// trainer 1 lose when i start at the center and when I start in the corner
// trainer 3 ties when i start in the center but lose when I start at the corner
// strategy 2 ties when I start at the center and when I start at any corner
