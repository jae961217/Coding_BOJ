//1912
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int arr[100001];
int dp[100001];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	long long value = -1000;

	for (int i = 0; i < N; i++)
	{
		if (value < dp[i])
			value = dp[i];
	}

	cout << value;

	return 0;
}