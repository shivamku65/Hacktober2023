#include <iostream>
// C++ code to implement DFS approach
#include <vector>
#include<algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		dfs(root, 0, result); // Perform modified preorder traversal
		for (int i = 1; i < result.size(); i += 2) { // Reverse the order of nodes at odd levels
			reverse(result[i].begin(), result[i].end());
		}
		return result;
	}

private:
	void dfs(TreeNode* root, int level, vector<vector<int>>& result) {
		if (!root) return;
		if (level >= result.size()) { // If current level not yet stored, create new level
			result.push_back(vector<int>());
		}
		result[level].push_back(root->val); // Store current node in its level
		dfs(root->left, level + 1, result); // Recursively traverse left subtree
		dfs(root->right, level + 1, result); // Recursively traverse right subtree
	}
};

// Driver code
int main() {
		/* Constructed binary tree is
			1
			/ \
			2	 3
		/ \ / \
		4 5 6 7
	*/
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	Solution sol;
	vector<vector<int>> result = sol.zigzagLevelOrder(root);

	// Print zigzag level order traversal
	cout<<"zig-zag traversal of binary tree is:"<<endl;
	for (int i = 0; i < result.size(); i++) {
	
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
	}
cout << endl;
	return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
