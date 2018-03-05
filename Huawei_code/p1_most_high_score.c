#include<stdio.h>

// 求最高分
// 输入描述:
// 输入包括多组测试数据。
// 每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
// 学生ID编号从1编到N。
// 第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
// 接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
// 当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。

// 输出描述:
// 对于每一次询问操作，在一行里面输出最高成绩.
int main() 
{ 
    int M,N,x,y;
    while(~scanf("%d%d",&N,&M))//非空继续循环
    {
        char s;
        int a[N];
        for (int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }

        while(M--)
        {
            scanf(" %c%d%d",&s,&x,&y); //特别注意单个字符前要空格
            // printf("%c",s);
            // printf("%d",x);
            // printf("%d",y);
            if (s=='Q')
            {
                if (x>y)//防止输入的范围x>y
                {
                    int temp;
                    temp=y;
                    y=x;
                    x=temp;
                }
                int max=0;
                for (int i=x;i<=y;i++)//求指定序号间的最大值
                {
                    if (a[i-1]>max)
                        max=a[i-1];
                }
                printf("%d\n",max);
            }
            else if (s=='U')
                a[x-1]=y;//替换对应序号x的值为y
        }
    }
    return 0;
}