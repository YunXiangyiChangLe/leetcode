//给定一个二叉树，找出其最大深度。 
//
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例： 给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1621 👎 0


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
    int maxDepth(TreeNode* root) {
        if(root== nullptr)return 0;
        queue<TreeNode*>q;
        int cnt=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int flag=0;
            while(size--){
                TreeNode*node=q.front();
                if(node)flag=1;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            if(flag)cnt++;
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
