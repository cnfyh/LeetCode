
#include <vector>

/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和-大于等于-target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/
/*暴力求解--超时*/

class Solution0 {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int sum=0;
        int res=0;
        for (int i=0; i<nums.size(); i++) {
            sum=0;
            for (int j=i;j<nums.size();j++) {
                sum+=nums[j];
                if (sum>=target) {
                    if (res==0) {
                        res=j+1-i;
                    }else {
                        res=res<j+1-i?res:j+1-i;
                    }
                }
            }
        }
        return res;
    }
};
/*双指针法(滑动窗口)*/
/*
a+b+c>=target
b+c<target
*/
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int sum=0;
        int left=0;
        int res=0;
        for (int right=0; right<nums.size(); right++) {
            sum+=nums[right];
            while (sum>=target) { //找到下一个起始位置的值
                if (res==0) {
                        res=right+1-left;
                }else {
                    res=res<right+1-left?res:right+1-left;
                }
                sum-=nums[left++];
            }
        }
        return res;
    }
};
