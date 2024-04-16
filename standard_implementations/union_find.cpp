// You can alway use simpler implementation for any given use case

class UnionFind {
	vector<int> id, rank, size;
	int cnt;
	
	// constructor
	UnionFind(int n): id(n), rank(n, 0), size(n, 1), cnt(n) {
		iota(id.begin(), id.end(), 0);
	}
	
	// find method
	int find(int a) {
		return id[a] == a ? a : (id[a] = find(id[a]));
	}
	
	// connect method
	// uses both rank and size to effectively merge two components
	int connect(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (rank[a] > rank[b]) {
			id[b] = a;
			size[b] += size[a];
		} else {
			id[a] = b;
			size[b] += size[a];
			if (rank[a] == rank[b]) rank[y]++;
		}
		--cnt;
	}

	// size of a component
	int getSize(int a) {
	return size[find(a)];
	}

	// number of components
	int getCount() { return cnt; }
};