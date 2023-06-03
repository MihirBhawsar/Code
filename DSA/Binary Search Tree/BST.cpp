#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};
Node *constructBST(vector<int> &arr, int si, int ei)
{
    if (si > ei)
    {
        return nullptr;
    }
    int mid = (ei + si) / 2;
    Node *node = new Node(arr[mid]);
    node->left = constructBST(arr, si, mid - 1);
    node->right = constructBST(arr, mid + 1, ei);
    return node;
}
int maxBST(Node *node)
{
    Node *curr = node;
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }
    return curr->data;
}
int minBST(Node *node)
{
    Node *curr = node;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr->data;
}
void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string ans = "";
    ans += (node->left == nullptr ? "." : to_string(node->left->data));
    ans += "<--";
    ans += to_string(node->data);
    ans += "-->";
    ans += (node->right == nullptr ? "." : to_string(node->right->data));
    cout << ans << endl;
    display(node->left);
    display(node->right);
}

bool findDataBST(Node *node, int val)
{
    Node* curr=node;
    while(curr!=nullptr){
        if(curr->data==val){
            return true;
        }else if(curr->data<val){
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {
        10,
        20,
        30,
        40,
        50,
        60,
        70,
        80,
        90,
        100,
        110,
        120,
        140,
    };

    Node *root = constructBST(arr, 0, arr.size() - 1);
    // display(root);
    cout << endl;
    // cout << "Max In BST" << maxBST(root) << endl;
    // cout << "Min In BST" << minBST(root) << endl;
    cout << "Value Present in BST-" << findDataBST(root,12) << endl;
    return 0;
}