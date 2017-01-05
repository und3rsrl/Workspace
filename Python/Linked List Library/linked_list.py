
    ########################
    #  SIMPLE LINKED LIST  #
    ########################


class NodeSimple(object):
    """
        This is a simple node for a simple linked list.
    """
    def __init__(self, data):
        """
            This function initialize the node.
        """
        self.data = data
        self.next = None



class SimpleList(object):

    def __init__(self):
        """
            This function initialize the head of a simple linked list.
        """
        self.head = None
        self.count = 0

    def display(self):
        """
            This function displays to console the elements of a simple linked list. As parameter receives the head of the list.
        """
        current = self.head
        iter = 0
        if(current != None):
            print("Elementele listei sunt:")
            while current is not None:
                iter += 1
                print("%d. " % iter + "%d" % current.data)
                current = current.next
        else:
            print("Lista este goala.")

    def insertStart(self, data):
        """
            This function insert a given value at first position of the list.
            As parameters it receives the head of the list and the value to be added.
        """
        self.count += 1
        newNode = NodeSimple(data)

        if not self.head:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode

    def insertEnd(self, data):
        """
            This function insert a given value at last position of the list.
            As parameters it receives the head of the list and the value to be added.
        """
        self.count += 1

        if self.head is None:
            self.insertStart(data);
            return;

        newNode = NodeSimple(data)
        current = self.head

        while current.next is not None:
            current = current.next

        current.next = newNode

    def addPoz(self, poz, data):
        """
            This function insert a given value at the given position of the list.
            As parameters it receives the head of the list, the value to be added and the position where to be added the value.
        """
        iter = 1
        current = self.head

        print("Valoarea %d" % data + "a fost adaugata la pozitia %d" % poz)

        if(poz == 1):
            self.insertStart(data)
        elif(poz == self.count):
            self.insertEnd(data)
        else:
            while(iter != poz - 1):
                current = current.next
                iter += 1

            newNode = NodeSimple(data)
            newNode.next = current.next
            current.next = newNode

        self.count += 1
    def removePoz(self, poz):
        """
            This function removes a value the given position of the list.
            As parameters it receives the head of the list and the position where we delete the value.
        """
        iter = 0
        current = self.head

        if(poz == 0):
            self.head = current.next
            print(current.data)
            self.count -= 1
        elif(poz > self.count):
            print("Nu se poate executa operatia.")
        else:
            while(iter < poz - 2):
                current = current.next
                iter += 1

            print(current.next.data)
            current.next = current.next.next
            self.count -= 1


    def elements(self):
        """
            This function displays the number of elements of a list.
            As parameters it receives the head of the list.
        """
        print("Lista contine %d" % (self.count - 1) + " elemente.")


def merge_simple_lists(head1, head2):
    """
        This function merges two simple linked lists.
        As parameters it receives the heads of the lists to be merged.
    """
    if head1 is None:
        return head2
    if head2 is None:
        return head1

    current = head1
    while current.next != None:
        current = current.next

    current.next = head2

    return head1




    ########################
    #  DOUBLE LINKED LIST  #
    ########################


class NodeDouble(object):
    """
        This is a double node for a double linked list.
    """
    def __init__(self, data):
        """
            This function initialize the node.
        """
        self.data = data
        self.prev = None
        self.next = None

class DoubleList(object):
    def __init__(self):
        """
            This function initialize the head of a simple linked list.
        """
        self.head = None
        self.count = 0

    def insertStart(self, data):
        """
            This function insert a given value at first position of the list.
            As parameters it receives the head of the list and the value to be added.
        """
        self.count += 1
        newNode = NodeDouble(data)

        if self.head == None:
            self.head = newNode
        else:
            newNode.next = self.head
            newNode.next.prev = newNode
            self.head = newNode

    def insertEnd(self, data):
        """
            This function insert a given value at last position of the list.
            As parameters it receives the head of the list and the value to be added.
        """
        self.count += 1

        if self.head is None:
            self.insertStart(data);
            return;

        newNode = NodeDouble(data)
        current = self.head

        while current.next != None:
            current = current.next

        current.next = newNode
        newNode.prev = current

    def addPoz(self, poz, data):
        """
            This function insert a given value at the given position of the list.
            As parameters it receives the head of the list, the value to be added and the position where to be added the value.
        """
        iter = 1
        current = self.head

        self.count += 1

        if (poz == 1):
            self.insertStart(data)
        elif (poz == self.count + 1):
            self.insertEnd(data)
        else:
            while (iter != poz - 1):
                current = current.next
                iter += 1

            newNode = NodeSimple(data)
            newNode.next = current.next
            newNode.next.prev = newNode
            newNode.prev = current
            current.next = newNode

    def removePoz(self, poz):
        """
            This function removes a value the given position of the list.
            As parameters it receives the head of the list and the position where we delete the value.
        """
        iter = 0
        current = self.head

        if (poz == 0):
            self.head = current.next
            print(current.data)
            self.count -= 1
        elif (poz > self.count):
            print("Nu se poate executa operatia.")
        else:
            while (iter < poz - 2):
                current = current.next
                iter += 1

            print(current.next.data)
            current.next.prev = current
            current.next = current.next.next
            self.count -= 1

    def display(self):
        """
            This function displays to console the elements of a simple linked list. As parameter receives the head of the list.
        """
        current = self.head
        iter = 0

        if(current != None):
            print("Elementele listei sunt:")
            while current != None:
                iter += 1
                print("%d. " % iter + "%d" % current.data)
                current = current.next
        else:
            print("Lista este goala")


    def display_backward(self):
        """
            This function displays to console the elements of a simple linked list from back to begin. As parameter receives the head of the list.
        """
        current = self.head

        while current.next != None:
            current = current.next

        while current.prev != None:
            print("%d" % current.data)
            current = current.prev

    def elements(self):
        """
            This function displays the number of elements of a list.
            As parameters it receives the head of the list.
        """
        print("Lista contine %d" % (self.count - 1) + " elemente.")


def merge_double_lists(head1, head2):
    """
        This function merges two double linked lists.
        As parameters it receives the heads of the lists to be merged.
    """
    if head1 is None:
        return head2
    if head2 is None:
        return head1

    current = head1
    while current.next != None:
        current = current.next

    current.next = head2
    head2.prev = current

    return head1
