// 栈应用---迷宫求解

// 数据元素类型定义
typedef struct {
    int     ord;        // 通道块在路径上的'序号‘
    PosType seat;       // 通道块在迷宫中的'坐标位置'
    int     di;         // 从此通道块走向下一通道块的'方向'
} SElemType;

// 所需头文件
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// 函数定义
Status MazePath( MazeType maze, PosType start, PosType end)
{
    // 若迷宫maze中存在从入口start到出口end的通道,则求得一条存放在栈中
    // (从栈底到栈顶), 并返回TRUE,否则返回FALSE
    InitStack(S);
    curpos = start;     // 设定'当前位置'为'入口位置'

    do {
        if (Pass(curpos)) {     // 当前位置可通过,即是未走过的通道块
            FootPrint(curpos);  // 留下足迹

            e = (curstep, curpos, 1);
            Push(S, e);         // 加入路径

            if (cuepos =- end)
                return (TRUE);  // 到达终点

            curpos = NextPos(curpos, 1);    // 下一位置是当前位置的东邻
            curstep++;          // 探索下一步
        }
        else {  // 当前位置不能通过
            if (!StackEmpty(S)) {
                Pop(S, e);
                while (e.di == 4 && !StackEmpty(S)) {
                    MarkPrint(e.seat);      // 留下不能通过的标志,并退回一步
                    Pop(S, e);
                }
            }

            if (e.di < 4) {
                e.di++;
                Push(S, e);
                curpos = NextPos(e.seat, e.di);
            }
        }
    } while (!StackEmpty(S));

    return (FALSE);
}
