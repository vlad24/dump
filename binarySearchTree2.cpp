#include "binarySearchTree2.h"
#include <cstdio>
#include <stdio.h>

Tree* createTree()
{
	Tree* tree = new Tree;
	tree->root = NULL;
	return tree;
}

bool isEmpty(Tree* tree)
{
	return (tree->root == NULL);
}

bool exsistsInSubtree(TreeNode* node,int value)
{
	if (node == NULL)
		return false;
	if (node -> value == value )
		return true;
	if (value > node->value)
		return exsistsInSubtree(node->right,value);
	else
		return exsistsInSubtree(node->left,value);
}

bool exsistsInTree(Tree* tree,int value)
{
		return exsistsInSubtree(tree->root,value);
}

TreeNode* searchInSubtree(TreeNode* &node,int value)
{
	if (node == NULL)
		return NULL;
	if (node -> value == value )
		return node;
	if (value > node->value)
		return searchInSubtree(node->right,value);
	else
		return searchInSubtree(node->left,value);
}

TreeNode* searchInTree(Tree* &tree,int value)
{
	return searchInSubtree(tree->root,value);
}

void createNode(TreeNode* &node,int value)
{
	node = new TreeNode;
	node->value = value;
	node->value2 = 1;
	node->left = NULL;
	node->right = NULL;
}

void addToSubtree(TreeNode* &node,int value)
{
	if (node == NULL)
		return createNode(node,value);
	else if (node -> value == value)
	{
		node->value2++;
		return;
	}
	else if (value > node->value)
			return addToSubtree(node->right,value);
		else
			return addToSubtree(node->left,value);		
}

void addToTree(Tree* &tree,int value)
{
	return addToSubtree(tree->root,value);	
}

bool hasLeftChild(TreeNode* &node)
{
	return (node->left != NULL);
}

bool hasRightChild(TreeNode* &node)
{
	return (node->right != NULL);
}

bool hasOneChild(TreeNode* &node)
{
	return ((hasLeftChild(node)) && !(hasRightChild(node))) || ( !(hasLeftChild(node)) && (hasRightChild(node)) );
}

bool isLeaf(TreeNode* &node)
{
	return (!hasLeftChild(node) && !hasRightChild(node)); 
}

int popMostLeftValue(TreeNode* &node)
{
	int k = 0 ;
	if (node->left != NULL)
		return popMostLeftValue(node->left);
	else
	{
		 k = node->value;
		 delete node;
		 node = NULL;
		 return k ;
	}
}

void removeFromSubTree(TreeNode* &node,int value)
{
	if (node == NULL)
		printf("no such an element.");
	else if (node -> value == value )
		{
			if((isLeaf(node))||(hasOneChild(node)))
			{
				if (isLeaf(node))
				{
					delete node;
					node = NULL;
					return;
				}
				if (hasOneChild(node))
				{
					if(hasLeftChild(node))
					{
						TreeNode* tmp = node->left;
						delete node;
						node = tmp;
					}
					else
					{
						TreeNode* tmp = node->right;
						delete node;
						node = tmp;
					}
				}
			}
			else
			{
				int tmp = popMostLeftValue(node->right);
				node->value = tmp;
			}

		}
		else if (value > node->value)
				return removeFromSubTree(node->right,value);
			else
				return removeFromSubTree(node->left,value);
		
	
}

void removeFromTree(Tree* tree,int value)
{
	removeFromSubTree(tree->root,value);
}

void inorder(TreeNode* &node)
{
	if (node->left != NULL)
	{
		inorder(node->left);
		printf(" %d(%d)",node->value,node->value2);
		if( node->right != NULL)
			inorder(node->right);
	}
	else
	{
		printf(" %d(%d)",node->value,node->value2);
		if( node->right != NULL)
			inorder(node->right);
	}
	return;
}

void treeInorder(Tree* &tree)
{
	if (!(isEmpty(tree)) )
		inorder(tree->root);
}

void specialInorder(TreeNode* &node)
{
	if (node->right != NULL)
	{
		specialInorder(node->right);
		printf(" %d",node->value);
		if( node->left != NULL)
			specialInorder(node->left);
	}
	else
	{
		printf("%d",node->value);
		if( node->left != NULL)
			specialInorder(node->left);
	}
	return;
}

void treeSpecialInorder(Tree* &tree)
{
	if (!(isEmpty(tree)) )
	specialInorder(tree->root);
}

void deleteSubTree(TreeNode* &node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		deleteSubTree(node->left);
		deleteSubTree(node->right);
		delete node;
	}
}

void deleteTree(Tree* &tree)
{
	deleteSubTree(tree->root);
	delete tree;
}