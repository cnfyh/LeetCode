#include <algorithm>
#include <float.h>
#include <functional>
#include <utility>
#include<vector>

/*
给你一个整数数组 nums ，
判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/

/*
题解：排序 + 双指针
1. 将数组升序排序，方便去重和双指针移动
2. 固定第一个数 nums[i]，用 left=i+1 和 right=n-1 两个指针向中间收拢
3. 若 sum > 0，right-- 减小总和；若 sum < 0，left++ 增大总和
4. 若 sum == 0，记录三元组，然后 left++ right-- 并跳过重复值
5. i 遇到重复值也跳过，避免答案出现重复三元组
6. 排序后若 nums[i] > 0 可直接 break，后面全正数不可能和为 0
*/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        /*std::function<void(std::vector<int>& nums,int left,int right)>quicksort;
        quicksort=[&quicksort](std::vector<int>& nums,int left,int right){
            if (left>=right) {
                return;
            }
            int temp=nums[left];
            int i=left;
            int j=right;
            while (i<j) {
                while (nums[j]>=temp && i<j) {
                    j--;
                }
                std::swap(nums[i],nums[j]);
                while (nums[i]<=temp && i<j) {
                    i++;
                }
                std::swap(nums[i],nums[j]);
            }
            nums[i]=temp;
            quicksort(nums,left,i-1);
            quicksort(nums,i+1,right);
        };
        quicksort(nums,0,nums.size()-1);*/
        std::vector<std::vector<int>> res;
        int size=nums.size();
        std::sort(nums.begin(),nums.end());
        if (size<3) {
            return res;
        }
        for (int i=0; i+2<size; i++) {
            if (i>0 && nums[i]==nums[i-1]) { //首位去重---原因：当与前一个重复时，下一个找到的为前一个的子集关系
                continue;
            }
            if (nums[i]>0) { //首位>0
                break;
            }
            if (nums[i]+nums[size-2]+nums[size-1]< 0) { //极大值< 0
                continue;;
            }
            int left=i+1;
            int right=size-1;
            while (left<right) {
                int sum=nums[i]+nums[left]+nums[right];
                if (sum>0) {
                    right--;
                }else if (sum<0) {
                    left++;
                }else {
                    res.push_back(std::vector<int>{nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while (left<right && nums[left]==nums[left-1]) { //保证合法去重
                        left++;
                    }
                    while (left<right && nums[right]==nums[right+1]) {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
