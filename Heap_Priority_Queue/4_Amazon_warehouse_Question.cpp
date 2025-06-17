#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Q. Amazon Warehouses Team uses a software to sort all the incoming online orders based on their priority and stores the information in a database.
This information is made available to the packaging system which continuously picks the order with the highest priority and packages it for delivery.

The OrderSortingService has the following functional requirements:

Support adding new orders continuously coming in from amazon.com.
Support getting the order with the highest priority.
Store the incoming orders.*/

class SortingOrderService{
    private: 
    // Max-heap: (priority, orderID)
    priority_queue<pair<int, int>> orderList;

    // Map: orderID -> Order Details
    unordered_map<int, vector<string>> orderDB;

    public:

    // Receive incomming orders
    void incommingNewOrders(int orderID, int PriorityNo, string CustomerName, string address, string MobileNo, string OrderDate){
        // Time complexity: O(log n) - per insertion 
        // space complexity: O(n) for n orders.
        
        // Store all fields as string
        vector<string> details = {to_string(orderID), to_string(PriorityNo), CustomerName, address, MobileNo, OrderDate};
        
        // store order details in the database
        orderDB[orderID] = details;
        orderList.push({PriorityNo, orderID});
    }

    // Get the highest priority order
    int processOrder(){
        if (orderList.empty()) {
            cout << "No orders in queue.\n";
            return -1;
        }

        int orderID=orderList.top().second;

        // remove from orderList
        orderList.pop();

        // Removing orderID/ orderDetails from order processing database
        orderDB.erase(orderID);
        return orderID;
    }
};

int main(){

    SortingOrderService amazon;
    amazon.incommingNewOrders(1, 5, "Saptarshi", "Bilaspur", "9999998756", "12:6:2025");
    amazon.incommingNewOrders(2, 1, "Saptarshi", "Bilaspur", "9999998756", "12:6:2025");
    amazon.incommingNewOrders(3, 12, "Saptarshi", "Bilaspur", "9999998756", "12:6:2025");
    amazon.incommingNewOrders(4, 10, "Saptarshi", "Bilaspur", "9999998756", "12:6:2025");

    cout<<"OrderID: "<<amazon.processOrder()<<" Process complete"<<endl; // 3
    cout<<"OrderID: "<<amazon.processOrder()<<" Process complete"<<endl; // 4
    cout<<"OrderID: "<<amazon.processOrder()<<" Process complete"<<endl; // 1
}


