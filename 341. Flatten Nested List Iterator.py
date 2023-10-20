class NestedIterator:
    def __init__(self, nestedList):
        self.stack = []
        self.flatten(nestedList)

    def next(self):
        if self.hasNext():
            return self.stack.pop()

    def hasNext(self):
        return len(self.stack) > 0

    def flatten(self, nestedList):
        for item in reversed(nestedList):
            if item.isInteger():
                self.stack.append(item.getInteger())
            else:
                self.flatten(item.getList())
