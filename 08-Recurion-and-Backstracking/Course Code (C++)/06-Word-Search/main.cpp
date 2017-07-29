#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};//四个方向移动的位移
    int m,n;//整个board平面有多少行多少列
    vector<vector<bool> > visited;

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从board[startx][starty]开始, 寻找word[index...word.size())
    // 每次从word的第index个元素开始寻找
    bool searchWord( const vector<vector<char> > &board, const string& word, int index,
                    int startx, int starty ){

        //assert( inArea(startx,starty) );
        //递归终止条件
        if( index == word.size() - 1 )
            return board[startx][starty] == word[index];

        //当前board所在的位置和要找的word[index]是相等的，
        //基于此才应该继续递归寻找
        if( board[startx][starty] == word[index] ){
            visited[startx][starty] = true;
            // 从startx, starty出发,向四个方向寻找
            for( int i = 0 ; i < 4 ; i ++ ){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                //确保不越界并且新的元素没有被访问过
                if( inArea(newx, newy) && !visited[newx][newy] &&
                    searchWord( board , word , index + 1 , newx , newy ) )
                    return true;
            }
            //因为使用的是回溯法，如果[startx][starty]所有的方向都没找到
            //要将它重新设置成false
            visited[startx][starty] = false;
        }
        //说明startx、starty这个位置都不对，直接return false
        return false;
    }
public:
    //在board中寻找word
    bool exist(vector<vector<char> >& board, string word) {

        m = board.size();//行
        assert( m > 0 );
        n = board[0].size();//列
        visited = vector<vector<bool> >(m,vector<bool>(n,false));
        //遍历board
        for( int i = 0 ; i < board.size() ; i ++ )
            for( int j = 0 ; j < board[i].size() ; j ++ )
                //每一重时都尝试从i/j出发来寻找word字符串
                if( searchWord( board, word, 0 , i, j) )
                    return true;

        return false;
    }
};

int main() {

    char b[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char> > board;
    for( int i = 0 ; i < 3 ; i ++ )
        board.push_back( vector<char>(b[i],b[i]+sizeof(b[i])/sizeof(char)) );

    int cases = 3;
    string words[3] = {"ABCCED" , "SEE" , "ABCB" };
    for( int i = 0 ; i < cases ; i ++ )
        if( Solution().exist(board,words[i]))
            cout<<"found "<<words[i]<<endl;
        else
            cout<<"can not found "<<words[i]<<endl;

    return 0;
}