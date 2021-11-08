quickSortList = [12, 45, 15, 98, 65, 45, 21, 36, 96, 45, 69, 45, 25, 1, 25, 36, 96,
                 445, 256, 98, 45, 36, 45, 96, 78, 1254, 6985, 457532, 6985, 45, 2, 365, 45, 75]
quickSortList = quickSortList.copy()


def quickSort(low, high):
    if low < high:
        partitionIndex = partition(low, high)
        quickSort(low, partitionIndex - 1)
        quickSort(partitionIndex + 1, high)


def partition(low, high):
    pivot = low
    pivotElement = quickSortList[pivot]

    while low < high:
        while low < len(quickSortList) and quickSortList[low] <= pivotElement:
            low += 1

        while quickSortList[high] > pivotElement:
            high -= 1

        if low < high:
            quickSortList[low], quickSortList[high] = quickSortList[high], quickSortList[low]

    quickSortList[pivot], quickSortList[high] = quickSortList[high], quickSortList[pivot]
    return high


print(quickSortList)
quickSort(0, len(quickSortList) - 1)
print(quickSortList)
