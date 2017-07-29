#include <iostream>
#include <cassert>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        assert( p != NULL && q != NULL );

        if( root == NULL )
            return NULL;

        if( p->val < root->val && q->val < root->val )
            //继续在root的左子树中寻找
            return lowestCommonAncestor( root->left, p, q);
        if( p->val > root->val && q->val > root->val )
            //继续在root的右子树中寻找
            return lowestCommonAncestor( root->right, p, q);

        //此时p和q中必然有一个大于等于root的val，一个小与等于root的val
        //此时root就一定是二者的最近公共祖先
        //前提是p和q都存在于这二叉搜索树中
        assert( p->val == root->val || q->val == root->val
                || (root->val-p->val)*(root->val-q->val) < 0 );

        return root;
    }
};

int main() {

    return 0;
}