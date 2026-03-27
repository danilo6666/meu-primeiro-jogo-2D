#include "raylib.h"

void reboot(int *score_player, int *score_enemy,int *Max_score, int *pausado){
    
    if(*Max_score == *score_player){
        *pausado = 1;
        DrawText("WIN",400,250,100,YELLOW);
        DrawText("WIN",400,250,102,BLACK);
        DrawText("precione 'p' para jogar novamente",250,350,30,BLACK);
        
        if(IsKeyPressed(KEY_P)){
            *score_player = 0;
            *score_enemy = 0;
            *pausado = 0;
        }
        
    }else if(*Max_score == *score_enemy){
        *pausado = 1;
        DrawText("LOSER",330,250,100,RED);
        DrawText("LOSER",330,250,102,BLACK);
        DrawText("precione 'p' para jogar novamente",250,350,30,BLACK);

        if(IsKeyPressed(KEY_P)){
            *score_player = 0;
            *score_enemy = 0;
            *pausado = 0;
        }


    }
    
}