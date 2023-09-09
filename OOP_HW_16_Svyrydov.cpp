// Create a binary tree and implement the following functions for tree manipulation:
// 
// - Create a new node
// - Add a node to the tree
// - Display all nodes
// - Create a binary search tree
//
// 
// Determine whether an element with a data field value of "k" 
// is present in the binary tree / binary search tree.
// 
// Determine the number of elements in a binary tree / binary search tree 
// that have both left and right children.
// 
// Determine the sum of all elements in a binary tree / binary search tree.
// 
// Determine the maximum depth of a binary tree / binary search tree.
//

#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
    // Create an empty root node.
    Node* root = nullptr;

    // Insert values into the binary tree.
    push(root, 50);
    push(root, 30);
    push(root, 70);
    push(root, 20);
    push(root, 40);
    push(root, 60);
    push(root, 80);

    // Display the binary tree structure.
    cout << "Binary Tree Structure:" << endl;
    display(root, 10);

    // Search for a value in the binary tree.
    int searchValue = 30;
    Node* searchResult = search(root, searchValue);

    if (searchResult != nullptr)
    {
        cout << endl << "Found " << searchValue << " in the tree." << endl;
    }
    else
    {
        cout << endl << searchValue << " not found in the tree." << endl;
    }

    // Count nodes with two children in the binary tree.
    int count = 0;
    twoChildren(root, count);
    cout << "\nNodes with two children: " << count << endl;

    // Calculate the sum of all values in the binary tree.
    int sum = 0;
    treeSum(root, sum);
    cout << "\nSum of all values in the tree: " << sum << endl;

    // Calculate the depth (height) of the binary tree.
    int depth = 0;
    int treeDepthResult = treeDepth(root, depth);
    cout << "\nDepth (Height) of the tree: " << treeDepthResult << endl;
}