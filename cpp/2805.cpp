//이분탐색 문제인데 공부 필요
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
long long M;
long long tree[1000000];

bool possible(long long height)
{
	long long len = 0;
	for (int i = 0; i < N; ++i)
	{
		if (tree[i] - height > 0) len += tree[i] - height;
	}

	if (len >= M) return true;
	return false;
}

int main()
{

	cin >> N >> M;
	long long low = 1, high = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> tree[i];
		if (high < tree[i]) high = tree[i];
	}

	long long result = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		if (possible(mid))
		{
			result = result > mid ? result : mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << result;

	return 0;
}