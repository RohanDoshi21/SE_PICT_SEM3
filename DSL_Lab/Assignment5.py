# Author: Rohan Doshi
# Problem statement Group B - 15
"""
Write a python program to store second year percentage of students in array. Write 
function for sorting array of floating point numbers in ascending order using 
a) Insertion sort 
b) Shell Sort and display top five scores
"""

from numpy.lib.function_base import insert


class Sorting:
    def __init__(self):
        self.__length = 0
        self.__arr = []
        self.__insertionList = []


    def acceptList(self):
        self.__length = int(input("Enter the number of students in the class "))
        for i in range(self.__length):
            temp = int(input(f"Enter the percent of student at {i+1} roll no "))
            self.__arr.append(temp)


    def insertionSort(self):
        print("Current List is ", end=" ")
        printList(self.__arr)
        self.__insertionList = self.__arr.copy()
        for j in range(1, self.__length):
            temp = self.__insertionList[j]
            self.Insert(temp, j-1)

        print("Sorted List using insertion sort", end=" ")
        printList(self.__insertionList)

    def Insert(self, temp, i):
        while(temp<self.__insertionList[i] and i>=0):
            self.__insertionList[i+1] = self.__insertionList[i]
            i -=1
        self.__insertionList[i+1] = temp
    
    # def shellSort(self):


def printList(list1):
        print(list1)

def switch(pos1, pos2, list1):
    temp = list1[pos1]
    list1[pos1] = list1[pos2]
    list1[pos2] = temp


obj = Sorting()
obj.acceptList()
obj.insertionSort()