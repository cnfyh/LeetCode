#include <array>
#include<string>
/* 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
字母异位词是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。
*/
// a=97，s 和 t 仅包含小写字母
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size()!=t.size()) {
            return false;
        }
        std::array<int,26> hashlist {}; //指定初值为0；
        //hashlist.fill(0);      //此方法可以将哈希表初始化为0
        for (int i=0; i<s.size(); i++) {
            int s_num=(int)s[i]-97;
            int t_num=(int)t[i]-97;
            hashlist[s_num]++;
            hashlist[t_num]--;
        }
        for (int i=0; i<26; i++) {
            if (hashlist[i]) {
                return false;
            }
        }
        return true;
    }
};