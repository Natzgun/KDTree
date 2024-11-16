#ifndef KDTREE_H
#define KDTREE_H

// A C++ program to demonstrate operations of KD tree
// This implementation is based from GeeksForGeeks but not 100%
#include <bits/stdc++.h>
using namespace std;

const int k = 2;

// A structure to represent node of kd tree
struct Node {
  int point[k]; // To store k dimensional point
  Node *left, *right;
};

// A method to create a node of K D tree
struct Node *newNode(int arr[]);

// Inserts a new node and returns root of modified tree
// The parameter depth is used to decide axis of comparison
Node *insertRec(Node *root, int point[], unsigned depth);

// Function to insert a new point with given point in
// KD Tree and return new root. It mainly uses above recursive
// function "insertRec()"
Node *insert(Node *root, int point[]);

// A utility method to determine if two Points are same
// in K Dimensional space
bool arePointsSame(int point1[], int point2[]);

// Searches a Point represented by "point[]" in the K D tree.
// The parameter depth is used to determine current axis.
bool searchRec(Node *root, int point[], unsigned depth);

// Searches a Point in the K D tree. It mainly uses
// searchRec()
bool search(Node *root, int point[]);

#endif // KDTREE_H
