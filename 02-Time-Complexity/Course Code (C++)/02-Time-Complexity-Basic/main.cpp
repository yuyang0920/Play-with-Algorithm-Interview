#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {

    for( int x = 1 ; x <= 9 ; x ++ ){

        int n = pow(10, x);

        clock_t startTime = clock();

        int sum = 0;
        for( int i = 0 ; i < n ; i ++ )
            //这条加法指令运行10^8时，大约消耗0.4s
            sum += i;
        clock_t endTime = clock();
        //每一秒包含CLOCKS_PER_SEC个时钟周期
        cout<<"10^"<<x<<" : "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    return 0;
}