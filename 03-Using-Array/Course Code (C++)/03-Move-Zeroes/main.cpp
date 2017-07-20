#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(n)
    // 空间复杂度 O(n)
    void moveZeroes(vector<int>& nums) {

        vector<int> nonZeroElements;

        // 将vec中所有非0元素放入nonZeroElements中
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] )
                nonZeroElements.push_back( nums[i] );

        // 将nonZeroElements中的所有元素依次放入到nums开始的位置
        for( int i = 0 ; i < nonZeroElements.size() ; i ++ )
            nums[i] = nonZeroElements[i];

        // 将nums剩余的位置放置为0
        for( int i = nonZeroElements.size() ; i < nums.size() ; i ++ )
            nums[i] = 0;
    }
};

//时间复杂度O(n)
//空间复杂度O(1)
class MySolution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        int j = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0)
                nums[j++] = nums[i];
            else
                k++;
        }
        for(int i=0; i<k; i++)
            nums[j++]=0;
    }
};



int main() {

    int arr[] = {0, 1, 0, 3, 12, 9, 78, 0, 9};
    //根据数组来创建vector
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    MySolution().moveZeroes(vec);

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}