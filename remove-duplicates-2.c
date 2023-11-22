/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现2次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int removeDuplicates(int *nums,int numsSize){
    if(numsSize >= 0 && numsSize <= 2){
        return numsSize;
    }

    int *p1,*p2,*tail;
    tail = nums + numsSize - 1;
    p1 = p2 = nums;
    while(p1 != tail){
        //note: p2 should not points to an address out of range
        while(p2 != tail && *p2 == *p1){
            p2++;
        }

        if(p2 - p1 <= 2){
            p1 = p2;
        }else{
            //consider the corner case:[1,1,4,4,4,4], when handling 4, 
            //p2 will points to the last 4, but not the one after the last 4
            if((p2 != tail) || (*p2 != *p1)){
                int moveSteps = p2 - p1 -2;
                p1 = p1 + 2;
                memcpy(p1,p2,sizeof(int)*(tail-p2+1));
                tail = tail - moveSteps;
                p2 = p1; //reset p2 to p1;
            }else{
                int moveSteps = p2 - p1 -1;
                tail = tail - moveSteps;
                p1 = tail;
            }

        }
    }
    return tail - nums + 1;
}

void main(){
    int nums1[]={1,1,1,2,2,3},expNums1[]={1,1,2,2,3},size1=0;
    size1 = removeDuplicates(nums1,sizeof(nums1)/sizeof(nums1[0]));
    printf("size1=%d\n",size1);
    assert(size1 == sizeof(expNums1)/sizeof(expNums1[0]));
    for(int i = 0; i < size1; i++){
        assert(nums1[i] == expNums1[i]);
        printf("nums1[%d]=%d\n",i,nums1[i]);
    }

    int nums2[]={0,0,1,1,1,1,2,3,3},expNums2[]={0,0,1,1,2,3,3},size2=0;
    size2 = removeDuplicates(nums2,sizeof(nums2)/sizeof(nums2[0]));
    printf("size2=%d\n",size2);
    assert(size2 == sizeof(expNums2)/sizeof(expNums2[0]));
    for(int i = 0; i < size2; i++){
        assert(nums2[i] == expNums2[i]);
        printf("nums2[%d]=%d\n",i,nums2[i]);
    }

    int nums3[]={},size3=0;
    size3 = removeDuplicates(nums3,0);
    assert(size3 == 0);
    printf("size3=%d\n",size3);

    int nums4[]={1},size4=0;
    size4 = removeDuplicates(nums4,1);
    assert(size4 == 1);
    printf("size4=%d\n",size4);

    int nums5[]={1,2},size5=0;
    size5 = removeDuplicates(nums5,2);
    assert(size5 == 2);
    printf("size5=%d\n",size5);   

    int nums6[]={0,0,1,1,1,1,2,3,3,4,4,4,4},expNums6[]={0,0,1,1,2,3,3,4,4},size6=0;
    size6 = removeDuplicates(nums6,sizeof(nums6)/sizeof(nums6[0]));
    printf("size6=%d\n",size6);
    assert(size6 == sizeof(expNums6)/sizeof(expNums6[0]));
    for(int i = 0; i < size6; i++){
        assert(nums6[i] == expNums6[i]);
        printf("nums6[%d]=%d\n",i,nums6[i]);
    }    
}