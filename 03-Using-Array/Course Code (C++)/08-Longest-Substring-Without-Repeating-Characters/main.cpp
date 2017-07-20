#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};
        //初始时，滑动窗口不包含任何元素
        int l = 0, r = -1; //滑动窗口为s[l...r]
        //满足条件的最长的子串的长度
        int res = 0;

        // 整个循环从 l == 0; r == -1 这个空窗口开始
        // 到l == s.size(); r == s.size()-1 这个空窗口截止
        // 在每次循环里逐渐改变窗口, 维护freq, 并记录当前
        // 窗口中是否找到了一个新的最优值
        while( l < s.size() ){
            //查看窗口的右侧的下一个字符和子串中的字符是否有重复的
            //r+1<s.size()确保窗口的右边界可以扩展
            //当发现右边界的下一个字符与子串中的某个元素是重复字符时，
            //我们不会扩展右边界，而是缩小左边界
            if( r + 1 < s.size() && freq[s[r+1]] == 0 )
                //改变滑动窗口的右侧
                freq[s[++r]] ++;
            else    //r已经到头 || freq[s[r+1]] == 1
                //改变滑动窗口的左侧
                freq[s[l++]] --;
            //当前子串的长度和已经找到的子串的长度进行取最大值
            res = max( res , r-l+1);
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;

    return 0;
}