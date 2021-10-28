# Author: Rohan Doshi
# Problem statement Group B - 15
"""
Write a python program to store first year percentage of students in array. Write function 
for sorting array of floating point numbers in ascending order using quick sort and display 
top five scores
"""


class Quicksort:
    def __init__(self):
        self.__list = []
        self.length = 0
        self.acceptList()
        print("\nList before sorting")
        self.printList()
        self.quick_sort(0, len(self.__list)-1)
        print("\nList after sorting")
        self.printList()
        self.top5()

    def acceptList(self):
        print("Keep on entering the students percentage in the list if you wish to break press -1")
        inputVar = 0.0
        counter = 0
        while(True):
            inputVar = float(
                input(f"Enter the percent of student at roll no {counter+1} "))
            if inputVar == -1:
                if counter > 4:
                    break
                else:
                    print("Enter at least 5 elements")
                    print(f"Number of students currently {counter}")
            while (inputVar < 0 or inputVar > 100):
                inputVar = float(input("Enter in valid range ie 0 to 100 "))
            counter += 1
            self.__list.append(inputVar)
        self.length = counter

    def swap(self, pos1, pos2):
        temp = self.__list[pos1]
        self.__list[pos1] = self.__list[pos2]
        self.__list[pos2] = temp

    def quick_sort(self, low, high):
        _low = low
        _high = high
        if low < high:
            pivotIndex = _low
            pivotElement = self.__list[_low]
            while _low < _high:
                while _low < len(self.__list) and self.__list[_low] <= pivotElement:
                    _low += 1
                while self.__list[_high] > pivotElement:
                    _high -= 1
                if _low < _high:
                    self.swap(_low, _high)
            self.swap(_high, pivotIndex)
            print("List after partition ", self.__list)

            partionioningIndex = _high
            self.quick_sort(low, partionioningIndex-1)
            self.quick_sort(partionioningIndex+1, high)

    def printList(self):
        print(self.__list)

    def top5(self):
        count = 1
        iterator = -1
        print("\n***TOP SCORES in the Class***")
        while iterator != -6:
            if (len(self.__list) >= count):
                print(
                    f"The score at position {count} = ", self.__list[iterator])
                count = count + 1
                iterator = iterator - 1
            else:
                break


obj = Quicksort()
