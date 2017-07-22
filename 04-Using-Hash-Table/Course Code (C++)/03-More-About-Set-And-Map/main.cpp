#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/// 349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //通过数组创建set，对于n个数据的插入，
        //总共的复杂度为O(n)
        unordered_set<int> record(nums1.begin(), nums1.end());

        //对于循环的查找、插入，也是O(n)级别的
        //这里查找的过程对数据的顺序性是没有要求的！
        unordered_set<int> resultSet;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            if( record.find( nums2[i] ) != record.end() )
                resultSet.insert( nums2[i] );
        //O(n)  
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};

int main() {

    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution().intersection(vec1, vec2);
    for(int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}