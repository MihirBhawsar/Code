#include <iostream>
#include <vector>
using namespace std;

class LinkedList
{
    class Node
    {
    public:
        int data = 0;
        Node *next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
    };
    Node *head = nullptr;
    Node *tail = nullptr;
    int eleCount = 0;

    int size()
    {
        return this->eleCount;
    }

    bool isEmpty()
    {
        return this->eleCount == 0;
    }

private:
    void addFirstNode(Node *node)
    {
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }
        this->eleCount++;
    }

public:
    void addFirst(int val)
    {
        Node *node = new Node(val);
        addFirstNode(node);
    }

private:
    void addLastNode(Node *node)
    {
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            this->tail->next = node;
            this->tail = node;
        }
        this->eleCount++;
    }

public:
    void addLast(int val)
    {
        Node *node = new Node(val);
        addLastNode(node);
    }

private:
    Node *removeFirstNode()
    {
        Node *node = this->head;
        if (eleCount == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            this->head = this->head->next;
            node->next = nullptr;
        }
        this->eleCount--;

        return node;
    }

public:
    int removeFirst()
    {
        if (this->eleCount == 0)
        {
            throw("nullPointer Exception");
        }

        Node *node = removeFirstNode();
        int rv = node->data;
        delete node;
        return rv;
    }

private:
    Node *getFirstNode()
    {
        return this->head;
    }

public:
    int getFirst()
    {
        if (this->eleCount == 0)
        {
            throw("null pointer exception");
        }

        Node *node = getFirstNode();
        return node->data;
    }

private:
    Node *getLastNode()
    {
        return this->tail;
    }

public:
    int getLast()
    {
        if (this->eleCount == 0)
        {
            throw("null pointer exception");
        }

        Node *node = getLastNode();
        return node->data;
    }

private:
    void addNodeAt(Node *currNode, int idx)
    {
        if (idx == 0)
        {
            addFirstNode(currNode);
        }
        else if (this->eleCount == idx)
        {
            addLastNode(currNode);
        }
        else
        {
            Node *preNode = getNodeAt(idx - 1);
            Node *nextNode = preNode->next;

            preNode->next = currNode;
            currNode->next = nextNode;
        }
        this->eleCount++;
    }

public:
    void addAt(int val, int idx)
    {
        if (idx < 0 || idx > this->eleCount)
        {
            throw("Invalid Index");
        }
        Node *node = new Node(val);
        addNodeAt(node, idx);
    }

private:
    Node *getNodeAt(int idx)
    {

        Node *currNode = this->head;
        while (idx > 0)
        {
            currNode = currNode->next;
            idx--;
        }

        return currNode;
    }

public:
    int getAt(int idx)
    {
        if (idx < 0 || idx > this->eleCount)
        {
            throw("Invalid Index");
        }
        Node *node = getNodeAt(idx);
        return node->data;
    }

private:
    Node *removeLastNode()
    {
        Node *node = this->tail;
        if (this->eleCount == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node *prev = getNodeAt(this->eleCount - 2);
            this->tail = prev;
            prev->next = nullptr;
        }
        return node;
    }

public:
    int removeLast()
    {
        if (this->head == nullptr)
        {
            throw("null pointer exception");
        }
        Node *node = removeLastNode();
        int rv = node->data;
        delete node;
        return rv;
    }

private:
    Node *removeNodeAt(int idx)
    {
        Node *node;
        if (idx == 0)
        {
            node = removeFirstNode();
        }
        else if (idx == this->eleCount - 1)
        {
            node = removeLastNode();
        }
        else
        {
            Node *prevNode = getNodeAt(idx - 1);
            node = prevNode->next;

            prevNode->next = node->next;
            node->next = nullptr;
            this->eleCount--;
        }

        return node;
    }

public:
    int removeAt(int idx)
    {
        if (idx < 0 || idx > this->eleCount)
        {
            throw("Invalid Index");
        }
        Node *node = removeNodeAt(idx);
        int rv = node->data;
        delete node;
        return rv;
    }

public:
    string toString()
    {
        Node *curr = this->head;
        string ans = "";
        ans += "[";
        while (curr != nullptr)
        {
            ans += to_string(curr->data);
            if (curr->next != nullptr)
            {
                ans += ",";
            }
            curr = curr->next;
        }
        ans += "]";
        return ans;
    }
};

int main()
{
    LinkedList li;
    for (int i = 1; i < 10; i++)
    {
        li.addLast(i*10);
    }
    cout << li.toString() << endl;
    return 0;
}