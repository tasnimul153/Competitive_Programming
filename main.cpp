#include <iostream>
#include <unordered_set>
#include <stack>

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
    Node * prev;
    Node * next;

    Node() {  }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
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

/// ************************************************ Delete node of given data ***********************************************

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

/// ************************************************ Search nodes by given data **********************************************

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

/// ****************************************************** Delete List ******************************************************

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

/// ************************************ Reverse a linked list in group of given size ***************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
struct Node *reverse (struct Node *head, int k) { 
    int counter = 0;
    struct Node * it = head, * tempNode = head, * tempNode2 = NULL;
    struct Node * prevNode = NULL, * nextNode = NULL;
    if(k != 1) {
        while(it != NULL) {
            if(counter < k) {
                nextNode = it->next;
                it->next = prevNode;
                prevNode = it;
                it = nextNode;
            } else {
                if(tempNode == head) {
                    head = prevNode;
                } else {
                    tempNode->next = prevNode;
                    tempNode = tempNode2;
                }
                tempNode2 = it;
                prevNode = NULL;
                counter = -1;
            }
            counter++;
        }
        if(tempNode != head)
            tempNode->next = prevNode;
        else 
            head = prevNode;
    }
    
    return head;
}

/// *********************************** Delete nodes having greater value on right side *************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
Node * reverseGeeks(Node * &head) {
    Node * it = head;
    Node * prevNode = NULL, * nextNode = NULL;
    
    while(it != NULL) {
        nextNode = it->next;
        it->next = prevNode;
        prevNode = it;
        it = nextNode;
    }
    
    return prevNode;
}

Node *compute(Node * head) {
    head = reverseGeeks(head);
    
    Node * it = head, * delNode;
    int maxNode = it->data;
    
    while(it->next != NULL) {
        if(maxNode > it->next->data) {
            delNode = it->next;
            it->next = delNode->next;
            delete delNode;
        } else {
            maxNode = it->next->data;
            it = it->next;
        }
    }
    
    return reverseGeeks(head);
}

/// ************************************** Segregate even and odd nodes in a Link List **************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
Node* divide(int N, Node *head){
        
    if(head == NULL) 
        return head;
    
    int data;
    Node * newNode = NULL;
    
    Node * newList = new Node(head->data);
    Node * left = (head->data % 2 == 0) ? newList : NULL;
    Node * right = newList;
    Node * it = head->next;
    
    while(it != NULL) {
        data = it->data;
        newNode = new Node(data);
        if(data & 1) {
            right->next = newNode;
            right = newNode;
        } else {
            if(left) {
                newNode->next = left->next;
                left->next = newNode;
                left = left->next;
            } else {
                newNode->next = newList;
                newList = newNode;
                left = newList;
            }
            if(right->data % 2 == 0) 
                right = left;
        }
        it = it->next;
    }
    
    return newList;
}

/// *********************************************** Detect Loop in linked list **********************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
bool detectLoop(Node* head) {
    Node * tortoise = head, * hare = head;
    
    while(hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if(hare == tortoise)
            return true;
    }
    
    return false;
}

/// *********************************************** Delete Loop in linked list **********************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
void removeLoop(Node* head) {
    Node * prevNode = NULL;
    Node * tortoise = head, * hare = head;
    
    while(hare && hare->next) {
        prevNode = tortoise;
        tortoise = tortoise->next;
        hare = hare->next->next;
        if(hare == tortoise) {
            break;
        }
    }
    
    if(tortoise == head) {
        prevNode->next = NULL;
    } else if(hare && hare->next) {
        hare = head;
        while(hare->next != tortoise->next) {
            hare = hare->next;
            tortoise = tortoise->next;
        }
        
        tortoise->next = NULL;
    }
}

/// ***************************************** Find first node of loop in a linked list **************************************

// LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/

Node *detectCycle(Node *head) {
    Node * prevSlow = head;
    Node * fast = head, * slow = head;
    
    while(fast != NULL && fast->next != NULL) {
        prevSlow = slow;
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) {
            break;
        }
    }
    
    if(prevSlow != NULL && slow == head) {
        return prevSlow->next;
    } else if(fast != NULL && fast->next != NULL) {
        fast = head;
        while(fast->next != slow->next) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->next;
    }
    
    return NULL;
}

