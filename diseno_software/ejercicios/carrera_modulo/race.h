#ifndef RACE_H_INCLUDED
#define RACE_H_INCLUDED

#include <iostream>
#include <math.h>

using namespace std;

typedef enum {F16, F1, MOTOGP} t_racer;

int get_race_distance(void);
float get_race_time(const float distance, const float accel, const float vmax);
void print_race_times(const float time_f16, const float time_f1, const float time_motogp);
t_racer get_race_winner(const float time_f16, const float time_f1, const float time_motogp, float& time_winner);
void print_race_winner(const t_racer winner, const float time_winner);



#endif // RACE_H_INCLUDED
