// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

// 示例 1：
// 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// 输出：[1,2,2,3,5,6]
// 解释：需要合并 [1,2,3] 和 [2,5,6] 。
// 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

// 示例 2：
// 输入：nums1 = [1], m = 1, nums2 = [], n = 0
// 输出：[1]
// 解释：需要合并 [1] 和 [] 。
// 合并结果是 [1] 。

// 示例 3：
// 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
// 输出：[1]
// 解释：需要合并的数组是 [] 和 [1] 。
// 合并结果是 [1] 。
// 注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

// 进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if(nums1Size != (m+n)){
        return;
    }
    if(n == 0){
        return;
    }
    if(m == 0){
        memcpy(nums1,nums2,sizeof(int)*n);
        return;
    }
    
    //handle case for m!=0 and n!=0
    int *tmpArray = (int *)malloc(sizeof(int)*(m+n));
    int i,idx1=0,idx2=0;
    for(i = 0; i < (m+n); i++){
        if((idx1 < m) && (idx2 < n)){
            if(nums1[idx1] <= nums2[idx2]){
                tmpArray[i] = nums1[idx1++];
            }else{
                tmpArray[i] = nums2[idx2++];
            }
        }
        if(idx1 == m){
            memcpy(tmpArray+i+1,nums2+idx2,sizeof(int)*(n-idx2));
            break;
        }
        if(idx2 == n){
            memcpy(tmpArray+i+1,nums1+idx1,sizeof(int)*(m-idx1));
            break;
        }
    }
    memcpy(nums1,tmpArray,sizeof(int)*(m+n));
    free(tmpArray);
}


int main() {
    int i,nums1[] = {1,2,3,0,0,0},nums2[]={2,5,6};
    merge(nums1,6,3,nums2,3,3);
    for(i = 0; i < 6; i++){
        printf("nums1[%d]=%d\n",i,nums1[i]);
    }
    printf("------------\n");
    int nums3[]={1},nums4[]={};
    merge(nums3,1,1,nums2,0,0);
    for(i = 0; i < 1; i++){
        printf("nums3[%d]=%d\n",i,nums3[i]);
    }
    printf("------------\n");
    int nums5[]={0},nums6[1]={};
    merge(nums5,1,0,nums6,1,1);
    for(i = 0; i < 1; i++){
        printf("nums5[%d]=%d\n",i,nums5[i]);
    }
    return 0;
}


/* The output result:
nums1[0]=1
nums1[1]=2
nums1[2]=2
nums1[3]=3
nums1[4]=5
nums1[5]=6
------------
nums3[0]=1
------------
nums5[0]=0
*/