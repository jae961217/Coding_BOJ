#include<iostream>
#include<vector>
using namespace std;

int N;
int frontdp[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	int maxV = 0;
	for (int i = 1; i < N; i++)
	{
		int tmp = 0;
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				if (frontdp[i] < frontdp[j] + 1)
					frontdp[i] = frontdp[j] + 1;
			}
		}
		if (maxV < frontdp[i]) maxV = frontdp[i];
	}

	cout << maxV + 1;


	return 0;
}