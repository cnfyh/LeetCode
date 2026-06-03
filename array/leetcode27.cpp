#include<vector>
/* 移除元素 */
/*
给你一个数组 nums 和一个值 val，你需要-原地-移除所有数值等于 val 的元素。
元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。
*/
/* 双指针*/
/*
快指针指向数组所需要的元素，慢指针为待填元素下标
*/
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int slow=0;
        for (int fast=0; fast<nums.size(); fast++) {
            if (nums[fast]!=val) {
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
/*
测试函数
int main(){
    Solution s;
    std::vector<int> nums;
    s.sortedSquares(nums);
    for (int num : res) {
        std::cout<<num<<' ';
    }
    return 0;
}

*/

