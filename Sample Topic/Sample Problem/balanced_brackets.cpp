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
