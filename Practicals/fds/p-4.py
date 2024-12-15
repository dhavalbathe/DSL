#A function to generate odd sized magic square

def generate_Magic_Square(size):
    magicSquare = [[0 for x in range(size)] for y in range(size)]

    # initializing first position of matrix
    i = size/2
    j = size-1

    # fill the magic square by placing values at apropriate position
    count = 1
    while count <= (size*size):
        if i == -1 and j == size: # 3rd condition
            i = 0
            j = size-2
        else:
            #next number goes out of right side of square
            if j == size:
                j = 0

            #next number goes out of upper side
            if i < 0:
                i = size-1
            
            if magicSquare[int(i)][int(j)]: #2nd condition
                j = j-2
                i = i+1
                continue
            else:
                magicSquare[int(i)][int(j)] = count
                count = count + 1
            
            j = j+1
            i = i-1 # 1st condition

    # printing of magic square
    sum = size*(size*size+1)/2
    print("sum of each row or column is: ", sum)
    print("Magic Square of size", size, "*", size, "is: \n")

    for i in range(0, size):
        for j in range(0, size):
            print('%2d' % (magicSquare[i][j]),end=' | ')

            # to display magic square in matrix form
            if j == size-1:
                print()
    
#---------------------------------------------------------->


#main function
flag = 1
while flag == 1:
    n = int(input("\nEnter the size of the MAGIC SQUARE: "))
    if n%2 == 0:
        s = int(input("Please enter an ODD Number (for example- 1, 3, 5, ...): "))
        generate_Magic_Square(s)
    else:
        generate_Magic_Square(n)
    
    a = input("\nDo you want to print Magic Square of some other size (yes/no): ")
    if a == "yes":
        flag = 1
    else: 
        flag = 0
        print("\nThank you for using this program")