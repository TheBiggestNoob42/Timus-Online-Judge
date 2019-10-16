#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<pair<string, int>> queue;
map<string, map<string, bool>> usu;

string to_string(vector<string>& vec) {
	string str = "[";
	for (int i = 0; i < vec.size() - 1; i++) {
		str += vec[i] + ", ";
	}
	str += vec[vec.size() - 1] + "]";
	return str;
}

bool find(vector<string>& vec, string element) {
	for (int x = 0; x < vec.size(); x++) {
		if (vec[x] == element) {
			return true;
		}
	}
	return false;
}

void addEdge(string first, string second) {
	map<string, bool> ff = map[]
}

void dfs(const string& str, int importance) {
	for (int x = 0; x < queue.size(); x++) {
		if (queue[x].first == str) {
			return;
		}
	}

	queue.push_back(pair<string, int>(str, importance));

	vector<string> neighbors = usu[str];
	for (int x = 0; x < neighbors.size(); x++) {
		dfs(neighbors[x], importance + 1);
	}
}

int main() {
	int N;
	cin >> N;

	string man("Isenbaev");

	string first, second, third;
	for (int i = 0; i < N; i++) {
		cin >> first;
		cin >> second;
		cin >> third;

		addEdge(first, second);
		addEdge(first, third);
		addEdge(second, third);
	}

	cout << endl;

	for (auto it = usu.begin(); it != usu.end(); it++) {
		cout << "Key: " << it->first << endl;
		cout << "Neighbors:" << to_string(it->second) << endl;
	}

	cout << endl;
	// dfs(man, 0);


	auto comp = [](const string& str1, const string& str2) -> bool {
		return str1.compare(str2) > 0;
	};

	
	for (int x = 0; x < queue.size(); x++) {
		cout << queue[x].first << " " << queue[x].second << endl;
	}

	return 0;
}