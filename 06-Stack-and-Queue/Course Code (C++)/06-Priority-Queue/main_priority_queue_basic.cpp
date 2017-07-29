#include <iostream>
#include <queue>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <functional>

using namespace std;

//比较a的b的各位数
//谁小就排在前面
//也就是true，则降序
bool myCmp( int a , int b ){

    return a%10 > b%10;
}

int main() {

    srand(time(NULL));

    // 默认的priority queue, 底层是最大堆
    priority_queue<int> pq;

    for( int i = 0 ; i < 10 ; i ++){
        //随机生成从0-99
        int num = rand()%100;
        pq.push( num );
        cout<<"insert "<<num<<" in priority queue."<<endl;
    }

    while( !pq.empty() ){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout << endl << endl;
/*--------------------------------------------------*/
    // 使用greater的priority queue, 底层是最小堆
    // C++中默认是使用less
    priority_queue< int, vector<int>, greater<int> > pq2;

    for( int i = 0 ; i < 10 ; i ++){
        int num = rand()%100;
        pq2.push( num );
        cout<<"insert "<<num<<" in priority queue."<<endl;
    }

    while( !pq2.empty() ){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }

    cout<<endl<<endl;
/*--------------------------------------------------*/
    #if 0
    // 使用自定义Comparator的priority queue
    // function<bool(int,int)> 可调用对象模板类。
    priority_queue<int, vector<int>, function<bool(int,int)>> pq3(myCmp);

    for( int i = 0 ; i < 10 ; i ++){
        int num = rand()%100;
        pq3.push( num );
        cout<<"insert "<<num<<" in priority queue."<<endl;
    }

    while( !pq3.empty() ){
        cout<<pq3.top()<<" ";
        pq3.pop();
    }
    #endif

    return 0;
}