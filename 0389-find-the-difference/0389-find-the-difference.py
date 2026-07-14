class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        mylist = list(s)
        for i in t:
            if i in mylist:
                mylist.remove(i)
            else:
                return i
        