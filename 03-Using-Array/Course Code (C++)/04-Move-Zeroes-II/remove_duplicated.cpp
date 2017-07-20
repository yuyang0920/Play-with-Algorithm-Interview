#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	set<int> s;
    	s.insert(nums.begin(), nums.end());
    	nums.clear();
        set<int>::iterator set_it = s.begin();
        while(set_it != s.end())
        	nums.push_back(*(set_it++));
        return nums.size();
    }
};






int main() {

    int arr[] = {0, 1, 0, 3, 12, 3, 1, 12, 9, 8};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    int len = Solution().removeDuplicates(vec);

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
    cout << "length: "<<len<<endl;
    return 0;
}