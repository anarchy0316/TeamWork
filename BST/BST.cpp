#include "stdafx.h"

#include <iostream>
using namespace std;
//It's new version
struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;

};
BstNode* root = NULL;
void Insert(BstNode** tree, int data){

	

	if (*tree == NULL){
		(*tree) = new BstNode();
		(*tree)->data = data;
		(*tree)->left = (*tree)->right = NULL;
		
	}
	else if (data < (*tree)->data){

		Insert(&(*tree)->left, data);
	}
	else {
		Insert(&(*tree)->right, data);

	}


}
void print_tree(BstNode* tree){
	if (tree == NULL){

	}
	else{
		print_tree(tree->left);
		cout << tree->data << endl;
		print_tree(tree->right);

	}
}
void delete_tree(BstNode* tree){
	if (tree == NULL){

	}
	else{
		delete_tree(tree->left);

		delete_tree(tree->right);
		delete tree;


	}
}
int main(){

	Insert(&root, 15);
	Insert(&root, 12);
	Insert(&root, 37);
	Insert(&root, 56);
	Insert(&root, 64);
	Insert(&root, 3);
	Insert(&root, 43);
	Insert(&root, 17);
	Insert(&root, 27);

	print_tree(root);

	delete_tree(root);
	cout << "delete completed";
	root = NULL;
	Insert(&root, 27);
	print_tree(root);
}
