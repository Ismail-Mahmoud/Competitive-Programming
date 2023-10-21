# https://leetcode.com/problems/flatten-nested-list-iterator/

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def flatten(lst: [NestedInteger]):
            for x in lst:
                if x.isInteger():
                    yield x.getInteger()
                else:
                    yield from flatten(x.getList())

        self._gen = flatten(nestedList)
        self._next = None
    
    def next(self) -> int:
        if self._next is None:
            return next(self._gen)
        ret, self._next = self._next, None
        return ret
    
    def hasNext(self) -> bool:
        try:
            self._next = self.next()
        except StopIteration:
            return False
        else:
            return True
         

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
