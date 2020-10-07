/*
    Balanced Brackets
    -----------
    Given a sequence of brackets as a string, check if it is balanced.

    Time complexity
    ---------------
    O(N), where N is the length of the string representing a sequence of brackets.

    Space complexity
    ----------------
    O(N)
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){

    string input_string;
    cin>>input_string;
    
    int is_balanced_flag = 1;
    stack<int> open_brackets;

    for(int i=0; input_string[i]!='\0' && is_balanced_flag; i++) {
        if(input_string[i] == '(' || input_string[i] == '[' || input_string[i] == '{' )
            open_brackets.push(input_string[i]);
        else {
            if( (input_string[i] == '}' && !open_brackets.empty() && open_brackets.top()=='{') ||
                (input_string[i] == ']' && !open_brackets.empty() && open_brackets.top()=='[') ||
                (input_string[i] == ')' && !open_brackets.empty() && open_brackets.top()=='(') )
                open_brackets.pop();
            else
                is_balanced_flag=0;
        }
    }
    
    if(is_balanced_flag==0 || !open_brackets.empty())
        cout<<"NO";
    else
        cout<<"YES";
        
    return 0;
}










//Find the number of valid parentheses expressions of given length

//Given a number n find the number of valid parentheses expressions of that length.

//Example:
//Input: 2
//Output: 1 
//There is only possible valid expression of length 2, "()"
//Time Complexity = O(n) Space Complexity = O(1)



#include <bits/stdc++.h> 
using namespace std; 
  
// Returns value of Binomial Coefficient C(n, k) 
unsigned long int binomialCoeff(unsigned int n, 
                                unsigned int k) 
{ 
    unsigned long int res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 
  
// A Binomial coefficient based function to  
// find nth catalan number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
    // Calculate value of 2nCn 
    unsigned long int c = binomialCoeff(2 * n, n); 
  
    // return 2nCn/(n+1) 
    return c / (n + 1); 
} 
  
// Function to find possible ways to put balanced 
// parenthesis in an expression of length n 
unsigned long int findWays(unsigned n) 
{ 
    // If n is odd, not possible to  
    // create any valid parentheses 
    if (n & 1) 
        return 0; 
  
    // Otherwise return n/2'th Catalan Numer 
    return catalan(n / 2); 
} 
  
// Main Function of the program 
int main() 
{ 
    int n ;
    cin>>n;
    cout << "Total possible expressions of length "
         << n << " is " << findWays(6); 
    return 0; 
} 


