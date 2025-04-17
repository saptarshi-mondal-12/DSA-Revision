'''
Q. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
    1. bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    2. bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    3. int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
'''
import random
class RandomizedSet:
    def __init__(self):
        self.data=[]
        self.hash={}
        self.currIndex=0
        
    def insert(self, val: int) -> bool:
        if val not in self.hash:
            self.hash[val]=self.currIndex
            self.currIndex+=1
            self.data.append(val)
            return True
        else:
            return False

    def remove(self, val: int) -> bool:
        if val in self.hash:
            index=self.hash[val]
            del self.hash[val]

            if index != self.currIndex-1:
                self.hash[self.data[-1]]=index
                self.data[index]=self.data[-1]
            self.data.pop()
            self.currIndex-=1
            return True 
        else:
            return False
        

    def search(self, val) -> bool:
        return self.hash.get(val, -1)
        

    def getRandom(self) -> int:
        random_index = random.randint(0, self.currIndex - 1)
        return self.data[random_index]


obj = RandomizedSet()
print(obj.insert(1))
print(obj.insert(10))
print(obj.insert(20))
print(obj.search(100))


 