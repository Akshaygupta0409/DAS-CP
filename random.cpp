// The code snippet defines various functions for tree traversal and manipulation. It includes functions for inorder, preorder, and postorder traversal, level order traversal, vertical order traversal, checking if a tree is symmetric, mirroring a tree, and finding the diameter of
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

void Inorder(TreeNode* root) {
  if (!root) {
    return;
  }
  // find the lenfth of this 
  Inorder(root->left);
  cout << root->val << " ";
  Inorder(root->right);
}

void Preorder(TreeNode* root) {
  if (!root) {
    return;
  }
  
  cout << root->val << " ";
  Preorder(root->left);
  Preorder(root->right);
}

void Postorder(TreeNode* root) {
  if (!root) {
    return;
  }
  
  Postorder(root->left);
  Postorder(root->right);
  cout << root->val << " ";
}

vector<int> LevelOrderTraversal(TreeNode* root) {
  vector<int> ans;

  if (!root) {
    // empty tree edge case
    return ans;
  }

  queue<pair<TreeNode*,int>> q;
  vector<TreeNode*> first_node;

  q.push({root, 0});
  while (!q.empty()) {
    TreeNode* node = q.front().first;
    int level = q.front().second;

    if ((int)first_node.size() == level) {
      // node is the first node at level
      first_node.push_back(node);
    }

    q.pop();

    ans.push_back(node->val);
    
    if (node->right) q.push({node->right, level + 1});
    if (node->left) q.push({node->left, level + 1});
  }

  return ans;
}

unordered_map<int, vector<int>> M;

void VerticalOrderTraversal(TreeNode* root, int level) {
  if (!root) {
    return;
  }

  M[level].push_back(root->val);

  VerticalOrderTraversal(root->left, level - 1);
  VerticalOrderTraversal(root->right, level + 1);
}

bool IsSymmetric(TreeNode* node1, TreeNode* node2) {
  if (!node1 && !node2) return true;
  if (!node1 || !node2) return false;
  if (node1->val != node2->val) return false;
  return IsSymmetric(node1->left, node2->right) && IsSymmetric(node1->right, node2->left);
}

bool IsSymmetric(TreeNode* root) {
  if (!root) return true;
  return IsSymmetric(root->left, root->right);
}

void Mirror(TreeNode* root) {
  if (!root) return;
  swap(root->left, root->right);
  Mirror(root->left);
  Mirror(root->right);
}


int dia = 0;

// farthest leaf node distance in root's subtree.
int solve(TreeNode* root) {
  if (!root) return 0;
  
  int d1 = solve(root->left);
  int d2 = solve(root->right);

  dia = max(dia, d1 + d2);

  return max(d1, d2) + 1;
}

int getDiameter(TreeNode* root) {
  dia = 0;
  solve(root);
  return dia;
}