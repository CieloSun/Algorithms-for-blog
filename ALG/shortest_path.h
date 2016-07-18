#pragma once
#include <algorithm>
#include <queue>
#include <vector>

const int MAX_V = 100;
const int INF = 1000000;
int cost[MAX_V][MAX_V];
int d[MAX_V], V, s;
//自定义优先队列less比较函数
struct cmp
{
	bool operator()(int &a, int &b) const
	{
		//因为优先出列为greater，所以反向定义实现最小值优先
		return d[a] > d[b];
	}
};


void Dijkstra()
{
	std::priority_queue<int, std::vector<int>, cmp> pq;
	pq.push(s);
	d[s] = 0;
	while (!pq.empty())
	{
		int tmp = pq.top();pq.pop();
		for (int i = 0;i < V;++i)
		{
			if (d[i] > d[tmp] + cost[tmp][i])
			{
				d[i] = d[tmp] + cost[tmp][i];
				pq.push(i);
			}
		}
	}
}

void Floyd_Washall()
{
	for (int i = 0;i < V;++i)
		for (int j = 0;j < V;++j)
			for (int k = 0;k < V;++k)
				cost[i][j] = std::min(cost[i][j], cost[i][k] + cost[k][j]);
	for (int i = 0;i < V;++i) d[i] = cost[s][i];
}

void DP_shortestPath()
{
	std::queue<int> q;
	d[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int v = q.front();q.pop();
		for (int i = 0;i < V;++i)
		{
			if (d[i] > d[v] + cost[v][i])
			{
				d[i] = d[v] + cost[v][i];
				q.push(i);
			}
		}
	}
}