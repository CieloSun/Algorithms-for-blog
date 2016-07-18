#pragma once
#include <cstring>
const int MAX_N = 100000;
class union_find_set
{
private:
	int par[MAX_N];
	int rank[MAX_N];//����rank��������ֹ�����˻��������ò����͵������ӵ������ߵ����ϣ�
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
		//�˲���Ϊ�����֣�find(par[x])Ϊ����Ѱ�Ҹ��ڵ㣬par[x]=���ݽ���ǰ�
		//Ҷ�ӽڵ�ֱ�����ӵ����ڵ�����ʵ��·��ѹ����Ϊ�������·��ѹ����
		//����û�и���rankֵ
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