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

                // Else check if we traversing right
                else if(val > currentNode->val)
                {

                    // Check if we have an empty right child
                    if(currentNode->right == nullptr)
                    {

                        // Add the node a new right child
                        currentNode->right = new TreeNode(val);

                        // Break
                        break;
                    }

                    // Else check if are replacing this subtree node
                    else if(val < currentNode->right->val)
                    {

                        // Hold the subtree
                        TreeNode* rightSubtree = currentNode->right;

                        // Add the new node
                        currentNode->right = new TreeNode(val);

                        // Add the subtree
                        currentNode->right->right = rightSubtree;

                        // Break
                        break;
                    }

                    // Else we just traverse right
                    else currentNode = currentNode->right;
                }

                // Else we are traversing left
                else
                {

                    // Check if we have an empty left child
                    if(currentNode->left)
                    {

                        // Add the node to the left child
                        currentNode->left = new TreeNode(val);

                        // Break
                        break;
                    }

                    // Else check if are replacing this subtree node
                    else if(val > currentNode->left->val)
                    {

                        // Hold the subtree
                        TreeNode* leftSubtree = currentNode->left;

                        // Add the new node
                        currentNode->left = new TreeNode(val);

                        // Add the subtree
                        currentNode->left->left = leftSubtree;

                        // Break
                        break;
                    }

                    // Else we just traverse left
                    else currentNode = currentNode->left;
                }
            }
        }

        // Increment the tree size
        size++;

        // Return true
        return true;
    }

    /*
    Shortcut for traversals
    Pre VLR
    In LVR
    Post LRV
    */

   void printPreOrder(TreeNode* node)
   {

        // Check if node is nullptr
        if(node == nullptr) return;

        // Print visited node
        std::cout << node->val << " ";

        // Traverse left
        printPreOrder(node->left);

        // Traverse right
        printPreOrder(node->right);
   }

   void printInOrder(TreeNode* node)
   {

        // Check if node is nullptr
        if(node == nullptr) return;

        // Traverse left
        printInOrder(node->left);

        // Print visited node
        std::cout << node->val << " ";

        // Traverse right
        printInOrder(node->right);
   }

   void printPostOrder(TreeNode* node)
   {

        // Check if node is nullptr
        if(node == nullptr) return;

        //Traverse left
        printPostOrder(node->left);

        // Traverse right
        printPostOrder(node->right);

        // Print visted node
        std::cout << node->val << " ";
   }
};

int main()
{

    BinarySearchTree* MyBST = new BinarySearchTree();

    MyBST->add(6);
    MyBST->add(3);
    MyBST->add(1);
    MyBST->add(2);

    MyBST->printPreOrder(MyBST->root);
}