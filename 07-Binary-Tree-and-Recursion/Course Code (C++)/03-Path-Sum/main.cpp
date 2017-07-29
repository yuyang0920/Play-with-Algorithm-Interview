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
    bool hasPathSum(TreeNode* root, int sum) {

        if( root == NULL )
            return false;

        //递归条件：明确root是一个叶子节点！
        if( root->left == NULL && root->right == NULL )
        //    条件成立的话，就找到了一条以叶子节点为终结的路径
        //    叶子节点的值本身就为sum
            return sum == root->val;

        return hasPathSum( root->left , sum - root->val )
                || hasPathSum( root->right , sum - root->val );
    }

    #if 0
    if(root ==NULL)
        return sum == 0;
    if(hasPathSum(root->left, sum-root->val));
        return true;
    if(hasPathSum(root->right, sum-root->val));
        return true;
    return false;
    #endif
};

int main() {

    return 0;
}