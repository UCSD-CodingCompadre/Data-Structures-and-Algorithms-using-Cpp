#include <iostream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct BinarySearchTree
{
    
    TreeNode* root;
    int size = 0;
    BinarySearchTree(): root(nullptr) {}
    BinarySearchTree(TreeNode* root): root(root) {}

    /*
    Add a tree node to the binary search tree
    @param int val the val of the tree node to be inserted
    @return bool true if the insertion was sucessful 
    */
    bool add(int val)
    {

        // Check if the root is a nullptr
        if(root == nullptr)
        {

            // Set the new root
            root = new TreeNode(val);
        }

        // Else we have a root
        else
        {

            // Hold the current node
            TreeNode* currentNode = root;

            // Loop until we can add the node
            while(true)
            {

                // Check if we have a duplicate
                if(currentNode->val == val) return false;

                // Check if we move right
                else if(currentNode->val < val)
                {

                    // Check if we can add the node
                    if(currentNode->right == nullptr)
                    {

                        // Add the node
                        currentNode->right = new TreeNode(val);

                        // Break from the loop
                        break;
                    }

                    // Else iterate to the right
                    else currentNode = currentNode->right;
                }

                // Else we move to the right
                else
                {

                    // Check if we can add the node
                    if(currentNode->left == nullptr)
                    {

                        // Add the node
                        currentNode->left = new TreeNode(val);

                        // Break from the loop
                        break;
                    }

                    // Else iterate to the left
                    else currentNode = currentNode->left;
                }
            }
        }

        // Increment the tree size
        size++;

        // Return true
        return true;
    }
};