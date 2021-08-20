#include <iostream>

using namespace std;

/*
struct Node {
    int data;
    struct Node * next;
};

struct Node * head;

Node * create_node(int data) {
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
*/

class Node {
public:
    int data;
    Node * next;

    Node() {  }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() { cout << "One node is deleted from the list!\n"; }
};

Node * head;

/// *********************************************** Print the linked list **********************************************

void printList() {
    cout << "[ ";
    if(head != NULL) {
        Node * temp = head;
        while(temp->next != NULL) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << " ";
    } else {
        cout << "Empty! ";
    }
    cout << "]\n";
}

// print the linked-list (recursive)
void printList_Recursive(Node * head) {
    if(head == NULL) { return; }
    cout << head->data << " ";
    printList_Recursive(head->next);
}

/// *********************************************** Push data to the list **********************************************

// add element at the front of the list
void pushFront(int data) {
    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}


// add element at the back of the list
void pushBack(int data) {
    Node * newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
    } else {
        Node * temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// add element at the back of the list (recursive)
void pushBack_Recursive(Node * &head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return;
    }
    pushBack_Recursive(head->next, data);
}

/// *********************************************** Length of the linked list **********************************************

int listLength() {
    int counter = 0;
    Node * temp = head;
    while(temp != NULL) {
        temp = temp->next;
        counter++;
    }
    return counter;
}

int listLength(Node * head) {
    if(head == NULL) { return 0; }
    return listLength(head->next) + 1;
}

/// *********************************************** Insert data at given index *********************************************

