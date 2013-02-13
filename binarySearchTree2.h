#pragma once
#include <stdio.h>
struct TreeNode
{
	int value;
	int value2;
	TreeNode* left;
	TreeNode* right;
};

struct Tree
{
	TreeNode* root;
};

Tree* createTree();

bool exsistsInTree(Tree* tree,int value);

TreeNode* searchInTree(Tree* &tree,int value);

void addToTree(Tree* &tree,int value);

void removeFromTree(Tree* tree,int value);

void treeInorder(Tree* &tree);

void treeSpecialInorder(Tree* &tree);

void deleteTree(Tree* &tree);
