#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V, E, K;
vector<pair<int, int>> vec[20001];
int cost[20001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++)
		cost[i] == 987654321;
	cost[K] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,K });

	while (!pq.empty())
	{
		int c = -pq.top().first;
		int h = pq.top().second;
		pq.pop();

		if (cost[h] < c)
			continue;

		for (int i = 0; i < vec[h].size(); i++)
		{
			int next = vec[h][i].first;
			int nc = vec[h][i].second;
			if (cost[next] > c + nc)
			{
				cost[next] = c + nc;
				pq.push({ -cost[next],next });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (cost[i] != 987654321)
			cout << cost[i] << '\n';
		else
			cout << "INF\n";
	}


	return 0;
}