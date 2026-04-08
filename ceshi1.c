/*语句判断，输入一个学生的成绩判断评级，如果输入的值小于60则为不及格，大于等于60且小于80则为良好，大于等于80且小于100，则为优秀。*/
#include <stdio.h>
int main() 
{
    float mark;
    scanf("%f",&mark);
    if(mark < 100 && mark >= 80)
    {
        printf("成绩为%.2f,优秀",mark);
    }
    else if (mark >= 60 && mark < 80)
    {
        printf("成绩为%.2f,良好",mark);
    }
    else
    {
        printf("成绩为%.2f,不及格",mark);
    }
    
   
    return 0;
}