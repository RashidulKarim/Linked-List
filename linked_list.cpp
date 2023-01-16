#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node * next;
};


class LinkedList
{
    Node *head;
    int sz = 0;
public:
    LinkedList()
    {
        head = NULL;
    }

    Node * createNode(int data)
    {
        Node * newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void InsertAtHead(int data)
    {
        Node * newNode = createNode(data);
        sz++;
        if(head == NULL)
            head = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    int getSize()
    {
        return sz;
    }

    void Traverse()
    {
        Node *node = head;
        while(node != NULL)
        {
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<"\n";
    }

    int getValue(int index)
    {
        Node * node = head;
        int flag = 0;
        while(node != NULL)
        {
            if(index == flag)
                return node->data;

            node = node->next;
            flag++;
        }
        return -1;
    }

    void printRev(Node * node)
    {
        if(node == NULL)
        {
            return;
        }

        printRev(node->next);
        cout<<node->data<<" ";

    }

    void printReverse()
    {
        printRev(head);
        cout<<"\n";
    }

    void swapFirst()
    {
        if(sz < 2)
            return;
        Node * second = head->next;
        head->next = second->next;
        second->next = head;
        head = second;

    }
};


int main()
{
    LinkedList l;
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout<<l.getValue(2)<<"\n";

    cout<<l.getValue(6)<<"\n";

    l.printReverse();
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse();



    return 0;
}
