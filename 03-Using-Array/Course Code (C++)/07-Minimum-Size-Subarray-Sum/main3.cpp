#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 滑动窗口的思路
// 时间复杂度: O(n)
// 指针r和指针l不停的向前遍历了一遍
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //初始状态窗口不包含任何元素
        int l = 0 , r = -1; // nums[l...r]为我们的滑动窗口
        int sum = 0;
        //初始化时将它设为最大值！
        int res = nums.size()+1;
        // 窗口的左边界在数组范围内,则循环继续
        while( l < nums.size() ){   

            if( r + 1 < nums.size() && sum < s )
                //拓展右边界
                sum += nums[++r];
            else // r已经到头 或者 sum >= s
                //缩小左边界
                sum -= nums[l++];
            //此时我们获得了一个窗口
            if( sum >= s )
                res = min(res, r-l+1);
        }
        //无解的情况
        if( res == nums.size() + 1 )
            return 0;
        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout<<Solution().minSubArrayLen(s, vec)<<endl;

    return 0;
}