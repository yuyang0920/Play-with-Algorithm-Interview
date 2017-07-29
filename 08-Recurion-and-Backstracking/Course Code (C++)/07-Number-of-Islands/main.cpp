#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    //若题目中对搜索的顺序有要求，就需要特别注意！
    int d[4][2] = {{-1,0}，{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从grid[x][y]的位置开始,进行floodfill
    // 进入到dfs中的都保证了(x,y)合法,且grid[x][y]是没有被访问过的陆地
    // 这里没有回溯的过程，因为我们最终的目的就是将最初和[i][j]相连的所有
    // 陆地都被标记上！
    void dfs( vector<vector<char>>& grid , int x , int y ){

        //assert( inArea(x,y) );
        //当前访问到的x、y之前是没有被访问过的
        visited[x][y] = true;
        for( int i = 0 ; i < 4 ; i ++ ){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            //实际上递归终止条件融入到了这个if语句中
            //满足这三点则找到了新的没有被标记的陆地，和当前[x][y]的位置相连接
            if( inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1' )
                dfs( grid , newx , newy );
        }

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        if( m == 0 )
            return 0;
        n = grid[0].size();
        visited = vector<vector<bool> >(m,vector<bool>(n,false));

        int res = 0;
        for( int i = 0 ; i < m ; i ++ )
            for( int j = 0 ; j < n ; j ++ )
                if( grid[i][j] == '1' && !visited[i][j] ){
                    //floodfill算法，对grid[i][j]这块陆地相连接的
                    //所有的陆地，即属于找到的新岛屿的所有陆地都进行一次标记
                    //即将想应的visited[i][j]标记成true
                    //这样再继续循环的时候对于同属于这块岛屿的陆地就不会重复计算了
                    //以i/j位置作为起始点进行深度优先遍历
                    dfs( grid , i , j );
                    res ++;
                }
        return res;
    }
};

int main() {

    char g1[4][5] = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}};
    vector<vector<char>> grid1;
    for(int i = 0 ; i < 4 ; i ++ )
        grid1.push_back( vector<char>( g1[i] , g1[i] + sizeof( g1[i])/sizeof(char) ) );
    cout<<Solution().numIslands(grid1)<<endl;

    char g2[4][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}};
    vector<vector<char>> grid2;
    for(int i = 0 ; i < 4 ; i ++ )
        grid2.push_back( vector<char>( g2[i] , g2[i] + sizeof( g2[i])/sizeof(char) ) );
    cout<<Solution().numIslands(grid2)<<endl;

    return 0;
}