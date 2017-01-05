from linked_list import *

    ########################
    #  SIMPLE LINKED LIST  #
    #        Tests         #
    ########################
print("SIMPLE LINKED LISTS:")
print("\n")

#Test1 - Inserting test

# Create,read elements from file and test insertStart() function

list1 = SimpleList()
test1 = open("test.txt", 'r')

print("TEST 1 - INSERTING TEST")
print("\n")


for line in test1:
    list1.insertStart(int(line.rstrip()))
test1.close()

print("LIST 1:")
print("\n")

list1.display()
list1.elements()

# Create, read elements from file and test insertEnd() function

test1 = open("test1.txt", 'r')
list2 = SimpleList()

for line in test1:
    list2.insertEnd(int(line.rstrip()))
test1.close()

print("LIST 2:")
print("\n")

list2.display()
list2.elements()

# Test 2 - Delete and Insert at given position

print("TEST 2 - Delete and Insert at given position")
print("\n")

# Add at given position test

addPoz = open("addPoz.txt", 'r')
for line in addPoz:
    buffer = line.split(' ')

    poz = int(buffer[0])
    value = int(buffer[1])

    list1.addPoz(poz,value)


list1.display()
list1.elements()

# Delete at given position test

deletePoz = open("deletePoz.txt", 'r')
for line in deletePoz:

    poz = int(line.rstrip())

    list1.removePoz(poz)


list1.display()
list1.elements()


# Test 3 - Merging two lists
print("TEST 3 - MERGING TWO LISTS")
print("\n")
merge_simple_lists(list1.head, list2.head)
list1.display()
print("\n")
print("\n")
    ########################
    #  DOUBLE LINKED LIST  #
    #        Tests         #
    ########################

print("DOUBLE LINKED LISTS:")
print("\n")

#Test1 - Inserting test
print("TEST 1 - INSERTING TEST")
print()
# Create,read elements from file and test insertStart() function

list3 = DoubleList()
test1 = open("test.txt", 'r')

for line in test1:
    list3.insertStart(int(line.rstrip()))
test1.close()

print("LIST 1:")
print("\n")
list3.display()
print("LIST 1 de la sfarsit:")
print("\n")
list3.display_backward()
list3.elements()

# Create, read elements from file and test insertEbd() function

test1 = open("test1.txt", 'r')
list4 = DoubleList()

for line in test1:
    list4.insertEnd(int(line.rstrip()))
test1.close()
print("LIST 2:")
print("\n")
list4.display()
print("LIST 2 de la sfarsit:")
print("\n")
list4.display_backward()
list4.elements()

# Test 2 - Delete and Insert at given position

# Add at given position test
print("TEST 2 - Delete and Insert at given position")
print("\n")
addPoz = open("addPoz.txt", 'r')
for line in addPoz:
    buffer = line.split(' ')

    poz = int(buffer[0])
    value = int(buffer[1])

    list3.addPoz(poz,value)

addPoz.close()
list3.display()
list3.elements()

# Delete at given position test

deletePoz = open("deletePoz.txt", 'r')
for line in deletePoz:

    poz = int(line.rstrip())

    list3.removePoz(poz)

deletePoz.close()

list3.display()
list3.elements()


# Test 3 - Merging two lists
print("TEST 3 - MERGING TWO LISTS")
print("\n")
merge_double_lists(list3.head, list4.head)
list3.display()
