//
// Binary Search Tree Example
// binary_search_tree_example.h
// Description: Preorder, In-order, and Post-order traversal along
// 				with basic insert, search, destroy (complete tree)
//				and find_min functions
//
// created: 4/8/15 by j-concept
//

#include <iostream>

using namespace std;

struct node
{
	int item;
	node *left;
	node *right;
};

class btree
{
public:
	btree();
	~btree();
	void insert_item(int item);
	node *search_bst(int item);	// O(h)
	void destroy_tree();
	node *preorder();			// O(n)
	node *inorder();			// O(n)
	node *postorder();			// O(n)
	node *findmin();			// O(h)
private:
	// recursive functions hidden to the user
	void insert_item(node *leaf, int item);
	node *search_bst(node *leaf, int item);		// O(h)
	void destroy_tree(node *leaf);
	node *preorder(node *leaf);
	node *inorder(node *leaf);
	node *postorder(node *leaf);
	node *findmin(node *leaf);
	
	node *root;
};

btree::btree()
{
	root = NULL;
}

btree::~btree()
{
	destroy_tree(root);
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

void btree::destroy_tree(node *leaf)
{
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

node *btree::search_bst(node *leaf, int item)
{
	if (leaf != NULL) {
		if (item == leaf->item)
			return(leaf);
		if (item < leaf->item)
			return(search_bst(leaf->left, item));	// left recursion
		else
			return(search_bst(leaf->right, item));	// right recursion
	}
	else {
		cout << "Item not found."; 					// need a better working solution to handle this situation
		return NULL;
	}
}

node *btree::search_bst(int item)
{
	return(search_bst(root, item));
}

void btree::insert_item(int item)
{
	if(root != NULL)
    	insert_item(root, item);
  	else {
	    if ( (root = new(nothrow)node) == NULL)	// check if dynamic memory was created (complete)
	    	cerr << "root node not created";
	    else {
	    	root->item = item;
		    root->left = NULL;
		    root->right = NULL;
	    }
  	}
}

void btree::insert_item(node *leaf, int item)
{
	if (item < leaf->item) {
		if (leaf->left != NULL)
			// if there is another child below, recursion begins until the last grandchild is reached
			insert_item(leaf->left, item);	// left recursion
		else {
			leaf->left = new(nothrow)node; 	// check if memory was allocated not complete (got lazy)
			leaf->left->item = item;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (item > leaf->item) {
		if (leaf->right != NULL)
			insert_item(leaf->right, item);	// right recursion
		else {
			leaf->right = new(nothrow)node; // check if memory was allocated not complete (got lazy)
			leaf->right->item = item;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

node *btree::preorder()
{
	return(preorder(root));
}

node *btree::preorder(node *leaf)
{
	if (leaf != NULL) {
		cout << leaf->item << " ";
		preorder(leaf->left);
		preorder(leaf->right);
	}

	return(leaf);
}

node *btree::inorder()
{
	return(inorder(root));
}

node *btree::inorder(node *leaf)
{
	if (leaf != NULL) {
		inorder(leaf->left);
		cout << leaf->item << " ";
		inorder(leaf->right);
	}

	return(leaf);
}

node *btree::postorder()
{
	return(postorder(root));
}

node *btree::postorder(node *leaf)
{
	if (leaf != NULL) {
		postorder(leaf->left);
		postorder(leaf->right);
		cout << leaf->item << " ";
	}

	return(leaf);
}

node *btree::findmin(node *leaf)
{
	// temp pointer used to store location where min is pointed
	node *temp;
	if (leaf == NULL)
		return NULL;

	temp = leaf;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return(temp);
}

node *btree::findmin()
{
	return(findmin(root));
}