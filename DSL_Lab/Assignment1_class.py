# Author: Rohan Doshi
# Problem statement Group A - 1
"""
In second year computer engineering class, group A student's play cricket, group B 
students play badminton and group C students play football. 
Write a Python program using functions to compute following: 
a) List of students who play both cricket and badminton 
b) List of students who play either cricket or badminton but not both 
c) Number of students who play neither cricket nor badminton 
d) Number of students who play cricket and football but not badminton. 
"""


class Sports:
    def __init__(self):
        self.sportsList = []
        self.listLength = 0
        self.acceptList()

    def acceptList(self):
        """Function that checks for the repeat inputs and 
        creates a list which will have set properties from the data entered
        """
        self.listLength = int(input("Enter the length of the list "))
        for i in range(self.listLength):
            temp = input(f"Enter the element at {i+1} position ")
            while temp in self.sportsList:
                temp = input(
                    f"Element already present in the list\nPlease re-enter the element at {i+1} position ")
            self.sportsList.append(temp)


def union(sport1, sport2):
    """returns union of 2 Lists"""
    unionList = sport1.sportsList.copy()
    for i in range(sport2.listLength):
        if sport2.sportsList[i] not in unionList:
            unionList.append(sport2.sportsList[i])

    return unionList


def intersection(sport1, sport2):
    """returns intersection of 2 Lists"""
    intersectionList = []
    for i in sport1.sportsList:
        if i in sport2.sportsList:
            intersectionList.append(i)

    return intersectionList


def substraction(list1, list2):
    """Substracts 2 lists"""
    substractionList = list1.copy()
    for i in list1:
        if i in list2:
            substractionList.remove(i)

    return substractionList


def unionOfList(list1, list2):
    """returns union of 2 Lists
    """
    unionList = list1.copy()
    for i in range(len(list2)):
        if list2[i] not in unionList:
            unionList.append(list2[i])

    return unionList


print("*"*15)
print("Enter data for Cricket")
cricket = Sports()

print("*"*15)
print("Enter data for football")
football = Sports()

print("*"*15)
print("Enter data for badminton")
badminton = Sports()

print("*"*15)

# cricket_union_badminton = cricket and badminton
print("List of students who play both cricket and badminton = ",
      intersection(cricket, badminton))

# cricket_union_badminton - cricket_intersection_badminton = either cricket or football but not both
print("List of students who play either cricket or badminton but not both",
      substraction(union(cricket, badminton), intersection(cricket, badminton)))

# football - football_Intersection_cricket - football_intersection_badminton = neither badminton nor cricket
print("List of students who play neither cricket nor badminton ",  substraction(substraction(
    football.sportsList, intersection(football, cricket)), intersection(football, badminton)))


# cricket_intersection_football - badminton
print("List of students who play cricket and football but not badminton ", substraction(
    union(cricket, football),  badminton.sportsList))


"""
OUTPUT: 

***************
Enter data for Cricket
Enter the length of the list 3
Enter the element at 1 position Rohan
Enter the element at 2 position Rohit
Enter the element at 3 position Tanmay
***************
Enter data for football
Enter the length of the list 3
Enter the element at 1 position Tanmay
Enter the element at 2 position John
Enter the element at 3 position Tom
***************
Enter data for badminton
Enter the length of the list 4
Enter the element at 1 position Jerry
Enter the element at 2 position John
Enter the element at 3 position Rohan
Enter the element at 4 position Tim
***************
List of students who play both cricket and badminton =  ['Rohan']
List of students who play either cricket or badminton but not both ['Rohit', 'Tanmay', 'Jerry', 'John', 'Tim']
List of students who play neither cricket nor badminton  ['Tom']
List of students who play cricket and football but not badminton  ['Rohit', 'Tanmay', 'Tom']

"""
