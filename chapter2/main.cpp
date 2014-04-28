// main.cpp - 主程序，主要为测试代码
//
#include <stdio.h>
#include "basic.h"

#include "sqlist.h"

int main(void)
{
    // 有关变量声明
    Sqlist L;       // 建立顺序表类型L，用于后期测试
    ElemType e;     // 建立L数据元素类型变量e
    ElemType cur_e, pre_e, next_e;      // 当前元素，前驱， 后继

    // 逐个进行边界测试
    if (InitList_sq(L))
        printf("the Sqlist is Init succsee!\n");
    else
        printf("the Sqlist is not init! somwthing happen!\n");

    int i, a[10];
    for (i=0; i<10; i++)
        a[i] = i;

    for(i = 0; i < 10; i++) {
        if (ListInsert_sq(L, i+1, a[i]))
            printf("%d num is insert seccess!\n", i);
        else
            printf("%d num is error\n", i);
    }

    printf("Length : %d\n", ListLength_sq(L));

    ListTraverse_sq(L, visit_sq);

    if (DestroyList_sq(L))
        printf("Sqlist is Destroy!\n");
    else
        printf("Sqlist is not Delete!\n");

    return 0;

}
