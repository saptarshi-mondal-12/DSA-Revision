#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    /*
    *****
    *****
    *****
    *****
    *****
    */
    // Tc - O(n^2) 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<"*";
    //     }
    //     cout<<"\n";
    // }



    /*
    *
    **
    ***
    ****
    *****
    */
    // for(int i=0;i<n;i++){
    //     for (int j=0;j<=i;j++){
    //         cout<<"*";
    //     }
    //     cout<<"\n";
    // }

    /*
    1
    12
    123
    1234
    12345
    */
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<j;
    //     }
    //     cout<<"\n";
    // }

    /*
    1
    22
    333
    4444
    55555
    */
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<i;
    //     }
    //     cout<<"\n";
    // }

    /*
    *****
    ****
    ***
    **
    *
    */

    // for(int i=0;i<n;i++){
    //     for(int j=n-i;j>0;j--){
    //         cout<<"*";
    //     }
    //     cout<<"\n";
    // }

    /*
    12345
    1234
    123
    12
    1
    */
    // for(int i=0;i<n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         cout<<j;
    //     }
    //     cout<<"\n";
    // }

    /*  
        *      [4,1,4]
       ***     [3,3,3]
      *****    [2,5,2]
     *******   [1,7,1]
    *********  [0,9,0]
    */
    // (space,star,space)

    // for(int i=0;i<n;i++){
    //     // space
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     // star
    //     for (int j=0;j<2*i+1;j++){
    //         cout<<"*";
    //     }
    //     // space
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     cout<<"\n";
    // }

    /*
    *********
     *******
      *****
       ***
        *
    */
    
    // for(int i=0;i<n;i++){
    //     // space
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     // star
    //     for (int j=0;j<(2*n-(2*i+1));j++){
    //         cout<<"*";
    //     }
    //     // space
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     cout<<"\n";
    // }

    /*
        *
       ***
      *****
     *******
    *********
     *******
      *****
       ***
        *
    */
    // for(int i=0;i<n;i++){
    //     // space
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     // star
    //     for (int j=0;j<2*i+1;j++){
    //         cout<<"*";
    //     }
    //     // space
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0;i<n;i++){
    //     // space
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     // star
    //     for (int j=0;j<(2*n-(2*i+1));j++){
    //         cout<<"*";
    //     }
    //     // space
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     cout<<"\n";
    // }


    /*
    *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *
    */

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=n-i-1;j>0;j--){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    /*
    1
    0 1
    1 0 1
    0 1 0 1
    1 0 1 0 1
    */
//     int flag=1;
//     for(int i=0;i<n;i++){
//         if(flag==1){
//             int f=1;
//             for(int j=0;j<i+1;j++){
//                 if(f==0){
//                     cout<<"0 ";
//                     f=1;
//                 }else{
//                     cout<<"1 ";
//                     f=0;
//                 }
//             }
//             flag=0;

//         }else{
//             int f=0;
//             for(int j=0;j<i+1;j++){
//                 if(f==0){
//                     cout<<"0 ";
//                     f=1;
//                 }else{
//                     cout<<"1 ";
//                     f=0;
//                 }
//             }
//             flag=1;
//         }
//         cout<<"\n";    
//    }

/*
1        1
12      21
123    321
1234  4321
1234554321
*/
// [number,space,number]

// int space=2*(n-1);
// for(int i=1;i<=n;i++){
//     // number
//     for(int j=1;j<=i;j++){
//         cout<<j;
//     }
//     // space
//     for(int j=1;j<=space;j++){
//         cout<<" ";
//     }
//     // number
//     for(int j=i;j>=1;j--){
//         cout<<j;
//     }
//     cout<<"\n";
//     space-=2;
// }

/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
// int p=1;
// for(int i=1;i<=n;i++){
//     for(int j=0;j<i;j++){
//         cout<<p<<" ";
//         p+=1;
//     }
//     cout<<"\n";
// }

/*
A
AB
ABC
ABCD
ABCDE
*/

// char s = 'A';
// for(int i=1;i<=n;i++){
//     for(int j=0;j<i;j++){
//         cout<<s;
//         s++;
//     }
//     s='A';
//     cout<<"\n";
// }

/*
A
BB
CCC
DDDD
EEEEE
*/

// char s = 'A';
// for(int i=1;i<=n;i++){
//     for(int j=0;j<i;j++){
//         cout<<s;
//     }
//     s++;
//     cout<<"\n";
// }


/*
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDBCA
*/

    
    // for(int i=0;i<n;i++){
    //     // space
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     // character
    //     char ch='A';
    //     int breakpoint=(2*i+1)/2;
    //     for(int j=1;j<=2*i+1;j++){ 
    //         cout<<ch;
    //         if (j<=breakpoint) ch++;
    //         else ch--;
    //     }
    //     // space
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }

    //     cout<<"\n";
    // }

/*
E
D E
C D E
B C D E
A B C D E
*/
// int s=64+n;
// for(int i=0;i<n;i++){
//     char c = char(s);
//     for(int j=0;j<i+1;j++){
//         cout<<c;
//         c++;
//     }
//     s-=1;
//     cout<<"\n"; 
// }

/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/  
// int k=n/2;
// int space=0;
// int flag=0;
// for(int i=0;i<n;i++){
    
//     if (flag==0){
//         for(int j=0;j<k;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<space;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<k;j++){
//             cout<<"*";
//         }
//         cout<<"\n";
//         k-=1;
//         space+=2;
//         if (i+2>n/2){
//             k=1;
//             flag=1;
//             space-=2;
//         }
//     }else{
//         for(int j=0;j<k;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<space;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<k;j++){
//             cout<<"*";
//         }
//         cout<<"\n";
//         k+=1;
//         space-=2;
//     }
// }

}