/// ************************************* Remove duplicate element from sorted Linked List **********************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
Node *removeDuplicates(Node *head) {
    Node * delNode = NULL;
    Node * fast = head->next, * slow = head;
    
    while(fast != NULL) {
        if(fast->data == slow->data) {
            delNode = slow->next;
            slow->next = slow->next->next;
            fast = fast->next;
            delete delNode;
        } else {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    return head;
}

/// ************************************ Remove duplicate element from unsorted Linked List *********************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
Node * removeDuplicates_unsorted(Node *head)  {
    unordered_set <int> seen;
    
    Node * current = head, * prev = NULL;
    
    while(current != NULL) {
        if(seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } else {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
    
    return head;
}

/// ************************************* Move last element to the front of the linked list **********************************

// GeeksForGeeks: https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
void moveLast() {
    Node * it = head;
    if(head == NULL || head->next == NULL) 
        return;
    while(it->next->next != NULL)
        it = it->next;
    Node * lastNode = it;
    it->next->next = head;
    head = it->next;
    lastNode->next = NULL;
}

/// ************************************************ Rotate the list k times ************************************************

// LeetCode: https://leetcode.com/problems/rotate-list/
Node* rotateRight(Node* head, int k) {
    
    if(!head || !head->next || k == 0)
        return head;
    
    int counter = 0;
    Node * it = head, * slow = head;
    Node * fast = head, * prevSlow = head;
    
    while(it != NULL) {
        it = it->next;
        counter++;
    }
    
    if(k % counter == 0)
        return head;
    
    for(int i = 0; fast && i < k % counter; i++)
        fast = fast->next;
    
    while(fast != NULL) {
        fast = fast->next;
        prevSlow = slow;
        slow = slow->next;
    }
    
    fast = slow;
    
    while(fast->next)
        fast = fast->next;
        
    fast->next = head;
    head = prevSlow->next;
    prevSlow->next = NULL;
    
    return head;
}

/// **************************************** Add 1 to a number represented as linked list ***********************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
Node* addOne(Node *head) {
    if(head == NULL)
        return head;
    int counter = 0;
    Node * it = head, * tracker = head, * prev = NULL;
    
    while(it != NULL) {
        if(it->data != 9) {
            prev = it;
            tracker = it;
            counter = 0;
        } else if(counter < 1) {
            counter = 1;
            tracker = it;
        } else {
            counter++;
        }
        it = it->next;
    }
    
    if(tracker == prev) {
        tracker->data++;
    } else {
        if(prev) { prev->data++; --counter; }
        else {
            tracker->data = 1;
            if(!tracker->next)
                tracker->next = new Node(0);
            tracker = tracker->next;
            --counter;
        }
        while(tracker->next) {
            tracker->data = 0;
            tracker = tracker->next;
            --counter;
        }
        if(counter) {
            tracker->data = 0;
            tracker->next = new Node(0);
        } else {
            tracker->data = 0;
        }
    }
    return head;
}

/// *********************************************** Intersection of two sorted list *****************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
Node* findIntersection(Node* head1, Node* head2) {
    if(!head1 || !head2)
        return head1;
    Node * newList = NULL, * it;
    while(head1 && head2) {
        if(head1->data == head2->data) {
            Node * newNode = new Node(head1->data);
            if(!newList) {
                newList = newNode;
                it = newList;
            } else {
                it->next = newNode;
                it = it->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        } else if(head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }
    return newList;
}

/// *************************************** Intersection Point in Y Shapped Linked Lists **********************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
int intersectPoint(Node* head1, Node* head2) {
    int c1 = 0, c2 = 0;
    Node * it1 = head1, * it2 = head2;
    
    while(it1 || it2) {
        c1 += it1 != NULL ? 1 : 0;
        c2 += it2 != NULL ? 1 : 0;
        if(it1) it1 = it1->next;
        if(it2) it2 = it2->next;
    }
    
    it1 = head1;
    it2 = head2;
    
    while(c1 < c2) {
        it2 = it2->next;
        c2--;
    }
    
    while(c2 < c1) {
        it1 = it1->next;
        c1--;
    }
    
    while(it1->next != it2->next) {
        it1 = it1->next;
        it2 = it2->next;
    }
    
    return it2->next->data;    
}

/// ********************************************** Reverse a Doubly Linked List *******************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
Node* reverseDLL(Node * head)
{
    Node * current = head, * prevNode = NULL, * nextNode;
    
    while(current) {
        nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;
        prevNode = current;
        current = nextNode;
    }
    
    head = prevNode;
    return head;
}

/// ******************************************* Check if a list is palindrome or not **************************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
bool isPalindrome(Node *head) {
    
    if(!head || !head->next)
        return true;
    
    stack <int> st;
    
    Node * it = head;
    
    while(it != NULL) {
        st.push(it->data);
        it = it->next;
    }
    
    it = head;
    while(it != NULL) {
        if(it->data != st.top())
            return false;
        else 
            st.pop();
        it = it->next;
    }
    return true;
}

/// ************************************* Multiply two numbers represented in a linked list *******************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    int MODU = 1000000007;
    unsigned long long num1 = 0, num2 = 0;
    while(l1 || l2) {
        if(l1) {
            num1 = (num1 * 10) % MODU + l1->data;
            l1 = l1->next;
        }
        if(l2) {
            num2 = (num2 * 10) % MODU + l2->data;
            l2 = l2->next;
        }
    }
    
    return ((num1 % MODU) * (num2 % MODU)) % MODU;
}

/// ************************************* Given a linked list of 0s, 1s and 2s, sort it ***********************************

// GeeksForGeeks: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
Node* segregate(Node *head) {
        
    if(!head || !head->next)
        return head;
    
    Node * zeros = NULL;
    Node * ones = NULL;
    Node * twos = NULL;
    
    Node * itz = zeros;
    Node * ito = ones;
    Node * itt = twos;
    
    while(head != NULL) {
        int data = head->data;
        if(data == 0) {
            if(zeros == NULL) {
                zeros = new Node(data);
                itz = zeros;
            } else {
                itz->next = new Node(data);
                itz = itz->next;
            }
        } else if(data == 1) {
            if(ones == NULL) {
                ones = new Node(data);
                ito = ones;
            } else {
                ito->next = new Node(data);
                ito = ito->next;
            }
        } else {
            if(twos == NULL) {
                twos = new Node(data);
                itt = twos;
            } else {
                itt->next = new Node(data);
                itt = itt->next;
            }
        }
        head = head->next;
    }
    if(itz)
        itz->next = ito ? ones : itt ? twos : NULL;
    else 
        zeros = ito ? ones : itt ? twos : NULL;
    if(ito)
        ito->next = itt ? twos : NULL;
    return zeros;
}

int main() {
    ios_base::sync_with_stdio(false);
    head = NULL;
    for(int i = 1; i <= 10; i++)
        pushBack(i);
    printList();
    moveLast();
    printList();
    cout << "Length: " << listLength(head) << "\n";
    cout << isExist(head, 9) << "\n"; 
    return 0;
}
