#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if( n == 0 )
            return 0;

        // memo[i] 表示考虑抢劫 nums[i...n-1] 所能获得的最大收益
        // 记录子问题的结果！
        vector<int> memo(n, 0);
        //自底向上，由规模较小的问题推出规模较大的问题
        memo[n-1] = nums[n-1];
        //每一次从i=n-2开始偷取
        for( int i = n-2 ; i >= 0 ; i -- )
            //memo[i]
            for (int j = i; j < n; j++)
                memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0) );
        //整个问题的解！
        return memo[0];
    }
};

int main() {

    int nums[] = {2,1};
    vector<int> vec(nums, nums+sizeof(nums)/sizeof(int));

    cout<<Solution().rob(vec)<<endl;

    return 0;
}