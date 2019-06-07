#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBst(const vector<Node>& tree, int ind, int min, int max) {
	bool left =1, right = 1;
	if (tree[ind].key <=min || tree[ind].key >=max)
		return 0;
	if (tree[ind].left != -1)
		left = IsBst(tree, tree[ind].left, min, tree[ind].key);
	if (tree[ind].right != -1)
		right = IsBst(tree, tree[ind].right, tree[ind].key, max);
	return left && right;
	//return IsBst(tree, tree[ind].left, min, tree[ind].key) && IsBst(tree, tree[ind].right, tree[ind].key, max);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  int min = -2147483647 - 1;
  int max = 2147483647;
  if(!tree.empty())
	  if (!IsBst(tree, 0, min, max))
		  return false;
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  //for (int i = 0; i < tree.size(); i++)
	//  cout << tree[i].key << ", " << tree[i].left << ", " << tree[i].right << endl;
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  //system("pause");
  return 0;
}
