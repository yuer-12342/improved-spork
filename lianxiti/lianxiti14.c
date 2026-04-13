#include <stdio.h>
#include <math.h>

int main() {
    float x, y;
    // 心形公式: (x^2 + y^2 - 1)^3 - x^2 * y^3 = 0
    for (y = 1.5f; y > -1.5f; y -= 0.1f) {
        for (x = -1.5f; x < 1.5f; x += 0.05f) {
            float equation = pow(x*x + y*y - 1, 3) - x*x * y*y*y;
            putchar(equation <= 0.0f ? '*' : ' ');
        }
        putchar('\n');
    }
    return 0;
}