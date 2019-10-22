#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;
map<point, vector<point>> graph;

void addEdge(const point& p1, const point& p2) {
    if (find(graph[p1].begin(), graph[p1].end(), p2) == graph[p1].end()) {
        graph[p1].push_back(p2);
    }

    if (find(graph[p2].begin(), graph[p2].end(), p1) == graph[p2].end()) {
        graph[p2].push_back(p1);
    }
}

void initialize(int N, int M) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {

        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> M;
    cin >> K;

    initialize(N, M);

    /*
    for (int i = 0; i < K; i++) {
        point p1, p2;
        cin >> p1.first >> p1.second;
        p2.first = p1.first - 1;
        p2.second = p1.second - 1;

        addEdge(p1, p2);
    }*/

    int cost = 1000000;
    return 0;
}