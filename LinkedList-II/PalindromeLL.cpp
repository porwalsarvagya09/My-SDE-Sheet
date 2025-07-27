// LEETCODE- 243
// T.C. : O(N)
// S.C. : O(1)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to check the linked list is palindrome or not
bool isPalindrome(Node* head) {
        if(!head || !head->next){ //base condition
            return true;
        } 

        Node* fast = head;
        Node* slow = head;
        Node* prev = NULL; 

        while(fast && fast->next){  // Finding middle node
            fast = fast->next->next;
            
            // Finding middle and reversing the node till middle node 
            Node* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        // Edge case if odd number of nodes are there in LL
        if(fast){
            slow = slow->next;
        }
        
        // checking the values are equal or not  
        while(slow != NULL && prev != NULL){
            if(slow->data != prev->data){
                return false;
            }

            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }

int main() {
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}





/*-------------------------------APPROACH - 2--------------------------------------*/

// RECURSIVE APPROACH

/*
  📦 Space Complexity
  Although there’s no explicit extra data structure used, 
  the recursive calls build up a call stack of depth n. Therefore:

  Auxiliary (explicit) space: O(1)
  Total space due to recursion: O(n) stack space.

  --------------------------------------------------------------
 
  🕒 Time Complexity
   Every node is visited exactly once on the recursion down, 
   and once more during the backtracking comparison. As each comparison is O(1), 
   the overall time complexity is O(n) where n is the number of nodes in the list.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// To find the palindrome
class Solution {
public:
    Node* curr;
    bool recurr(Node* head){
        // base condition
        if(!head){
            return true;
        }
        
        // head pointing to the last then after reaching last it will start
        // backtracking
        bool ans = recurr(head->next);
        
        // check the values are equal or not
        if(head->data != curr->data){
            return false;
        }
        
        // Moving forward
        curr = curr->next;

        return ans;
    }  
    bool isPalindrome(Node* head) {
        curr = head;
        return recurr(head);   
    }
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution sol;
    
    bool ans = sol.isPalindrome(head);

    // Check if the linked list is a palindrome
    if (ans) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}