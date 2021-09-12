#include<iostream>
#include<vector>
using namespace std;

int N, M;
long long dist[501];
vector<pair<int, int>> v[501];
bool cycle;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 2; i <= N; i++)
		dist[i] = 987654321;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				int b = v[j][k].first;
				int c = v[j][k].second;
				if (dist[j] != 987654321 && dist[b] > c + dist[j])
				{
					dist[b] = c + dist[j];
					if (i == N) cycle = true;
				}
			}

		}
	}

	if (cycle) cout << -1 << '\n';
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == 987654321) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}


	return 0;
}