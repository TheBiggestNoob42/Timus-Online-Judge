#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef pair<string, int> person;
vector<person> list_of_people;

vector<int> queue;
map<int, vector<int>> usu;


string to_string(vector<int>& vec) {
	string str = "[";
	for (int i = 0; i < vec.size() - 1; i++) {
		// str += list_of_people[vec[i]].first + ", ";
		str += to_string(vec[i]) + ", ";
	}
	// str += list_of_people[vec[vec.size() - 1]].first + "]";
	str += to_string(vec[vec.size() - 1]) + "]";
	return str;
}

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

void dfs(const int& pers1, int importance) {
	for (int x = 0; x < queue.size(); x++) {
		if (queue[x] == pers1) {
			return;
		}
	}

	queue.push_back(pers1);
	list_of_people[pers1].second = importance;

	vector<int> neighbors = usu[pers1];
	for (int x = 0; x < neighbors.size(); x++) {
		dfs(neighbors[x], importance + 1);
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
	list_of_people[idx] = man;

	for (auto itr = usu.begin(); itr != usu.end(); itr++) {
		clean(itr->second);
	}

	cout << endl;

	/*
	for (auto it = usu.begin(); it != usu.end(); it++) {
		cout << "Key: " << list_of_people[it->first].first << endl;
		cout << "Neighbors:" << to_string(it->second) << endl;
	}
	*/

	dfs(idx, 0);

	auto comp = [](const person& p1, const person& p2) -> bool {
		string str1 = p1.first;
		string str2 = p2.first;
		return str1.compare(str2) < 0;
	};

	sort(list_of_people.begin(), list_of_people.end(), comp);

	for (int i = 0; i < list_of_people.size(); i++) {
		cout << list_of_people[i].first << " " << (list_of_people[i].second >= 0 ? to_string(list_of_people[i].second) : "undefined") << endl;
	}

	return 0;
}