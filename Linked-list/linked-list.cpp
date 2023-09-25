// Travaersal, Insertion and Deletion in Linked List

#include <iostream>
using namespace std;
// NODE structure
struct Node{
    char data;
    Node *ptr;
};
// Function prototypes
void printList(Node *start);
int countNode(Node *start);
void insertNode(Node* &start, char data, int index);
bool isEmpty(Node* start);
void deleteNode(Node* &start, int index);

int main()
{
    // Dynamically allocate memory
    Node *start = nullptr;
    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    // Assigning value
    n1 -> data = 'A';
    n2 -> data = 'B';
    n3 -> data = 'C';
    // Connecting nodes
    start = n1;
    n1 -> ptr = n2;
    n2 -> ptr = n3;
    n3 -> ptr = nullptr;

    // Here index of node starts from 0(zero)

    printList(start);
    insertNode(start, 'D', 0);
    printList(start);
    insertNode(start, 'Z', 3);
    printList(start);
    insertNode(start, 'X', 5);
    printList(start);
    deleteNode(start, 5);
    printList(start);
    deleteNode(start, 2);
    printList(start);
    deleteNode(start, 0);
    printList(start);


    

    delete n1;
    delete n2;
    delete n3;

    return 0;
}
// Function definitions
void printList(Node *start){
    Node *current = start;
    
    while(current != nullptr){
        cout << current -> data << " ";
        current = current -> ptr;
    }
    cout << endl;
}
int countNode(Node *start){
    int count = 0;
    if(start==nullptr)
    {
        return 0;
    }
    Node *current = start;
    while (current != nullptr) {
        count ++;
        current = current -> ptr;
    }
    return count;
}
void insertNode(Node* &start, char data, int index){
    Node *newNode = new Node;
    newNode -> data = data;
    Node *current = start;
    
    if(index > countNode(start)){
        cout << "INDEX OUT OF RANGE" << endl;
        return;
    }
    if(countNode(start) == 0){
        start = newNode;
        newNode -> ptr = nullptr;
    }
    else if(index == countNode(start)){
        for(int i = 0; i < index-1; i++){
            current = current -> ptr;
        }
        current -> ptr = newNode;
        newNode -> ptr = nullptr;
    }
    else if(index < countNode(start) && index > 0){
        for(int i = 0; i < index-1; i++){
            current = current -> ptr;
        }
        newNode -> ptr = current -> ptr;
        current -> ptr = newNode; 

    }
    else if (index == 0) {
        newNode -> ptr = start;
        start = newNode;
    }
}
bool isEmpty(Node* start){
    if(start == nullptr){
        return true;
    }
    return false;
}
void deleteNode(Node* &start, int index){
    Node *current = start;
    if(isEmpty(start)){
        cout << "NOTHING TO DELETE" << endl;
        return;
    }
    if(index == countNode(start)-1){
        for(int i = 0; i < index-1; i++){
            current = current -> ptr;
        }
        delete current -> ptr;
        current -> ptr = nullptr;
    }
    else if (index < countNode(start) && index > 0){
        for(int i = 0; i < index-1; i++){
            current = current -> ptr;
        }
        current -> ptr = current -> ptr -> ptr;
    }
    else if (index == 0){
        start = start -> ptr;
        delete current;
    }
    else {
        cout << "INDEX NOT VALID" << endl;
    }
}