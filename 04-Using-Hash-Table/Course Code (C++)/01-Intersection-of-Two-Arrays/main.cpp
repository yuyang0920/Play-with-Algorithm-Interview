#include <iostream>
#include <vector>
#include <set>
using namespace std;

/// 349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record;
        for( int i = 0 ; i < nums1.size() ; i ++ )
            record.insert(nums1[i]);

        set<int> resultSet;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            if( record.find( nums2[i] ) != record.end() )
                resultSet.insert( nums2[i] );

        vector<int> resultVector;
        for(set<int>::iterator iter = resultSet.begin() ; iter != resultSet.end() ; iter ++ )
            resultVector.push_back( *iter );

        return resultVector;
    }
};


class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> recordSet;
        set<int> resultSet;
        //第一步，将nums1的元素放入recordSet中
        recordSet.insert(nums1.begin(), nums1.end());

        //第二步，在recordSet中查找nums2的元素，
        //并将找到的元素放入resulSet中
        for(int i=0; i<nums2.size(); i++)
        {
            if(recordSet.find(nums2[i]) != recordSet.end())
                resultSet.insert(nums2[i]);
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};


int main() {

    int nums1[] = {1, 2, 2, 1, 100, 99, 6};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2, 3, 5, 6, 99, 100};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution1().intersection(vec1, vec2);
    for(int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}