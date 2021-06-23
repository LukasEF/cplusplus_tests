//============================================================================
// Name        : LinkedListWithTemplates.cpp
// Author      :
// Version     :
// Copyright   :
// Description : LinkedList using Nodes with template data
//============================================================================

#include <iostream>

using namespace std;

template <typename T>
class Node {
    public:
        T data;
    Node * next;
};

template <typename A>
void print_list(Node<A> * n) {
    cout << "\nPrinting new list..." << endl;
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

template <typename B>
void push(struct Node<B> ** head_ref, B new_data) {
    struct Node<B> * new_node = (struct Node<B> * ) malloc(sizeof(struct Node<B>));
    new_node->data = new_data;
    new_node->next = ( * head_ref);
    ( * head_ref) = new_node;
}

template <typename C>
void append(struct Node<C> ** head_ref, C new_data) {
    struct Node<C> * new_node = (struct Node<C> * ) malloc(sizeof(struct Node<C>));
    struct Node<C> * last = * head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

template <typename D>
void insertAfter(struct Node<D> * prev_node, D new_data) {
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
    struct Node<D> * new_node = (struct Node<D> * ) malloc(sizeof(struct Node<D>));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main() {
    Node<char> * head = NULL;
    Node<char> * second = NULL;
    Node<char> * third = NULL;

    head = new Node<char>();
    second = new Node<char>();
    third = new Node<char>();

    head->data = 'a';
    head->next = second;

    second->data = 'b';
    second->next = third;

    third->data = 'c';
    third->next = NULL;

    print_list(head);

    push(&head, '0');
    print_list(head);

    append(&head, 'd');
    print_list(head);

    insertAfter(second, 'B');
    print_list(head);
}
