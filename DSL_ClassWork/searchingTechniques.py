searchingList = [12, 45, 15, 98, 65, 45, 21, 36, 96, 45, 69, 45, 25, 1, 25, 36, 96,
                 445, 256, 98, 45, 36, 45, 96, 78, 1254, 6985, 457532, 6985, 45, 2, 365, 45, 75]
sortedList = [12, 45, 69, 78, 125, 215, 449, 665, 787, 4547]


def LinearSearch(key):
    for i in range(len(searchingList)):
        if key == searchingList[i]:
            return i

    return -1


def SentinelSearch(key):
    lastElement = searchingList[len(searchingList)-1]
    searchingList[len(searchingList)-1] = key

    i = 0
    while searchingList[i] != key:
        i += 1

    searchingList[len(searchingList)-1] = lastElement

    if i < len(searchingList)-1 or lastElement == key:
        return i

    return -1


def BinarySearch(key):
    low = 0
    high = len(sortedList) - 1

    while low <= high:
        mid = (high+low)//2
        if sortedList[mid] == key:
            return mid
        elif sortedList[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    return -1


def FibonacciSearch(key):
    n = len(sortedList)
    memset(-1, n+2)
    fibonacci(n+1)

    m = 0
    while FibonacciList[m] < n:
        m +=1
    
    offset = -1
    while FibonacciList[m] > 1:
        i = min(offset + fibonacci(m-2), n-1)
        if key > sortedList[i]:
            offset = i
            m = m-1
        elif key < sortedList[i]:
            m = m-2
        else:
            return i

    if fibonacci(m-1) and sortedList[offset+1]:
        return offset+1

    return -1

FibonacciList = []

def memset(value, length):
    for i in range(length):
        FibonacciList.append(value)

def fibonacci(n):
    if FibonacciList[n] == -1:
        if n <= 1:
            FibonacciList[n] = n
        else:
            FibonacciList[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return FibonacciList[n]

print(LinearSearch(24))
print(LinearSearch(69))

print(SentinelSearch(24))
print(SentinelSearch(69))
print(SentinelSearch(75))

print(BinarySearch(2))
print(BinarySearch(665))
print(BinarySearch(12))
print(BinarySearch(4547))


# for i in range(50):
#     print(fibonacci(i))

print(FibonacciSearch(2))
print(FibonacciSearch(665))
print(FibonacciSearch(12))
print(FibonacciSearch(4547))
