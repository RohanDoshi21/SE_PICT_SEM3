# Author: Rohan Doshi
# Problem statement
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

def checkValidRollno(x , listInput):
    if listInput == rollNoList :
        for j in range(len(listInput)):
            if (x == listInput[j]):
                print("The roll no is aldreay present in the list")
                print("Please re-enter the roll no")
                inputRollNo = int(input())
                return checkValidRollno(inputRollNo, listInput)
            
        return x

    else:
        for j in range(len(rollNoList)):
            if (x == rollNoList[j]):
                for k in range(len(listInput)):
                    if (x == listInput[k]):
                        print("The roll no is aldreay present in the list")
                        print("Please re-enter the roll no")
                        inputRollNo = int(input())
                        return checkValidRollno(inputRollNo, listInput)

                return x

        print("This roll no is not present in the class")
        tempRollno = int(input("Enter valid roll no"))
        return checkValidRollno(tempRollno, listInput)
        # for k in range(len(listInput)):
        #     if (x == listInput[k]):
        #         print("The roll no is aldreay present in the list")
        #         print("Please re-enter the roll no")
        #         inputRollNo = int(input())
        #         return checkValidRollno(inputRollNo, listInput)
        # return x


def listgenerator(listInput):
    noOfStudents = int(input("Enter no of students "))
    if listInput != rollNoList:
        while noOfStudents > len(rollNoList):
            print("No of students cannot be greater than the Class strength")
            noOfStudents = int(input("Enter no of students "))
    print("Enter roll no of students")
    for i in range(noOfStudents):
        x = int(input())
        validNo = checkValidRollno(x , listInput)
        listInput.append(validNo)



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


