#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 时间复杂度: O(n)
// 空间复杂度: O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if( nums.size() <= 1 )
            return false;

        if( k <= 0 )
            return false;
        //创建查找表，而滑动窗口的长度就是record的长度
        //也就是record的大小在k+1以内就可以了
        unordered_set<int> record;
        for( int i = 0 ; i < nums.size() ; i ++ ){
            //在record找到了和nums[i]重复的元素
            if( record.find( nums[i] ) != record.end() )
                return true;
            //没找到重复的元素，在record中添加这个nums[i]
            record.insert( nums[i] );

            // 保持record中最多有k个元素
            // 因为在下一次循环中会添加一个新元素,
            // 使得总共考虑k+1个元素(距离为k)
            if( record.size() == k + 1 )
                //删除窗口最左侧的元素
                record.erase( nums[i-k] );
        }

        return false;
    }
};

int main() {

    int nums[] = {1,2,1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int k = 1;

    if( Solution().containsNearbyDuplicate(vec, k))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}