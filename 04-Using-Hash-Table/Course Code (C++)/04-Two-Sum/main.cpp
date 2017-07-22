#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

//时间复杂度O(n)
//空间复杂度O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //不需要考虑元素的顺序性！
        unordered_map<int,int> record;
        for( int i = 0 ; i < nums.size() ; i ++ ){
            //在数组中nums[i]有可能是重复的，而map的key不能重复！
            //避免一次性把所有元素都放入查找表中，避免相同的元素被覆盖！
            //我们在当前的查找表中要查找的元素complement
            int complement = target - nums[i];
            //第一次循环record是空的！
            //注意：unordered_map在查找后不会将元素加入到该查找表中！
            if( record.find(complement) != record.end() ){

                int res[] = {i, record[complement]};
                return vector<int>(res, res + 2);
            }
            //没找到，就将nums[i]放入当前查找表中！
            record[nums[i]] = i;
        }

        throw invalid_argument("the input has no solution");
    }
};

//暴力解法
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                if(target == (nums[i] + nums[j]) && (i != j) )
                { 
                    vec.push_back(i);
                    vec.push_back(j);
                }
                   
            }
        }
        return vec;
    }
};


//先排序，再进行双索引对撞
//注意返回的是排序后的数组
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        sort(nums.begin(), nums.end());
        //左索引从0开始，右索引从nums.size()-1开始
        int i = 0, j = nums.size()-1;
        while(i<j)
        {
            if((nums[i] + nums[j]) == target)
            {
                vec.push_back(i);
                vec.push_back(j);
                return vec;
            }

            else if(nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
        
    }
};


int main() {

    const int nums[] = {2,7,11,15};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 9;

    vector<int> res = Solution().twoSum(nums_vec, target);
    cout<<res[0]<<" , "<<res[1]<<endl;

    return 0;
}
