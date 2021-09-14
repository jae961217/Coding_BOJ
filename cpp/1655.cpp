#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;


int main()
{
	priority_queue<int> maxpq, minpq;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (i % 2 == 0)
			maxpq.push(num);
		else
			minpq.push(-num);

		if (i == 0)
			cout << maxpq.top() << '\n';
		else
		{
			if (maxpq.top() > -minpq.top())
				cout << -minpq.top() << '\n';
			else
				cout << maxpq.top() << '\n';
		}

	}




	return 0;
}