#include <vector>
//using namespace std;
/* 二分搜索 */
/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  
写一个函数搜索 nums 中的 target，如果 target 存在返回下标，否则返回 -1。

你必须编写一个具有 O(log n) 时间复杂度的算法。
*/
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while (left<=right) { //--可以相等 eg： nums={5}，target=5 ，return 0
            int mid=left+(right-left)/2;
            if (target>nums[mid]) {
                left=mid+1;
            }else if (target<nums[mid]) {
                right=mid-1;
            }else {
                return mid;
            }
        }
        return -1;
    }
};