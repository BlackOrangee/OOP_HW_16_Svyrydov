#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int value;      // The integer value stored in the node.
	Node* right;   // Pointer to the right child node.
	Node* left;    // Pointer to the left child node.

	// Constructors
	Node();         // Default constructor.
	Node(int);      // Constructor with a given integer value.
};

// Function to insert a new node with a given value into the binary tree.
void push(Node*&, int);

// Function to display the binary tree structure.
void display(Node*, int);

// Function to search for a specific value in the binary tree and return the node.
Node* search(Node*, int);

// Function to count nodes in the binary tree that have two children.
void twoChildren(Node*, int&);

// Function to calculate the sum of all values in the binary tree.
void treeSum(Node*, int&);

// Function to calculate the depth (height) of the binary tree.
int treeDepth(Node*, int);
