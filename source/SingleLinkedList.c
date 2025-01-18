#include <stdio.h>
#include<stdlib.h>


typedef struct Node {

    int data;
    struct Node *next;

} Node;

Node *createNode(int new_data);
Node *insertHead(Node *head, int new_data);
Node *insertAtPosition(Node *head, int position, int new_data);
Node *insertEnd(Node *head, int new_data);
Node *deleteHead(Node *head);
Node *deleteAtPosition(Node *head, int position);
Node *deleteEnd(Node *head);
void displayLinkedList(Node *head);
void reversePrintLinkedList(Node *head); // recursive 

int main() {

    Node *head = NULL;
    head = insertHead(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertAtPosition(head, 3, 4);

    printf("List is displaying\n");
    displayLinkedList(head);

    printf("List is displaying as reversed:\n");
    reversePrintLinkedList(head);

    
    head = deleteAtPosition(head, 1);
    printf("After deleting a node in List:\n");
    displayLinkedList(head);

    head = deleteHead(head);
    printf("After deleting head node in List\n");
    displayLinkedList(head);

    printf("List is displaying as reversed:\n");
    reversePrintLinkedList(head);

    return 0;
}



Node *createNode(int new_data){

    Node *new_node = (Node *)malloc(sizeof(Node));
    
    if(new_node == NULL){

        printf("Allocation Failed\n");
        exit(-1);
    }
    
    new_node->data = new_data;
    new_node->next = NULL;

    return new_node;
}


Node* insertHead(Node* head, int new_data){

    Node *new_node = createNode(new_data);
    new_node->next = head;
    head = new_node;

    return head;
}

Node* insertAtPosition(Node* head, int position, int new_data){

    if(position < 0){

        printf("Invalid Position\n");
        return head;
    }

    if(position == 0){

        Node *new_node = createNode(new_data);
        new_node->next = head;
        head = new_node;

        return head;
    }

    Node *current = head;

    for (int i = 0; i < position - 1 && current != NULL; i++){

        current = current->next;
        
    }

    if(current == NULL){

        printf("Invalid Position\n");
        return head;
    }

    Node *new_node = createNode(new_data);
    new_node->next = current->next;
    current->next = new_node;

    return head;
}


Node* insertEnd(Node* head, int new_data){

    Node *new_node = createNode(new_data);

    if(head == NULL){

        return new_node;
    }

    Node *current = head;

    while(current->next != NULL){

        current = current->next;
    }

    current->next = new_node;

    return head;
}

Node* deleteHead(Node* head){

    if(head == NULL){

        printf("List is Empty\n");
        return head;
    }

    if(head->next == NULL){

        free(head);
        printf("List is Empty\n");
        return NULL;
    }

    Node *temp = head;
    head = head->next;

    free(temp);
    return head;
}


Node* deleteAtPosition(Node* head, int position){

    if(head == NULL || position < 0 ){

        printf("Invalid Position or List is Empty\n");
        return head;
    }

    if(position == 0){

        return deleteHead(head);
    }

    Node *current = head;

    for (int i = 0; i < position - 1 && current != NULL; i++){

        current = current->next;
    }


    if(current == NULL || current->next == NULL){

        printf("Invalid Position\n");
        return head;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}


Node* deleteEnd(Node* head){

    if(head == NULL){

        printf("List is Empty\n");
        return head;
    }

    if(head->next == NULL){

        free(head);
        printf("List is Empty\n");
        return NULL;
    }

    Node *current = head;
    
    while(current->next->next != NULL){

        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

void displayLinkedList(Node* head){

    if(head == NULL){

        printf("List is Empty\n");
        return;
    }

   

    Node *current = head;

    while(current != NULL){

        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void reversePrintLinkedList(Node* head){

    if(head == NULL){

        return;
    }

    reversePrintLinkedList(head->next);
    printf("%d\n", head->data);

}

