#include "KdTree.h"

struct Node *newNode(int arr[]) {
  struct Node *temp = new Node;

  for (int i = 0; i < k; i++)
    temp->point[i] = arr[i];

  temp->left = temp->right = NULL;
  return temp;
}

Node *insertRec(Node *root, int point[], unsigned depth) {
  // Tree is empty?
  if (root == NULL)
    return newNode(point);

  // Calculate current dimension (cd) of comparison
  unsigned cd = depth % k;

  // Compare the new point with root on current dimension 'cd'
  // and decide the left or right subtree
  if (point[cd] < (root->point[cd]))
    root->left = insertRec(root->left, point, depth + 1);
  else
    root->right = insertRec(root->right, point, depth + 1);

  return root;
}

Node *insert(Node *root, int point[]) { return insertRec(root, point, 0); }

bool arePointsSame(int point1[], int point2[]) {
  // Compare individual pointinate values
  for (int i = 0; i < k; ++i)
    if (point1[i] != point2[i])
      return false;

  return true;
}

bool searchRec(Node *root, int point[], unsigned depth) {
  // Base cases
  if (root == NULL)
    return false;
  if (arePointsSame(root->point, point))
    return true;

  // Current dimension is computed using current depth and total
  // dimensions (k)
  unsigned cd = depth % k;

  // Compare point with root with respect to cd (Current dimension)
  if (point[cd] < root->point[cd])
    return searchRec(root->left, point, depth + 1);

  return searchRec(root->right, point, depth + 1);
}

bool search(Node *root, int point[]) {
  // Pass current depth as 0
  return searchRec(root, point, 0);
}
