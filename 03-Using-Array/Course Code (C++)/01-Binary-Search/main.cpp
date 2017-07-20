#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"

using namespace std;

template<typename T>
//arr含有n个元素
//O(logn)
int binarySearch( T arr[], int n, T target ){
    // 在[l...r]的范围里寻找target
    int l = 0, r = n-1; 
    // 当 l == r时,区间[l...r]依然是有效的
    while( l <= r ){    
        //int mid = (l+r)/2;
        int mid = l + (r-l)/2;
        if( arr[mid] == target ) return mid;
        if( target > arr[mid] )
        // target在[mid+1...r]中; [l...mid]一定没有target
            l = mid + 1;  
        else    // target < arr[mid]
        // target在[l...mid-1]中; [mid...r]一定没有target
            r = mid - 1;  
    }

    return -1;
}

int main() {

    int n = pow(10,7);
    //生成 0~(1000W-1) 的有序数组
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for( int i = 0 ; i < n ; i ++ )
        assert( i == binarySearch(data, n, i) );
    clock_t endTime = clock();

    cout<<"binarySearch test complete."<<endl;
    cout<<"Time cost: "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}