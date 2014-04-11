// Algorism 1.19
// 计算 i! x 2pow(i) 的值并分别存入数组a［ARRSIZE］中；
// 错误处理：
//  n > ARRSIZE 时错误，输出错误信息并返回ERROR；
//  计算结果 > MAXINT(计算机允许整数最大值)时错误；
//
#include <stdio.h>
#define OK 1
#define ERROR 0
#define ARRSIZE 100
#define MAXINT 1665

int cal_int(int a[], int n)
{
    int i;

    if (n > ARRSIZE) {
        printf("ERROR: 数值个数大于数组大小\n");
        return ERROR;
    }

    for (i=0; i<n; i++) {
        if (!i)
            a[i] = 2;
        else
            a[i] = i * a[i-1] * 2;

        if (a[i] > MAXINT) {
            printf("ERROR:计算结果溢出！\n");
            return ERROR;
        }
    }
    return OK;
}

int main()
{
    int a[ARRSIZE], n;
    n = 10;
    cal_int(a, n);
}

