#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int N, M;

bool func(int a)
{
	int left = 0, right = N - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (v[mid] > a) right = mid - 1;
		else if (v[mid] < a) left = mid + 1;
		else return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		if (func(a)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}