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
//ͼ����ʼ�㣬�յ�+1
void rankFinding(Rank_finding_point S[], int from, int to)
{
	int n = to - from;//ͳ����Ҫ����ĵ�ĸ���
	if (n <= 0)
	{
		return;
	}
	if (n == 1)
	{
		rankVal[S[from].x][S[from].y] = 0;
		return;
	}
	std::sort(S + from, S + to, cmpx);//�����е㰴x��С��������
	int mid = (to + from) >> 1;//��ȡ�е�
	rankFinding(S, from, mid);//�����from�㵽mid-1��
	rankFinding(S, mid, to);//�����mid�㵽to-1��
	std::sort(S + from, S + mid, cmpy);//�����ֱ�y����
	std::sort(S + mid, S + to, cmpy);
	for (int i = mid; i < to; ++i)//��������������飬�ҳ�yֵС��ѡ����yֵ�ĵ㼴Ϊ��ȫС�����ĵ�
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

