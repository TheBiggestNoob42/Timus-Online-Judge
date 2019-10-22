#include <bits/stdc++.h>
using namespace std;

int* parliament;

struct tree {
    tree* left;
    tree* right;
    int val;
};

tree* insert(tree* node, int value) {
	if (node == NULL) {
		node = new tree;
		node->val = value;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	if (value < node->val) {
		node->left = insert(node->left, value);
		return node;
	} else {
		node->right = insert(node->right, value);
		return node;
	}
}

void print_tree(tree* node) {
	if (node == NULL) {
		return;
	}

	print_tree(node->right);
	print_tree(node->left);
	printf("%d\n", node->val);
}

void delete_tree(tree* root) {
	if (root == NULL) {
		return;
	}
	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
	root = NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    parliament = new int[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &parliament[i]);
    }

	tree* root = NULL;
	for (int i = N - 1; i >= 0; i--) {
		root = insert(root, parliament[i]);
	}

	print_tree(root);

    delete[] parliament;
	delete_tree(root);
    return 0;
}