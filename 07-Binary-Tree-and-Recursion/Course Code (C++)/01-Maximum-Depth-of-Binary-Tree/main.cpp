#include <iostream>

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
    int maxDepth(TreeNode* root) {
        //递归终止条件
        if( root == NULL )
            return 0;

        //递归逻辑
        //先计算当前节点的左子树的最大高度
        //再计算当前节点的右子树的最大高度
        int leftLength = maxDepth(root->left);
        int rightLength = maxDepth(root->right);
        return 1 + max(leftLength+rightLength);
        //return 1 + max( maxDepth(root->left) , maxDepth(root->right) );
    }
};

int main() {

    return 0;
}