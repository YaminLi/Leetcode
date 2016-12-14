//
//  main.cpp
//  257-binaryTreePaths
//
//  Created by Michael on 12/13/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        helper(root, res, "");
        return res;
    }
    
private:
    void helper(TreeNode* root, vector<string>& res, string tmp){
        if (!root->left && !root->right){
            res.push_back(tmp.size()? tmp+"->"+to_string(root->val): to_string(root->val));
            return;
        }
        if (root->left) helper(root->left, res, tmp.size() ? tmp+"->"+to_string(root->val) : to_string(root->val));
        if (root->right) helper(root->right, res, tmp.size() ? tmp+"->"+to_string(root->val) :  to_string(root->val));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution st;
    vector<string> res = st.binaryTreePaths(root);
    for (auto s:res)
        cout << s << endl;
    
//    std::cout << "Hello, World!\n";
    return 0;
}
