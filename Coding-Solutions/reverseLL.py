def reverseList(head):
    prevNode = None
    current_node = head
    nextNode = None

    while current_node != None:
        nextNode = current_node.next
        current_node.next = prevNode
        prevNode = current_node
        current_node = nextNode

    return prevNode