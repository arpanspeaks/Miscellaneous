/*

Closest friends!

https://practice.geeksforgeeks.org/contest-problem/closest-friends28530119593001233851/0/

There are N persons standing in a line from left to right. This line is represented with an array of size N and the elements of the array are the height of the persons. For each person the closest friend is the closest person to his left whose height is strictly smaller than him. If for any person there is no person to his left whose height is smaller than him print -1 else print the index of smaller friend (0-based indexing).

Input: 
First line contains an integer T which denotes number of test cases. Next line contains an integer N which which is the size of the array. Next line of each test case contain N space seperated integers denoting the array  .

Output: 
For each print -1 or index of the closet friend, if found.

Constraints:
1 <= T <= 10000
1 <= N <= 105
0 <= A[i] <= 105

Example :
Input :
1
6
1 3 4 1 3 8
Output :
-1 0 1 -1 3 4

*/

#include <bits/stdc++.h>
using namespace std;

void func(vector<int> arr, int n) {
    if (arr.size() == 0) return;
    cout << -1 << " ";
    if (arr.size() == 1) return;
    stack<int> s;
    s.push(0);
    for(int i=1; i<n; i++)
        while (!s.empty() && arr[i] <= arr[s.top()]) s.pop();
        if (s.empty()) cout << -1 << " ";
        else cout << s.top() << " ";
        s.push(i);
    return;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> arr;
	    for(int i=0; i<n; i++) {
	        int x;
	        cin >> x;
	        arr.push_back(x);
	    }
	    func(arr, n);
	    cout << endl;
	}
	return 0;
}
