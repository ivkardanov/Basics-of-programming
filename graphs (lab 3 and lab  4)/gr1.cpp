#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int maxPathSum(TreeNode* root, int& maxSum) {
    if (root == nullptr) {
        return 0;
    }

    int leftMax = max(0, maxPathSum(root->left, maxSum));
    int rightMax = max(0, maxPathSum(root->right, maxSum));

    int currentMax = root->val + leftMax + rightMax;
    maxSum = max(maxSum, currentMax);

    return root->val + max(leftMax, rightMax);
}

int main() {
    string choice;
    do {
        // Создаем дерево из примера [-10,9,20,null,null,15,7]
        TreeNode* root = new TreeNode{ -10 };
        root->left = new TreeNode{ 9 };
        root->right = new TreeNode{ 20 };
        root->right->left = new TreeNode{ 15 };
        root->right->right = new TreeNode{ 7 };

        int maxSum = INT_MIN;
        int result = maxPathSum(root, maxSum);
        cout << "Max path sum: " << result << endl;

        // Очищаем память, выделенную под дерево
        delete root->right->right;
        delete root->right->left;
        delete root->right;
        delete root->left;
        delete root;

        cout << "Run again ? (y/n): ";
        cin >> choice;
    } while (choice == "Y" || choice == "y");
    return 0;
}
