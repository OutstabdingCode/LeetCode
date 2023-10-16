#define _CRT_SECURE_NO_WARNINGS 1
//移除元素
int removeElement(int* nums, int numsSize, int val) 
{
    //采用原地覆盖法
    //src用来存覆盖值，dst用来遍历数组
    int src = 0, dst = 0;
    //遍历数组
    while (dst < numsSize)
    {
        //当下标为dst的元素与指定的值一样时dst移动，不进行覆盖
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
//删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize) 
{
    //原地覆盖
    int cur = 0, next = 1, src = 0;
    //next会存在数组越界
    while (next < numsSize)
    {
        //如果值相等，下标一起移动
        if (nums[cur] == nums[next])
        {
            cur++;
            next++;
        }
        else
        {
            //当它们的值不同时，cur的下标一定是重复出现的那个数字
            nums[src] = nums[cur];
            src++;
            cur++;
            next++;
        }
    }
    //当next越界时，最后一个元素还没有覆盖
    nums[src] = nums[cur];
    src++;
    return src;

}