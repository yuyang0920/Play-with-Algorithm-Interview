#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
#if 0
    map<int,int> myMap;
    if( myMap.find( 42 ) == myMap.end() )
        cout<<"Can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;
            cout<<myMap[42]<<endl;
    if( myMap.find( 42 ) == myMap.end() )
        cout<<"Can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;

    myMap[42] ++;
    cout<<myMap[42]<<endl;
    if( myMap.find( 42 ) == myMap.end() )
        cout<<"Can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;

    myMap[42] --;
    cout<<myMap[42]<<endl;
    if( myMap.find( 42 ) == myMap.end() )
        cout<<"Can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;

    myMap.erase( 42 );
    if( myMap.find( 42 ) == myMap.end() )
        cout<<"Can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;
#endif
#if 1
    unordered_map<int,int> myMap1;
    if( myMap1.find( 42 ) == myMap1.end() )
        cout<<"Can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;
    if( myMap1.find( 42 ) == myMap1.end() )
        cout<<"Can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;
#endif

    return 0;
}