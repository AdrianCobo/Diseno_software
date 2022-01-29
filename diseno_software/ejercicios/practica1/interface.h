#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "tdttt.h"

int get_difficulty(void);
int get_number_of_matches(void);
void play(const int difficulty, const int number_of_matches);
t_strategy get_trainer(const int difficulty);

#endif // INTERFACE_H_INCLUDED
