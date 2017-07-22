#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdexcept>

using namespace std;

//时间复杂度O(n^2)
//空间复杂度O(n^2)
class Solution {
public:
    int numberOfBoomerangs(vector< pair<int, int> >& points) {

        int res = 0;
        for( int i = 0 ; i < points.size() ; i ++ ){

            // record中存储 点i 到所有其他点的距离出现的频次
            // 第一个int的距离，第二个int是出现的频率
            // 对每一个点都创建一个查找表
            unordered_map<int, int> record;
            for( int j = 0 ; j < points.size() ; j ++ )
                if( j != i )
                    record[dis(points[i], points[j])] += 1;

            for( unordered_map<int, int>::iterator iter = record.begin() ; 
                    iter != record.end() ; iter ++ )
                res += (iter->second)*(iter->second-1);
        }
        return res;
    }

private:
    //两点之间的距离有可能是浮点型，会有误差，所以在用查找表进行
    //准确的查找时有可能是不安全的。要尽量避免浮点型的误差
    //我们计算两点间的距离时不开根号，任然可以反映距离的大小
    //注意整型溢出的问题，由于题目给出了坐标的范围[-10000,10000]
    //没有超过32位整型的范围
    //两点间的距离：sqrt((x1-x2)^2 + (y1-y2)^2)
    int dis( const pair<int,int> &pa, const pair<int,int> &pb){
        return (pa.first - pb.first) * (pa.first - pb.first) +
               (pa.second - pb.second) * (pa.second - pb.second);
    }
};

int main() {

    vector<pair<int,int>> vec;
    vec.push_back( make_pair(0, 0) );
    vec.push_back( make_pair(1, 0) );
    vec.push_back( make_pair(2, 0) );

    cout<<Solution().numberOfBoomerangs( vec )<<endl;

    return 0;
}