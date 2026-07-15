class Solution:
    def convertDateToBinary(self, date: str) -> str:
        newlist = date.split('-')
        rough = []
        
        for i in newlist:
            # bin(int(i))[2:] removes the "0b" prefix
            rough.append(bin(int(i))[2:])
            
        return "-".join(rough)
