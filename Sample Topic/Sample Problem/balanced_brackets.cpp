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


//other similar problem code(function code)...
    //using stack
//Evaluate the value of an arithmetic expression in Reverse Polish Notation.

//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
/*Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9*/

int Solution::evalRPN(vector<string> &A) {int n=A.size();stack<int> q;
for(int i=0;i<n;i++){
    if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/"){
        int f=q.top();q.pop();
        int s=q.top();q.pop();
        if(A[i]=="+") q.push(f+s);if(A[i]=="-") q.push(s-f);if(A[i]=="*") q.push(f*s);
        if(A[i]=="/") q.push(s/f);
        
    }
    else q.push(stoi(A[i]));
}
return q.top();
}



    
    
    
    
