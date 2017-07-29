#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//O(nlogn)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //按照降序排序！！C++默认是从升序排序
        //O(nlogn)
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        //用连个索引来跟踪两个数组
        //分别指向最大的饼干和最贪心的小朋友
        int gi = 0, si = 0;
        //多少个小朋友开心了
        int res = 0;
        //O(n)
        while( gi < g.size() && si < s.size() ){
            //当前最大的饼干能满足当前最贪心的小朋友
            if( s[si] >= g[gi] ){
                res ++;
                si ++;
                gi ++;
            }
            else
                gi ++;
        }

        return res;
    }
};

int main() {

    int g1[] = {1, 2, 3};
    vector<int> gv1(g1, g1 + sizeof(g1)/sizeof(int));
    int s1[] = {1, 1};
    vector<int> sv1(s1, s1 + sizeof(s1)/sizeof(int));
    cout<<Solution().findContentChildren(gv1, sv1)<<endl;

    int g2[] = {1, 2};
    vector<int> gv2(g2, g2 + sizeof(g2)/sizeof(int));
    int s2[] = {1, 2, 3};
    vector<int> sv2(s2, s2 + sizeof(s2)/sizeof(int));
    cout<<Solution().findContentChildren(gv2, sv2)<<endl;

    return 0;
}