
#include<vector>

/* 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。*/

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        std::vector<int>res;
        if (row==0) { //数组为空
            return res;
        }
        int left=0;
        int up=0;
        int right=col-1;
        int down=row-1;
        while (true) {
            //遍历上边
            for (int i=left; i<=right; i++) {
                res.push_back(matrix[up][i]);
            }
            //做越界判断
            if (++up>down) { 
                break;
            }
            //遍历右边
            for (int i=up; i<=down; i++) {
                res.push_back(matrix[i][right]);
            }
            if (--right<left) { 
                break;
            }
            //遍历下边
            for (int i=right; i>=left; i--) {
                res.push_back(matrix[down][i]);
            }
            if (--down<up) { 
                break;
            }
            //遍历左边
            for (int i=down; i>=up; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left>right) { 
                break;
            }
        }
        return res;
    }
};