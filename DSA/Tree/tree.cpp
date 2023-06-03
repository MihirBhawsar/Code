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

// construct Tree using Recursion
int idx = 0;
Node *constructTree(vector<int> arr)
{
    if (arr.size() == idx || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
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

// find size of the tree
int sizeOfTree(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int countLeft = sizeOfTree(node->left);
    int countRight = sizeOfTree(node->right);

    return countLeft + countRight + 1;
}
int heightOfTree(Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    int leftH = heightOfTree(node->left);

    int rightH = heightOfTree(node->right);

    if (leftH > rightH)
    {
        return leftH + 1;
    }
    else
    {
        return rightH + 1;
    }
}
int heightOfTreeNode(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftH = heightOfTreeNode(node->left);

    int rightH = heightOfTreeNode(node->right);

    return max(leftH, rightH) + 1;
}

void preOrdered(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << to_string(node->data) << " ";
    preOrdered(node->left);
    preOrdered(node->right);
}

void inOrdered(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inOrdered(node->left);
    cout << to_string(node->data) << " ";
    inOrdered(node->right);
}
void postOrdered(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    postOrdered(node->left);
    postOrdered(node->right);
    cout << to_string(node->data) << " ";
}

bool findData(Node *node, int val)
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->data == val)
    {
        return true;
    }
    bool left = findData(node->left, val);
    bool right = findData(node->right, val);

    return left || right;
}
bool rootToNode(Node *root, vector<Node *> &arr, int x)
{

    if (!root)
        return false;

    if (root->data == x)
    {
        arr.push_back(root);
        return true;
    }
    arr.push_back(root);

    bool res = (rootToNode(root->left, arr, x) ||
                rootToNode(root->right, arr, x));
    if (!res)
    {
        arr.pop_back();
    }
    return res;
}
bool nodeToRoot(Node *root, vector<Node *> &arr, int x)
{

    if (!root)
        return false;

    if (root->data == x)
    {
        arr.push_back(root);
        return true;
    }

    bool res = (nodeToRoot(root->left, arr, x) ||
                nodeToRoot(root->right, arr, x));
    if (res)
    {
        arr.push_back(root);
    }

    return res;
}

void printPath(Node *root, int x)
{
    vector<Node *> arr;

    if (rootToNode(root, arr, x))
    {
        for (int i = 0; i < arr.size() - 1; i++)
            cout << arr[i]->data << "->";
        cout << arr[arr.size() - 1]->data;
    }
    // if (nodeToRoot(root, arr, x))
    // {
    //     for (int i = 0; i < arr.size() - 1; i++)
    //         cout << arr[i]->data << "->";
    //     cout << arr[arr.size() - 1]->data;
    // }

    else
        cout << "No Path";
}
vector<Node *> rootToNodeTwo(Node *node, int x)
{

    if (!node)
        return {};
    vector<Node *> arr;
    arr.push_back(node);

    if (node->data == x)
    {
        vector<Node *> base;
        base.push_back(node);
    }

    vector<Node *> left = rootToNodeTwo(node->left, x);
    if (left.size() != 0)
    {
        left.push_back(node);
    }
    vector<Node *> right = rootToNodeTwo(node->right, x);
    if (right.size() != 0)
    {
        right.push_back(node);
    }

    arr.pop_back();
    return arr;
}

vector<Node *> nodeToRootTwo(Node *node, int data)
{
    if (node == nullptr)
    {
        return {};
    }

    if (node->data == data)
    {
        vector<Node *> base;
        base.push_back(node);
        return base;
    }

    vector<Node *> left = nodeToRootTwo(node->left, data);
    if (left.size() != 0)
    {
        left.push_back(node);
        return left;
    }

    vector<Node *> right = nodeToRootTwo(node->right, data);
    if (right.size() != 0)
    {
        right.push_back(node);
        return right;
    }

    return {};
}
void BFS_01(Node *node)
{
    queue<Node *> que;
    que.push(node);

    while (!que.empty())
    {
        Node *removeNode = que.front();
        que.pop();
        cout << removeNode->data << " ";
        if (removeNode->left != nullptr)
            que.push(removeNode->left);
        if (removeNode->right != nullptr)
            que.push(removeNode->right);
    }
}
void BFS_02(Node *node)
{
    queue<Node *> que;
    que.push(node);
    int level = 0;
    while (!que.empty())
    {
        int size = que.size();
        cout << "Level-" << level << " ";
        while (size--)
        {
            Node *removeNode = que.front();
            que.pop();
            cout << removeNode->data << " ";
            if (removeNode->left != nullptr)
                que.push(removeNode->left);
            if (removeNode->right != nullptr)
                que.push(removeNode->right);
        }
        cout << endl;
        level++;
    }
}
vector<int> BFSLeftView(Node *node)
{
    queue<Node *> que;
    que.push(node);
    int level = 0;
    vector<int> ans;
    while (!que.empty())
    {
        int size = que.size();
        ans.push_back(que.front()->data);
        while (size--)
        {
            Node *removeNode = que.front();
            que.pop();

            if (removeNode->left != nullptr)
                que.push(removeNode->left);
            if (removeNode->right != nullptr)
                que.push(removeNode->right);
        }
        level++;
    }
    return ans;
}

