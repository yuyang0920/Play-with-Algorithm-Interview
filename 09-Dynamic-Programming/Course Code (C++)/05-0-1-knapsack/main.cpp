#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Knapsack01{

private:
    vector<vector<int>> memo;

    // 用 [0...index]的物品,填充容积为c的背包的最大价值
    int bestValue(const vector<int> &w, const vector<int> v, int index, int c){
        //无法装入新的物品
        if( c <= 0 || index < 0 )
            return 0;

        //消除重叠子问题：index和c构成的数据对在求解过程中可能出现多次
        if( memo[index][c] != -1 )
            return memo[index][c];

        //策略1来填充背包：用[0...index-1]的物品来填充背包
        int res = bestValue(w, v, index-1, c);
        //确保当前的c能容纳第index个背包
        if( c >= w[index] )
            res = max( res , v[index] + bestValue(w, v, index-1, c-w[index]) );
        memo[index][c] = res;
        return res;
    }
public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int C){
        assert( w.size() == v.size() && C >= 0 );
        int n = w.size();
        if( n == 0 || C == 0 )
            return 0;
        // n x (c+1) 的数组
        // memo[i][j]表示的就是bestvalue中给定一个index和c相应的状态
        memo = vector<vector<int>>( n, vector<int>(C+1,-1));
        //F(i, c)约束条件：考虑从[0...n-1]n个所有的物品将它们装入到容积为C的背包中
        return bestValue(w, v, n-1, C);
    }
};

int main() {

    int n, W;
    cin>>n>>W;

    int v,w;
    vector<int> vs, ws;
    for( int i = 0 ; i < n ; i ++ ){
        cin>>w>>v;
        vs.push_back(v);
        ws.push_back(w);
    }

    cout<<Knapsack01().knapsack01(ws,vs,W)<<endl;
    return 0;
}