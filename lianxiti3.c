<<<<<<< HEAD
/*字符转换*/
#include <stdio.h>

int main()
{
    char zimu;
    int a;
    do
    {
        printf("请输入大写或者小写的26个字母:");
        zimu = getchar();
        while (getchar() != '\n');
        if ((zimu >= 'A'  && zimu <='Z')||(zimu >= 'a'  && zimu <='z'))
        {
            a = 1;
        }
        else
        {
            printf("错误：只能输入字母，请重新输入！\n");
            a = 0;
        }
    }while(!a);

 

	if(zimu>='A'&&zimu<='Z')
    {
        zimu=zimu+32;
	    printf("%c\n",zimu);
	}
	else if (zimu>='a'&&zimu<='z')
    {
        zimu=zimu-32;
        printf("%c\n",zimu);
    }
	else
    {
        printf("%c\n",zimu);
    }
    return 0;
}
=======
/*字符转换*/
#include <stdio.h>

int main()
{
    char zimu;
    int a;
    do
    {
        printf("请输入大写或者小写的26个字母:");
        zimu = getchar();
        while (getchar() != '\n');
        if ((zimu >= 'A'  && zimu <='Z')||(zimu >= 'a'  && zimu <='z'))
        {
            a = 1;
        }
        else
        {
            printf("错误：只能输入字母，请重新输入！\n");
            a = 0;
        }
    }while(!a);

 

	if(zimu>='A'&&zimu<='Z')
    {
        zimu=zimu+32;
	    printf("%c\n",zimu);
	}
	else if (zimu>='a'&&zimu<='z')
    {
        zimu=zimu-32;
        printf("%c\n",zimu);
    }
	else
    {
        printf("%c\n",zimu);
    }
    return 0;
}
>>>>>>> 396a23ae414c43fdab6dff61adf422139cf9faa3
