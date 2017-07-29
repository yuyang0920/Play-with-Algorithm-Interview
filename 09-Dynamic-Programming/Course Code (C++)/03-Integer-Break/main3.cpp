#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    int max3( int a , int b , int c ){
        return max(max(a,b),c);
    }
public:
    int integerBreak(int n) {

        // memo[i] 表示将数字i分割(至少分割成两部分)后得到的最大乘积
        vector<int> memo(n+1, -1);
        //自底向上
        memo[1] = 1;
        //对[2...n]进行分割
        for( int i = 2 ; i <= n ; i ++ )
            // 求解memo[i]
            // 尝试将i进行分割
            for( int j = 1 ; j <= i-1 ; j ++ )
                // 每次分割都尝试将i分割成j + (i-j)
                // 因为i-j一定小与i，此时i-j就一定被计算出来了
                memo[i] = max3( memo[i] , j*(i-j) , j*memo[i-j]);
        return memo[n];
    }
};

int main() {

    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(3)<<endl;
    cout<<Solution().integerBreak(4)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}