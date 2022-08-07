#include<iostream>
#include<cstdlib>

using namespace std;

struct Node {
    int val;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int x) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = x;
    new_node->next = nullptr;
    if (*head == nullptr) {
        *head = new_node;
    }
    else {
        struct Node* iter = *head;
        while (iter->next != nullptr) {
            iter = iter->next;
        }
        iter->next = new_node;
    }
}

void insertAtBeg(struct Node** head, int x) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = x;
    new_node->next = *head;
    *head = new_node;
}

void displayList(struct Node* iter) {
    cout << "\n";
    if (iter == nullptr) cout << "Empty List";
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    }
}

struct Node* getLastNode(struct Node* iter) {
    if (iter == nullptr) {
        cout << "\n\nlast node is null.. should'nt happen!";
    }

    while (iter->next != nullptr) {
        iter = iter->next;
    }
    return iter;
}

struct Node* deleteLastNode(struct Node** head) {
    if (*head == nullptr) {
        cout << "\n\nlast node to delete is null.. should'nt happen!";
        return nullptr;
    }
    struct Node* iter = *head;
    if (iter->next == nullptr) {
        *head = nullptr;
        return iter;
    }
    while (iter->next->next != nullptr) {
        iter = iter->next;
    }
    struct Node* last = iter->next;
    iter->next = nullptr;
    return last;
}
int calcSumAndCarry(int v1, int v2, int* carry) {
    int sum = v1 + v2 + *carry;
    if (sum > 9) {
        *carry = sum / 10;
        sum = sum % 10;
    }
    else {
        *carry = 0;
    }
    return sum;
}
void sumIt(struct Node* l1, struct Node* l2, struct Node** ans) {

    struct Node* t1, * t2;
    int carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        t1 = deleteLastNode(&l1);
        t2 = deleteLastNode(&l2);

        cout << "\n" << t1->val << " + " << t2->val << " + " << carry << " = ";
        int sum = calcSumAndCarry(t1->val, t2->val, &carry);
        cout << sum;

        insertAtBeg(&*ans, sum);
    }
    while (l1 != nullptr) {
        t1 = deleteLastNode(&l1);
        int sum = calcSumAndCarry(t1->val, 0, &carry);
        insertAtBeg(&*ans, sum);
    }
    while (l2 != nullptr) {
        t2 = deleteLastNode(&l2);
        int sum = calcSumAndCarry(t2->val, 0, &carry);
        insertAtBeg(&*ans, sum);
    }
    if (carry != 0) {
        insertAtBeg(&*ans, carry);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    struct Node* l1 = nullptr;
    struct Node* l2 = nullptr;

    for (int i = 0; i < 13; i++) {
        int t;
        cin >> t;
        insertAtEnd(&l1, t);
    }
    for (int i = 0; i < 10; i++) {
        int t;
        cin >> t;
        insertAtEnd(&l2, t);
    }

    // while (l1 != nullptr)
    //     deleteLastNode(&l1);
    displayList(l1);
    displayList(l2);

    struct Node* ans = nullptr;
    sumIt(l1, l2, &ans);
    //insertAtEnd(&ans, 3);
    //insertAtEnd(&ans, 5);
    cout << "\nSum:";
    displayList(ans);

    return 0;
}