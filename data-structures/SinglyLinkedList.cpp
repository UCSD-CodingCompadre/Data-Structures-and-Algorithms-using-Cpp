#include <iostream>

/*
This is SinglyLinkedListNode that points to the next
node in the SinglyLinkedList or null if it is the tail. It contains data 
in this case it is an int.
*/
struct SinglyLinkedListNode
{

    int val;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

/*
This is SinglyLinkedList that is a collection of Nodes that point to the next.
It has a start and end point known as the head and tail respectivly. 
*/
struct SinglyLinkedList
{
    int size;
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    /*
    Default constructor of the SinglyLinkedList
    */
    SinglyLinkedList()
    {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    /*
    Retrieve the value of a linked list node at the given index
    @param int index the index of the node 
    @return int the value of the node
    */
    int get(int index) 
    {

       // Check if we have a head
       if(head == nullptr) return -1;

       // Check if the index is valid
       if(index >= size || index < 0) return -1; 

       // Check if the index is the head node
       if(index == 0)
       {
            
            // Return the head value
            return head->val;
       }

       // Check if the index is the tail node
       if(index == size-1)
       {
            
            // Return the tail value
            return tail->val;
       }

       // Hold the current node
       SinglyLinkedListNode* currentNode = head;

       // Hold current index
       int currentIndex = 0;
       
       // Loop until we reach the index
       while(currentIndex != index)
       {
        
            // Assign the next node
            currentNode = currentNode->next;

            // Increment current index
            currentIndex++;
       }

       // Return the val
       return currentNode->val;
    }
    
    /*
    Add a node to the head of the SinglyLinkedList
    @param int val the value of the new node to add
    @return void
    */
    void addAtHead(int val) 
    {

        // Return if we have a duplicate
        if(find(val)) return;

        // Create new SinglyLinkedListNode
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(val);

        // Check if we have no head 
        if(head == nullptr)
        {
            
            // Set the new node as head and tail
            head = newNode;
            tail = newNode;
        }

        // Else we have a head
        else
        {

            // Set the next ptr for the new node
            newNode->next = head;

            // Set the new head
            head = newNode;
        }

        // Increment the size 
        size++;
    }
    
    /*
    Add at the tail of the SinglyLinkedList
    @param int val the value of the new node to add
    @return void
    */
    void addAtTail(int val) 
    {
        
        // Return if we have a duplicate
        if(find(val)) return;

        // Create new SinglyLinkedListNode
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(val);

        // Check if we have no tail
        if(tail == nullptr)
        {

            // Set the new node as head and tail
            head = newNode;
            tail = newNode;            
        }

        // Else we have a tail
        else
        {

            // Set the next ptr for the new node
            tail->next = newNode;

            // Set the new tail
            tail = newNode;
        }
    }
    
    /*
    Add a node at the index of the SinglyLinkedList
    @param int index the index to add the new node at
    int val the value of the new node to add
    @return void
    */
    void addAtIndex(int index, int val) 
    {

        // Return if we have a duplicate
        if(find(val)) return;

        // Check if the index is valid
        if(index > size || index < 0) return;

        // Check if the node is being added to the head
        if(index == 0) addAtHead(val);

        // Check if the node is being added to the tail
        if(index == size) addAtTail(val);

        // Create new SinglyLinkedListNode
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(val);

        // Hold the current node
        SinglyLinkedListNode* currentNode = head;

        // Hold the index
        int currentIndex = 0;

        // Loop through the nodes
        while(currentNode != nullptr)
        {

            // Check if we have the correct index
            if(currentIndex == index - 1)
            {
                
                // Connect the new node using the current node's next node
                newNode->next =  currentNode->next;

                // Add the new node
                currentNode->next = newNode;

                // Increment current index
                currentIndex++;
            }
        }

        // Increment the size
        size++;
    }
    
    /*
    Delete a node in the SinglyLinkedList at the passed index 
    @param int index the index to remove the node from
    @return void 
    */
    void deleteAtIndex(int index) 
    {
        
        // Check if the index is valid
        if(index >= size || index < 0) return;

        // Hold the current node
        SinglyLinkedListNode* currentNode = head;

        // Check if it is the head
        if(index == 0)
        {

            // Set the new head
            head = currentNode->next;

            // Drop the current node
            delete currentNode;
        }

        // Hold the current index
        int currentIndex = 0;

        // Loop until we find the target index
        while(currentIndex < index - 1)
        {

            // Get the next node
            currentNode = currentNode->next;

            // Increment current index
            currentIndex++;
        }
        
        // Remove the node
        currentNode->next = currentNode->next->next;

        // Check we have a new tail
        if(index == size-1)
        {

            // Assign the new tail
            tail = currentNode;
        }

        // Decrement the size
        size--;
    }

    /*
    Check if a node exists in the SinglyLinkedList
    @param int val the value being searched in the SinglyLinkedList
    @return true if the value exists in the SinglyLinkedList
    */
    bool find(int val)
    {

        // Check if there is no head
        if(head == nullptr) return false;

        // Hold the current node
        SinglyLinkedListNode* currentNode = head;

        // Loop through the list
        while(currentNode != nullptr)
        {

            // Check if the val exists
            if(currentNode->val == val) return true;

            // Assign the new current node
            currentNode = currentNode->next;
        }

        // Return false
        return false;
    }
};

int main()
{
    SinglyLinkedList* MySinglyLinkedList = new SinglyLinkedList();

    MySinglyLinkedList->addAtHead(1);
    MySinglyLinkedList->addAtTail(2);
}