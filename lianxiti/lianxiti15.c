//查看存入数字的地址在哪里
#include <stdio.h>

int main() {
    int num = 45;   // 你存入的数字

    // 用 & 运算符获取 num 的地址
    printf("变量 num 的值是: %d\n", num);
    printf("变量 num 的地址是: %p\n", (void*)&num);

    return 0;
}