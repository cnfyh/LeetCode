#include <algorithm>
#include<vector>

/*
组 [nums[a], nums[b], nums[c], nums[d]] 
（若两个四元组元素一一对应，则认为两个四元组重复）：

·0 <= a, b, c, d < n
·a、b、c 和 d 互不相同
·nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。


*/
/* 可以优化 */

/*
优化思路，(极值剪枝)看当前最大和最小四元组与target的比值
当 当前最大 即cur + nums[n-3] + nums[n-2] + nums[n-1] <target 即说明当前不存在符合条件的四元组
当 当前最小 即cur + nums[i+1] + nums[i+2] + nums[i+3] >target 即说明当前不存在符合条件的四元组
*/

class Solution {
public:
   std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        int size=nums.size();
        if (size<4) {
            return res;
        }
        std::sort(nums.begin(),nums.end());
        for (int i=0; i+3<size; i++) {
            if (i>0 && nums[i]==nums[i-1]) { //首位去重
                continue;
            }
            if ((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) {  //极小值剪枝
                break;
            }
            if ((long long)nums[i]+nums[size-3]+nums[size-2]+nums[size-1] < target) {//极大值剪枝
                continue;
            }
            for (int j=i+1; j+2<size; j++) {
                if (j>i+1 && nums[j]==nums[j-1]) { //首位去重
                    continue;
                }
                if ((long long)nums[j]+nums[j+1]+nums[j+2] > target-nums[i]) {
                    break;
                }
                if ((long long)nums[j]+nums[size-2]+nums[size-1] < target-nums[i]) {
                    continue;
                }
                int left=j+1;
                int right=size-1;
                while (left<right) {
                    long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if (sum>target) {
                        right--;
                    }else if (sum<target) {
                        left++;
                    }else {
                        res.push_back(std::vector<int>{nums[i],nums[j],nums[left],nums[right]});
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
        }
       return res;
    }
};

/* 优化版：通用极值剪枝 + 溢出修复 */
class Solution2 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i + 3 < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            // 最小四元组 > target，后面更大，直接终止
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            // 当前i能凑出的最大四元组 < target，跳到下一个i
            if ((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            for (int j = i + 1; j + 2 < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left-1]) left++;
                        while (left < right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        return res;
    }
};