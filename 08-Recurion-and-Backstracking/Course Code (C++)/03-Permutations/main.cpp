#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > res;
    //used[i]来判断nums[i]是否被使用过了(添加到了p中)
    vector<bool> used;

    // p中保存了一个有index个元素的排列。
    // 向这个排列的末尾添加第index+1个元素, 获得一个有index+1个元素的排列
    //参数1：需要nums这个数组在组成我们的排列
    //参数2：表示现在真正处理第几个元素
    //参数3：p用来存储我们在递归的过程中找到的一个排列
    void generatePermutation( const vector<int>& nums, int index, vector<int>& p){
        //此时p中已经包含了nums中所有元素的排列
        if( index == nums.size() ){
            res.push_back(p);
            return;
        }
        //在排列中找到需要添加的第index+1个元素，但是当进入generatePermutation时
        //在p中已经有了index个元素，对于这index个元素，我们不能重复使用。
        //所以每一次都需要判断当前所看的nums[i]是否在p这个数组中
        //不在的话，我们才将它添加到p中
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( !used[i] ){
                used[i] = true;
                p.push_back( nums[i] );
                //递归调用，此时p中就有了index+1个元素
                //递归调用的过程中，p中元素逐渐增多，直到index等于nums.size()时
                //就获得了一个排列
                generatePermutation(nums, index+1, p );
                //这个就是回溯的过程，恢复状态
                //回去的时候我们就要尝试nums中的其他元素，在这之前必须把当前
                //尝试的元素给退回去
                //这一轮中不使用nums[i]，下一轮中还要使用，不能一直占着
                p.pop_back();
                used[i] = false;
            }

        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        res.clear();
        if( nums.size() == 0 )
            return res;

        used = vector<bool>(nums.size(), false);
        vector<int> p;
        //p来存储在递归的过程中生成的排列
        generatePermutation( nums, 0, p );

        return res;
    }
};

int main() {

    int nums[] = {1, 2, 3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int) );

    vector< vector<int> > res = Solution().permute(vec);
    for( int i = 0 ; i < res.size() ; i ++ ){

        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}