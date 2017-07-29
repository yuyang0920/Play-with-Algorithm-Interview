#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    // memo[i][c] 表示使用索引为[0...i]的这些元素,是否可以完全填充一个容量为c的背包
    // -1 表示为未计算; 0 表示不可以填充; 1 表示可以填充
    //index和sum可能产生重叠子问题的！！
    vector<vector<int> > memo;

    // 使用nums[0...index], 是否可以完全填充一个容量为sum的背包
    bool tryPartition(const vector<int> &nums, int index, int sum){
        //说明背包已经没有空间，已经填充好了！！
        if( sum == 0 )
            return true;
        //sum<0 表示背包装不下的，index<0说明背包还没有满，
        //而此时已经没有物品可以选了
        if( sum < 0 || index < 0 )
            return false;

        if( memo[index][sum] != -1 )
            return memo[index][sum] == 1;
        //尝试用[0...index-1]的物品填充大小为sum的背包，若能填充，我们只是不使用nums[index]
        //要使用nums[index]
        memo[index][sum] = (tryPartition(nums, index-1 , sum ) ||
               tryPartition(nums, index-1 , sum - nums[index] ) ) ? 1 : 0;

        return memo[index][sum] == 1;
    }
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for( int i = 0 ; i < nums.size() ; i ++ ){
            assert( nums[i] > 0 );
            sum += nums[i];
        }
        //确保和能被平分！
        if( sum%2 )
            return false;

        memo = vector<vector<int> >(nums.size(), vector<int>(sum/2+1,-1));
        //背包的大家就是sum/2
        return tryPartition(nums, nums.size()-1 , sum/2 );
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