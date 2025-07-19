// leetcode -2
// ADD TWO NUMBERS

// Time Complexity: O(max(m,n)). 
// Assume that m and n represent the length of l1 and l2 respectively, 
// the algorithm above iterates at most max(m,n) times.

// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void appendNode(ListNode*& head, ListNode*& tail, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    ListNode* result = dummy->next;
    delete dummy;
    return result;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << " -> ";
    }
    cout << "\n";
}

int main() {

    int m, n;
    cout << "Enter size of first list (m): ";
    cin >> m;
    ListNode *l1 = nullptr, *t1 = nullptr;
    cout << "Enter " << m << " values for first list:\n";
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        appendNode(l1, t1, x);
    }

    int size = 0;
    cout << "Enter size of second list (n): ";
    cin >> n;
    ListNode *l2 = nullptr, *t2 = nullptr;
    cout << "Enter " << n << " values for second list:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        appendNode(l2, t2, x);
    }

    cout << "First list: ";
    printList(l1);
    cout << "Second list: ";
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Result (sum list): ";
    printList(result);

    return 0;
}
