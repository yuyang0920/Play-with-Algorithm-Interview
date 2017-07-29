#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    void generateCombinations(int n, int k, int start, vector<int> &c){

        if( c.size() == k ){
            res.push_back(c);
            return;
        }

        // 1.当进入到递归函数中，c中就已经存放着当前已经寻找到的组合中相应的元素
        // 2.还有k - c.size()个空位, 所以,[i...n]中至少要有k-c.size()个元素
        // 3.问题就在于i取多少时[i,n]中有k-c.size()个元素？
        // 4.假设要保证k-c.size()为1的话，那么i就为n;为2的话，i就为n-1...
        // i最多为 n - (k-c.size()) + 1
        // 要从[start...n]中寻找k-c.size()个元素来填补空位
        for( int i = start ; i <= n - (k-c.size()) + 1 ; i ++ ){
            c.push_back( i );
            generateCombinations(n, k, i + 1 , c );
            c.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {

        res.clear();
        if( n <= 0 || k <= 0 || k > n )
            return res;

        vector<int> c;
        generateCombinations(n, k, 1, c);

        return res;
    }
};

int main() {

    vector<vector<int>> res = Solution().combine(4,2);
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}