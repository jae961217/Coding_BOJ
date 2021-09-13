#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N;
int arr[1000001];
int res[1000001];
vector<pair<int, int>> v;
stack<pair<int, int>> ss;


void func()
{
	ss.push({ arr[0],0 });
	for (int i = 1; i < N; i++)
	{
		if (ss.top().first > arr[i])
			ss.push({ arr[i],i });
		else
		{
			while (!ss.empty() && ss.top().first < arr[i])
			{
				res[ss.top().second] = arr[i];
				ss.pop();
			}
			ss.push({ arr[i],i });
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

	}

	func();


	for (int i = 0; i < N; i++)
	{
		if (res[i] == 0)
			res[i]--;
		cout << res[i] << " ";
	}




	return 0;
}