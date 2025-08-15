#include <raylib.h>
#include <engine.h>

#define W_WIDTH 1280
#define W_HEIGHT 720
#define SCREEN_CENTER_X W_WIDTH/2
#define SCREEN_CENTER_Y W_HEIGHT/2

void BallDefaultSetting(Ball *ball);
void PlayerPaddleDefaultSetting(Paddle *paddle);
void CpuPaddleDefaultSetting(Paddle *paddle);
void BallCollisionCheckPaddle(Ball *ball, Paddle *player);
void GameScore(Ball *ball);

s32 player_score = 0;
s32 cpu_score = 0;

extern unsigned char game_icon[];
extern unsigned int game_icon_length;

int main(void){
    InitWindow(W_WIDTH, W_HEIGHT, "Pong Raylib");
    SetTargetFPS(60);

    Ball ball;
    Paddle player;
    Paddle CPU;

    Score player_sc = {
        .x = W_WIDTH/4 - 20,
        .y = 20,
        .f = 80,
        .colour = WHITE
    };

    Score cpu_sc = {
        .x = 3*W_WIDTH/4 - 20,
        .y = 20,
        .f = 80,
        .colour = WHITE
    };

    Image icon = LoadImageFromMemory(".png", game_icon, game_icon_length);
    SetWindowIcon(icon);

    PlayerPaddleDefaultSetting(&player);
    BallDefaultSetting(&ball);
    CpuPaddleDefaultSetting(&CPU);

    while(!WindowShouldClose()){
        BallUpdate(&ball);
        PlayerUpdate(&player);
        CpuUpdate(&CPU, &ball);
        
        BallCollisionCheckPaddle(&ball, &player);
        BallCollisionCheckPaddle(&ball, &CPU);
        GameScore(&ball);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawLine(SCREEN_CENTER_X, 0, SCREEN_CENTER_X, W_HEIGHT, WHITE);
            DrawBall(ball);
            DrawPaddle(player);
            DrawPaddle(CPU);
            DrawScore(TextFormat("%d", player_score), player_sc);
            DrawScore(TextFormat("%d", cpu_score), cpu_sc);
        EndDrawing();
    }

    UnloadImage(icon);
    CloseWindow();
    return 0;
}

void BallDefaultSetting(Ball *ball){
    ball->x = SCREEN_CENTER_X;
    ball->y = SCREEN_CENTER_Y;
    ball->radius = 20;
    ball->colour = WHITE;
    ball->speed_x = 7.0f;
    ball->speed_y = 7.0f;
    ball->last_collision_t = 0.0f;
}

void PlayerPaddleDefaultSetting(Paddle *paddle){
    paddle->w = 25;
    paddle->h = 120;
    paddle->x = 10;
    paddle->y = (SCREEN_CENTER_Y - paddle->h/2);
    paddle->colour = WHITE;
    paddle->speed = 6.0f;
}

void CpuPaddleDefaultSetting(Paddle *paddle){
    paddle->w = 25;
    paddle->h = 120;
    paddle->x = (W_WIDTH - paddle->w - 10);
    paddle->y = (SCREEN_CENTER_Y - paddle->h/2);
    paddle->colour = WHITE;
    paddle->speed = 6.0f;
}

void BallCollisionCheckPaddle(Ball *ball, Paddle *paddle){ 
    f32 c_time = GetTime();
    if(CheckCollisionCircleRec(ball->v_ball, ball->radius, paddle->r_paddle)){
        if(c_time - ball->last_collision_t >= 1.0f){
            ball->speed_x *= -1.0f;
            ball->last_collision_t = c_time;
        }
    }
}

void GameScore(Ball *ball){
    if(ball->x + ball->radius >= W_WIDTH){
        player_score++;
        ResetBall(ball);
    }
    if(ball->x - ball->radius <= 0){
        cpu_score++;
        ResetBall(ball);
    }
}