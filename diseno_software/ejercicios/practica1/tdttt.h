#ifndef TDTTT_H_INCLUDED
#define TDTTT_H_INCLUDED

typedef enum {STRATEGY_1 = 1, STRATEGY_2, STRATEGY_3} t_strategy;

void tdttt_init(void);
void tdttt_train_agent(const t_strategy strategy);
void tdttt_play_against_human(const int num_games = 1);

#endif // TDTTT_H_INCLUDED
