#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int> > res;

    // 递归函数
    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    // 每一步递归调用时由于存在之前在某个分支中某一个数字全部考虑了的情况，
    // 所以在考虑每个子问题的时候只需要考虑某一个数及以后的数即可
    // 参数4：存储在递归的过程中，当前所搜索的组合中时所存在的元素
    void generateCombinations(int n, int k, int start, vector<int> &c){
        //已经找到了含有k个元素的组合了
        if( c.size() == k ){
            res.push_back(c);
            return;
        }

        for( int i = start ; i <= n ; i ++ ){
            c.push_back( i );
            //从i+1开始就可以了，因为之前已经将i这个数字放进了组合中
            //不用考虑i了；而对于i之前的数字，在将i push进c中之前，
            //i前面的数也已经放进了c中
            //所以在下一次寻找的时候只需要考虑i+1 和i+1以后的数字就可以了
            generateCombinations(n, k, i + 1 , c );
            //回溯，将先前push的i给pop出来
            c.pop_back();
        }

        return;
    }
public:
    //[1...n]中取k个数
    vector<vector<int> > combine(int n, int k) {

        res.clear();
        if( n <= 0 || k <= 0 || k > n )
            return res;

        vector<int> c;
        //第一次调用，从数字1开始搜索，[1...n]
        generateCombinations(n, k, 1, c);

        return res;
    }
};

int main() {

    vector<vector<int> > res = Solution().combine(4,2);
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}