vector<int> BFSRightView(Node *node)
{
    queue<Node *> que;
    que.push(node);
    vector<int> ans;
    while (!que.empty())
    {
        int size = que.size();
        ans.push_back(que.back()->data);
        while (size--)
        {
            Node *removeNode = que.front();
            que.pop();
            if (removeNode->left != nullptr)
            {
                que.push(removeNode->left);
            }
            if (removeNode->right != nullptr)
            {
                que.push(removeNode->right);
            }
        }
    }

    return ans;
}

void widthNode(Node *node, int level, vector<int> &minMax)
{
    if (node == nullptr)
    {
        return;
    }
    minMax[0] = max(minMax[0], level);
    minMax[1] = min(minMax[1], level);

    widthNode(node->left, level - 1, minMax);
    widthNode(node->right, level + 1, minMax);
}

vector<vector<int>> verticalNodePrint(Node *node)
{
    vector<int> minMax(2, 0);
    widthNode(node, 0, minMax);

    int n = minMax[0] - minMax[1] + 1;
    vector<vector<int>> ans(n);

    queue<pair<Node *, int>> que;

    que.push({node, -minMax[1]});

    while (!que.empty())
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<Node *, int> removePair = que.front();
            que.pop();

            ans[removePair.second].push_back(removePair.first->data);

            if (removePair.first->left != nullptr)
            {
                que.push({removePair.first->left, removePair.second - 1});
            }
            if (removePair.first->right != nullptr)
            {
                que.push({removePair.first->right, removePair.second + 1});
            }
        }
    }
    return ans;
}
vector<int> bottomView(Node *node)
{
    vector<int> minMax(2, 0);
    widthNode(node, 0, minMax);

    int n = minMax[0] - minMax[1] + 1;
    vector<int> ans(n);

    queue<pair<Node *, int>> que;

    que.push({node, -minMax[1]});

    while (!que.empty())
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<Node *, int> removePair = que.front();
            que.pop();

            ans[removePair.second] = removePair.first->data;

            if (removePair.first->left != nullptr)
            {
                que.push({removePair.first->left, removePair.second - 1});
            }
            if (removePair.first->right != nullptr)
            {
                que.push({removePair.first->right, removePair.second + 1});
            }
        }
    }
    return ans;
}
vector<int> topView(Node *node)
{
    vector<int> minMax(2, 0);
    widthNode(node, 0, minMax);

    int n = minMax[0] - minMax[1] + 1;
    vector<int> ans(n, 0);

    queue<pair<Node *, int>> que;

    que.push({node, -minMax[1]});

    while (!que.empty())
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<Node *, int> removePair = que.front();
            que.pop();
            if (ans[removePair.second] == 0)
            {
                ans[removePair.second] = removePair.first->data;
            }

            if (removePair.first->left != nullptr)
            {
                que.push({removePair.first->left, removePair.second - 1});
            }
            if (removePair.first->right != nullptr)
            {
                que.push({removePair.first->right, removePair.second + 1});
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = {10, 20, 40, 80, -1, -1, 90, 100, -1, -1, -1, 50, -1, -1, 30, 60, 110, 120, -1, -1, 140, -1, -1, -1, 70, -1, -1};

    Node *root = constructTree(arr);
    // display(root);
    // cout << "sizeOfTree--" << sizeOfTree(root) << endl;
    // cout << "heightOfTree--" << heightOfTree(root) << endl;
    // cout << "heightOfTreeNode--" << heightOfTreeNode(root) << endl;

    // preOrdered(root);
    // cout << endl;
    // inOrdered(root);
    // cout << endl;
    // postOrdered(root);
    // cout << endl;

    // cout << findData(root, 110) << endl;

    // printPath(root, 50);

    // vector<Node *> ans = nodeToRootTwo(root, 90);
    // for (Node *node : ans)
    // {
    //     cout << node->data << "-->";
    // }

    // BFS_01(root);
    // BFS_02(root);
    //    vector<int> ans= BFSLeftView(root);
    //    vector<int> ans= BFSRightView(root);
    //    for(int ele:ans){
    //     cout<<ele<<" ";
    //    }

    // vector<int> minMax(2, 0);
    // widthNode(root,0,minMax);
    // cout<<"width of tree-"<<minMax[0]-minMax[1]<<endl;

    // vector<vector<int>> ans = verticalNodePrint(root);
    // for (vector<int> v : ans)
    // {
    //     for (int ele : v)
    //     {
    //         cout << ele << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> ans = bottomView(root);
    vector<int> ans = topView(root);
    for (int ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}