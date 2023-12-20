#include <iostream>

/*
A tactic that is useful is reversing a linked list. We use three pointers and at the end we have access to the new head.
*/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) 
{
    
    // Hold the previous pointer
    ListNode* prev = nullptr;
        
    // Hold the next pointer
    ListNode* next = head;
    
    while(next != nullptr)
    {
        
        // Hold the next node
        ListNode* temp = next->next;
        
        // Reverse the next node
        next->next = prev;
        
        // Move the pointers
        prev = next;
        
        if(temp == nullptr) return next;
        
        next = temp;    
    }
    
    return nullptr;
}

int main()
{
    
}