/*
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/
#include <stdio.h>
#include <stdlib.h>

int majorityElement(int *nums,int numsSize){
    //as array is not empty, we don't need to handle numsSize == 0 case
    if(numsSize == 1 || numsSize == 2){
        return nums[0];
    }

    int *p1,*p2,*p3,*tail, major;
    p1 = p2 = nums;
    tail = p3 = nums + numsSize - 1;

    while(p1 != tail){
        int replicas = 0; //indicate the repeat times of int pointed by p1;
        //count the replicas in positive direction
        while(*p2 == *p1){
            p2++;
            replicas++;
        }
        //count the replicas in negative direction
        while(p3 >= p2){
            if(*p3 == *p1){
                replicas++;
            }
            p3--;
        }

        if(replicas >= ((numsSize+1)/2)){
            major = *p1;
            break;
        }else{
            p1 = p2;
            p3 = tail;
        }
    }

    return major;
}

void main(){
    int nums1[]={3,2,3}, nums2[]={2,2,1,1,1,2,2},major = 0;
    major = majorityElement(nums1,sizeof(nums1)/sizeof(nums1[0]));
    printf("major = %d\n",major);

    major = majorityElement(nums2,sizeof(nums2)/sizeof(nums2[0]));
    printf("major = %d\n",major);
}