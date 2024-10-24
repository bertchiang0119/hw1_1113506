#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

void insertAtBottom(stack<int>& st, int x)
{
    if (st.empty())
    {
        st.push(x);
    }
    else
    {
        int a = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(a);
    }
}

void reverseStack(stack<int>& st)
{
    if (!st.empty())
    {
        int x = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, x);
    }
}

void buildStack(stack<int>& st, const vector<int>& nums, int index)
{
    if (index < nums.size())
    {
        buildStack(st, nums, index + 1);
        st.push(nums[index]);
    }
}

void printStack(stack<int>& st)
{
    if (!st.empty())
    {
        int x = st.top();
        st.pop();
        cout << x << " ";
        printStack(st);
        st.push(x);
    }
}

int main()
{
    stack<int> st;

    cout << "Enter elements of the stack from top to bottom: ";
    string inputLine;
    getline(cin, inputLine);

    istringstream iss(inputLine);
    vector<int> numbers;
    int x;
    while (iss >> x)
    {
        numbers.push_back(x);
    }

    buildStack(st, numbers, 0);

    reverseStack(st);

    cout << "Reversed stack elements from top to bottom: ";
    printStack(st);
    cout << endl;

    return 0;
}