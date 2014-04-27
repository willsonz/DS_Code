// 河内塔问题----递归的应用
#include <stdio.h>
#include <stdlib.h>

int c = 0;      // 搬动次数

void hanoi(int n, char x, char y, char z);
void move(char x, int n, char z);

void hanoi(int n, char x, char y, char z)
{
    // 将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘
    // 按规则搬到塔座z上,y可做辅助塔座;
    if (n == 1)
        move(x, 1, z);
    else {
        hanoi(n-1, x, z, y);    // 将x上编号1至n-1的圆盘移到y
        move(x, n, z);
        hanoi(n-1, y, x, z);    // 将y上编号为至n-1的圆盘移到z
    }
}

void move(char x, int n, char z)
{
    printf("%i. Move disk %i from %c to %c\n", ++c, n, x, z);
}

int main()
{
    hanoi(10, 'x', 'y', 'z');

    return 0;
}
