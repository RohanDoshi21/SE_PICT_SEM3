sortingList = [12, 45, 15, 98, 65, 45, 21, 36, 96, 45, 69, 45, 25, 1, 25, 36, 96,
               445, 256, 98, 45, 36, 45, 96, 78, 1254, 6985, 457532, 6985, 45, 2, 365, 45, 75]
shellSortList = list(sortingList)


def ShellSort():
    n = len(shellSortList)
    gap = n//2

    while gap > 0:
        for j in range(gap, n):
            for i in range(j-gap, -1, -gap):
                if shellSortList[i] > shellSortList[i+gap]:
                    shellSortList[i], shellSortList[i+gap] = shellSortList[i+gap], shellSortList[i]
                else:
                    break
        gap //=2


print(sortingList)
ShellSort()
print(shellSortList)
