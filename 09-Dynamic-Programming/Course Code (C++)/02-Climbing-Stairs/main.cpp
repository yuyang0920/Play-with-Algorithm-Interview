#include <iostream>
#include <vector>

using namespace std;

// 记忆化搜索
class Solution {
private:
    vector<int> memo;

    int calcWays(int n){

// n = 0 时说明一阶台阶都没有，无路可走，也算一种方法！
        if( n == 0 || n == 1)
            return 1;

        if( memo[n] == -1 )
            //计算出爬n-1和n-2阶台阶共有多少种方法!
            memo[n] = calcWays(n-1) + calcWays(n-2);

        return memo[n];
    }
public:
    //n阶台阶
    int climbStairs(int n) {

        memo = vector<int>(n+1,-1);
        return calcWays(n);
    }
};

int main() {

    cout<<Solution().climbStairs(10)<<endl;
    return 0;
}