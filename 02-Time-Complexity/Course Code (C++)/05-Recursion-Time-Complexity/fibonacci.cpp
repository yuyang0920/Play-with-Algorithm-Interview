#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

//O(N)
long long fibonacci(int n)
{
	assert( n>=0 );

	int res[] = {0, 1};
	if(n<2)
		return res[n];

	long long fibN = 0;
	long long fibOne = 1;
	long long fibTwo = 0;

	for(int i = 2; i<n; i++)
	{
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
	}
	return fibN;
}

long long fibonacci2(int n)
{
	assert( n>=0 );

	int res[] = {0, 1};
	if(n<2)
		return res[n];

	return fibonacci2(n-2) + fibonacci2(n-1);
}

int main()
{
	int n = 50;
	clock_t startTime = clock();
	fibonacci(n);
	clock_t endTime = clock();
	cout << "none-recursion: "<<double(endTime - startTime)/CLOCKS_PER_SEC <<endl;

	startTime = clock();
	fibonacci2(n);
	endTime = clock();
	cout << "recursion: "<<double(endTime - startTime)/CLOCKS_PER_SEC <<endl;
	return 0;
}