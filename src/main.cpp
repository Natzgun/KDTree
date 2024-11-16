#include "KdTree.h"
#include "KdTreeRenderer.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  struct Node *root = NULL;
  KdTreeRender renderKdtree(800, 800);
  renderKdtree.render(root);

  // int points[][k] = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
  //                    {9, 1}, {2, 7},   {10, 19}};

  // int n = sizeof(points) / sizeof(points[0]);

  // for (int i = 0; i < n; i++)
  //   root = insert(root, points[i]);

  // int point1[] = {10, 19};
  // (search(root, point1)) ? cout << "Found\n" : cout << "Not Found\n";

  // int point2[] = {12, 19};
  // (search(root, point2)) ? cout << "Found\n" : cout << "Not Found\n";

  return 0;
}
