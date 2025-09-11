#include<bits/stdc++.h>
using namespace std;

/* Q. Maximum Average Pass Ratio 

There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.


Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485

*/

double calculateGain(int pass, int totalStudent){
    // calculate the gain of adding an extra student
    auto gain = (double)(pass + 1) / (totalStudent + 1) - (double)pass / totalStudent;
    return gain;
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    /* Time complexity: O(k⋅log(n)+n)

        Building the max heap: Inserting each class into the max heap takes O(logn) time per insertion, and since there are n classes, this step takes O(nlogn) time.
        
        Distributing extra students: Each insertion and removal from the max heap takes O(logn) time. Since we perform this operation k⋅ times, this step takes O(k⋅logn) time.

        Calculating the final average pass ratio: This involves iterating through the heap, which takes O(nlogn) time in the worst case.
        Overall, the dominant factor is the initial heap construction and the distribution of extra students, leading to a time complexity of O(klogn+nlogn)=O(k⋅log(n)+n).
    
    Space complexity: O(n)
    
    
    */
    
        // Total no of classes
        int n = classes.size();

        // Max heap to store (-gain, passes, totalStudents)
        priority_queue<pair<double, pair<int,int>>> pq;

        for(int i=0;i<n;i++){
            int pass=classes[i][0];
            int totalStudent=classes[i][1];
            double gain = calculateGain(pass, totalStudent);
            pq.push({gain, {pass, totalStudent}});
        }
        
        // Distribute extra students
        while(extraStudents > 0){
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int totalStudent = top.second.second;

            // Add 1 student
            pass++;
            totalStudent++;

            double gain = calculateGain(pass, totalStudent);
            pq.push({gain, {pass, totalStudent}});

            extraStudents--;
        }

        // Calculate the final average pass ratio
        double totalPassRatio=0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            totalPassRatio += (double)top.second.first / top.second.second;
        }

        cout<<"result: ";
        return totalPassRatio / n;
    }

int main(){
    vector<vector<int>>classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    cout<<maxAverageRatio(classes, extraStudents);
}