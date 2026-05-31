#include<vector>
#include<iostream>
/*
给你一个按 非递减顺序(存在负数)排序的整数数组 nums，返回每个数字的平方组成的新数组
要求也按非递减顺序排序。
请你设计时间复杂度为 O(n) 的算法解决本问题
*/
/*思路：寻找分分界出，然后双指针循环一边排好序*/

/*
易错处：全负数组，单独判断
*/
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int left;
        int right;
        int i;
        int lens=nums.size();
        int k=0;
        std::vector<int>res(lens);
        //寻找左右指针的起始位置
        for (i=0; i<lens; i++) {
            if (nums[i]>=0) {
                left=i-1;
                right=i;
                break;
            }
        }
        if (i==lens) {
            i--;
            while (i>=0) {
                res[k]=nums[i]*nums[i];
                k++;
                i--;
            }
        }else {
            while (left>=0 && right<lens) {
                if (nums[right]*nums[right]<=nums[left]*nums[left]) {
                    res[k]=nums[right]*nums[right];
                    k++;
                    right++;
                }else if (nums[right]*nums[right]>nums[left]*nums[left]) {
                    res[k]=nums[left]*nums[left];
                    k++;
                    left--;
                }
            }
            while (left>=0) {
                res[k]=nums[left]*nums[left];
                k++;
                left--;
            }
            while (right<lens) {
                res[k]=nums[right]*nums[right];
                k++;
                right++;
            }
        }
        
        return res;
    }
};
