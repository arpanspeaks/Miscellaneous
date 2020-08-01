'''
ROLLING HASH

https://practice.geeksforgeeks.org/contest-problem/rolling-hash51043607553159093725/0/

You are given a string S and a Pattern P. You need to find all matches of hash of P in string S. Also, print the index (0 based) at which the pattern's hash is found. If no match is found, print -1.

Note: All the matches should have same length as pattern P.

The hash of pattern P is calculated by summing the values of characters as they appear in the alphabets table. For reference, a is 1, b is 2, ...z is 26. Now, using the mentioned values, hash of ab is 1+2=3.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains the string S. The second line contains the pattern P.

Output:
For each testcase, in a new line, print the matches and index separated by a space. All the matches should be printed in their own separate lines.

Constraints:
1 <= T <= 100
1 <= |S|, |P| <= 105

Examples:
Input:
1
bacdaabaa
aab
Output:
aab 4
aba 5
baa 6

Explanation:
Testcase1: P is aab, and S is bacdaabaa
Now, the hash of P: aab is 1+1+2=4
In the string S, the hash value of 4 is obtained by the following:
aab=1+1+2=4, at index 4
aba=1+2+1=4, at index 5
baa=2+1+1=4, at index 6
'''


def func(s, p):
    m, n = len(s), len(p)
    if m < n:
        print(-1)
        return
    d = dict()
    hval = 1
    for i in range(26):
        d[chr(97+i)] = hval
        hval += 1
    pH = 0
    for i in range(n):
        pH += d[p[i]]
    arr = []
    winSum = 0
    for i in range(n):
        winSum += d[s[i]]
    arr.append(winSum)
    for i in range(m - n): 
        winSum = winSum - d[s[i]] + d[s[i + n]]
        arr.append(winSum)
    flag = False
    for i in range(len(arr)):
        if arr[i] == pH:
            flag = True
            print(''.join(s[i : i + n]), i)
    if not flag:
        print(-1)
        
def main():
    t = int(input())
    while t:
        s = str(input())
        p = str(input())
        func(s, p)
        t -= 1
        
if __name__ == '__main__':
    main()

