/*用户任意输入多个无要求的数字，不管正负还是小数、整数，统一可以计算出最大公约数和最小公倍数*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 求两个正整数的最大公约数（辗转相除法）
long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// 求两个正整数的最小公倍数（先除后乘防溢出）
long long lcm_ll(long long a, long long b) {
    if (a == 0 || b == 0) return 0; // 0的LCM无定义
    return a / gcd_ll(a, b) * b;
}

int main() {
    char line[4096];
    printf("请输入多个数字（整数或小数，空格分隔），按回车结束：\n");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        printf("读取错误\n");
        return 1;
    }

    // 去掉末尾换行符
    line[strcspn(line, "\n")] = '\0';

    // 分割字符串
    char *token = strtok(line, " \t");
    if (token == NULL) {
        printf("未输入任何数字\n");
        return 1;
    }

    double nums[1000]; // 最多支持1000个数字
    int count = 0;
    do {
        nums[count++] = atof(token);
    } while ((token = strtok(NULL, " \t")) != NULL && count < 1000);

    // 确定所有数字中小数部分的最大位数
    int max_decimal = 0;
    for (int i = 0; i < count; i++) {
        char str[64];
        snprintf(str, sizeof(str), "%.10f", nums[i]); // 转换为字符串
        char *dot = strchr(str, '.');
        if (dot) {
            int len = strlen(dot + 1);
            // 去掉末尾无效的0
            while (len > 0 && dot[len] == '0') len--;
            if (len > max_decimal) max_decimal = len;
        }
    }

    // 计算缩放因子 scale = 10^max_decimal
    long long scale = 1;
    for (int i = 0; i < max_decimal; i++) {
        scale *= 10;
    }

    // 将所有数字乘以 scale 并四舍五入得到整数
    long long ints[1000];
    int has_zero = 0;
    for (int i = 0; i < count; i++) {
        long long val = (long long)round(nums[i] * scale);
        if (val < 0) val = -val; // 取绝对值
        ints[i] = val;
        if (val == 0) has_zero = 1;
    }

    if (has_zero) {
        printf("错误：输入中包含0（或乘以缩放因子后为0），最小公倍数无定义。\n");
        return 1;
    }

    // 计算多个数的最大公约数（两两迭代）
    long long g = ints[0];
    for (int i = 1; i < count; i++) {
        g = gcd_ll(g, ints[i]);
    }

    // 计算多个数的最小公倍数（两两迭代）
    long long l = ints[0];
    for (int i = 1; i < count; i++) {
        l = lcm_ll(l, ints[i]);
        if (l == 0) {
            printf("最小公倍数过大或出现0\n");
            return 1;
        }
    }

    // 输出结果
    if (max_decimal == 0) {
        // 整数情况
        printf("最大公约数 = %lld\n", g);
        printf("最小公倍数 = %lld\n", l);
    } else {
        // 小数情况，还原为原始比例
        double gcd_orig = (double)g / scale;
        double lcm_orig = (double)l / scale;
        printf("（统一放大 %lld 倍后计算）\n", scale);
        printf("最大公约数 ≈ %.6f\n", gcd_orig);
        printf("最小公倍数 ≈ %.6f\n", lcm_orig);
    }

    return 0;
}