#include <unordered_map>
#include<vector>
/*
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案
2 <= nums.length <= 104
*/
/* 暴力枚举 */
class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int>res(2);
        int i,j;
        for (i=0; i<nums.size(); i++) {
            for (j=i+1; j<nums.size(); j++) {
                if (nums[i]+nums[j]==target) {
                    goto labal;
                }
            }
        }
        labal:return std::vector<int>{i,j};
    }
};
/* 哈希表 */

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int>hashmap; //无需map插入更快，真是不会对插入元素排序
        int i;
        int j;
        for (i=1; i<nums.size(); i++) {
            hashmap[nums[i-1]]=i-1;
            int findnum=target-nums[i];
            if (hashmap.count(findnum)) {
                j=hashmap[findnum];
                break;
            }
        }
        return std::vector<int>{i,j};
    }
};
