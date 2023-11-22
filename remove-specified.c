/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    if(numsSize ==0 ){
        return 0;
    }
    int finalLen = numsSize;
    int *head,*tail;
    head = nums;
    tail = nums + numsSize - 1;
    while(head != tail){
        //remove the tailing duplicates, but keep the tail not out of range
        while(tail != head){
            if(*tail == val){
                tail--;
                finalLen--;
            }else{
                break;
            }
        }

        //test if tail equals head
        if(tail == head){
            if(*head == val){
                return finalLen -1;
            }else{
                return finalLen;
            }
        }

        //handle tail not equals head
        if(*head == val){
            *head = *tail;
            finalLen--;
            tail--;
        }else{
            head++;
        }
    }
    return finalLen;
}
int main(){
    int nums1[] = {3,2,2,3},nums2[] = {0,1,2,2,3,0,4,2};
    int i,size1,size2;
    size1 = removeElement(nums1,4,3);
    for(i = 0; i < size1; i++){
        printf("nums1[%d]=%d\n",i,nums1[i]);
    }
    
    printf("----------\n");
    size2 = removeElement(nums2,8,2);
    for(i = 0; i < size2; i++){
        printf("nums2[%d]=%d\n",i,nums2[i]);
    }

    int nums3[]={};
    int size3 = removeElement(nums3,0,0);
    printf("----------\n");
    printf("size3=%d\n",size3);

    int nums4[]={1};
    int size4 = removeElement(nums4,1,1);
    printf("----------\n");
    printf("size4=%d\n",size4);

    int nums5[]={3,3};
    int size5 = removeElement(nums5,2,3);
    printf("----------\n");
    printf("size5=%d\n",size5);

    int nums6[]={4,5};
    int size6 = removeElement(nums6,2,5);
    printf("----------\n");
    printf("size6=%d\n",size6);
}
/*
The output is:
nums1[0]=2
nums1[1]=2
----------
nums2[0]=0
nums2[1]=1
nums2[2]=4
nums2[3]=0
nums2[4]=3
----------
size3=0
----------
size4=0
*/