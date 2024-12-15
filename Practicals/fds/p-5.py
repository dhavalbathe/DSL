# Accepting roll number of the students

def accept_roll():
    arr = []
    n = int(input("\nEnter the number of students: "))
    for i in range(n):
        arr.append(int(input("Enter Roll Number of student {0}: ".format(i+1))))

    return arr

# printing the roll numbers of the students

def print_roll(arr):
    for i in range(len(arr)):
        print(arr[i], sep="\n")

# selection sort for sorting the list of roll number

def selection_sort(arr):
    for i in range(len(arr)):

        # find the minimum element in remaining unsorted array
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j
            
        # swap
        arr[i], arr[min_idx] = arr[min_idx], arr[i]


# function for performing non recursive ternary serach

def ternary_search(arr, target):
    left = 0
    right = len(arr)-1

    while left <= right:
        mid1 = left + (right-left) // 3
        mid2 = right - (right-left) //3

        if arr[mid1] == target:
            return mid1
        elif arr[mid2] == target:
            return mid2
        elif target < arr[mid1]:
            right = mid1 - 1
        elif target > arr[mid2]:
            left = mid2 + 1
        else:
            left = mid1 + 1
            right = mid2 - 1
        
    return -1

#main
unsort_roll = []
sort_roll = []
flag = 1
while flag == 1:
    print("\n--------------------MUNU-----------------")
    print("1. Accept Students Roll Number")
    print("2. Display the roll numbers of students")
    print("3. Sort roll number from the list")
    print("4. Perform the ternary search")
    print("5. exit \n")

    ch = int(input("Enter your choice (from 1 to 5): "))

    if ch == 1:
        unsort_roll = accept_roll()
    elif ch == 2:
        print_roll(unsort_roll)
    elif ch == 3:
        print("Elements after perfoming selection sort: \n")
        sort_roll = selection_sort(unsort_roll)
        print_roll(sort_roll)
    elif ch == 4:
        target = int(input("Enter the roll number to be serached: "))
        index = ternary_search(sort_roll, target)
        if index != -1:
            print("The roll number", target, " is found at position", index+1)
        else:
            print("Roll number", target, " nor found!!")
    elif ch == 5:
        print("Thank you for using this program !!")
        flag = 0
    else:
        print("Wrong choice!!")
        flag = 0
        
    
            