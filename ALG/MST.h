#pragma once
#include "shortest_path.h"
#include "union_find_set.h"

struct Edge
{
	int from, to, cost;
} edge[MAX_N];//用结构体表示边
bool compare(const Edge &a, const Edge &b)
{
	return a.cost < b.cost;
}
bool path[MAX_V][MAX_V];//记录结果
int res;
void Kruskal()
{
	res = 0;
	union_find_set set(V);//初始化并查集
	int p = 0;//初始化edge数组游标
	for (int i = 0;i < V;++i)
	{
		for (int j = 0;j < V;++j)
		{
			path[i][j] = false;//给结果数组赋值
			if (cost[i][j] != INF)
			{
				edge[p++] = { i,j,cost[i][j] };//给edge数组赋值
			}
		}
	}
	std::sort(edge, edge + p, compare);//按边权从小到大排序edge数组	
	for (int i = 0;i < p;++i)
	{
		if (!set.same(edge[i].from, edge[i].to))//如果边的首尾节点没有在一个生成树中
		{
			path[edge[i].from][edge[i].to] = true;//添加这条边进入生成树
			set.unite(edge[i].from, edge[i].to);//让首尾节点连接
			res += edge[i].cost;
		}
	}
}
bool used[MAX_V];//表示是否访问过
int mincost[MAX_V];//表示到此点消耗值
void Prime()
{
	res = 0;
	for (int i = 0;i < V;++i)//初始化
	{
		used[i] = false;
		mincost[i] = INF;
		for (int j = 0;j < V;++j)
		{
			path[i][j] = false;
		}
	}
	mincost[0] = 0;//从0点开始
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