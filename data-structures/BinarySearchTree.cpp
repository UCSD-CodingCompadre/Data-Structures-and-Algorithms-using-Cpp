#include <iostream>
#include <queue>

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

                    // Else we just traverse right
                    currentNode = currentNode->right;
                }

                // Else we are traversing left
                else
                {

                    // Check if we have an empty left child
                    if(currentNode->left == nullptr) 
                    {

                        // Add the node to the left child
                        currentNode->left = new TreeNode(val);

                        // Break
                        break;
                    }

                    // Else we just traverse left
                    currentNode = currentNode->left;
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

   /*
   Print the preorder traversal of a binary search tree
   @param TreeNode* node a pointer to the current visted node
   @return void
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

    /*
    Print the inorder traversal of a binary search tree
    @param TreeNode* node a pointer to the current visted node
    @return void
    */
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

    /*
    Print the postorder traversal of a binary search tree
    @param TreeNode* node a pointer to the current visted node
    @return void
    */
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

    /*
    Print the level order traversal of a binary search tree
    @param none
    @return void
    */
    void printLevelOrder()
    {

        // Check if we have no root
        if(this->root == nullptr) return;

        // Create a queue for the TreeNodes
        std::queue<TreeNode*> MyQueue; 

        // Push the head of the Binary Search Tree
        MyQueue.push(root);

        // Loop until the queue is empty
        while(!MyQueue.empty())
        {

            // Hold the amount of nodes in the level
            int levelSize = MyQueue.size();

            // Loop until the levelSize is 0
            while(levelSize > 0)
            {

                // Hold the element from the queue
                TreeNode* MyNode = MyQueue.front();

                // Pop the element from the queue
                MyQueue.pop();

                // Check if the node has a left child
                if(MyNode->left != nullptr) MyQueue.push(MyNode->left);

                // Check if the node has a right child
                if(MyNode->right != nullptr) MyQueue.push(MyNode->right);

                // Print the node
                std::cout << MyNode->val << " ";

                // Decrement the levelSize
                levelSize--;
            }

            // Print a new line
            std::cout << std::endl;
        }
    }
};

int main()
{

    BinarySearchTree* MyBST = new BinarySearchTree();

    MyBST->add(6);
    MyBST->add(3);
    MyBST->add(1);
    MyBST->add(4);

    MyBST->printLevelOrder();
}