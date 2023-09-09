#include "Node.h"

// Node constructor with no initial value.
Node::Node()
{
	value = 0;         // Initialize the node's value to 0.
	right = nullptr;   // Initialize the right child pointer to nullptr.
	left = nullptr;    // Initialize the left child pointer to nullptr.
}

// Node constructor with an initial value.
Node::Node(int value)
{
	this->value = value;  // Initialize the node's value with the provided value.
	right = nullptr;     // Initialize the right child pointer to nullptr.
	left = nullptr;      // Initialize the left child pointer to nullptr.
}

// Function to insert a new node with a given value into the binary tree.
void push(Node*& root, int value)
{
	if (root == nullptr)
	{
		root = new Node(value);  // If the current node is nullptr, create a new node with the given value.
		return;
	}

	if (root->value > value)
	{
		push(root->left, value);  // If the value is smaller than the current node's value, insert it into the left subtree.
	}
	else
	{
		push(root->right, value); // If the value is greater or equal, insert it into the right subtree.
	}
}

#define Count 10

// Function to display the binary tree with proper formatting.
void display(Node* root, int space)
{
	if (root == nullptr) {
		return;  // If the current node is nullptr, exit the function.
	}

	space += Count;  // Increase the horizontal space for proper formatting.

	display(root->right, space);  // Recursively display the right subtree.

	cout << endl;  // Move to the next line for the current node.

	for (int i = Count; i < space; i++) {
		cout << " ";  // Print spaces for proper indentation.
	}
	cout << root->value;  // Print the value of the current node.

	display(root->left, space);  // Recursively display the left subtree.
}

// Function to search for a node with a specific value in the binary tree.
Node* search(Node* root, int value)
{
	// If the current node is nullptr, or the value is found, return the current node.
	if (root == nullptr || root->value == value)
	{
		return root;
	}

	Node* left = nullptr;
	Node* right = nullptr;

	// Determine whether to search in the left or right subtree based on the comparison with the value.
	if (root->value > value)
	{
		left = search(root->left, value);  // Recursively search in the left subtree.
	}
	else
	{
		right = search(root->right, value);  // Recursively search in the right subtree.
	}

	// If the node is found in the right subtree, return it. Otherwise, return the node found in the left subtree.
	if (right != nullptr)
	{
		return right;
	}
	else if (left != nullptr)
	{
		return left;
	}

	// If the value is not found, return nullptr.
	return nullptr;
}

// Function to count nodes in the binary tree that have two children.
void twoChildren(Node* root, int& count)
{
	// If the current node is nullptr, return.
	if (root == nullptr)
	{
		return;
	}

	// Check if the current node has both left and right children.
	if (root->left != nullptr && root->right != nullptr)
	{
		count++; // Increment the count since this node has two children.
	}

	// Recursively call the function for the left and right subtrees.
	twoChildren(root->left, count);
	twoChildren(root->right, count);
}

// Function to calculate the sum of all values in the binary tree.
void treeSum(Node* root, int& sum)
{
	// If the current node is nullptr, return.
	if (root == nullptr)
	{
		return;
	}

	// Add the value of the current node to the running sum.
	sum += root->value;

	// Recursively call the function for the left and right subtrees.
	treeSum(root->left, sum);
	treeSum(root->right, sum);
}

// Function to calculate the depth (height) of the binary tree.
int treeDepth(Node* root, int depth)
{
	// If the current node is nullptr, return the current depth.
	if (root == nullptr)
	{
		return depth;
	}

	// Increment the depth for the current level.
	depth++;

	// Recursively calculate the depth of the left and right subtrees.
	int depth_left = treeDepth(root->left, depth);
	int depth_right = treeDepth(root->right, depth);

	// Compare the depths of the left and right subtrees and choose the maximum.
	if (depth_left > depth_right)
	{
		depth = depth_left;
	}
	else
	{
		depth = depth_right;
	}

	// Return the maximum depth.
	return depth;
}
