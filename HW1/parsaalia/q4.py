def Q4(n,p, numbers):
    path1 = []
    path2 = []
    path1.append(numbers[0][0])
    path2.append(numbers[1][0])
    for i in range(1,n):
        if(path1[-1]> path2[-1]-p):
            first = path1[-1] + numbers[0][i]
        else:
            first = path2[-1] - p + numbers[0][i]
        if(path1[-1]-p<path2[-1]):
            second = path2[-1] + numbers[1][i]
        else:
            second = path1[-1] - p + numbers[1][i]
        path1.append(first)
        path2.append(second)
    if (path1[-1] > path2[-1]):
        return path1[-1]
    else:
        return path2[-1]


if __name__=='__main__':
    n, p = map(int,input().split())
    a = list(map(int,input().split()))[:n]
    b = list(map(int,input().split()))[:n]
    numbers = []
    numbers.append(a)
    numbers.append(b)
    print(Q4(n, p, numbers))
   