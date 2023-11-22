/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

#define TRUE 0x1
#define FALSE 0x0

int removeDuplicates(int *nums,int numsSize){
    if(numsSize == 0 || numsSize == 1){
        return numsSize;
    }

    int *tmpArray = (int *)malloc(sizeof(int) * numsSize);
    int finalLen = 1, found;
    tmpArray[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        found = FALSE;
        for(int j = 0; j < finalLen; j++){
            if(tmpArray[j] == nums[i]){
                found = TRUE;
                break;
            }
        }
        if(!found){
            tmpArray[finalLen++] = nums[i];
        }
    }
    memcpy(nums,tmpArray,sizeof(int)*finalLen);
    free(tmpArray);
    return finalLen;
}

void main(){
    int nums1[]={1,2,2},expNums1[]={1,2},size1=0,i;
    size1 = removeDuplicates(nums1,3);
    printf("size1=%d\n",size1);
    assert(size1 == (sizeof(expNums1)/sizeof(expNums1[0])));
    for(i = 0; i < size1; i++){
        assert(nums1[i] == expNums1[i]);
    }

    int nums2[]={0,0,1,1,1,2,2,3,3,4},expNums2[]={0,1,2,3,4},size2=0;
    size2 = removeDuplicates(nums2,10);
    assert(size2 == (sizeof(expNums2)/sizeof(expNums2[0])));
    for(i = 0; i < size2; i++){
        assert(nums2[i] == expNums2[i]);
    }

    int nums3[]={0},expNums3[]={0},size3=0;
    size3 = removeDuplicates(nums3,1);
    assert(size3 == (sizeof(expNums3)/sizeof(expNums3[0])));
    for(i = 0; i < size3; i++){
        assert(nums3[i] == expNums3[i]);
    }

    int nums4[]={},expNums4[]={},size4=0;
    size4 = removeDuplicates(nums4,0);
    assert(size4 == 0);
}