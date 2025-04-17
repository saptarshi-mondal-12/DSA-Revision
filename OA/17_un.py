'''
Divide Intervals Into Minimum Number of Groups

You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.
Return the minimum number of groups you need to make.
Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
'''


class Solution:

    def brute_smallestRange(self, intervals):
        # Time complexity: O(n log n) + O(n^2)
        # Space complexity: O()

        intervals.sort()
        result=[intervals[0]]

        for arrival, departure in intervals[1:]:
            flag=0
            for i in range(0, len(result)):
                prevArr=result[i][0]
                prevDep=result[i][1]
                if arrival > prevDep:
                    result[i][0]=arrival
                    result[i][1]=departure 
                    flag=1
                    break
            if flag==0:
                result+=[[arrival, departure]]
        return len(result)


    def optimal_smallestRange(self, intervals):
        # Time complexity: O(n)
        # Space complexity: O(n)

        n=len(intervals)
        arrival=[]
        departure=[]
        for a, d in intervals:
            arrival.append(a)
            departure.append(d)
        arrival.sort()
        departure.sort()
        i=0
        j=0
        result=1
        group=0
        while i < n:
            if arrival[i] <= departure[j]:
                group+=1 
                i+=1
            else:
                group-=1
                j+=1
            result=max(result, group)
        return result

        
    
    
soln = Solution()
intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]

# brute
result=soln.brute_smallestRange(intervals)
print(result)

# optimal
# result=soln.optimal_smallestRange(intervals)
# print(result)