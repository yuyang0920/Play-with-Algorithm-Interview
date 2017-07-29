#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
    vector<int> memo;

    // 考虑抢劫nums[index...nums.size())这个范围的所有房子
    int tryRob( vector<int> &nums, int index){

        //此时我们要考虑的范围是一个空集了
        if( index >= nums.size() )
            return 0;

        if( memo[index] != -1 )
            return memo[index];

        //开始考虑抢劫房子
        int res = 0;
        for( int i = index ; i < nums.size() ; i ++ )
            //抢劫第i个房子后还要尝试取抢劫[i+2...n-1]的房子
            res = max(res, nums[i] + tryRob(nums, i+2));
        memo[index] = res;
        return res;
    }
public:
    // nums表示房子的价值
    int rob(vector<int>& nums) {

        memo = vector<int>(nums.size(), -1);
        //考虑从0号开始偷取
        return tryRob(nums, 0);
    }
};

int main() {

    return 0;
}