#pragma once
#include "NodeTree.h"
#include <iostream>
#include <vector>
#include <string>

template <class T,class VAL>
class BinaryTree
{
	NodeTree<T,VAL> *root;
	std::vector<std::string> str;
	NodeTree<T, VAL>* insert(NodeTree<T, VAL>* node, T elem, VAL val);
	NodeTree<T, VAL>* remove(NodeTree<T, VAL>* node, T elem);
	void showNode(NodeTree<T, VAL>* node);


	NodeTree<T, VAL>* findmin(NodeTree<T, VAL>* p)
	{
		return p->left ? findmin(p->left) : p;
	}

	NodeTree<T, VAL>* removemin(NodeTree<T, VAL>* p)
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}
	unsigned char height(NodeTree<T, VAL>* p)
	{
		return p!= nullptr ? p->heightNode : 0;
	}

	int bfactor(NodeTree<T, VAL>*& p)
	{
		return height(p->right) - height(p->left);
	}

	void fixHeight(NodeTree<T, VAL>*& p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->heightNode = (hl > hr ? hl : hr) + 1;
	}

	NodeTree<T, VAL>* rotateRight(NodeTree<T, VAL>*& p)
	{
		NodeTree<T, VAL>* q = p->left;
		p->left = q->right;
		q->right = p;
		fixHeight(p);
		fixHeight(q);
		return q;
	}
	NodeTree<T, VAL>* rotateLeft(NodeTree<T, VAL>*& q)
	{
		NodeTree<T, VAL>* p = q->right;
		q->right = p->left;
		p->left = q;
		fixHeight(q);
		fixHeight(p);
		return p;
	}
	NodeTree<T, VAL>* balance(NodeTree<T, VAL>* p)
	{
		fixHeight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateRight(p->right);
			return rotateLeft(p);
		}
		if(bfactor(p) == -1)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateLeft(p->left);
			return rotateRight(p);
		}
		return p;
	}
	
public:
	BinaryTree();
	~BinaryTree();

	void add(T elem,VAL val);
	void remove(T elem);
	void show();

	unsigned char height()
	{
		return height(root);
	}

};

template<class T,class VAL>
NodeTree<T, VAL> * BinaryTree<T, VAL>::insert(NodeTree<T, VAL>* node, T elem, VAL val)
{
	if (elem == 3746)
		elem = elem;
	if (node == nullptr)
	    return new NodeTree<T, VAL>(elem,val);
	 
	if (elem <= node->data)
        node->left = insert(node->left, elem,val);
	else
	    node->right = insert(node->right, elem,val);
	return balance(node);

}

template<class T,class VAL>
inline NodeTree<T, VAL>* BinaryTree<T, VAL>::remove(NodeTree<T, VAL>* node, T elem)
{
	if (node == nullptr)
		return nullptr;
	if (elem < node->data)
		node->left = remove( node->left, elem);
	else if(elem > node->data)
		node->right = remove( node->right, elem);
	else
	{
		NodeTree<T, VAL>* q = node->left;
		NodeTree<T, VAL>* r = node->right;
		delete node;
		if (!r) return q;
		NodeTree<T, VAL>* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}

	return balance(node);
}

 template<class T,class VAL>
void BinaryTree<T, VAL>::showNode(NodeTree<T, VAL>* node)
 {
	
	 if (node != nullptr)
	 {
		 showNode(node->left);
		 std::cout << node->valdata << " < ";
		 showNode(node->right);
	 }
 }

template<class T, class VAL>
BinaryTree<T, VAL>::BinaryTree()
{
	root = nullptr;
}

template<class T, class VAL>
BinaryTree<T, VAL>::~BinaryTree()
{
}

template<class T,class VAL>
void BinaryTree<T, VAL>::add(T elem, VAL val)
{
	root = insert( root, elem,val);
}
template<class T, class VAL>
void BinaryTree<T, VAL>::remove(T elem)
{
	root = remove(root, elem );
}

template<class T, class VAL>
void BinaryTree<T, VAL>::show()
{
	showNode(root);
	}
