#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
class Node
{
public:
    int data;
    vector<Node *> childs;
    Node(int data)
    {
        this->data = data;
    }
};

Node *constructGT(vector<int> &arr)
{
    int i = 0;
    int n = arr.size();
    stack<Node *> st;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int ele = arr[i];
        if (ele == -1)
        {
            Node *child = st.top();
            st.pop();
            st.top()->childs.push_back(child);
        }
        else
        {
            Node *node = new Node(ele);
            st.push(node);
        }
    }

    return st.top();
}

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string ans = "";
    ans += to_string(node->data) + "-->";
    for (Node *child : node->childs)
    {
        ans += to_string(child->data) + " ";
    }
    cout << ans << endl;
    for (Node *child : node->childs)
    {
        display(child);
    }
}
int sizeOfGST(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int size = 0;

    for (Node *child : node->childs)
    {
        size += sizeOfGST(child);
    }
    return size + 1;
}

bool find(Node *root, int tar)
{
    if (root->data == tar)
    {
        return true;
    }
    for (Node *child : root->childs)
    {
        if (find(child, tar))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = constructGT(arr);
    // display(root);
    cout << sizeOfGST(root) << endl;
    cout << find(root, 80) << endl;
}