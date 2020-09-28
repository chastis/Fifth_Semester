#include <iostream>
#include <string>
#include "BPlus_Tree.h"
#include "Sortings.h"

using namespace std;

int main()
{
	Sortings<int>::getCountSort();
	BPlusTree<string, string> tree(1);
	string one, two, three;
	one = "hello";
	two = "bye";
	tree.insert(one, "1");
	tree.insert(two, "2");
	three = "one";
	tree.insert(three, "3");
	tree.showLeaves();


	cin.get();
	return 0;
}