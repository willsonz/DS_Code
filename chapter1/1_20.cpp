// Algorism 1.20
// 计算一元多项式的值，使用格式输入和输出
// 算法时间复杂度：O(n)
//
#include <stdio.h>
#include <math.h>
#define OK 1
#define ERROR 0

double uni_polynomial(int n)
{
    int a[n+1], x;                                  // 1次
    int i;
    double sum = 0.0;
    // 读入用户输入的a1，a2。。。值
    for (i=0; i <= n; i++) {
        printf("Please input the a%d: ", i);    // n+1次
        scanf(" %d", &a[i]);
    }
    // 读入x0
    printf("Please input the x0: ");
    scanf(" %d", &x);

    // 计算过程
    for (i = 0; i <= n; i++) {
        sum += a[i] * pow(x, i);            // n+1次
    }
    // 返回结果
    return sum;
}

int main()
{
    printf("\n %f \n", uni_polynomial(10));

    return OK;
}
