#include "BinaryTree.h"
#include <string>
#include <iostream>

void main()
{
	BinaryTree<int,std::string> binary;

	binary.add(5, "elem1");
	binary.add(1, "elem2");
	binary.add(3, "elem3");
	binary.add(16,"elem4");
	binary.add(6, "elem5");
	binary.add(9, "elem6");
	binary.add(24,"elem7");
	binary.add(5, "elem8");
	binary.add(4, "elem9");
	binary.add(2, "elem10");
	binary.add(10,"elem11");

	binary.remove(100);
	binary.remove(5);
	binary.remove(9);
	binary.remove(300);

	binary.show();

	std::cin.get();

	return;

}