#include <type_traits>
#include <vector>
//螺旋矩阵2
/*给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，
且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。*/
//1 <= n <= 20
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        int count=1;
        //初始化std::vector<int>arr(n,0),arr初始长度为n，初始值为0
        std::vector<std::vector<int>>Matrix(n,std::vector<int>(n)); 
        int left=0;
        int right=n-1;
        int up=0;
        int down=n-1;
        while (true) {
            //填入上边
            for (int i=left; i<=right; i++) {
                Matrix[up][i]=count++;
            }
            if (++up>down) {
                break;
            }
            //填入右边
            for (int i=up; i<=down; i++) {
                Matrix[i][right]=count++;
            }
            if (--right<left) {
                break;
            }
            //填入下边
            for (int i=right; i>=left; i--) {
                Matrix[down][i]=count++;
            }
            if (--down<up) {
                break;
            }
            //填入左边
            for (int i=down; i>=up; i--) {
                Matrix[i][left]=count++;
            }
            if (++left>right) {
                break;
            }
        }
        return Matrix;
    }
};