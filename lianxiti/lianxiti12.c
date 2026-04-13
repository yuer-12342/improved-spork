#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

// 心形隐式方程: (x^2 + y^2 - 1)^3 - x^2 * y^3 <= 0
// 将坐标映射到控制台字符网格

#define WIDTH  70      // 控制台宽度（字符数）
#define HEIGHT 30      // 控制台高度（字符数）
#define SCALE  2.2f    // 缩放系数，控制心形大小

// 全局控制台句柄
HANDLE hConsole;

// 设置光标位置
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(hConsole, coord);
}

// 隐藏光标（减少闪烁）
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// 设置颜色（前景色）
void setColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

// 绘制单帧爱心，scale 为当前缩放比例（0.8 ~ 1.2）
void drawHeart(float scale) {
    char screen[HEIGHT][WIDTH + 1];
    // 初始化屏幕为空格
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
        screen[i][WIDTH] = '\0';
    }

    // 心形方程遍历
    for (float y = -1.2f; y <= 1.2f; y += 0.035f) {
        for (float x = -1.5f; x <= 1.5f; x += 0.025f) {
            // 缩放后的坐标
            float xs = x / scale;
            float ys = y / scale;
            float eq = pow(xs*xs + ys*ys - 1, 3) - xs*xs * ys*ys*ys;
            if (eq <= 0.0f) {
                // 映射到屏幕坐标
                int cx = (int)((x + 1.5f) / 3.0f * WIDTH);
                int cy = (int)((1.2f - y) / 2.4f * HEIGHT);
                if (cx >= 0 && cx < WIDTH && cy >= 0 && cy < HEIGHT) {
                    // 双色：左半红，右半粉（根据原始 x 坐标）
                    if (xs < 0)
                        screen[cy][cx] = '1';   // 标记为红色区域
                    else
                        screen[cy][cx] = '2';   // 标记为粉色区域
                }
            }
        }
    }

    // 输出到控制台
    for (int i = 0; i < HEIGHT; i++) {
        gotoxy(0, i);
        for (int j = 0; j < WIDTH; j++) {
            if (screen[i][j] == '1') {
                setColor(12);  // 亮红色
                printf("*");
            } else if (screen[i][j] == '2') {
                setColor(13);  // 亮粉色（品红）
                printf("*");
            } else {
                setColor(7);   // 白色（背景默认）
                printf(" ");
            }
        }
    }
}

int main() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hideCursor();
    system("cls");   // 清屏

    float scale = 1.0f;
    float delta = 0.008f;
    int frame = 0;

    while (1) {
        drawHeart(scale);
        // 简单延时（约 30 fps）
        Sleep(30);
        // 更新缩放比例，实现跳动
        scale += delta;
        if (scale > 1.2f) {
            scale = 1.2f;
            delta = -delta;
        } else if (scale < 0.8f) {
            scale = 0.8f;
            delta = -delta;
        }
        // 可选：根据帧数微调，让跳动更自然
        // 可以用 sin 函数，但为了纯 C 简单起见，用线性往返
    }
    return 0;
}