
#include "iterfaz.h"
#include <iostream>

using namespace std;

int get_difficulty(void)
{
    int difficulty = 0;

    do
    {
        cout <<"Please enter a difficulty between 1 to 4" << endl;
        cout <<"1. Basic level" << endl;
        cout <<"2. Normal level" << endl;
        cout <<"3. Advanced level" << endl;
        cout <<"4. Extreme difficulty" << endl;
        cin >> difficulty;
    }
    while(difficulty < 1 || difficulty > 4);

    return difficulty;
}

int get_number_of_matches(void)
{
    int number_of_matches = 0;

    do
    {
        cout <<"How many matches do you want to play (enter a number higher than 0)" << endl;
        cin >> number_of_matches;
    }
    while(number_of_matches < 1);

    return number_of_matches;
}

void play(const int difficulty,const int number_of_matches)
{
    if(difficulty == 1)
    {
        tdttt_init();
        tdttt_play_against_human(number_of_matches);
    }else
    {
        const t_strategy trainer = get_trainer(difficulty);
        tdttt_init();
        tdttt_train_agent(trainer);
        tdttt_play_against_human(number_of_matches);
    }
}

t_strategy get_trainer(int difficulty)
{
    t_strategy selected_dificculty;

    if(difficulty == 2)
    {
        selected_dificculty = STRATEGY_1;
    }else if(difficulty == 3)
    {
        selected_dificculty = STRATEGY_3;
    }else
    {
        selected_dificculty = STRATEGY_2;
    }
    return selected_dificculty;
}
