#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> stack;
        for( int i = 0 ; i < s.size() ; i ++ )
            if( s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
            else{
                    //拿到了一个有括号，但是此时栈中没有元素了
                    //说明不匹配
                    if( stack.size() == 0 )
                        return false;

                    char c = stack.top();
                    stack.pop();

                    char match;
                    if( s[i] == ')' )
                        match = '(';
                    else if( s[i] == ']' )
                        match = '[';
                    else{
                        //s[i]不是‘}’说明当前字符串还含有别的字符
                        assert( s[i] == '}' );
                        match = '{';
                    }

                    if( c != match )
                        return false;
                }

        if( stack.size() != 0 )
            return false;

        return true;
    }
};


class Solution1 {
public:
    bool isValid(string s) {
        stack<int> stack;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push(s[i]);
            else
            {
                if(stack.size() == 0)
                    return false;

                char c = stack.top();
                //将栈顶元素移除
                stack.pop();

                char match;
                switch(s[i])
                {
                    case ')':
                        match = '(';
                        break;
                    case ']':
                        match = '[';
                        break;
                    case '}':
                        match = '{';
                        break;
                    default:
                        return false;
                }
                if(c != match)
                    return false;
            }
        }
        if(stack.size() != 0)
            return false; 
        else 
            return true;
    }
};

int main() {

    if( Solution().isValid("()") )
        cout<<"() is valid."<<endl;
    else
        cout<<"() is invalid."<<endl;

    if( Solution().isValid("()[]{}") )
        cout<<"()[]{} is valid."<<endl;
    else
        cout<<"()[]{} is invalid."<<endl;

    if( Solution().isValid("(]") )
        cout<<"(] is valid."<<endl;
    else
        cout<<"(] is invalid."<<endl;

    if( Solution().isValid("([)]") )
        cout<<"([)] is valid."<<endl;
    else
        cout<<"([)] is invalid."<<endl;

    return 0;
}