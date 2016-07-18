#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

const int RANK_FINDING_MAX_N = 1000;

struct  Rank_finding_point
{
	int x, y;
};

bool cmpx(Rank_finding_point a, Rank_finding_point b)
{
	return a.x < b.x;
}

bool cmpy(Rank_finding_point a, Rank_finding_point b)
{
	return a.y < b.y;
}

int rankVal[RANK_FINDING_MAX_N][RANK_FINDING_MAX_N];

Rank_finding_point S[RANK_FINDING_MAX_N];
//图，起始点，终点+1
void rankFinding(Rank_finding_point S[], int from, int to)
{
	int n = to - from;//统计需要处理的点的个数
	if (n <= 0)
	{
		return;
	}
	if (n == 1)
	{
		rankVal[S[from].x][S[from].y] = 0;
		return;
	}
	std::sort(S + from, S + to, cmpx);//将所有点按x从小到大排序
	int mid = (to + from) >> 1;//获取中点
	rankFinding(S, from, mid);//处理从from点到mid-1点
	rankFinding(S, mid, to);//处理从mid点到to-1点
	std::sort(S + from, S + mid, cmpy);//处理后分别按y排序
	std::sort(S + mid, S + to, cmpy);
	for (int i = mid; i < to; ++i)//对于右组遍历左组，找出y值小于选定点y值的点即为完全小于它的点
	{
		for (int j = from; j < mid; ++j)
		{
			if (S[i].y > S[j].y)
			{
				rankVal[S[i].x][S[i].y]++;
			}
		}
	}
}

