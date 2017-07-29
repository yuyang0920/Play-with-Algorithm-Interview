#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <cassert>
using namespace std;

// Memory Limit Exceed
class Solution {
public:
    int numSquares(int n) {

        assert(n>0);
        //树中进行层序遍历本质就是广度优先遍历
        //第一个int 表示具体数字，第二个int表示之后建立
        //的图中经历了几段路径到达了这个数字
        queue< pair<int,int> > q;
        //初始化
        q.push( make_pair( n , 0 ) );
        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            //num=0就直接返回step，说明我们已经找到了
            //通过了step步从n到0的路径
            //最后一定会经过这个语句，因为对于合法的n总有解
            if( num == 0 )
                return step;
            //终止条件：num-i*i 表示num还能承受一个完全平方数
            //我们重复推入了很多节点，导致性能较低
            //n非常大的时候，有很多可能性来到达给某个数字表达的节点
            for( int i = 1 ; num - i*i >= 0 ; i ++ )
                q.push( make_pair( num - i*i , step + 1 ) );
        }

        throw invalid_argument("No Solution.");
    }
};

int main() {

    cout<<Solution().numSquares(12)<<endl;
    cout<<Solution().numSquares(13)<<endl;

    return 0;
}