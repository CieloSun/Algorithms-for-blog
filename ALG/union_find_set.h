#pragma once
#include <cstring>
const int MAX_N = 100000;
class union_find_set
{
private:
	int par[MAX_N];
	int rank[MAX_N];//增加rank变量来防止树的退化（尽量让层数低的树连接到层数高的树上）
public:
	union_find_set(int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		for (int i = 0;i < n;++i)
		{
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x)
	{
		if (par[x] == x) return x;
		//此部分为两部分，find(par[x])为回溯寻找根节点，par[x]=回溯结果是把
		//叶子节点直接连接到根节点上以实现路径压缩，为简化起见，路径压缩后
		//我们没有更改rank值
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else
		{
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
};