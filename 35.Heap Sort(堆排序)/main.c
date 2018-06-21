//
//  main.c
//  35.Heap Sort(堆排序)
//
//  Created by sunny&pei on 2018/6/21.
//  Copyright © 2018年 sunny&pei. All rights reserved.
//
/**
 堆排序：假设是大顶堆。此时序列的最大值就是堆顶的根节点。将它移走（就是将其与堆数组的末尾元素交换，此时末尾就是最大值），然后将剩余的n-1个序列重新构造成一个堆，这样就会得到n个元素中的次大值。如此反复执行，就能得到一个有序的序列了。
 */
#include <stdio.h>
typedef struct {
    int r[10];
    int length;
}Sqlist;
void swap(Sqlist *L,int i,int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

/**
 已知L->[s..m]中记录的关键字除L->r[s]外均满足堆的定义
 本函数调整L->r[s]的关键字。使L->r[s..m]成为一个大顶堆
 */
void HeapAdjust(Sqlist *L,int s,int m){
    int j ,temp;
    temp = L->r[s];
    for (j = s*2 ; j<=m; j *= 2) {
        //判断左右孩子的大小，如果左孩子小，则++j；
        if (L->r[j]<L->r[j+1] && j<m) {
            ++j;
        }
        //判断结点与较大孩子的值得大小
        if (temp >= L->r[j]) {
            //如果大，就结束
            break;
        }
        //赋值，使得结点值最大
        //但是，此时L->r[s]和L->r[j]的值一样，待会需要将值，换过来。
        L->r[s] = L->r[j];
        //这一操作，很好！！！用在break后，也改变了s的值
        s = j;
//        printf("%d",L->r[s]);
    }
    L->r[s] = temp;
    
}
void HeapSort(Sqlist *L){
    int i;
    for (i = L->length/2; i>0; i--) {
        //把L中的r构建成一个大顶堆
        HeapAdjust(L,i,L->length);
        
        
    }
    for (i = L->length; i>1; i--) {
        swap(L, 1, i);/*将堆顶记录和当前未排序子序列的最后一个记录交换*/
        HeapAdjust(L,1,i-1);/*将L->[1..i-1]重新调整为大顶堆*/
    }
}

/**
 总结：堆排序；
 时间复杂度O(nLogn)
 不稳定排序，比较和交换是跳跃式的。
 不适合待排序序列个数较少的情况。
 */
int main(int argc, const char * argv[]) {
    Sqlist L;
    L.length = 9;
    L.r[1] = 9;
    L.r[2] = 7;
    L.r[3] = 8;
    L.r[4] = 6;
    L.r[5] = 5;
    L.r[6] = 4;
    L.r[7] = 3;
    L.r[8] = 2;
    L.r[9] = 1;
    printf("排序前：\n");
    for (int i = 1; i<=L.length; i++) {
        printf("%d ",L.r[i]);
    }
    HeapSort(&L);
    printf("\n排序后：\n");
    for (int i = 1; i<=L.length; i++) {
        printf("%d ",L.r[i]);
    }
    printf("\n,%d",L.length);
    return 0;
}
