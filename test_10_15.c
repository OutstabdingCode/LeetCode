#define _CRT_SECURE_NO_WARNINGS 1
//�Ƴ�Ԫ��
int removeElement(int* nums, int numsSize, int val) 
{
    //����ԭ�ظ��Ƿ�
    //src�����渲��ֵ��dst������������
    int src = 0, dst = 0;
    //��������
    while (dst < numsSize)
    {
        //���±�Ϊdst��Ԫ����ָ����ֵһ��ʱdst�ƶ��������и���
        if (nums[dst] == val)
        {
            dst++;
        }
        else
        {
            nums[src] = nums[dst];
            src++;
            dst++;
        }
    }
    return src;

}
//ɾ�����������е��ظ���
int removeDuplicates(int* nums, int numsSize) 
{
    //ԭ�ظ���
    int cur = 0, next = 1, src = 0;
    //next���������Խ��
    while (next < numsSize)
    {
        //���ֵ��ȣ��±�һ���ƶ�
        if (nums[cur] == nums[next])
        {
            cur++;
            next++;
        }
        else
        {
            //�����ǵ�ֵ��ͬʱ��cur���±�һ�����ظ����ֵ��Ǹ�����
            nums[src] = nums[cur];
            src++;
            cur++;
            next++;
        }
    }
    //��nextԽ��ʱ�����һ��Ԫ�ػ�û�и���
    nums[src] = nums[cur];
    src++;
    return src;

}