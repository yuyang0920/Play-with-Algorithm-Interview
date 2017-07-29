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
    TreeNode* invertTree(TreeNode* root) {

        if( root == NULL)
            return NULL;
        //1.将root的左孩子所在的二叉树进行反转
        invertTree( root->left );
        //2.将root的右孩子所在的二叉树进行反转
        invertTree( root->right );
        //3.将root的左右两个孩子交换位置
        swap( root->left, root->right);

        return root;
    }
};

int main() {

    return 0;
}