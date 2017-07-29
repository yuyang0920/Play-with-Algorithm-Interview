#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
using namespace std;

// 使用visited数组,记录每一个入队元素
class Solution {
public:
    int numSquares(int n) {

        queue< pair<int,int> > q;
        q.push( make_pair( n , 0 ) );
        //处理冗余数据
        //避免导致大量的重复节点都放入队列中
        //表示从n到0这n+1个数字有没有被访问过
        vector<bool> visited(n+1, false);
        visited[n] = true;

        while( !q.empty() ){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if( num == 0 )
                return step;

            for( int i = 1 ; num - i*i >= 0 ; i ++ )
                if( !visited[num-i*i] ){
                    //当这个数字没有被访问过，才将它推入队列
                    q.push( make_pair( num - i*i , step + 1 ) );
                    visited[num-i*i] = true;
                }
        }

        throw invalid_argument("No Solution.");
    }
};

int main() {

    cout<<Solution().numSquares(12)<<endl;
    cout<<Solution().numSquares(13)<<endl;

    return 0;
}