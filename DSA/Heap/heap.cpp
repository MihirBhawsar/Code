#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Heap
{
private:
    vector<int> arr;
    bool isMaxHeap = true;

    void constructHeap()
    { // O(nlogn)==o(n)
        // bottom-up approach
        for (int i = this->arr.size() - 1; i >= 0; i--)
        {
            downHeapify(i);
        }
    }

    void downHeapify(int pi)
    { // o(logn)
        int maxIdx = pi;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        if (lci < this->arr.size() && compareTo(this->arr, this->isMaxHeap, lci, maxIdx))
        {
            maxIdx = lci;
        }

        if (rci < this->arr.size() && compareTo(this->arr, this->isMaxHeap, rci, maxIdx))
        {
            maxIdx = rci;
        }

        if (maxIdx != pi)
        {
            swap(this->arr[maxIdx], this->arr[pi]);
            downHeapify(maxIdx);
        }
    }
    void defaultHeap(bool isMaxHeap)
    {
        this->isMaxHeap = isMaxHeap;
    }

    bool compareTo(vector<int> &arr, bool isMaxHeap, int i, int j)
    {
        if (isMaxHeap)
        {
            return arr[i] > arr[j];
        }
        else
        {
            return arr[j] > arr[i];
        }
    }

    void upHeapify(int ci)
    { // O(logn)
        int pi = (ci - 1) / 2;
        if (pi >= 0 && compareTo(this->arr, this->isMaxHeap, ci, pi))
        {
            // means ci>pi
            swap(this->arr[ci], this->arr[pi]);
            upHeapify(pi);
        }
    }

public:
    Heap()
    {
        defaultHeap(true);
    }

    Heap(bool isMaxHeap)
    {
        defaultHeap(isMaxHeap);
    }
    Heap(vector<int> &arr, bool isMaxHeap)
    {
        defaultHeap(isMaxHeap);
        for (int ele : arr)
        {
            this->arr.push_back(ele);
        }

        constructHeap();
    }

    int size()
    { // o(1)
        return this->arr.size();
    }

    bool isEmpty()
    { // o(1)
        return this->arr.size() == 0;
    }

    int top()
    { // o(1)
        if (!isEmpty())
        {
            return this->arr[0];
        }
        return -1;
    }
    int remove()
    { // o(logn)
        int rEle = this->arr[0];
        int n = this->arr.size();
        swap(this->arr[0], this->arr[n - 1]);
        this->arr.pop_back();
        downHeapify(0);
        return rEle;
    }

    void push(int val)
    {
        this->arr.push_back(val);
        int n = this->arr.size();
        upHeapify(n - 1);
    }

    void displayHeap()
    {
        for (int ele : this->arr)
        {
            cout << ele << " ";
        }
    }
};

int main()
{
    vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13, 14};
    Heap maxHeap(arr, true);
    // cout << maxHeap.size() << endl;
    // cout << maxHeap.isEmpty() << endl;
    // cout << maxHeap.top() << endl;

    // while (maxHeap.size() != 0)
    // {
    //     cout << maxHeap.remove() << " ";
    // }

    // maxHeap.displayHeap();
    // maxHeap.push(15);
    // cout<<endl;
    // maxHeap.displayHeap();
}