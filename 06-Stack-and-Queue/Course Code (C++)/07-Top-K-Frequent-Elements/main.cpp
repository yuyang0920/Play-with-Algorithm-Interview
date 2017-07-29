#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <algorithm>
using namespace std;

#if 1
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        assert( k > 0 );

        // 统计每个元素出现的频率
        unordered_map<int,int> freq;
        for(int i = 0 ; i < nums.size() ; i ++ )
            freq[nums[i]] ++;

        assert( k <= freq.size() );

        // 扫描freq,维护当前出现频率最高的k个元素
        // 在优先队列中,按照频率排序,所以数据对是 (频率,元素) 的形式
        // 因为在进行比较的时候，我们是先比较的频率
        // 此处我们要维护的是最小堆
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        for( unordered_map<int,int>::iterator iter = freq.begin() ;
             iter != freq.end() ; iter ++ ){
            //当前优先队列中已经出现了出现频率最高的元素
            //此时iter就访问了一个新的元素，新的元素可能会挤掉
            //优先队列中某个元素
            if( pq.size() == k ){
                //比队列中最小频率的元素要高，则先将其弹出再入队
                if( iter->second > pq.top().first ){
                    pq.pop();
                    pq.push( make_pair( iter->second , iter->first) );
                }
            }
            else
                //优先队列未满
                pq.push( make_pair( iter->second , iter->first ) );
        }

        vector<int> res;
        while( !pq.empty() ){
            res.push_back( pq.top().second );
            pq.pop();
        }

        return res;
    }
};
#endif


int main() {

    int nums[] = {1, 1, 1, 2, 2, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int));
    int k = 2;

    vector<int> res = Solution().topKFrequent(vec, 2);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}