#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* Lnode;
	struct Node* Rnode;
}Node;

typedef struct Tree {
	Node* root;
	Node* cur;
	Node* parent;
	Node* child;
}Tree;

int Search(Tree* tree, int data) {
	tree->cur = tree->root;
	tree->parent = NULL;

	while (1) {
		if (tree->cur->key == data) {
			return 1;
		}
		else if (tree->cur->key < data) {
			tree->parent = tree->cur;
			if (tree->cur->Rnode == NULL) {
				return 0;
			}
			tree->cur = tree->cur->Rnode;
		}
		else {
			tree->parent = tree->cur;
			if (tree->cur->Lnode == NULL) {
				return 0;
			}
			tree->cur = tree->cur->Lnode;
		}
	}
}

void Insert(Tree* tree, int data) {
	Node* newNode = malloc(sizeof(Node));
	newNode->key = data;
	newNode->Lnode = NULL;
	newNode->Rnode = NULL;

	if (tree->root == NULL) {
		tree->root = newNode;
		return;
	}

	if (Search(tree, data)) {
		puts("중복!!!");
		return;
	}
	else {
		if (tree->parent->key < data) {
			tree->parent->Rnode = newNode;
		}
		else {
			tree->parent->Lnode = newNode;
		}
	}
}

void Display(Node* root) {
	if (root != NULL) {
		Display(root->Lnode);
		printf("%d -> ", root->key);
		Display(root->Rnode);
	}
}

void Ch_No(Tree* tree) {
	if(tree->parent->Lnode == tree->cur) tree->parent->Lnode = NULL;
	else tree->parent->Rnode = NULL;
	free(tree->cur);
}

void Ch_One(Tree* tree) {
	if (tree->cur->Lnode == NULL) tree->child = tree->cur->Rnode;
	else tree->child = tree->cur->Lnode;

	if (tree->cur == tree->parent->Lnode) tree->parent->Lnode = tree->child;
	else tree->parent->Rnode = tree->child;

	free(tree->cur);
}

void Ch_Two(Tree* tree) {
	Node* Suc = tree->cur->Rnode; 
	Node* pSuc = tree->cur;

	while (Suc->Lnode != NULL) {
		pSuc = Suc;
		Suc = Suc->Lnode;
	}

	tree->cur->key = Suc->key;
	if (pSuc->Lnode == Suc)
		pSuc->Lnode = Suc->Rnode;
	else
		pSuc->Rnode = Suc->Rnode;
	tree->cur = Suc;

	free(tree->cur);
}

void Delete(Tree* tree, int data) {
	//삭제하고자하는 값이 없는 경우
	if (!Search(tree, data)) {
		puts("삭제할 데이터 없음.");
		return;
	}

	//삭제하고자 할 노드의 자식이 없는 경우
	if (tree->cur->Lnode == NULL && tree->cur->Rnode == NULL) {
		Ch_No(tree);
	}

	//삭제하고자 할 노드의 자식이 하나만 있는 경우
	else if (tree->cur->Lnode == NULL || tree->cur->Rnode == NULL) {
		Ch_One(tree);
	}

	//삭제하고자 할 노드의 자식이 둘인 경우
	else{
		Ch_Two(tree);
	}
}

void main() {
	Tree tree;
	tree.root = NULL;
	tree.cur = NULL;
	tree.parent = NULL;
	tree.child = NULL;

	Insert(&tree, 50);
	Insert(&tree, 35);
	Insert(&tree, 70);
	Insert(&tree, 6);
	Insert(&tree, 40);
	Insert(&tree, 15);
	Insert(&tree, 45);
	Insert(&tree, 48);


	Display(tree.root);
	puts("");

	Delete(&tree, 15);

	Display(tree.root);
}