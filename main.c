#include "raylib.h"
#include "reboot.c"


int main() {
	InitWindow(1000, 700, "Teste danilo");
	SetTargetFPS(60);

	Texture2D fundo = LoadTexture("fundo.png");

	float playery = 250;

	float enemyY = 250;

	float ballx = 400;
	float bally = 300;

	float ballspeedx = 8;
	float ballspeedy = 8;

	int player_score = 0;
	int enemy_score = 0;

	int Max_score = 10;

	int pausado = 0;

	while (!WindowShouldClose()) {

		

		if(pausado == 0){

			bally += ballspeedy;
			ballx += ballspeedx;

			if (ballx <= 10) {
				enemy_score++;
				ballx = 500;
				bally = 350;	
			}
			else if(ballx >= 990){
				player_score++;
				ballx = 500;
				bally = 350;	
			}

		

			if(playery + 100 >= 700){playery = 600;}
			if (playery <= 0) { playery = 0;}
		

			if (IsKeyDown(KEY_W)) { playery -= 9; }
			if (IsKeyDown(KEY_S)) { playery += 9; }

			if (bally <= 10 || bally >= 690) {
				ballspeedy *= -1;
			}
			else if (ballx <= 10 || ballx >= 990) {
				ballspeedx *= -1;
			}
		
			if (ballx >= 500) {
				if (enemyY + 50 < bally) {
					enemyY += 6;
				}
				else if (enemyY + 50 > bally) {
					enemyY -= 6;
				}

			}

			if (ballx - 10 <= 70 && ballx > 50 && bally >= playery && bally <= playery + 100) { ballspeedx *= -1;ballx = 80;}
			if(ballx + 10 <= 970 && ballx > 950 && bally >= enemyY && bally <= enemyY + 110) { ballspeedx *= -1;ballx = 940;}
		}

		

		BeginDrawing();
		ClearBackground(BLACK);

		DrawTextureEx(fundo,(Vector2){-25,0}, 0.0f, 0.69f, WHITE);

		reboot(&player_score, &enemy_score, &Max_score, &pausado);

		DrawText(TextFormat("%d/10",player_score),400,0,40,WHITE);
		DrawText(TextFormat("%d/10", enemy_score), 600, 0, 40, WHITE);
		
		DrawCircle(ballx, bally, 10, WHITE);

		DrawRectangle(950, enemyY, 20, 100, WHITE);
		DrawRectangle(50, playery, 20, 100, WHITE);

		EndDrawing();

	}
	UnloadTexture(fundo);
	CloseWindow();
	return 0;
}