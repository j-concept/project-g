//
// Binary Search Tree Example
// binary_search_tree_example.cpp
// Description: Preorder, In-order, and Post-order traversal along
// 				with basic insert, search, destroy (complete tree)
//				and find_min functions
//
// created: 4/8/15 by j-concept
//


#include <iostream>
#include <"binary_search_tree_example.h">

using namespace std;


int main()
{
	// create a binary tree object and initialize it with some values
	btree bst;

	// insert a few items into the tree
	bst.insert_item(7);
	bst.insert_item(1);
	bst.insert_item(0);
	bst.insert_item(3);
	bst.insert_item(2);
	bst.insert_item(5);
	bst.insert_item(4);
	bst.insert_item(6);
	bst.insert_item(9);
	bst.insert_item(8);
	bst.insert_item(10);

	// search for the value of "2" within the tree
	cout << "You searched for the value of: " << (bst.search_bst(100))->item << '\n';

	// test the 3 basic types of binary tree traversal
	cout << "preorder: ";
	bst.preorder();
	cout << '\n';

	cout << "inorder: ";
	bst.inorder();
	cout << '\n';

	cout << "postorder: ";
	bst.postorder();
	cout << '\n';

	cout << "the minimum of the binary tree is: " << (bst.findmin())->item << '\n';

	return 0;
}