#include <stdio.h>
/*
* 整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。
例如，对于 num = 1321 ，数组形式是 [1,3,2,1] 。
给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。
*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int flag = k, kSize = 0, dec = 0;//dec表示进位
    while (flag)
    {
        //求k的位数
        kSize++;
        flag = flag / 10;
    }
    //相加之后可能的位数
    int len = numSize > kSize ? numSize : kSize;
    //开辟存储空间
    int* retArr = (int*)malloc(sizeof(int) * (len + 1));
    int nI = numSize - 1, rI = 0;
    while (len)
    {
        int ret = 0;
        if (nI >= 0)
        {
            ret = num[nI];
        }
        //相加的结果
        int result = ret + k % 10 + dec;
        if (result > 9)//判断是否进位
        {
            retArr[rI] = result % 10;
            dec = 1;
        }
        else
        {
            retArr[rI] = result;
            dec = 0;
        }
        k = k / 10;
        nI--;
        rI++;
        len--;
    }
    //当循环结束时,进位为1时说明该数据的还有高位没有加1
    if (dec == 1)
    {
        retArr[rI] = 1;
        rI++;
    }
    //逆置数组
    int left = 0, right = rI - 1;
    while (left < right)
    {
        int temp = retArr[left];
        retArr[left] = retArr[right];
        retArr[right] = temp;
        left++;
        right--;
    }
    *returnSize = rI;
    return retArr;
}