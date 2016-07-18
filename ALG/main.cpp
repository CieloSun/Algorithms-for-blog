#include "sort.h"
#include "search.h"
#include "rankfinding.h"
#include "MST.h"
#include "huffman_code.h"
#include "LCS.h"
#include "matrix-chain.h"
#include <array>
#include <vector>
#include <functional>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;
int testArray[100000];
template<class T> void SortTest(T* testArray)
{
	std::default_random_engine engine((unsigned int)time(NULL));
	std::uniform_real_distribution<double> distribution(0, 100000);
	for (int e = 1;e <= 16;e++)
	{
		long long length = std::pow(2, e);
		for (long long i = 0;i < length;++i)
		{
			testArray[i] = static_cast<T>(distribution(engine));
		}
		double startTime = clock();
		insertSort(testArray, length);
		double endTime = clock();
		printf("%lld\t%s%f\n", length, "Insert Sort:", (endTime - startTime) / 1000);
	}
}
void searchTest()
{
	
	int a[] = { 1,2,3,4,5,7,9,11,17,20,23,39 };
	cout << binarySearch(a, 0, 11, 39) << endl;
	cout << binarySearch(a, 0, 11, 37) << endl;
	cout << binarySearch(a, 5, 10, 39) << endl;
	cout << endl;
	cout << binarySearchRecursive(a, 0, 11, 39) << endl;
	cout << binarySearchRecursive(a, 0, 11, 37) << endl;
	cout << binarySearchRecursive(a, 5, 10, 39) << endl;
	cout << endl;
	vector<int> b{ 1,2,3,4,4,7,9,11,17,20,23,39 };
	cout << "vector<int> b{ 1,2,3,4,4,7,9,11,17,20,23,39 };" << endl;
	cout << "count(b.begin(), b.end(), 4):"
		<< count(b.begin(), b.end(), 4) << endl;
	cout << endl;
	cout << "find(b.begin(), b.end(), 39) - b.begin():"
		<< find(b.begin(), b.end(), 39) - b.begin() << endl;
	cout << "find(b.begin(), b.end(), 4) - b.begin():"
		<< find(b.begin(), b.end(), 4) - b.begin() << endl;
	cout << "find(b.begin(), b.end(), 37) - b.begin():"
		<< find(b.begin(), b.end(), 37) - b.begin() << endl;
	cout << "find(b.begin() + 5, b.begin() + 10, 39) - b.begin():"
		<< find(b.begin() + 5, b.begin() + 10, 39) - b.begin() << endl;
	cout << endl;
	cout << "binary_search(b.begin(), b.end(), 39):"
		<< binary_search(b.begin(), b.end(), 39) << endl;
	cout << "binary_search(b.begin(), b.end(), 37):"
		<< binary_search(b.begin(), b.end(), 37) << endl;
	cout << endl;
	cout << "lower_bound(b.begin(), b.end(), 39) - b.begin():"
		<< lower_bound(b.begin(), b.end(), 39) - b.begin() << endl;
	cout << "lower_bound(b.begin(), b.end(), 4) - b.begin():"
		<< lower_bound(b.begin(), b.end(), 4) - b.begin() << endl;
	cout << "lower_bound(b.begin(), b.end(), 37) - b.begin():"
		<< lower_bound(b.begin(), b.end(), 37) - b.begin() << endl;
	cout << "lower_bound(b.begin() + 5, b.begin() + 10, 39) - b.begin():"
		<< lower_bound(b.begin() + 5, b.begin() + 10, 39) - b.begin() << endl;
	cout << endl;
	cout << "upper_bound(b.begin(), b.end(), 39) - b.begin():"
		<< upper_bound(b.begin(), b.end(), 39) - b.begin() << endl;
	cout << "upper_bound(b.begin(), b.end(), 4) - b.begin():"
		<< upper_bound(b.begin(), b.end(), 4) - b.begin() << endl;
	cout << "upper_bound(b.begin(), b.end(), 37) - b.begin():"
		<< upper_bound(b.begin(), b.end(), 37) - b.begin() << endl;
	cout << "upper_bound(b.begin() + 5, b.begin() + 10, 39) - b.begin():"
		<< upper_bound(b.begin() + 5, b.begin() + 10, 39) - b.begin() << endl;
}
void rankfindingTest()
{
	memset(rankVal, -1, sizeof(rankVal));
	memset(S, 0, sizeof(S));
	S[0] = { 1, 1 };
	S[1] = { 1, 3 };
	S[2] = { 2, 5 };
	S[3] = { 6, 2 };
	S[4] = { 9, 3 };
	S[5] = { 4, 8 };
	S[6] = { 7, 6 };
	S[7] = { 5, 5 };
	S[8] = { 2, 3 };
	rankFinding(S, 0, 9);
	for (int i = 0; i < RANK_FINDING_MAX_N; ++i)
	{
		for (int j = 0; j < RANK_FINDING_MAX_N; ++j)
		{
			if (rankVal[i][j] != -1)
			{
				std::cout << i << ' ' << j << ' ' << rankVal[i][j] << std::endl;
			}
		}
	}
}
void shortestPathTest()
{
	/*
	9
	1000000 1 5 7 4 1000000 1000000 1000000 1000000
	1000000 1000000 1000000 1000000 1000000 3 10 1000000 1000000
	1000000 1000000 1000000 1000000 1000000 2 1000000 2 1000000
	1000000 1000000 1000000 1000000 1000000 1000000 1 1000000 1000000
	1000000 1000000 1000000 1000000 1000000 1000000 1000000 3 1000000
	1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 2
	1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 9
	1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 5
	1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000
	*/
	cin >> V;
	for (int i = 0;i < V;++i)
		for (int j = 0;j < V;++j) cin >> cost[i][j];
	for (int i = 0;i < V;++i) d[i] = INF;
	s = 0;
	Dijkstra();
	//DP_shortestPath();
	//Floyd_Washall();
	for (int i = 0;i < V;++i) cout << d[i] << endl;
}
void mstTest()
{
	/*
	9
	1000000 1 5 7 4 1000000 1000000 1000000 1000000
	1 1000000 1000000 1000000 1000000 3 10 1000000 1000000
	5 1000000 1000000 1000000 1000000 2 1000000 2 1000000
	7 1000000 1000000 1000000 1000000 1000000 1 1000000 1000000
	4 1000000 1000000 1000000 1000000 1000000 1000000 3 1000000
	1000000 3 2 1000000 1000000 1000000 1000000 1000000 2
	1000000 10 1000000 1 1000000 1000000 1000000 1000000 9
	1000000 1000000 2 1000000 3 1000000 1000000 1000000 5
	1000000 1000000 1000000 1000000 1000000 2 9 5 1000000
	*/
	cin >> V;
	for (int i = 0;i < V;++i)
		for (int j = 0;j < V;++j)
		{
			cin >> cost[i][j];
		}			
	for (int i = 0;i < V;++i) d[i] = INF;
	cout << "Kruskal:" << endl;
	Kruskal();
	for (int i = 0;i < V;++i)
	{
		for (int j = 0;j < V;++j)
		{
			if (path[i][j]) cout << i << " " << j << endl;
		}
	}
	cout << res << endl;
	cout << endl;
	cout << "Prime" << endl;
	Prime();
	for (int i = 0;i < V;++i)
	{
		for (int j = 0;j < V;++j)
		{
			if (path[i][j]) cout << i << " " << j << endl;
		}
	}
	cout << res << endl;
}
void huffman_codeTest()
{
	cin >> huffman_N;
	for (int i = 0;i < huffman_N;++i)
	{
		int tmp;
		cin >> tmp;
		huffman_node[i].init(i, tmp);
	}
	make_huffman_tree();
	for (int i = 0;i < huffman_N;++i)
		cout << i << " " << huffman_node[i].freq << " " << huffman_code_res[i] << endl;
}
void LCS_Test()
{
	string s, t;
	cin >> s >> t;
	cout << LCS(s, t) << endl;
}
void matrix_chain_test()
{
	cin >> matrix_V;
	for (int i = 0;i <= matrix_V;++i) cin >> matrix_p[i];
	for (int i = 0;i <= matrix_V;++i)
	{
		for (int j = 0;j <= matrix_V;++j)
		{
			m[i][j] = INF;
		}
		m[i][i] = 0;
	}
	int i, j;
	while (true)
	{
		cin >> i >> j;
		if (i == -1) break;
		cout << matrix_mul(i, j) << endl;
	}
}
int main()
{
	//SortTest(testArray);
	//searchTest();
	//rankfindingTest();
	//shortestPathTest();
	//mstTest();
	//huffman_codeTest();
	//LCS_Test();
	matrix_chain_test();
	return 0;
}