#include <iostream>
#include <vector>
#include <map>
using namespace std;

/// 350. Intersection of Two Arrays II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> record;
        for( int i = 0 ; i < nums1.size() ; i ++ )
            //将nums1中第i个元素的频次加1
            record[nums1[i]] += 1;

        vector<int> resultVector;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            //在record中nums2的第i个元素的频次是否大于0
            //大于0，说明找到了nums1和nums2的重合的元素
            if( record[ nums2[i] ] > 0 ){
                resultVector.push_back( nums2[i] );
                //我们已经用掉了一次nums[i]，频次减1
                record[nums2[i]] --;
            }

        return resultVector;
    }
};

int main() {

    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution().intersect(vec1, vec2);
    for(int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}