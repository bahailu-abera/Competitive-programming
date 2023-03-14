import array

class MyCircularDeque:

    def __init__(self, k: int):
        self.size = k
        self.deque = array.array('i', [0]*k)
        self.rear = self.front = -1

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.front == -1:
            self.front = self.rear = 0
            self.deque[self.front] = value
        elif self.front == 0:
            self.front = self.size - 1
            self.deque[self.front] = value
        else:
            self.front -= 1
            self.deque[self.front] = value

        return True


    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.rear == -1:
            self.front = self.rear = 0
            self.deque[self.front] = value
            return True
        self.rear = (self.rear + 1) % self.size
        self.deque[self.rear] = value

        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        if self.front == self.rear:
            self.front = self.rear = -1
            return True
        self.front = (self.front + 1) % self.size
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        if self.front == self.rear:
           self.front = self.rear = -1
           return True

        self.rear -= 1
        if self.rear < 0:
            self.rear = self.size - 1
        return True


    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.front]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.rear]

    def isEmpty(self) -> bool:
        if self.front == -1:
            return True
        return False

    def isFull(self) -> bool:
        if self.front == (self.rear + 1) % self.size:
            return True
        return False


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
