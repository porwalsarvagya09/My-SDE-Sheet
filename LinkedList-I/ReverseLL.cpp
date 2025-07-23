// leetcode - 92
// ⏰ Time Complexity: O(n)
// 🧠 Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int x;
    ListNode* next;

    ListNode(int val) {
        this->x = val;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        for (int i = 1; i <= right - left; i++) {
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }

        return dummy->next;
    }
};

void appendNode(ListNode*& head, ListNode*& tail, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == nullptr) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->x << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int n;
    cout << "Enter size of LL: ";
    cin >> n;

    int left;
    cout << "Enter left index: ";
    cin >> left;

    int right;
    cout << "Enter right index: ";
    cin >> right;

    cout << "Enter the elements of linked list: ";
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        appendNode(head, tail, value);
    }

    Solution sol;
    ListNode* reversedList = sol.reverseBetween(head, left, right);

    cout << "Reversed Linked List: ";
    printList(reversedList);

    return 0;
}
