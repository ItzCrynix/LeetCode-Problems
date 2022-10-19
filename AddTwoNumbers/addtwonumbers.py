class Node:
    def __init__(self, value, next = None) -> None:
        self.val = value
        self.next = next

class SinglyLinkedList:
    def __init__(self, vals: list) -> None:
        self.start = Node(None)
        self.actual = self.start

        for item in vals:
            if self.actual.val is None:
                self.actual.val = item
            else:
                self.actual.next = Node(item)
                self.actual = self.actual.next
        
        self.actual = self.start
    
    def toNext(self):
        self.actual = self.actual.next
    
    def toStart(self):
        self.actual = self.start

    def value(self):
        return self.actual.val if self.actual is not None else self.actual
        
class Solution:
    def addTwoNumbers(self, l1: SinglyLinkedList, l2: SinglyLinkedList):
        result = []
        addOne = False

        while l1.value() is None or l2.value() is None:
            sum = l1.value() if l1.value() is None else 0 + l2.value() if l2.value() is None else 0 + (1 if addOne else 0)
            if sum > 9:
                addOne = True
                sum = sum - 10
            else:
                addOne = False
            result.append(sum)

            l1.toNext()
            l2.toNext()
        
        return result


solucao = Solution()
print(solucao.addTwoNumbers(SinglyLinkedList([1, 2, 3]), SinglyLinkedList([2, 3])))