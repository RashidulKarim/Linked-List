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
    int sz;
public:
    LinkedList()
    {
        head = NULL;
        sz = 0;
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

    void insertAtAnyIndex(int data, int index)
    {
        if(index < 0 || index > sz)
            return;
        if( index  == 0)
        {
            InsertAtHead(data);
            return;
        }
        int idx = 0;
        Node * node = head;
        Node * newNode = createNode(data);

        while(idx <  index)
        {
            if(index -1 == idx)
            {
                newNode->next = node->next;
                node ->next = newNode;
                sz++;
                return;
            }
            node = node->next;
            idx++;
        }
    }

    void deleteFormHead()
    {
        if(head == NULL)
            return;
        Node * a = head;
        head = a->next;
        sz--;
        delete a;
    }

    void deleteAnyIndex(int index)
    {
        if(index < 0 || index > sz)
        {
            return;
        }
        if(index == 0)
        {
            deleteFormHead();
            return;
        }

        Node * a = head;
        int idx = 0;

        while(idx < index)
        {
            if(idx == index -1)
            {
                sz--;
                Node * b = a->next;
                a->next = b->next;
                delete b;
                return;
            }
            idx++;
            a = a->next;
        }
    }

    void insertAfterValue(int value, int data)
    {
        Node * node = head;
        while(node != NULL)
        {
            if(value == node->data)
            {
                Node * newNode = createNode(data);
                newNode->next = node->next;
                node->next = newNode;
                sz++;
                return;
            }
            node = node->next;
        }
        cout<<value<<" doesn't exist in Linked-list\n";
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
    l.insertAtAnyIndex(500, 5);
    l.deleteFormHead();
    l.deleteAnyIndex(2);
    l.insertAfterValue(30, 1000);
    l.Traverse();
    cout<<l.getSize()<<"\n";
    //l.printReverse();



    return 0;
}
