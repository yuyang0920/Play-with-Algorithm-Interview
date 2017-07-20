#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// 时间复杂度: O(n)
// 空间复杂度: O(1)
// 对整个数组只遍历了一遍
class Solution {
public:
    void sortColors(vector<int> &nums) {
        //zero的初值不能为0，因为我们的区间是[0...zero]
        //起始时，该区域没有任何一个元素为0！
        int zero = -1;          // [0...zero] == 0
        //初始0，该没有任何一个元素为2
        int two = nums.size();  // [two...n-1] == 2
        //在循环中我们就要维持定义的区间！
        //for循环中，不需要i++，因为有一种情况i不需要++
        for( int i = 0 ; i < two ; ){
            if( nums[i] == 1 )
                i ++;
            else if ( nums[i] == 2 )
                //nums[--two]是一个我们还没处理的元素，
                //所以i不需要++，下次循环中要继续处理该元素
                swap( nums[i] , nums[--two]);
            else{ // nums[i] == 0
                //增加代码的严谨性，数组的元素只能是0、1、2
                assert( nums[i] == 0 );
                swap( nums[++zero] , nums[i++] );
            }
        }
    }
};

int main() {

    int nums[] = {2, 2, 2, 1, 1, 0};
    vector<int> vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    Solution().sortColors( vec );
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}
