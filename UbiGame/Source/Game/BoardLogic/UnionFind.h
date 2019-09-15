#pragma once
#include <vector>
#ifndef  UNIONFIND_H
#define	UNIONFIND_H

using namespace std;
class UnionFind
{
public:
	UnionFind(int n);
	UnionFind();


	void unionF(int p, int q);
	
	int find(int i);
	int count(int i);
	
	bool connected(int p, int q);
private:
	std::vector<int> id;
	std::vector<int> size;
};

#endif	UNIONFIND_H

