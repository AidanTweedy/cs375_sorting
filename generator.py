import random

def main():
#    print("Length must be a multiple of 10")
    length = int(input("How long do you want the test string? "))
    print("yy is yes, n is no(random), yk is kinda, r is reversed")
    sort = input("Do you want the string to be sorted? (yy/n/yk/r) ")
    retVal = []
    if(sort[0] == "y"):
        for i in range(length):
            retVal.append(str(i))
        if(sort[1] == "k"):
            percent = float(input("Enter percent sorted (must be decimal): "))
            indexsort = int(length * percent) #this is the amount sort
            print("index sort is " + str(indexsort))
            for i in range(indexsort, len(retVal)):
            #    print("i is " + str(i) + " retval[i] is " + retVal[i])
            #    retVal.replace(str(i),str(random.randrange(indexsort, length)))
                retVal[i] = str(random.randrange(indexsort, length))
    elif(sort == "r"):
        for i in range(length):
            retVal.insert(0, str(i))
    elif(sort == "n"):
        for i in range(length):
            retVal.append(str(random.randrange(length)))
    else:
        print("Something went wrong oopsy")
        return
    testStr = ""
    for i in retVal:
        testStr = testStr + i + ","
    testStr = testStr[:-1]
    print("Your string is " + testStr)

main()
