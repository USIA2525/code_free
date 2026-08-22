#include <stdio.h>
#include <stdbool.h>

// 画面サイズなどの定数
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// ゲームの状態を管理する変数（グローバル変数として定義）
float ball_x = 320.0f, ball_y = 240.0f; // ボールの座標
float ball_vx = 3.0f, ball_vy = -3.0f;  // ボールの移動速度（X方向、Y方向）
float paddle_x = 320.0f;                // パドルのX座標
bool is_game_over = false;              // ゲームオーバー判定フラグ

int main() {
    // 1. 【 A 】処理：ウィンドウの生成や画面サイズの設定などを行う
    InitGame(); 

    // 2. メインループ：ゲームオーバーになるまで、高速で同じ処理を繰り返す
    // ループの条件式には何が入るでしょうか？
    while (! is_game_over) {

        // --- ① プレイヤーの操作 ---
        if ( IsRightKeyPressed() ) {
            paddle_x = paddle_x + 5.0f;
        }
        if ( IsLeftKeyPressed() ) {
            paddle_x = paddle_x - 5.0f;
        }

        // --- ② 移動処理 ---
        // ボールの現在の座標に、速度を足してボールを進める
        ball_x = ball_x +  ball_vx;
        ball_y = ball_y +  ball_vy;

        // --- ③ 当たり判定（左右の壁） ---
        // ボールが画面の左端（0）未満、または右端（SCREEN_WIDTH）を超えたら
        if ( ball_x < 0 || ball_x > SCREEN_WIDTH ) {
            // X方向の移動速度を反転（プラスとマイナスを入れ替える）させる
            ball_vx = -ball_vx; 
        }

        // --- ④ 画面の描画 ---
        ClearScreen();              // 画面を一度真っ黒に消去する
        DrawPaddle(paddle_x, 450);  // 新しい座標にパドルを描画
        DrawBall(ball_x, ball_y);   // 新しい座標にボールを描画
        UpdateScreen();             // 裏で描いた画面を表に表示する

        // --- ⑤ ウェイト処理 ---
        Wait(16); // 約60FPS（1秒間に60回ループ）にするため、16ミリ秒待つ
    }

    // 終了処理（メモリの解放など）
    CleanUp();
    return 0;
}