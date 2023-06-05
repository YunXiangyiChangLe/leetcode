//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2437 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root== nullptr)return true;
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()){
            TreeNode*left_node=q.front();
            q.pop();
            TreeNode*right_node=q.front();
            q.pop();
            if(left_node== nullptr&&right_node== nullptr)continue;
            if(left_node== nullptr||right_node== nullptr||(left_node->val!=right_node->val))return false;
            q.push(left_node->left);
            q.push(right_node->right);
            q.push(left_node->right);
            q.push(right_node->left);
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
