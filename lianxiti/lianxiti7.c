/*用于测试lianxiti6.c当中的代码而生成的随机数*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int n;               // 要生成的数字个数
    int min = 0, max = 999;  // 随机数范围（可修改）
    FILE *fp;

    printf("请输入要生成的随机整数个数：");
    scanf("%d", &n);

    // 打开文件（若存在则覆盖）
    fp = fopen("data.csv", "w");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return 1;
    }

    srand((unsigned)time(NULL));  // 用当前时间播种随机数

    for (int i = 1; i <= n; i++) {
        int num = rand() % (max - min + 1) + min;
        fprintf(fp, "%d", num);
        if (i % 10 == 0)          // 每10个数字换行
            fprintf(fp, "\n");
        else if (i < n)
            fprintf(fp, ", ");
    }

    fclose(fp);
    printf("已生成 %d 个随机整数，保存到 data.csv\n", n);
    return 0;
}