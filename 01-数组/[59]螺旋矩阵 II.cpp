//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1052 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <vector<int>> generateMatrix(int n) {
        vector <vector<int>> res = vector < vector < int >> (n, vector<int>(n, 0));
        int loop = n / 2;
        int val = 1;
        int startx = 0, starty = 0;
        int i, j;
        int offest = 1;
        while (loop--) {
            i = startx, j = starty;
            for (j = starty; j < n - offest; j++) {
                res[i][j] = val;
                val++;
            }
            for (i = startx; i < n - offest; i++) {
                res[i][j] = val;
                val++;
            }
            for (j = n - offest; j > starty; j--) {
                res[i][j] = val;
                val++;
            }
            for (i = n - offest; i > startx; i--) {
                res[i][j] = val;
                val++;
            }
            startx++;
            starty++;
            offest++;
        }
        if (n % 2 == 1) {
            res[n / 2][n / 2] = val;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
