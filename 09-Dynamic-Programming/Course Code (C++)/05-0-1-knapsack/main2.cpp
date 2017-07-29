#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Knapsack01{

public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int C){
        assert( w.size() == v.size() && C >= 0 );
        int n = w.size();
        //传进来的v和w为空，此时背包中没有任何物品可选
        if( n == 0 || C == 0 )
            return 0;

        vector<vector<int> > memo( n, vector<int>(C+1,0));

        //自底向上：第0行
        //j代表的是此时我们处理的背包的容量,只考虑0这个物品
        //memo[x][y]:x表示[0...x]号物品，y表示此时背包容量
        for( int j = 0 ; j <= C ; j ++ )
            //j >= w[0]说明背包中能将第0号物品放进去，
            //此时背包的价值就是V[0]，否则背包无法放入第0个物品
            memo[0][j] = ( j >= w[0] ? v[0] : 0 );

        //接下来每行的解决问题
        for( int i = 1 ; i < n ; i ++ )
            //而在每行中我们有逐列的解决问题
            for( int j = 0 ; j <= C ; j ++ ){
                //memo[i][j]表示的是[0...i]这些物品且容积为j的背包获得
                //的最大值是多少
                
                //策略1：不考虑第i个物品
                memo[i][j] = memo[i-1][j];
                //策略2：考虑第i个物品能放入背包中
                if( j >= w[i] )
                    memo[i][j] = max( memo[i][j], v[i] + memo[i-1][j-w[i]]);
            }
        return memo[n-1][C];
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