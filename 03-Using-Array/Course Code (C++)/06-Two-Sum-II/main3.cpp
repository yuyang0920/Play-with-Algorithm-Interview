#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept> 
using namespace std;

// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        assert( numbers.size() >= 2 );
        // assert( isSorted(numbers) );

        int l = 0, r = numbers.size()-1;
        while( l < r ){

            if( numbers[l] + numbers[r] == target ){
                int res[2] = {l+1, r+1};
                return vector<int>(res, res+2);
            }
            else if( numbers[l] + numbers[r] < target )
                l ++;
            else // numbers[l] + numbers[r] > target
                r --;
        }

        throw invalid_argument("the input has no solution");
    }

    vector<int> MyTwoSum(vector<int>& numbers, int target)
    {
        assert( numbers.size() >= 2 );
        int i = 0;
        int j = numbers.size()-1;
        while(i<j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                int res[2] = {i+1, j+1};
                return vector<int>(res, res+2);
            }
            else if(numbers[i] + numbers[j] < target)
                i++;
            else 
                j--;
        }
        throw invalid_argument("the input has no solution");
    }

};

int main() {

    int nums[] = {2, 7, 11, 15};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int target = 9;

    vector<int> res = Solution().twoSum( vec, target );
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}