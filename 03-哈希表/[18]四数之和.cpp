//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[
//b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 
//
// 
// 0 <= a, b, c, d < n 
// a、b、c 和 d 互不相同 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// 你可以按 任意顺序 返回答案 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related Topics 数组 双指针 排序 👍 1598 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <vector<int>> fourSum(vector<int> &nums, int target) {
        vector <vector<int>> res;
        if(nums.size()<4)return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            //cout<<typeid(nums.size()).name();
            if (i > 0 && nums[i] == nums[i - 1])continue;
            //cout<<"cmm"<<endl;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])continue;
                int left = j + 1;
                int right = nums.size() - 1;

                while (right > left) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    } else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                    } else {
                        res.push_back(vector < int > {nums[i], nums[j], nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1])right--;
                        while (right > left && nums[left] == nums[left + 1])left++;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
