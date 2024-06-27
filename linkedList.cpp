#include <iostream>


class Node
{
public:
    Node(){};
    Node(int data) : data(data){};
    int data;
    Node* next;

};


class LinkedList
{
public:
    Node* head{};
    Node* tail{};
    int size=0;

public:
    void insertAtBeginning(int data)
    {
        Node* node = new Node(data);
        node->next = this->head;
        this->head = node;
        if (size==0){
            this->tail = node;
        }
        size++;
    }

    void insertAtEnd(int data)
    {
        Node* node = new Node(data);
        node->next = nullptr;
        this->tail->next = node;
        this->tail = node;
        size++;
    }
};





int main(int argc, char const *argv[])
{
    LinkedList myList;
    myList.insertAtBeginning(1);
    myList.insertAtEnd(2);

    Node* node = myList.head;
    std::cout << node->data << std::endl;
    node = node->next;
    std::cout << node->data << std::endl;


    return 0;
}
