sortingList = [12, 45, 15, 98, 65, 45, 21, 36, 96, 45, 69, 45, 25, 1, 25, 36, 96,
                 445, 256, 98, 45, 36, 45, 96, 78, 1254, 6985, 457532, 6985, 45, 2, 365, 45, 75]
insertionSortList = list(sortingList)

def InsertionSort():
    for j in range(1, len(insertionSortList)):
        temp = insertionSortList[j]
        insert(temp, j-1)

    print(insertionSortList)

def insert(value, i):
    while value < insertionSortList[i] and i>=0:
        insertionSortList[i+1] = insertionSortList[i]
        i -=1
    insertionSortList[i+1] = value


InsertionSort()
print(sortingList)
# print(insertionSortList)