#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

void processWhile(stack<int>& s, int arr_i, int i, const vector<int>& arr, vector<int>& nge)
{
    if (s.empty() || arr_i <= arr[s.top()])
    {
        return;
    }
    else
    {
        nge[s.top()] = arr_i;
        s.pop();
        processWhile(s, arr_i, i, arr, nge);
    }
}

void process(int i, stack<int>& s, const vector<int>& arr, vector<int>& nge)
{
    int n = arr.size();
    if (i >= n)
    {
        return;
    }
    else
    {
        processWhile(s, arr[i], i, arr, nge);
        s.push(i);
        process(i + 1, s, arr, nge);
    }
}

void printResult(int i, const vector<int>& arr, const vector<int>& nge)
{
    int n = arr.size();
    if (i >= n)
    {
        return;
    }
    else
    {
        cout << arr[i] << " --> " << nge[i] << endl;
        printResult(i + 1, arr, nge);
    }
}

int main()
{
    cout << "Enter the elements of the array: ";
    vector<int> arr;
    int num;
    string line;

    getline(cin, line);
    istringstream iss(line);

    while (iss >> num)
    {
        arr.push_back(num);
    }

    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> s;

    process(0, s, arr, nge);

    printResult(0, arr, nge);

    return 0;
}