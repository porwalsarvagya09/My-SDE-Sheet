// leetcode-237
// Delete Node in a Linked List

/*-------------------APPROACH - 1-----------------*/

// T.C.: O(n)
// S.C.: O(1)

#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    // Take value
    int val;
    
    // Create pointer to next
    ListNode* next;
    
    // Create node
    ListNode(int x)
    {
        this->val = x;
        next = nullptr;
    }
};

class Solution{
    public:
   
    // Create a function to append node 
    void appendNode(ListNode* &head, ListNode* &tail, int value){
        ListNode* newNode = new ListNode(value);

        if(head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {   
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Create a function to delete node(node can not be a last node)
    void deleteNode(ListNode* node){
        ListNode* prev = NULL;

        while(node != NULL && node->next != NULL)
        {
            node->val = node->next->val;
            prev = node; // assigning node place as prev
            node = node->next; 
        }

        prev->next = NULL;
        delete(node);
    }

};

int main()
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int n;
    cout<<"Enter size of LL: ";
    cin>>n;
   
    Solution sol;

    cout<<"Enter"<<n<<"integers: \n";
    for(int i=0; i<n; ++i){
        int val;
        cin>>val;
        sol.appendNode(head, tail, val);
    }

    cout<<"Print before deleting node: "<<endl;

    for (ListNode* cur = head; cur; cur = cur->next) {
        std::cout << cur->val << " ";
    }
    cout<<"\n";
    

    int nodeVal;
    cout<<"Enter the node value to delete: ";
    cin >> nodeVal;

    // Find the node with the given value (excluding the last node)
    ListNode* nodeToDelete = nullptr;
    for (ListNode* cur = head; cur && cur->next; cur = cur->next) {
        if (cur->val == nodeVal) {
            nodeToDelete = cur;
            break;
        }
    }

    if (nodeToDelete != nullptr) {
        sol.deleteNode(nodeToDelete);

        cout << "After deletion:  ";
        for (auto cur = head; cur; cur = cur->next) 
            cout << cur->val << " ";
        cout << "\n";

    } else {
        cout << "Node not found or it's the last node (cannot delete last node with this method)." << endl;
    }

    return 0;
}






/*-----------APPROACH - 2-----------------------------*/

// T.C.= O(1)
// S.C.= O(1)


#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:

    int val;

    ListNode* next;

    ListNode(int x){
        this->val = x;
        next = nullptr;
    }
};

void appendNode(ListNode* &head, ListNode* &tail, int value){
    ListNode* newNode = new ListNode(value);

    if(head == nullptr){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteNode(ListNode* node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{   
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int n;
    cout<<"Enter the size of LL: ";
    cin>>n;
    
    cout<<"Enter "<<n<<" integers: ";

    for(int i=0; i<n; ++i){
        int val;
        cin>>val;
        appendNode(head, tail, val);
    }

    // Print the L.L before deleting node
    cout<<"Print the linked list before deleting: ";
    for(ListNode* curr = head; curr; curr=curr->next){
        cout<<curr->val<<" ";
    }
    cout<<"\n";

    // Find node in Linked List

    int node;
    cout<<"Enter node value to delete: ";
    cin>>node;

    ListNode* nodeToDelete = nullptr;
    for(ListNode* curr = head; curr; curr=curr->next){
        if(curr->val == node)
        {
            nodeToDelete = curr;
            break;
        }
    }

    if(nodeToDelete != nullptr && nodeToDelete->next != nullptr)
    {
        deleteNode(nodeToDelete);

        cout<<"After deletion: ";

        for(ListNode* curr = head; curr; curr = curr->next){
            cout<<curr->val<<" ";
        }
    }else{
        cout<<"Node not found or it's the last node (cannot delete last node with this method).";
    }
    return 0;
}