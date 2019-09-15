#include "UnionFind.h"



UnionFind::UnionFind()
{
	
	for (int i = 0; i < 400; i++) {
		id.push_back(i);
		size.push_back(1);
	}
}
UnionFind::UnionFind(int n)
{
	for (int i = 0; i < n; i++) {
		id.push_back(i);
		size.push_back(0);
	}
}



int UnionFind::find(int i)
{
	while (i != id[i]) {
		i = id[i];
	}
	return i;
}
void UnionFind::unionF(int p, int q)
{
	int rootp = find(p);
	int rootq = find(q);
	if (rootp == rootq) return;
	if (size[rootp] < size[rootq]) {
		id[rootp] = rootq;
		size[rootq] += size[rootp];

	}
	else {
		id[rootq] = rootp;
		size[rootp] += size[rootq];
	}
	
}
int UnionFind::count(int i) {
	return size[i];
}

bool UnionFind::connected(int p, int q) {
	if (find(p) == find(q)) return true;
	return false;
}
