//이항계수 변형 -> 0개수 세는 문제
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;

long long twoCount(long long num)
{
	long long tmp = 0;

	for (long long i = 2; i <= num; i *= 2)
	{
		tmp += num / i;
	}
	return tmp;
}

long long fiveCount(long long num)
{
	long long tmp = 0;

	for (long long i = 5; i <= num; i *= 5)
	{
		tmp += num / i;
	}
	return tmp;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	long long two = twoCount(n) - twoCount(m) - twoCount(n - m);
	long long five = fiveCount(n) - fiveCount(m) - fiveCount(n - m);

	cout << min(two, five);

	return 0;
}