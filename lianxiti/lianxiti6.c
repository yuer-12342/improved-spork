/*根据lianxiti5.c的题目修改成，统计excel数据表中的偶数个数和奇数个数，以及偶数的和，奇数的和*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;                      // 文件指针
    char line[1024];               // 存储每一行
    char *token;                   // 存储分割后的数字字符串
    long long num;                 // 存储转换后的整数
    long long odd_sum = 0, even_sum = 0; // 奇偶数和（用 long long 防止大数溢出）
    long long odd_count = 0, even_count = 0; // 奇偶数个数

    // 1. 打开CSV文件
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("错误：无法打开文件 data.csv，请确保文件存在！\n");
        return 1;
    }

    // 2. 逐行读取文件
    while (fgets(line, sizeof(line), fp)) {
        // 3. 分割每一行，提取数字
        token = strtok(line, ",\n"); // 按逗号或换行符分割
        while (token != NULL) {
            num = atoll(token); // 将字符串转换为长整型数字
            
            // 4. 判断奇偶并统计
            if (num % 2 == 0) {
                even_sum += num;
                even_count++;
            } else {
                odd_sum += num;
                odd_count++;
            }
            token = strtok(NULL, ",\n"); // 继续分割下一个数字
        }
    }

    // 5. 关闭文件
    fclose(fp);

    // 6. 输出统计结果
    printf("------- 统计结果 -------\n");
    printf("奇数个数：%lld，奇数之和：%lld\n", odd_count, odd_sum);
    printf("偶数个数：%lld，偶数之和：%lld\n", even_count, even_sum);

    return 0;
}