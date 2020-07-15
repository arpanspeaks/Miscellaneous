# First and last occurrences of X
# https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0

def leftIndex(arr, N, X):
    lo = 0
    hi = N-1
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] > X:
            hi = mid - 1
        elif arr[mid] < X:
            lo = mid + 1
        else:
            if mid == 0 or arr[mid-1] != X:
                return mid
            else:
                hi = mid - 1
    return -1
    
def rightIndex(arr, N, X):
    lo = 0
    hi = N-1
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] > X:
            hi = mid - 1
        elif arr[mid] < X:
            lo = mid + 1
        else:
            if mid == N-1 or arr[mid+1] != X:
                return mid
            else:
                lo = mid + 1
    
def cal(arr, N, X):
    lIndex = leftIndex(arr, N, X)
    if  lIndex == -1:
        print (-1)
    else:
        print(lIndex, rightIndex(arr, N, X))
        
def main():
    t = int(input())
    while t:
        N, X = input().split()
        arr = input().split()
        for i in range(len(arr)):
            arr[i] = int(arr[i])
        
        cal(arr, int(N), int(X))

        t -= 1
        
if __name__ == '__main__':
    main()