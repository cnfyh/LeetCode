#include <unordered_map>
#include <vector>

/* 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n 
请你计算有多少个元组 (i, j, k, l) 能满足：
-----元组为四个元素相加等于0
· 0 <= i, j, k, l < n
· nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/
/* map 解题*/
class Solution2 {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        std::unordered_map<int, int>map1;
        std::unordered_map<int, int>map2;
        int size=nums1.size();
        int res=0;
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                map1[nums1[i]+nums2[j]]++;
            }
        }
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                map2[nums3[i]+nums4[j]]++;
            }
        }
        for (auto it1=map1.begin(); it1!=map1.end(); it1++) {
            auto it2=map2.find(-1*it1->first);
            if (it2!=map2.end()) {
                res+=it1->second * it2->second;
            }
        }
        return res;
    }
};
/* map解题优化版 
a+b+c+d=0;
map1存a+b出现的次数
直接查询-（c+d）的次数就可以
eg 1+2-1-2=0;
1+2=3，要想为0，c+d必须等于-3，在map查询3出现次数即可
*/
class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        std::unordered_map<int, int>map1;
        int size=nums1.size();
        int res=0;
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                map1[nums1[i]+nums2[j]]++;
            }
        }
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                auto it=map1.find(-(nums3[i]+nums4[j]));
                if (it!=map1.end()) {
                    res+=it->second;
                }
            }
        }
        return res;
    }
};