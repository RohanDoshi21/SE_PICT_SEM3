# Author: Rohan Doshi
# Problem statement
"""
Write a Python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix
"""


class Matrix:
    def __init__(self):
        self.matrix = []
        self.rows = 0
        self.columns = 0
        self.acceptMatrix()

    def acceptMatrix(self):
        self.rows = int(input("Enter number of Rows: "))
        self.columns = int(input("Enter number of Columns: "))
        for i in range(self.rows):
            matrix = []
            for j in range(self.columns):
                matrix.append(int(input()))
            self.matrix.append(matrix)


def printMatrix(matrix):
    rows = len(matrix)
    columns = len(matrix[0])
    for i in range(rows):
        for j in range(columns):
            print(matrix[i][j], end=" ")
        print()


def additionMatrix(matrix1, matrix2):
    if matrix1.rows != matrix2.rows or matrix1.columns != matrix2.columns:
        print("Matrices are not suitable for addition")
        return -1

    matrix3 = []
    for i in range(matrix1.rows):
        mat = []
        for j in range(matrix1.columns):
            x = matrix1.matrix[i][j] + matrix2.matrix[i][j]
            mat.append(x)
        matrix3.append(mat)

    return matrix3


def subtractionMatrix(matrix1, matrix2):
    if matrix1.rows != matrix2.rows or matrix1.columns != matrix2.columns:
        print("Matrices are not suitable for subtraction")
        return -1

    matrix3 = []
    for i in range(matrix1.rows):
        mat = []
        for j in range(matrix1.columns):
            x = matrix1.matrix[i][j] - matrix2.matrix[i][j]
            mat.append(x)
        matrix3.append(mat)

    return matrix3


def multiplicationMatrix(matrix1, matrix2):
    if matrix1.rows != matrix2.columns:
        print("Matrices are not suitable for multiplication")
        return -1

    matrix3 = []
    for i in range(matrix1.rows):
        mat = []
        for j in range(matrix2.columns):
            mat.append(0)
        matrix3.append(mat)

    for i in range(matrix1.rows):
        for j in range(matrix2.columns):
            for k in range(matrix2.rows):
                matrix3[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j]

    return matrix3




m1 = Matrix()
m2 = Matrix()

print("*" * 10)
print("Matrix 1")
printMatrix(m1.matrix)
print('*' * 10)
print("Matrix 2")
printMatrix(m2.matrix)
print('*' * 10)

print('*' * 10)
print("Addition")
printMatrix(additionMatrix(m1, m2))

print('*' * 10)
print("Subtraction")
printMatrix(subtractionMatrix(m1, m2))

print('*' * 10)
print("multiplication")
printMatrix(multiplicationMatrix(m1, m2))
