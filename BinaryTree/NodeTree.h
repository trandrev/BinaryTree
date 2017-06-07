#pragma once


template<class T,class VAL>
struct NodeTree
{
	NodeTree *left, *right;
	T data;
	VAL valdata;
	int heightNode;
	NodeTree(T key,VAL val) {
		
		data = key;
		valdata = val;
		left = right = 0;
		heightNode = 1;
	}
};