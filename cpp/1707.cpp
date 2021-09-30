#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int K, V, E;
vector<int> v[20001];
int res[20001];

bool check()
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			int next = v[i][j];
			if (res[i] == res[next])
				return false;
		}
	}
	return true;
}

void func(int a, int b)
{
	res[a] = b;

	for (int i = 0; i < v[a].size(); i++)
	{
		int next = v[a][i];
		if (!res[next])
			func(next, 3 - b);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;
	for (int i = 0; i < K; i++)
	{

		cin >> V >> E;
		for (int j = 0; j < E; j++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int j = 1; j <= V; j++)
		{
			if (res[j] == 0)
				func(j, 1);
		}

		if (check())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		for (int j = 1; j <= V; j++)
			v[j].clear();
		memset(res, 0, sizeof(res));
	}



	return 0;
}