#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int> > levelOrder(TreeNode* root) {

        vector<vector<int> > res;
        if( root == NULL )
            return res;
        //队列中存储的元素：如果只是简单的以层序遍历的形式将
        //节点打印出来，那我们存储TreeNode就可以了
        //
        //但是在返回信息中，不仅存在层序遍历的顺序信息，
        //与此同时每一个元素在哪一层中这个信息也需要记录。
        //表示相应的节点TreeNode在第几层pair<TreeNode*,int>
        queue<pair<TreeNode*,int> > q;
        //初始时，将make_pair(root,0)压入队列
        q.push( make_pair( root , 0 ) );

        while( !q.empty() ){
            //取出队首的元素！
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            //将上述取出的节点信息放入到res之前要考虑
            //当前节点所在的层是否是当前res中已经包含的层数
            if( level == res.size() )
                //level = res.size()表示当前节点还不存在res中！
                //因为我们访问res这个数组时索引要相应小于res.size()
                //
                res.push_back( vector<int>() );
            assert( level < res.size() );

            res[level].push_back( node->val );
            //让node的左右节点入队！
            if( node->left )
                q.push( make_pair(node->left, level + 1 ) );
            if( node->right )
                q.push( make_pair(node->right, level + 1 ) );
        }

        return res;
    }
};

int main() {

    return 0;
}