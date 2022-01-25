#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int sequence[] = { 68,49,31,25,22,48,38,19, 1,80,8,83,55,33,98,29 };

    const int n = sizeof(sequence) / sizeof(sequence[0]);

    int longest[n];

    for (int i = 1; i < n; i++) {
        longest[i] = 1;
        for (int j = 0; j < i; j++)
            if (sequence[i] > sequence[j] && longest[i] < longest[j] + 1)
                longest[i] = longest[j] + 1;
    }

    int* x;

    x =  max_element(longest, longest + n);

    cout << endl << *x;
}


