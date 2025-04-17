'''
Two Best Non-Overlapping Events

You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Example 1 Diagram
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.


Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
'''

class Solution:
    def maxTwoEvents(self, events):
        #TC= O(N LOG N)
        n=len(events)

        # Step 1: Sort the events by their start time
        events.sort(key=lambda x: x[0])

        # Step 2: Create the valueMax array for the maximum event value from each event onward
        valueMax=[0]*n
        valueMax[n-1]=events[n-1][2]
        
        # Populate the valueMax array
        for i in range(n-2, -1, -1):
            valueMax[i]=max(events[i][2], valueMax[i+1])

        result=0

        # Step 3: For each event, find the next event that starts after it ends
        for i in range(0,n):
            left=i+1
            right=n-1 
            index=-1

            # Perform binary search to find the next non-overlapping event
            while left <= right:
                mid=(left+right)//2

                if events[i][1] < events[mid][0]:
                    index=mid
                    right=mid-1
                else:
                    left=mid+1

            # If a valid next event is found, update the max sum
            if index != -1:
                result=max(result,  events[i][2]+valueMax[index])

            # Also consider the case where we take only the current event
            result=max(result, events[i][2])

        return result


        # Time complexity - O(N^2)
        # n=len(events)
        # events.sort()
        # result=0
        # for i in range(0,n):
        #     start_1=events[i][0]
        #     end_1=events[i][1]
        #     value_1=events[i][2]
        #     result=max(result, value_1)
        #     for j in range(i+1, n):
        #         start_2=events[j][0]
        #         end_2=events[j][1]
        #         value_2=events[j][2]
        #         if end_1 < start_2:
        #             result=max(result, value_1+value_2)
        # return result   