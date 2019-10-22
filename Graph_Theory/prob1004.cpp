#include <bits/stdc++.h>
using namespace std;

#define MAXN 100 + 1
int graph[MAXN][MAXN];

/* An adjacency list implementation */
class Graph {
private:
	// each vertex holds a list of connected vertex as well as the weights associated with both
	map<vector<int>, pair<int, int>> weight;
public:
	Graph();
	~Graph();

	void addEdge(int u, int v, int weight);

	void getWeight(int u, int v);
};

Graph::Graph() {
	
}

int main() {
	int N, M;

	cin >> N >> M;

	do {
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				graph[i][j] = 0;
			}
		}

		int a, b, length; // a and b are the ends of the graph
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> length;
			graph[a][b] = length;
			graph[b][a] = length;
		}
		cout << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}

		

		cin >> N;
		if (N == -1) {
			break;
		}
		cin >> M;
	} while (true);
}
