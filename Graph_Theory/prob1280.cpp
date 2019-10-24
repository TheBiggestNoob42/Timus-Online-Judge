#include <bits/stdc++.h>
#define MAX_N 1001
using namespace std;

// (node, (parent, children))
map<int, pair<vector<int>*, vector<int>*>*> dependencies;

void delete_map() {
    for (auto itr = dependencies.begin(); itr != dependencies.end(); itr++) {
        if (itr->second != NULL) {
            if (itr->second->first != NULL) {
                delete itr->second->first;
                itr->second->first = NULL;
            }
            if (itr->second->second != NULL) {
                delete itr->second->second;
                itr->second->second = NULL;
            }
            delete itr->second;
            itr->second = NULL;
        }
    }
}

void add_directed_edge(int to, int from) {
    if (dependencies[to] == NULL) {
        dependencies[to] = new pair<vector<int>*, vector<int>*>;
        dependencies[to]->first = NULL;
        dependencies[to]->second = NULL;
    }

    if (dependencies[from] == NULL) {
        dependencies[from] = new pair<vector<int>*, vector<int>*>;
        dependencies[from]->first = NULL;
        dependencies[from]->second = NULL;
    }

    if (dependencies[to]->second == NULL) {
        dependencies[to]->second = new vector<int>;
    }

    if (dependencies[from]->first == NULL) {
        dependencies[from]->first = new vector<int>;
    }


}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        dependencies[i] = NULL;
    }

    int to, from;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &from, &to);
        add_directed_edge(from, to);
    }

    int* plan = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &plan[i]);
    }

    for (auto itr = dependencies.begin(); itr != dependencies.end(); itr++) {
        printf("Class %d\n=================\n", itr->first);
        
        printf("Prerequisites: ");
        auto parent = itr->second->first;
        printf("I am here\n");
        printf("%d is size\n", parent->size());
        for (int i = 0; i < parent->size(); i++) {
            printf("I am here");
            printf("%d ", parent->operator[](i));
        }
        printf("\n");

        printf("Courses requiring it: ");
        auto children = itr->second->second;
        for (int i = 0; i < children->size(); i++) {
            printf("%d ", children->operator[](i));
        }
        printf("\n\n");
    }

    // iterate through all the graph
    // once a node has been determined to pass
    // then set it to true and remove all traces
    // of it from the array as a parent
    // it should also not have any positive value of it
    /*
    bool flag = true;
    for (int i = 0; i < N && false; i++) {
        if (has_prerequisites(plan[i])) {
            flag = false;
        } else {
            remove(plan[i]);
        }
    }*/

    delete[] plan;
    delete_map();
    return 0;
}