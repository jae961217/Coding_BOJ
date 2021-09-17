#include<iostream>
#include<queue>
using namespace std;


int N, M;
char arr[1001][1001];
int res[1001][1001][2];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct node
{
	int x;
	int y;
	int block;
};

bool check(int a, int b)
{
	if (a < 0 || a >= N)
		return false;
	if (b < 0 || b >= M)
		return false;
	return true;
}

int func()
{
	queue<node> q;
	q.push({ 0,0,1 });
	res[0][0][1] = 1;
	while (!q.empty())
	{
		int tmpx = q.front().x;
		int tmpy = q.front().y;
		int block = q.front().block;
		q.pop();

		if (tmpx == N - 1 && tmpy == M - 1)
			return res[tmpx][tmpy][block];

		for (int i = 0; i < 4; i++)
		{
			int nx = tmpx + dx[i];
			int ny = tmpy + dy[i];
			if (check(nx, ny))
			{
				if (arr[nx][ny] == '1' && block)
				{
					res[nx][ny][block - 1] = res[tmpx][tmpy][block] + 1;
					q.push({ nx,ny,block - 1 });
				}
				else if (arr[nx][ny] == '0' && res[nx][ny][block] == 0)
				{
					res[nx][ny][block] = res[tmpx][tmpy][block] + 1;
					q.push({ nx,ny,block });
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << func();

	return 0;
}