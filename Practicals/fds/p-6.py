# Function for Selection Sort of elements

def Selection_Sort(marks):
    for i in range(len(marks)):
        # find the min element in the remaining array

        min_idx = i
        for j in range(i+1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j

        marks[i], marks[min_idx] = marks[min_idx], marks[i]

    
    print("Marks of students after performing Selection Sort on the list: ")
    for i in range(len(marks)):
        print(marks[i])

# Function for Bubble Sort of elements

def Bubble_Sort(marks):
    n = len(marks)

    for i in range(n-1):
        for j in range(0, n-i-1):
            if marks[j] > marks[j+1]:
                marks[j], marks[j+1] = marks[j+1], marks[j]

    print("Marks of student after performing Bubble sort on the list: ")
    for i in range(marks):
        print(marks[i])


# Function for displaying top marks

def top_five_marks(makrs):
    print("Top", len(marks),"Marks are: ")
    print(*marks[::-1], sep="\n")

# Main funtion

marks = []

n = int(input("Enter number of students whose makrs are to be displayed: "))
print("Enter marks for", n, " student (Press ENTER after every students marks): ")
for i in range(0, n):
    ele = int(input())
    marks.append(ele)

print("The marks of", n, " students are: ")
print(marks)

flag = 1
while flag == 1:
    print("\n\n----------------------------MENU------------------------")
    print("1. Selection Sort of the Marks")
    print("2. Bubble Sort of the marks")
    print("3. Exit")
    ch = int(input("Enter you choice (from 1 to 3): "))

    if ch == 1:
        Selection_Sort(marks)
        a = input("\nDo you want to display top marks from the list (yes/no): ")
        if a == "yes":
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag = 0
    
    elif ch == 2:
        Bubble_Sort(marks)
        a = input("\nDo you want to display top marks from the list (yes/no): ")
        if a == "yes":
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag = 0

    elif ch == 3:
        print("\nThanks for using this program")
        flag = 0

    else:
        print("\nEnter  a valid choice!!")
        print("\nThanks for using this program!!")
        flag = 0
