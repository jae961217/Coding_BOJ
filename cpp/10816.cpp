#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		cout << upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a) << " ";
	}

	return 0;
}
