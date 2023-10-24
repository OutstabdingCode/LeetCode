#include <stdio.h>
/*
* ������ ������ʽ  num �ǰ��մ����ҵ�˳���ʾ�����ֵ����顣
���磬���� num = 1321 ��������ʽ�� [1,3,2,1] ��
���� num �������� ������ʽ �������� k ������ ���� num + k �� ������ʽ ��
*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int flag = k, kSize = 0, dec = 0;//dec��ʾ��λ
    while (flag)
    {
        //��k��λ��
        kSize++;
        flag = flag / 10;
    }
    //���֮����ܵ�λ��
    int len = numSize > kSize ? numSize : kSize;
    //���ٴ洢�ռ�
    int* retArr = (int*)malloc(sizeof(int) * (len + 1));
    int nI = numSize - 1, rI = 0;
    while (len)
    {
        int ret = 0;
        if (nI >= 0)
        {
            ret = num[nI];
        }
        //��ӵĽ��
        int result = ret + k % 10 + dec;
        if (result > 9)//�ж��Ƿ��λ
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
    //��ѭ������ʱ,��λΪ1ʱ˵�������ݵĻ��и�λû�м�1
    if (dec == 1)
    {
        retArr[rI] = 1;
        rI++;
    }
    //��������
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