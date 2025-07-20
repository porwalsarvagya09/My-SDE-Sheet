// leetcode-160

/*

Time Complexity: O(2*max(length of list1,length of list2))

Reason: Uses the same concept of the difference of lengths of two lists.

Space Complexity: O(1)

*/


#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Two-pointer intersection finder (Corrected)
ListNode* getIntersection(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while (temp1 != temp2) {
        temp1 = (temp1 != nullptr) ? temp1->next : headB;
        temp2 = (temp2 != nullptr) ? temp2->next : headA;
    }

    return temp1; // either the intersection node or nullptr
}

// Smart printer to avoid duplicate printing of intersecting tail
void printUntil(ListNode* head, ListNode* stop) {
    while (head && head != stop) {
        cout << head->val << " -> ";
        head = head->next;
    }
    // Now print shared tail (if any)
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int n1, n2;
    cout << "Enter number of nodes in listA: ";
    cin >> n1;
    cout << "Enter number of nodes in listB: ";
    cin >> n2;

    vector<ListNode*> nodesA(n1), nodesB(n2);

    cout << "Enter the values for listA: ";
    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        nodesA[i] = new ListNode(val);
        if (i > 0) nodesA[i - 1]->next = nodesA[i];
    }

    cout << "Enter the values for listB: ";
    for (int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        nodesB[i] = new ListNode(val);
        if (i > 0) nodesB[i - 1]->next = nodesB[i];
    }

    ListNode* headA = (n1 ? nodesA[0] : nullptr);
    ListNode* headB = (n2 ? nodesB[0] : nullptr);

    cout << "Enter intersection index in A (0-based, -1 for no intersection): ";
    int idx;
    cin >> idx;

    if (idx >= 0 && idx < n1 && n2 > 0) {
        nodesB[n2 - 1]->next = nodesA[idx];
        cout << "Lists intersect at A[" << idx << "] = " << nodesA[idx]->val << "\n";
    } else {
        cout << "No intersection will be created.\n";
    }

    ListNode* inter = getIntersection(headA, headB);

    cout << "print listA: ";
    printUntil(headA, nullptr);

    cout << "print listB: ";
    if (inter)
        printUntil(headB, inter); // print B until intersection, then tail from intersection
    else
        printUntil(headB, nullptr);

    if (inter) {
        cout << "Intersection found at node with value: " << inter->val << "\n";
        cout << "Merged tail: ";
        printUntil(inter, nullptr);
    } else {
        cout << "No intersection found.\n";
    }

    return 0;
}
