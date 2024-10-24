#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

void interleaveQueue(queue<int>& q)
{
    if (q.empty())
        return;

    int n = q.size();
    if (n % 2 != 0)
    {
        cout << "Queue has an odd number of elements." << endl;
        return;
    }

    int halfSize = n / 2;
    queue<int> firstHalf;

    for (int i = 0; i < halfSize; ++i)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int num;
    cout << "Enter the elements of the queue (even number): ";
    string line;
    getline(cin, line);
    istringstream iss(line);

    while (iss >> num)
    {
        q.push(num);
    }

    if (q.size() % 2 != 0)
    {
        cout << "The number of elements is not even." << endl;
        return 1;
    }

    interleaveQueue(q);

    cout << "Rearranged queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}