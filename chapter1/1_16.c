// Algorism 1.16 - Sort_three.c
// 算法：自大至小依次输出顺序输入的x, y, z
// 条件：输入的x，y，z为实数

#include <stdio.h>
#define OK 1
#define ERROR 0

int sort_three(void)
{
    int i, j;
    float values[3], temp;
    // 读入X， Y， Z
    for(i=0; i<3; i++) {
        scanf(" %f", &values[i]);
    }

    // 比较三个数字大小并输出
    for (i=0; i<3; i++) {
        for (j=i; j<3; j++) {
            if (values[j] < values[j+1]) {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }

    printf("%f > %f > %f\n", values[0], values[1], values[2]);
    return OK;
}

int main()
{
    sort_three();
    return 0;
}
