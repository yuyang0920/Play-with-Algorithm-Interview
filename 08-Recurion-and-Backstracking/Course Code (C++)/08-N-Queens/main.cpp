#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    vector<bool> col, dia1, dia2;
    vector<vector<string> > res;

    // 尝试在一个n皇后问题中, 摆放第index行的皇后位置
    // row存放的是每一行皇后摆放在第几列。
    // 例如row[i]=k,则说明皇后摆放在第k列
    void putQueen(int n , int index, vector<int> &row){

        if( index == n ){
            res.push_back( generateBoard(n,row) );
            return;
        }

        for( int i = 0 ; i < n ; i ++ )
            // 尝试将第index行的皇后摆放在第i列
            if( !col[i] && !dia1[index+i] && !dia2[index-i+n-1] ){
                row.push_back(i);
                //第i列不能再有皇后了
                col[i] = true;
                //对角线上不能有皇后了
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                //在index+1行尝试摆放皇后
                putQueen(n, index + 1, row);
                //回溯的过程，不再把第index行的皇后放在第i列了
                //同时将i给pop出来，继而将index行的皇后摆放在后面的位置
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
                row.pop_back();
            }

        return;
    }

    //将n皇后row的解转化成vector<string>
    vector<string> generateBoard( int n, vector<int> &row ){
        assert( row.size() == n );
        //初始化有n个string，每个string就是'.'
        vector<string> board(n, string(n, '.'));
        for( int i = 0 ; i < n ; i ++ )
            board[i][row[i]] = 'Q';
        return board;
    }
public:
    vector<vector<string> > solveNQueens(int n) {

        res.clear();
        //竖方向，在尝试的过程中如果将皇后摆在了第i列
        //则相应的col[i]为true
        col = vector<bool>(n, false);
        //对角线，个数为2*n-1
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);

        vector<int> row;
        //从第0行开始摆，同时解存在row中
        putQueen(n , 0 , row);

        return res;
    }
};

int main() {

    int n = 8;
    vector<vector<string> > res = Solution().solveNQueens(n);
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < n ; j ++)
            cout<<res[i][j]<<endl;
        cout<<endl;
    }

    return 0;
}