# function for accepting the percentage of students
def accept_percentage(listofprecentage):
    n = int(input("Enter the number of students: "))
    for i in range(n):
        p = int(input("Enter the percentage of student"+str(i+1)+": "))
        listofprecentage.append(p)
    
# function for displaying the percentage of students

def display_percentage(listofprecentage):
    for i in range(len(listofprecentage)):
        print(listofprecentage[i])
    
# Function for performing partition of data
def percentage_partition(listofprecentage, start, end):
    pivot = listofprecentage[start]
    lower_bound = start + 1
    upper_bound = end

    while True:
        # Find the first element greater than pivot from the left
        while lower_bound <= upper_bound and listofprecentage[lower_bound] <= pivot:
            lower_bound += 1
        
        # Find the first element smaller than pivot from the right
        while lower_bound <= upper_bound and listofprecentage[upper_bound] >= pivot:
            upper_bound -= 1

        if lower_bound <= upper_bound:
            # Swap elements
            listofprecentage[lower_bound], listofprecentage[upper_bound] = listofprecentage[upper_bound], listofprecentage[lower_bound]
        else:
            break

    # Place the pivot in its correct position
    listofprecentage[start], listofprecentage[upper_bound] = listofprecentage[upper_bound], listofprecentage[start]

    return upper_bound

# Function for performing quick sort on the list
def quick_sort(listofprecentage, start, end):
    if start < end:
        # Partition the list
        partition_index = percentage_partition(listofprecentage, start, end)
        
        # Recursively apply quick sort on the left and right sublists
        quick_sort(listofprecentage, start, partition_index - 1)
        quick_sort(listofprecentage, partition_index + 1, end)

    return listofprecentage


# main function

percentage = []

flag = 1
while flag == 1:
    print("\n--------------------MUNU-----------------")
    print("1. Accept the percentage of student")
    print("2. Display the Percentage of students")
    print("3. Perform Quick sort on the data")
    print("4. exit \n")

    ch = int(input("Enter your choice (from 1 to 4) " ))

    if ch == 1:
        accept_percentage(percentage)
        a = input("Do you want of continue (yes/no): ")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program")
        
    elif ch == 2:
        display_percentage(percentage)
        a = input("Do you want of continue (yes/no): ")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program")

    elif ch == 3:
        quick_sort(percentage, 0, len(percentage)-1)
        display_percentage(percentage)
        a = input("Do you want of continue (yes/no): ")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program")
    elif ch == 4:
        print("Thanks for using this program")
        flag = 0
    else:
        print("please enter valid choice")
        flag = 0
        print("Thanks for usign this program")
