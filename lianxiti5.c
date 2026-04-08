/*在键盘输入任何n个数，分别统计所有奇数的和、奇数的个数、所有偶数的和、偶数的个数。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char line[1024];
    int num;
    int odd_sum = 0, odd_count = 0;
    int even_sum = 0, even_count = 0;

    printf("请输入任意个整数（以空格分隔，按回车结束）：\n");
    fgets(line, sizeof(line), stdin);

    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        num = atoi(token);
        if (num % 2 == 0) {
            even_sum += num;
            even_count++;
        } else {
            odd_sum += num;
            odd_count++;
        }
        token = strtok(NULL, " \t\n");
    }

    printf("\n统计结果：\n");
    printf("奇数个数：%d，奇数之和：%d\n", odd_count, odd_sum);
    printf("偶数个数：%d，偶数之和：%d\n", even_count, even_sum);

    return 0;
}
