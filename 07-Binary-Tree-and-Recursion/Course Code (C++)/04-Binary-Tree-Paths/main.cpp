#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;

//递归终止条件
        if( root == NULL )
            return res;
            //判断是否到达叶子节点
        if( root->left == NULL && root->right == NULL ){
            //to_string 将整型转化为string
            res.push_back( to_string(root->val) );
            return res;
        }

//递归过程
        vector<string> leftPaths = binaryTreePaths(root->left);
        for( int i = 0 ; i < leftPaths.size() ; i ++ )
            //向res中推入当前节点箭头+获得的左子树中的所有路径
            res.push_back( to_string(root->val) + "->" + leftPaths[i] );

        vector<string> rightPaths = binaryTreePaths(root->right);
        for( int i = 0 ; i < rightPaths.size() ; i ++ )
            res.push_back( to_string(root->val) + "->" + rightPaths[i] );
//将res返回给上层的父节点！
        return res;
    }
};

int main() {

    return 0;
}