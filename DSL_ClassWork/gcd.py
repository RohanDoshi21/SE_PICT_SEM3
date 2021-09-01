def gcd(x,y):
     
    # Everything divides 0
    if (x == 0):
        return y
    elif (y == 0):
        return x
    elif (x == y):
        return x
    elif (x > y):
        return gcd(x-y, y)
    return gcd(x, y-x)


print(gcd(10,15))