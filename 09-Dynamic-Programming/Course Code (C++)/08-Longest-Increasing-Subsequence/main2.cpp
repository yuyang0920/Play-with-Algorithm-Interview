#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
    //O(N^2)
    int lengthOfLIS(vector<int>& nums) {

        if( nums.size() == 0 )
            return 0;

        // memo[i] 表示以 nums[i] 为结尾的最长上升子序列的长度
        vector<int >memo( nums.size() , 1 );
        //不用考虑nums[0]，因为初始时nums[0]就为1
        for( int i = 1 ; i < nums.size() ; i ++ )
            //考察nums[i]之前的所有元素
            for( int j = 0 ; j < i ; j ++ )
                //nums[i]可以跟在nums[j]的后面
                if( nums[i] > nums[j] )
                    memo[i] = max( memo[i] , 1 + memo[j] );

        int res = memo[0];
        for( int i = 1 ; i < nums.size() ; i ++ )
            res = max( res , memo[i] );

        return res;
    }
};

int main() {

    int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18}; // 4
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec1 )<<endl;


    int nums2[] = {4, 10, 4, 3, 8, 9};  // 3
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec2 )<<endl;


    int nums3[] = {2, 2};   // 1
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec3 )<<endl;

    int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6}; // 6
    vector<int> vec4(nums4, nums4 + sizeof(nums4)/sizeof(int));

    cout<<Solution().lengthOfLIS( vec4 )<<endl;


    return 0;
}