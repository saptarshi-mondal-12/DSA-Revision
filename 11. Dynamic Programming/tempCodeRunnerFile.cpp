/* 
    Q. Print the longest common substring.
    Intuition: store the coordinate(i,j) of maximum using dp table. 
    To print the string, move to diagonal only coordinate(i,j) ---> (top left corner side) and then reverse the string.    
    */

    int i = coordinate_x;
    int j = coordinate_y;
    string s = "";
    while (i > 0 && j > 0){
        s+=s2[j-1]; 
        i--;
        j--;
    }
    reverse(s.begin(), s.end());
    cout<<"longest common substring is: "<<s<<endl;
    return ans;