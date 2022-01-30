#include <iostream>
#include <algorithm>

using namespace std;

int longestIncSub(int sequence[], int n)
{
    int longest[n];

    if (n >= 1)
      longest[0] = 1;

    for (int i = 1; i < n; i++)
      longest[i] = 1;
      for (int j = 0; j < i; j++)
        if (sequence[i] > sequence[j] && longest[i] < longest[j] + 1)
          longest[i] = longest[j] + 1;

    return *max_element(longest, longest + n);
}

int main()
{
    // read in data here (or make separate function)
    int sequence[] = {68, 49, 31, 25, 22, 48, 38, 19,
                    1, 80, 8, 83, 55, 33, 98, 29};
    const int n = sizeof(sequence) / sizeof(sequence[0]);

    cout << longestIncSub(sequence, n);

    return 0;
}