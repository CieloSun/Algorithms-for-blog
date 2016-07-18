#pragma once
#include <string>

using std::string;

string LCS(string s, string t)
{
	const int MAX_N = 100;
	int dp[MAX_N][MAX_N];
	string rec[MAX_N][MAX_N];

	for (int i = 0;i < s.size();++i)
	{
		for (int j = 0;j < t.size();++j)
		{
			dp[i][j] = 0;
			rec[i][j].clear();
		}
	}
	for (int i = 0;i < s.size();++i)
	{
		for (int j = 0;j < t.size();++j)
		{
			if (s[i] == t[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				rec[i + 1][j + 1] = rec[i][j] + s[i];
			}
			else
			{
				if (dp[i][j + 1] > dp[i + 1][j])
				{
					dp[i + 1][j + 1] = dp[i][j + 1];
					rec[i + 1][j + 1] = rec[i][j + 1];
				}
				else
				{
					dp[i + 1][j + 1] = dp[i + 1][j];
					rec[i + 1][j + 1] = rec[i + 1][j];
				}
			}
		}
	}
	return rec[s.size()][t.size()];
}