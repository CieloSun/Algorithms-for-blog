#pragma once
#include <queue>
#include <string>

int huffman_N;
std::string huffman_code_res[MAX_N];

struct Node
{
	int id, freq, left, right;
	void init(int i, int f)
	{
		id = i;
		freq = f;
		left = right = INF;
	}
	bool operator<(const Node &a) const
	{
		return a.freq < freq;
	}
} huffman_node[2 * MAX_N];

void add_huffman_code(Node tmp)
{
	huffman_code_res[tmp.left] = huffman_code_res[tmp.id] + "0";
	huffman_code_res[tmp.right] = huffman_code_res[tmp.id] + "1";
	if (huffman_node[tmp.left].left != INF) add_huffman_code(huffman_node[tmp.left]);
	if (huffman_node[tmp.right].left != INF) add_huffman_code(huffman_node[tmp.right]);
}

void make_huffman_tree()
{
	std::priority_queue<Node> pq;
	for (int i = 0;i < huffman_N;++i)
	{
		pq.push(huffman_node[i]);
		huffman_code_res[i] = "";
	}
	Node a, b;
	while (!pq.empty())
	{
		a = pq.top();pq.pop();
		if (pq.empty()) break;
		b = pq.top();pq.pop();
		huffman_node[a.id + huffman_N] = { a.id + huffman_N,a.freq + b.freq,a.id,b.id };
		pq.push(huffman_node[a.id + huffman_N]);
	}
	add_huffman_code(a);
}
/*
7 2 3 5 8 13 15 18
*/