#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define WINNING_POSITION 12
#define NUM_SIMULATIONS 10000000

typedef struct {
    int number;
    int position;
    int can_move;
} Player;

int get_ai_choice() {
    int choices[3] = {1, 3, 5};
    return choices[arc4random_uniform(3)];
}

int simulate_game()
{
    Player players[NUM_PLAYERS];
    int i;
    int j;
    players[0].number = 1;

    i = 0;
    while(i < NUM_PLAYERS)
    {
        players[i].position = 0;
        i++;
    }
    while(1)
    {
        i = 1;
        while(i < NUM_PLAYERS)
        {
            players[i].number = get_ai_choice();
            // printf("PLAYER %d  NUMBER IS = %d \n",i,players[i].number);
            i++;
        }
        i = 0;
        while (i < NUM_PLAYERS)
        {
            j =  0;
            players[i].can_move = 1;
            while(j < NUM_PLAYERS)
            {
                if(players[i].number == players[j].number && i != j)
                    players[i].can_move = 0;
                j++;
            }
            i++;
        }
        i = 0;
        while(i < NUM_PLAYERS)
        {
            // printf("PLAYER %d  CAN MOVE= %d \n",i,players[i].can_move);
            i++;
        }
        i = 0;
        while(i < NUM_PLAYERS)
        {
            if(players[i].can_move == 1)
            {
                players[i].position += players[i].number;
                // printf("PLAYER [%d] MOVED %d SPACES\n",i,players[i].number);
            }
            i++;
        }
        i = 0;
        while(i < NUM_PLAYERS)
        {
            if(players[i].position >= WINNING_POSITION)
            {
                if(i == 0)
                {
                    // printf("PLAYER %d WON!!!\n",i);
                    return 1;
                }
                return 0;
            }
            i++;
        }
    }

}

int main()
{
    int result;

    result = 0;
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        result += simulate_game();
    }
    printf("REAL PLAYER WON %d TIMES",result);
    return 0;
}
