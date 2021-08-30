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

rollNoList = []
cricketList =[]
badmintonList = []
footballList =[]

def checkValidRollNo(x , listInput):
    """Checks for the unique roll and if number is present in the master roll no list

    Args:
        x (int): Roll no 
        listInput (list): List to be appended with roll no

    Returns:
        [int]: [Valid roll no]
    """
    if listInput == rollNoList :
        for j in range(len(listInput)):
            if (x == listInput[j]):
                print("The roll no is already present in the list")
                print("Please re-enter the roll no")
                inputRollNo = int(input())
                return checkValidRollNo(inputRollNo, listInput)
            
        return x

    else:
        for j in range(len(rollNoList)):
            if (x == rollNoList[j]):
                for k in range(len(listInput)):
                    if (x == listInput[k]):
                        print("The roll no is already present in the list")
                        print("Please re-enter the roll no")
                        inputRollNo = int(input())
                        return checkValidRollNo(inputRollNo, listInput)

                return x

        print("This roll no is not present in the class")
        tempRollNo = int(input("Enter valid roll no"))
        return checkValidRollNo(tempRollNo, listInput)
        # for k in range(len(listInput)):
        #     if (x == listInput[k]):
        #         print("The roll no is already present in the list")
        #         print("Please re-enter the roll no")
        #         inputRollNo = int(input())
        #         return checkValidRollNo(inputRollNo, listInput)
        # return x


def listgenerator(listInput):
    """This is a function which generates a valid list for the required sets accepting unique roll nos

    Args:
        listInput (List): Class list/Sports list which will save the unique roll no
    """
    noOfStudents = int(input("Enter no of students "))
    if listInput != rollNoList:
        while noOfStudents > len(rollNoList):
            print("No of students cannot be greater than the Class strength")
            noOfStudents = int(input("Enter no of students "))
    print("Enter roll no of students")
    for i in range(noOfStudents):
        x = int(input())
        validNo = checkValidRollNo(x , listInput)
        listInput.append(validNo)

CricketandBadmintonList = []
def bothCricketandBadminton():
    for i in rollNoList:
        if i in cricketList and i in badmintonList:
                CricketandBadmintonList.append(i)
        elif i in cricketList and i not in badmintonList:
                CricketandBadmintonList.append(i)
        elif i in badmintonList and i not in cricketList:
                CricketandBadmintonList.append(i)


CricketOrBadmintonList =[]
def CricketOrBadminton():
    for i in rollNoList:
        if i in cricketList and i in badmintonList:
                continue
        elif i in cricketList and i not in badmintonList:
                CricketOrBadmintonList.append(i)
        elif i in badmintonList and i not in cricketList:
                CricketOrBadmintonList.append(i)

NorCricketOrBadmintonList =[]
def NorCricketOrBadminton():
    for i in rollNoList:
        if i not in cricketList and i not in badmintonList:
            NorCricketOrBadmintonList.append(i)

CricketFootballnotBadmintonList =[]
def CricketFootballnotBadminton():
    for i in rollNoList:
        if i in cricketList and i not in badmintonList and i in footballList:
            CricketFootballnotBadmintonList.append(i)


print("Enter data for the total class")
listgenerator(rollNoList)
# print(rollNoList)

print("*"*15)
print("Enter data for Cricket")
listgenerator(cricketList)
# print(cricketList)

print("*"*15)
print("Enter data for Badminton")
listgenerator(badmintonList)

print("*"*15)
print("Enter data for Football")
listgenerator(footballList)


bothCricketandBadminton()
print("List of roll no of students playing both cricket and badminton")
print(CricketandBadmintonList)

CricketOrBadminton()
print("List of roll no of students who either play cricket or badminton but not both")
print(CricketOrBadmintonList)

NorCricketOrBadminton()
print("No of student that neither play cricket nor badminton = ", NorCricketOrBadmintonList)

CricketFootballnotBadminton()
print("No of student that play cricket, football but not badminton = ", CricketFootballnotBadmintonList)