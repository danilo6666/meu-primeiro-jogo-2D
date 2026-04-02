#include "raylib.h"

void Tela_Inicial(int *pausado, Texture2D inicial)
{
    
    DrawTextureEx(inicial,(Vector2){0,10}, 0.0f, 0.66f, WHITE);
    Color cor = WHITE;

    Vector2 mouse = GetMousePosition();

    Rectangle B_iniciar = {420, 370, 200, 80};
    Rectangle B_sair = {440, 430 ,200 ,80};

    if(CheckCollisionPointRec(mouse, B_iniciar)){
        DrawText("iniciar",440 ,390 ,60,RED);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){*pausado = 0;}
            
    }else{
        DrawText("iniciar",440 ,390 ,60,BLACK);
    }



    if(CheckCollisionPointRec(mouse, B_sair)){
        DrawText("sair",460 ,450 ,60,RED);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){CloseWindow();}
            
    }else{
        DrawText("sair",460 ,450 ,60,BLACK );
    }

    


    

 
}