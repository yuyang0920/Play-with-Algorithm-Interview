#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Knapsack01{

public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int C){
        assert( w.size() == v.size() && C >= 0 );
        int n = w.size();
        if( n == 0 || C == 0 )
            return 0;

        vector<int> memo(C+1,0);

        for( int j = 0 ; j <= C ; j ++ )
            //memo[0][j] = ( j >= w[0] ? v[0] : 0 );
            memo[j] = ( j >= w[0] ? v[0] : 0 );
 
        for( int i = 1 ; i < n ; i ++ )
            //每一次处理都是从容量C开始向前走,直到j >= w[i]
            //因为j<W[i]的时候，当前物品就已经不能放进背包里了
            //当前j<W[i]的元素就是上一行中相应的元素。
            for( int j = C ; j >= w[i] ; j -- )
                //memo[i][j] = max( memo[i][j], v[i] + memo[i-1][j-w[i]]);
                memo[j] = max( memo[j], v[i] + memo[j-w[i]]);

        return memo[C];
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