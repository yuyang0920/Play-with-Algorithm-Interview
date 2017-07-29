#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
            " ",    //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz"  //9
    };

    vector<string> res;

    // s中保存了此时从digits[0...index-1]翻译得到的一个字母字符串
    // 寻找和digits[index]匹配的字母, 获得digits[0...index]翻译得到的解
    //参数1：处理的数字字符串
    //参数2：每一次调用findCombination的时候都只处理数字字符串下标为index的一位
    //参数3：
    void findCombination(const string &digits, int index, const string &s){

        cout<<index<<" : "<<s<<endl;
        //index已经达到数字字符串的末尾
        if( index == digits.size() ){
            res.push_back( s );
            cout<<"get "<<s<<" , return"<<endl;
            return;
        }
        //首先处理递归部分
        char c = digits[index];
        assert( c >= '0' && c <= '9' && c != '1');
        //当前数字对应的字母
        string letters = letterMap[c-'0'];
        //每次得到digits[index]这个数字所代表的一个字母
        for( int i = 0 ; i < letters.size() ; i ++ ){
            cout<<"digits["<<index<<"] = "<<c<<" , use "<<letters[i]<<endl;
            findCombination(digits, index+1, s + letters[i]);
        }

        cout<<"digits["<<index<<"] = "<<c<<" complete, return"<<endl;

        return;
    }

public:
    vector<string> letterCombinations(string digits) {

        res.clear();

        if( digits == "" )
            return res;

        findCombination(digits, 0, "");

        return res;
    }
};

int main() {
    cout << "hello" <<endl;
    vector<string> res = Solution().letterCombinations("234");
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<endl;

    return 0;
}