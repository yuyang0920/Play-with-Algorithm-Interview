#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

/// 144. Binary Tree Preorder Traversal

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//模拟计算机的指令
struct Command{
    //描述我们的命令
    // go访问某个节点, print输出节点信息
    string s;   
    //指令要作用在节点上
    TreeNode* node;
    Command(string s, TreeNode* node): s(s), node(node){}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        if( root == NULL )
            return res;

        stack<Command> stack;
        //压入第一个命令：访问根节点
        stack.push( Command("go", root) );
        while( !stack.empty() ){
            Command command = stack.top();
            stack.pop();

            if( command.s == "print" )
                res.push_back( command.node->val );
            else{
                //栈是先进后出的，前序遍历时我们先打印，
                //再访问左孩子，再访问右孩子
                assert( command.s == "go" );
                if( command.node->right)
                    stack.push( Command("go",command.node->right));
                if( command.node->left)
                    stack.push( Command("go",command.node->left));
                stack.push( Command("print", command.node));
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
