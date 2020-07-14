# Maximum Circular Subarray Sum
# https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum/0

def kadanes(arr, n):
    
    res = arr[0]
    maxEnding = arr[0]
    for i in range(1, n):
        maxEnding = max(maxEnding + arr[i], arr[i])
        res = max(res, maxEnding)
        
    return res

def calculate(arr, n):
    
    normMax = kadanes(arr, n)
    if normMax < 0:
        return normMax
    else:
        cumSum = 0
        for i in range(n):
            cumSum += arr[i]
            arr[i] *= -1
        rotMax = cumSum + kadanes(arr, n)
        
    return max(normMax, rotMax)

def main():
    
    t = int(input())
    while t:
        n = int(input())
        arr = input().split()
        for i in range(len(arr)):
            arr[i] = int(arr[i])
        
        res = calculate(arr, len(arr))
        print(res)

        t -= 1
        
if __name__ == '__main__':
    main()