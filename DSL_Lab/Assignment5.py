# Author: Rohan Doshi
# Problem statement Group B - 15
"""
Write a python program to store second year percentage of students in array. Write 
function for sorting array of floating point numbers in ascending order using 
a) Insertion sort 
b) Shell Sort and display top five scores
"""

class Sorting:
    def __init__(self):
        self.__length = 0
        self.__arr = []
        self.__insertionSortList = []
        self.__shellSortList = []


    def acceptList(self):
        self.__length = int(input("Enter the number of students in the class "))
        for i in range(self.__length):
            temp = float(input(f"Enter the percent of student at {i+1} roll no "))
            self.__arr.append(temp)


    def insertionSort(self): #in each pass the list gets divided into 2 parts sorted and unsorted time complexity O(n^2)
        print("Current List is ", end=" ")
        printList(self.__arr)
        self.__insertionSortList = self.__arr.copy()
        for j in range(1, self.__length):
            temp = self.__insertionSortList[j]
            self.Insert(temp, j-1) #pass value of j-1 to compare

            print("Insert operation")
            print(self.__insertionSortList)

        print("\nSorted List using insertion sort", end=" ")
        printList(self.__insertionSortList)

    def Insert(self, temp, i): #This is code to insert elements before the jth index in the consideration
        while(temp<self.__insertionSortList[i] and i>=0):  #Here i>=0 is the last condition of the check
            self.__insertionSortList[i+1] = self.__insertionSortList[i]
            i -=1
        self.__insertionSortList[i+1] = temp
    

    def shellSort(self):
        print("Current List is ", end=" ")
        printList(self.__arr) 
        self.__shellSortList = self.__arr.copy()
        n = self.__length
        gap = n//2
        while gap > 0:  # loop(i = n/2; 0; i/=2)
            j = gap
            while j < n: #loop(j = gap; j<n; j++)
                i = j - gap
                while i>=0: #loop(i= j-gap; i>=0; i-=gap) 
                    #This is to check say if gap is 2 then it will check for each gap previous values also
                    if self.__shellSortList[i] > self.__shellSortList[i+gap]:
                        switch(i+gap, i, self.__shellSortList)
                        i = i-gap
                    else:
                        i = i-gap
                        break
                    # print("After operation:", end= " ")
                    # print(self.__shellSortList)
                j +=1
            gap = gap//2

            print("Pass")
            print(self.__shellSortList)

        print("\nSorted List using shell sort", end=" ")
        printList(self.__shellSortList)

        print("\nTop 5 in ascending order")
        print(self.__shellSortList[-5:])
                    

def printList(list1):
        print(list1)

def switch(pos1, pos2, list1):
    temp = list1[pos1]
    list1[pos1] = list1[pos2]
    list1[pos2] = temp


obj = Sorting()
obj.acceptList()

while True:
    print()
    print("*" * 10 + "Menu" + "*" * 10)
    print("""1 . Insertion Sort
2. Shell Sort
3. EXIT """)
    print("*" * 24)
    choice = int(input("Enter your choice for the following operations:"))

    if choice == 1:
        obj.insertionSort()

    elif choice == 2:
        obj.shellSort()

    elif choice == 3:
        print("EXIT")
        break

    else:
        print("Enter valid input")