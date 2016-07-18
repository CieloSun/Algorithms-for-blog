#pragma once
#include "shortest_path.h"
#include "union_find_set.h"

struct Edge
{
	int from, to, cost;
} edge[MAX_N];//�ýṹ���ʾ��
bool compare(const Edge &a, const Edge &b)
{
	return a.cost < b.cost;
}
bool path[MAX_V][MAX_V];//��¼���
int res;
void Kruskal()
{
	res = 0;
	union_find_set set(V);//��ʼ�����鼯
	int p = 0;//��ʼ��edge�����α�
	for (int i = 0;i < V;++i)
	{
		for (int j = 0;j < V;++j)
		{
			path[i][j] = false;//��������鸳ֵ
			if (cost[i][j] != INF)
			{
				edge[p++] = { i,j,cost[i][j] };//��edge���鸳ֵ
			}
		}
	}
	std::sort(edge, edge + p, compare);//����Ȩ��С��������edge����	
	for (int i = 0;i < p;++i)
	{
		if (!set.same(edge[i].from, edge[i].to))//����ߵ���β�ڵ�û����һ����������
		{
			path[edge[i].from][edge[i].to] = true;//��������߽���������
			set.unite(edge[i].from, edge[i].to);//����β�ڵ�����
			res += edge[i].cost;
		}
	}
}
bool used[MAX_V];//��ʾ�Ƿ���ʹ�
int mincost[MAX_V];//��ʾ���˵�����ֵ
void Prime()
{
	res = 0;
	for (int i = 0;i < V;++i)//��ʼ��
	{
		used[i] = false;
		mincost[i] = INF;
		for (int j = 0;j < V;++j)
		{
			path[i][j] = false;
		}
	}
	mincost[0] = 0;//��0�㿪ʼ
	int prev = 0;
	while (true)
	{
		int visited = -1;
		for (int i = 0;i < V;++i)
		{
			if (!used[i] && (visited == -1 || mincost[i] < mincost[visited])) visited = i;
		}
		if (visited == -1) break;
		used[visited] = true;
		if (visited)
		{
			path[prev][visited] = true;
			prev = visited;
		}
		res += mincost[visited];
		for (int i = 0;i < V;++i)
		{
			mincost[i] = std::min(mincost[i], cost[visited][i]);
		}
	}
}