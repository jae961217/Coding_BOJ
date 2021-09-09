//Longest Common Subsequence, ���� ���� �κ� ����
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s1, s2;
int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;
	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[s1.size()][s2.size()];

}