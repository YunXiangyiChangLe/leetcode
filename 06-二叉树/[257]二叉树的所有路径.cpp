//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 972 👎 0


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
    void traversal(TreeNode *cur, vector<int> &path, vector <string>& res) {
        path.push_back(cur->val);
        cout<<cur->val<<endl;
        if (cur->left == nullptr && cur->right == nullptr) {
            string ress="";
            for(int i=0;i<path.size()-1;i++){
                ress+=to_string(path[i]);
                ress+="->";
            }
            ress+=to_string(path[path.size()-1]);
            cout<<ress<<endl;
            res.push_back(ress);
        }
        if(cur->left){
            traversal(cur->left,path,res);
            path.pop_back();
        }
        if(cur->right){
            traversal(cur->right,path,res);
            path.pop_back();
        }
    }

    vector <string> binaryTreePaths(TreeNode *root) {
        vector<string>res{};
        vector<int>path{};
        if(root== nullptr)return res;
        traversal(root,path,res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
