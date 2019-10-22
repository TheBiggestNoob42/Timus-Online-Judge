#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

typedef pair<string, int> person;

vector<person> list_of_people;
map<int, vector<int>> usu;

int find(const vector<person>& vec, const person& p1) {
	for (int x = 0; x < vec.size(); x++) {
		if (vec[x].first == p1.first) {
			return x;
		}
	}
	return -1;
}


int addPeople(const person& p1) {
	int idx = find(list_of_people, p1);

	if (idx != -1) {
		return idx;
	}
	
	list_of_people.push_back(p1);
	return list_of_people.size() - 1;
}

void addEdge(int first, int second) {
	usu[first].push_back(second);
	usu[second].push_back(first);
}

void bfs(const int& pers1) {
	queue<int> q;

	q.push(pers1);

	int idx, importance;
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		importance = list_of_people[idx].second;
		
		auto neighbors = usu[idx];
		for (int x = 0; x < neighbors.size(); x++) {
			if (list_of_people[neighbors[x]].second == -1) {
				list_of_people[neighbors[x]].second = importance + 1;
				q.push(neighbors[x]);
			}
		}
	}
}

void clean(vector<int>& vec) {
	unordered_set<int> temp;
	temp.insert(vec.begin(), vec.end());
	
	while (!vec.empty()) {
		vec.pop_back();
	}
	for (const int& x: temp) {
		vec.push_back(x);
	}
}

int main() {
	int N;
	cin >> N;

	person one, two, three;
	int idx1, idx2, idx3;
	for (int i = 0; i < N; i++) {
		cin >> one.first;
		cin >> two.first;
		cin >> three.first;

		one.second = -1;
		two.second = -1;
		three.second = -1;

		idx1 = addPeople(one);
		idx2 = addPeople(two);
		idx3 = addPeople(three);

		addEdge(idx1, idx2);
		addEdge(idx1, idx3);
		addEdge(idx2, idx3);
	}

	person man = pair<string, int>("Isenbaev", 0);
	int idx = find(list_of_people, man);
	if (idx != -1) {
		list_of_people[idx] = man;
	}

	for (auto itr = usu.begin(); itr != usu.end(); itr++) {
		clean(itr->second);
	}

	if (idx != -1) {
		bfs(idx);
	}

	auto comp = [](const person& p1, const person& p2) -> bool {
		return p1.first.compare(p2.first) < 0;
	};

	sort(list_of_people.begin(), list_of_people.end(), comp);

	for (int i = 0; i < list_of_people.size(); i++) {
		cout << list_of_people[i].first << " " << (list_of_people[i].second >= 0 ? to_string(list_of_people[i].second) : "undefined") << endl;
	}

	return 0;
}