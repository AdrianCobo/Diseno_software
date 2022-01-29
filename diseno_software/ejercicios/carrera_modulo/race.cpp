#include "race.h"

int get_race_distance(void)
{
    const int MIN_DISTANCE = 100;
    const int MAX_DISTANCE = 2000;
    const int STEP_DISTANCE = 100;
    int race_distance;
    bool incorrect_distance;
    do
    {
        cout <<"please enter a race distance: ";
        cin >> race_distance;

        incorrect_distance =(race_distance < MIN_DISTANCE) ||
                            (race_distance > MAX_DISTANCE) ||
                            ((race_distance % 100) != 0);

        if(incorrect_distance)
            cout << "ERROR: Invalid distance!" << endl;

    }while(incorrect_distance);
    return race_distance;
}

float get_race_time(const float distance, const float accel, const float vmax)
{
    float race_time;

    //MRUA: v*v=2*a*d ; d = (v*v)/(2*a)
    float cross_distance = (vmax * vmax) / (2 * accel);

    if (cross_distance > distance)
    {
        //only MRUA
        //d = 0.5*a*t*t -> t = sqrt(2*d/a)
        race_time = sqrt( 2 * distance / accel);
    }
    else
    {
        //MRUA
        race_time = sqrt( 2 * cross_distance / accel);
        //MRU: d = v*t -> t = d/v
        race_time += (distance - cross_distance) / vmax;
    }

    return race_time;
}
void print_race_times(const float time_f16, const float time_f1, const float time_motogp)
{
     cout <<"Time F16 " << time_f16 << "sec" << endl;
     cout <<"Time F1 " << time_f1 << "sec" << endl;
     cout <<"Time motogp " << time_motogp << "sec" << endl;
}

t_racer get_race_winner(const float time_f16, const float time_f1, const float time_motogp, float& time_winner)
{
    t_racer winner;
    if((time_f16 < time_f1) && (time_f16 < time_motogp))
    {
        winner = F16;
        time_winner = time_f16;
    }
    else if((time_f1 < time_f16) && (time_f1 < time_motogp))
    {
        winner = F1;
        time_winner = time_f1;
    }
    else
    {
        winner = MOTOGP;
        time_winner = time_motogp;
    }
    return winner;
}

void print_race_winner(const t_racer winner, const float time_winner)
{
     cout <<"winner: ";
     switch(winner)
     {
        case F16:
            cout <<"F16 (" << time_winner << "sec)" << endl;
            break;
        case F1:
            cout <<"F1 " << time_winner << "sec)" << endl;
            break;
        case MOTOGP:
            cout <<"MOTOGP " << time_winner << "sec)" << endl;
            break;
     }
}
