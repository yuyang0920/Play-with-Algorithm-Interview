#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {

public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for( int i = 0 ; i < nums.size() ; i ++ ){
            assert( nums[i] > 0 );
            sum += nums[i];
        }

        if( sum%2 )
            return false;

        int n = nums.size();
        int C = sum/2;
        //设置成bool型，因为在递推的过程中一定是从小问题到大问题一步步的
        vector<bool> memo(C+1,false);
        //首先只考虑第一个nums物品的话，能不能把memo相对应的背包填满
        for( int i = 0 ; i <= C ; i ++ )
            //nums[0]等于容量i，说明能填满背包
            memo[i] = ( nums[0] == i );
        //从第[1...n-1]个物品
        for( int i = 1 ; i < n ; i ++ )
            //j小于nums[i]时就不用计算了，因为背包已经放不下了
            ////从容量[C...j]
            for( int j = C; j >= nums[i] ; j -- )
                //memo[j] = memo[j]说明用前面i-1个物品就能填满背包了
                //或者使用第i个物品填满背包!
                memo[j] = memo[j] || memo[j-nums[i]];
        //return true说明用这n个数字可以填满sum/2这么大的容量
        //为C的背包！
        return memo[C];
    }
};

int main() {

    int nums1[] = {1, 5, 11, 5};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    if( Solution().canPartition(vec1) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    int nums2[] = {1, 2, 3, 5};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    if( Solution().canPartition(vec2) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}