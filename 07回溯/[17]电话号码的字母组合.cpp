//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2557 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string>res;
    string path;
    const string mapletter[10]={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
public:
    void backtracking(const string& digits,int index){
        if(path.size()==digits.size()){
            res.push_back(path);
            return;
        }
        int digit=digits[index]-'0';
        string letters=mapletter[digit];
        for(int i=0;i<letters.size();i++){
            path.push_back(letters[i]);
            backtracking(digits,index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return res;
        }
        backtracking(digits,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
