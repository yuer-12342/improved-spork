<<<<<<< HEAD
/*从键盘输入三个数，将它们按从大到小进行排序，然后输出。*/
#include <stdio.h>
int main()
{
    float a,b,c;
    float temp;
    printf("请输入三个数（空格或回车分隔）：");
    scanf("%f %f %f", &a, &b, &c);
    if (a<b)
    {
        temp = a;
        a = b;
        b = temp;
        
    }
    if (a<c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b<c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    printf("从大到小排序：%.1f > %.1f > %.1f\n",a,b,c);
    return 0;
}
=======
/*从键盘输入三个数，将它们按从大到小进行排序，然后输出。*/
#include <stdio.h>
int main()
{
    float a,b,c;
    float temp;
    printf("请输入三个数（空格或回车分隔）：");
    scanf("%f %f %f", &a, &b, &c);
    if (a<b)
    {
        temp = a;
        a = b;
        b = temp;
        
    }
    if (a<c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b<c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    printf("从大到小排序：%.1f > %.1f > %.1f\n",a,b,c);
    return 0;
}
>>>>>>> 396a23ae414c43fdab6dff61adf422139cf9faa3