void insertAt(int loc, int data) {
    Node * newNode = new Node(data);
    if(loc == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node * temp = head;
        for(int i = 0; temp != NULL && i < loc - 1; i++) 
            temp = temp->next;
        if(temp == NULL) {
            cout << "Invalid index!\n";
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// add element at the given index (recursive)
void insertAt_Recursive(Node * &head, int loc, int data) {
    if(loc == 0) {
        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    } else if(head == NULL) {
        cout << "Invalid index!\n";
        return;
    } 
    return insertAt_Recursive(head->next, --loc, data);
}

/// *********************************************** Delete node of given index *********************************************

void deleteAt(int loc) {
    Node * delNode = head;
    if(loc == 0) {
        head = head->next;
        delete delNode;
    } else {
        Node * temp = head;
        for(int i = 0; temp->next != NULL && i < loc - 1; i++)
            temp = temp->next;
        if(temp->next == NULL) {
            cout << "Invalid index!\n";
        } else {
            delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }
}

void deleteAt(Node * &head, int loc) {
    if(head == NULL) { 
        cout << "Invalid index!\n";
        return;
    } else if(loc == 0) {
        Node * delNode = head;
        head = delNode->next;
        delete delNode;
        return;
    }  
    return deleteAt(head->next, --loc);
}

/// *********************************************** Delete node of given data **********************************************

void deleteData(int data) {
    bool flag = false;
    Node * temp = head, * del;
    if(head->data == data) {
        del = head;
        head = head->next;
        delete del;
    } else {
        while(temp->next != NULL) {
            if(temp->next->data == data) {
                del = temp->next;
                temp->next = del->next;
                delete del;
                flag = true;
                break;
            } 
            temp = temp->next;
        }
        if(!flag) {
            cout << "Invalid data!\n";
        }
    }
}

void deleteData(Node * &head, int data) {
    if(head == NULL) {
        cout << "Invalid data!\n";
        return;
    } else if(head->data == data) {
        Node * del = head;
        head = head->next;
        delete del;
        return;
    } 
    return deleteData(head->next, data);
}

/// *********************************************** Search nodes by given data *********************************************

// If it returns -1 then node doesn't exist else returned value is the index 
int isExist(int data) {
    int counter = 0;
    Node * temp = head;
    while(temp != NULL) {
        if(temp->data == data)
            return counter;
        counter++;
        temp = temp->next;
    }
    return -1;
}

// If node exist then return true otherwise return false
bool isExist(Node * head, int data) {
    if(head == NULL) 
        return false;
    else if(head->data == data) 
        return true;
    return isExist(head->next, data);
}

/// ***************************************************** Delete List *****************************************************

void deleteList() {
    Node * delNode;
    if(head != NULL) {
        while(head != NULL) {
            delNode = head;
            head = head->next;
            free(delNode);
        }
        cout << "Linked-list delation done!\n";
    } else {
        cout << "List is already deleted!\n";
    }
}

void deleteList_Recursive(Node * &head) {
    if(head == NULL) { return; } 
    deleteList_Recursive(head->next);
    free(head); head = NULL;
}

/// ********************************************** Print middle of a linked list *******************************************

void printMiddle() {
    Node * it = head;
    int nodeCounter = 0;
    while(it != NULL) {
        it = it->next;
        nodeCounter++;
    }
    it = head;
    for(int i = 0; i < nodeCounter/2; i++)
        it = it->next;
    cout << it->data << "\n";
}

// Using two pointers
void printMiddle_TwoPointers() {
    Node * slow = head, * fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << "\n";
}

// Recrursive way
void printMiddle_Recursive(Node * head) {
    static int i = 0, j;
    if(head == NULL) { return; } 
    i+=1; j = i;
    printMiddle_Recursive(head->next);
    if(--i == j/2)
        cout << head->data << "\n";
}

/// ************************************************ Reverse a linked list *************************************************

void reverseList() {
    Node * current = head;
    Node * prev = NULL, * nextNode = NULL;

    while(current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } 
    
    head = prev;
}

// Recursive
void reverseList_Recursive(Node * current) {
    if(!current->next) {
        head = current;
        return;
    }
    reverseList_Recursive(current->next);
    current->next->next = current;
    current->next = NULL;
}

/// ************************************ Find the nth node from the end of the linked list **********************************

void nthFromEnd(int n) {
    int nodeCounter = 0;
    Node * it = head;
    while(it != NULL) {
        it = it->next;
        nodeCounter++;
    }

    if(n >= nodeCounter) {
        cout << "Invalid index!\n";
        return;
    }

    it = head;
    
    for(int i = 0; it != NULL && i < nodeCounter-n-1; i++)
        it = it->next; 
    cout << "nth-node from the end: " <<  it->data << "\n";
}

// Using two pointers
void nthFromEnd_TwoPointer(int n) {
    int nodeCounter = 0;
    Node * fast = head, * slow = head;
    if(head != NULL) {
        while(nodeCounter <= n) {
            nodeCounter++;
            fast = fast->next;
            if(fast == NULL) 
                break;
        }
        if(nodeCounter <= n) {
            cout << "Invalid index!\n";
            return;
        }
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        cout << "nth-node from the end: " <<  slow->data << "\n";
    } else { cout << "Invalid operation - Empty list!\n"; }
}

// Recursive way
void nthFromEnd_Recursive(Node * head, int n) {
    static int i = 0;
    if(head == NULL) return;
    nthFromEnd_Recursive(head->next, n);
    if(++i == n+1)
        cout << "nth-node from the end: " <<  head->data << "\n";
}

/***************************************************************************************************************************
                                                 * * * Problem Solving * * *                                          
//*************************************************************************************************************************/

/// ********************************************* Delete all occurrence of data ********************************************

// leetCode: https://leetcode.com/problems/remove-linked-list-elements/
Node * removeElements(int data) {
    Node * del = head;
    while(head != NULL && head->data == data) {
        del = head;
        head = head->next;
        delete del;
    }
    if(head == NULL && head->next == NULL)
        return head;
    Node * temp = head;
    while(temp->next != NULL) {
        if(temp->next->data == data) {
            del = temp->next;
            temp->next = del->next;
            delete del;
        } else { temp = temp->next; }
    }
    return head;
}

/// ************************************************* Merge two sorted List ***********************************************

// leetCode: https://leetcode.com/problems/merge-two-sorted-lists/
Node* mergeTwoLists(Node* l1, Node* l2) {
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    int val;
    
    if(l1->data <= l2->data) {
        val = l1->data;
        l1 = l1->next;
    } else {
        val = l2->data;
        l2 = l2->next;
    }
    
    Node * newList = new Node(val);
    
    Node * it = newList;
    
    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            it->next = new Node(l1->data);
            l1 = l1->next;
        } else {
            it->next = new Node(l2->data);
            l2 = l2->next;
        }
        it = it->next;
    }
    
    it->next = (l1 == NULL) ? l2 : l1;
    
    return newList;
}

/// ************************************************* Return the middle node ***********************************************

// leetCode: https://leetcode.com/problems/middle-of-the-linked-list/
Node* middleNode(Node* head) {
    Node * slow = head;
    Node * fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

/// **************************************** Add two numbers represented by linked list *************************************

// leetCode: https://leetcode.com/problems/add-two-numbers/
Node * addTwoNumbers(Node * first, Node * second) {
    Node * init = NULL, * prev, * current;
    int sum, carry = 0;

    while(first != NULL || second != NULL) {
        sum = carry + (first? first->data : 0) + (second? second->data : 0);
        carry = sum >= 10 ? 1 : 0;
        current = new Node(sum % 10);
        if(head == NULL)
            head = current;
        else 
            prev->next = current;
        
        prev = current;

        if(first) first = first->next;
        if(second) second = second->next;
    }

    if(carry)
        prev->next = new Node(carry);
    return head;
}

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node * current1 = first, * next1 = NULL, * prev1 = NULL;
    struct Node * current2 = second, * next2 = NULL, * prev2 = NULL;
    
    int sum, carry = 0;
    
    while(current1 || current2) {
        if(current1) {
            next1 = current1->next;
            current1->next = prev1;
            prev1 = current1;
            current1 = next1;
        } 
        if(current2) {
            next2 = current2->next;
            current2->next = prev2;
            prev2 = current2;
            current2 = next2;
        }
    }
    
    first = prev1;
    second = prev2;
    
    struct Node * newList = NULL;
    
    while(first || second) {
        sum = carry + (first? first->data : 0) + (second? second->data : 0);
        carry = sum >= 10 ? 1 : 0;
        
        current1 = new Node(sum % 10);
        
        current1->next = newList;
        newList = current1;
        
        if(first) first = first->next;
        if(second) second = second->next;
    }
    
    if(carry) {
        current1 = new Node(carry);
        current1->next = newList;
        newList = current1;
    }
    
    return newList;
}

int main() {
    ios_base::sync_with_stdio(false);
    head = NULL;
    for(int i = 1; i <= 10; i++)
        pushBack(i);
    printList();
    nthFromEnd_Recursive(head, 4);
    printList();
    cout << "Length: " << listLength(head) << "\n";
    cout << isExist(head, 9) << "\n"; 
    return 0;
}
