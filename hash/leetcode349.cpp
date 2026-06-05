#include <unordered_set>
#include <vector>

class Solution2 {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set(nums1.begin(), nums1.end());
        std::unordered_set<int> result;
        for (int i=0;i< nums2.size();i++) {
            if (set.count(nums2[i])) {       // 在 nums1 中找到了
                result.insert(nums2[i]);        // 加入结果（自动去重）
                set.erase(nums2[i]);         // 删掉，避免重复判断
            }
        }
        return std::vector<int>(result.begin(), result.end());
    }
};



