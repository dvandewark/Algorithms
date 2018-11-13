import time

#given a (sorted) list and a target number, recursivley finds
def binarySearch(lst, target):
   indx = int(len(lst)/2)
   testNum = lst[indx]
   if (indx == 0 and testNum != target):
      return "Number not in list"
   if (testNum == target):
      msg = "" +str(target) +" was found"
      return msg
   elif (testNum > target):
      return binarySearch(lst[:indx], target)
   elif (testNum < target):
      return binarySearch(lst[indx:], target)
      

#the list to be searhced on
input = []
for i in range(0,999999):
   input.append(i)

#the method call with a number to be searhced for
#time taken by algorithm is also calculated
t1 = time.time()
result = binarySearch(input, 750000)
t2 = time.time()
print(result +" taking " +str(t2-t1) +" seconds")