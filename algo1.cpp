//Joseph Fleming

// The algorithm in the program will identify the longest increasing subsequence of an array of 
// integers. It implements vectors to store the arrays of longest subsequences during the calculations.
// The program will print the value of the lis and the sequence(s) that correspond to it. 


#include <iostream>
#include <vector>

using namespace std;

//declare function
void findLIS(int arr[], int n);

int main()
{
    //input data
    int arr[] = { 186, 359, 274, 927, 890, 520, 571, 310, 916, 798, 732, 23, 196, 579,
    426, 188, 524, 991, 91, 150, 117, 565, 993, 615, 48, 811, 594, 303, 191,
    505, 724, 818, 536, 416, 179, 485, 334, 74, 998, 100, 197, 768, 421,
    114, 739, 636, 356, 908, 477, 656 };
    // size of data
    int n = sizeof(arr) / sizeof(arr[0]);
    // pass data and size to algorithm function
    findLIS(arr, n);

    return 0;
}

// function containing lis algoritm and print
void findLIS(int arr[], int n)
{
    // declare vector containing vector for lis subsequences
    vector < vector<int>>  lis(n);
     
    lis[0].push_back(arr[0]);

    // main algorithm for finding lis
    for (int i = 1; i < n; i++)
    {
      
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] > arr[j]) && (lis[i].size() < lis[j].size() + 1))
                lis[i] = lis[j];
        }
    
        lis[i].push_back(arr[i]);
    }

    // longest/maximum vector calculation starts at 1
    vector<int> longest = lis[0];

    // find longest lis in vector
    for (vector<int> x : lis)
        if (x.size() > longest.size())
            longest = x;

    cout << "the longest subsequence is " <<  longest.size() << endl;

    // print lis sequence
    for (int x : longest)
        cout << x << " ";

}
