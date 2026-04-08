#include <stdio.h>

int main() {
    float mark;
    int valid;

    do {
        printf("请输入成绩(0~100):");
        valid = scanf("%f", &mark);  // 检查是否成功读取一个浮点数

        // 清除输入缓冲区（如果用户输入了非数字字符，防止无限循环）
        while (getchar() != '\n');

        if (valid != 1 || mark < 0 || mark > 100) {
            printf("输入无效！成绩必须在 0~100 之间，请重新输入。\n");
            valid = 0;  // 标记为无效，继续循环
        } else {
            valid = 1;  // 输入有效，退出循环
        }
    } 
    while (!valid);/*循环会先执行一次循环体（大括号里的代码），然后检查 while 后面的条件。如果条件为真，就跳回去再次执行循环体；如果条件为假，就退出循环。*/

    // 现在 mark 一定是 0~100 之间的数，可以安全判断
    if (mark >= 80) {
        printf("成绩为 %.2f,优秀\n", mark);
    } else if (mark >= 60) {
        printf("成绩为 %.2f,良好\n", mark);
    } else {
        printf("成绩为 %.2f,不及格\n", mark);
    }

    return 0;
}

