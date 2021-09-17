#include<iostream>
using namespace std;

int T;

int GCD(int a, int b)
{
	if (a % b == 0) return b;
	return GCD(b, a % b);
}


int cal(int M, int N, int x, int y)
{
	int maxYear = M * N / GCD(M, N);
	while (1)
	{
		if (x > maxYear || (x - 1) % N + 1 == y) break;
		x += M;
	}

	if (x > maxYear) return -1;
	else return x;
}


int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		cout << cal(M, N, x, y) << '\n';
	}

	return 0;
}