#ifndef ENGINE_H
#define ENGINE_H

#include <stdint.h>
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef float f32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#include <raylib.h>
typedef struct{
    s32 x;
    s32 y;
    s32 radius;
    Color colour;
    f32 speed_x, speed_y;
    Vector2 v_ball;
    f32 last_collision_t;
}Ball;

typedef struct{
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    Color colour;
    f32 speed;
    Rectangle r_paddle;
}Paddle;

void DrawBall(Ball ball){
    DrawCircle(ball.x, ball.y, ball.radius, ball.colour);
}

void DrawPaddle(Paddle paddle){
    DrawRectangle(paddle.x, paddle.y, paddle.w, paddle.h, paddle.colour);
}

void BallUpdate(Ball *ball){
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;

    if(ball->y + ball->radius >= GetScreenHeight() || ball->y - ball->radius <= 0){
        ball->speed_y *= -1.0f;
    }
    /*if(ball->x + ball->radius >= GetScreenWidth() || ball->x - ball->radius <= 0){
        ball->speed_x *= -1.0f;
    }*/

    ball->v_ball = (Vector2){ball->x, ball->y};
}

s32 PaddleCollisionScreenCheck(Paddle *paddle){
    if(paddle->y <= 0) return 0;
    else if(paddle->y + paddle->h >= GetScreenHeight()) return GetScreenHeight() - paddle->h;
    else return paddle->y;
}

void PlayerUpdate(Paddle *paddle){
    if(IsKeyDown(KEY_UP)){
        paddle->y = paddle->y - paddle->speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        paddle->y = paddle->y + paddle->speed;
    }

    paddle->y = PaddleCollisionScreenCheck(paddle);

    paddle->r_paddle = (Rectangle){paddle->x, paddle->y, paddle->w, paddle->h};
}

void CpuUpdate(Paddle *paddle, Ball *ball){
    if(paddle->y + paddle->h/2 > ball->y) paddle->y = paddle->y - paddle->speed;
    if(paddle->y + paddle->h/2 <= ball->y) paddle->y = paddle->y + paddle->speed;

    paddle->y = PaddleCollisionScreenCheck(paddle);

    paddle->r_paddle = (Rectangle){paddle->x, paddle->y, paddle->w, paddle->h};
}

typedef struct{
    s32 x;
    s32 y;
    s32 f;
    Color colour;
}Score;

void DrawScore(const char* text, Score score){
    DrawText(text, score.x, score.y, score.f, score.colour);
}

void ResetBall(Ball *ball){
    ball->x = GetScreenWidth()/2;
    ball->y = GetScreenHeight()/2;

    f32 speed_c[2] = {-1.0, 1.0};
    ball->speed_x *= speed_c[GetRandomValue(0,1)];
    ball->speed_y *= speed_c[GetRandomValue(0,1)];
}

#endif