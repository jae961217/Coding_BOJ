//다익스트라를 이용한 풀이도 가능은 한데 시간이 조금 차이가 난다(다익스트라 풀이 아래에 주석)
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[101][101];

void func()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = 987654321;
		}
	}

	for (int i = 1; i <= n; i++)
		arr[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		if (arr[a][b] > c)
			arr[a][b] = c;
	}

	func();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 987654321)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}



//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int n, m;
//vector<pair<int, int>> v[101];
//long long dist[101];
//long long res[101][101];
//
//void func(int num)
//{
//	for (int i = 1; i <= n; i++)
//		dist[i] = 987654321;
//	dist[num] = 0;
//
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0,num });
//
//	while (!pq.empty())
//	{
//		int c = -pq.top().first;
//		int h = pq.top().second;
//		pq.pop();
//
//		for (int i = 0; i < v[h].size(); i++)
//		{
//			int next = v[h][i].first;
//			int nc = v[h][i].second;
//			if (dist[next] > dist[h] + nc)
//			{
//				dist[next] = dist[h] + nc;
//				pq.push({ -dist[next],next });
//			}
//		}
//	}
//
//
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (dist[i] == 987654321)
//		{
//			res[num][i] = 0;
//			continue;
//		}
//		res[num][i] = dist[i];
//	}
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a].push_back({ b,c });
//	}
//
//
//	for (int i = 1; i <= n; i++)
//		func(i);
//
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cout << res[i][j] << " ";
//		}
//		cout << '\n';
//	}
//
//
//
//
//	return 0;
//}