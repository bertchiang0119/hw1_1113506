#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

void printFirstNegativeInteger(vector<int>& arr, int k)
{
    int n = arr.size();
    queue<int> negatives;

    for (int i = 0; i < k; ++i)
    {
        if (arr[i] < 0)
            negatives.push(i);
    }

    for (int i = k; i <= n; ++i)
    {
        if (!negatives.empty())
            cout << arr[negatives.front()] << " ";
        else
            cout << "0 ";

        while (!negatives.empty() && negatives.front() <= i - k)
            negatives.pop();

        if (i < n && arr[i] < 0)
            negatives.push(i);
    }
    cout << endl;
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

    int k;
    cout << "Enter the window size k: ";
    cin >> k;

    if (k <= 0 || k > arr.size())
    {
        cout << "Invalid window size." << endl;
        return 1;
    }

    printFirstNegativeInteger(arr, k);

    return 0;
}