# Balanced Brackets

### Problem Description

Given strings of brackets, determine whether each sequence of brackets is balanced. A sequence of brackets is considered to be _balanced_ if the following conditions are met:

*   It contains no unmatched brackets.
*   The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.


Two brackets are considered to be a _matched pair_ if the an opening bracket (i.e., `(`, `[`, or `{`) occurs to the left of a closing bracket (i.e., `)`, `]`, or `}`) _of the exact same type_. There are three types of matched pairs of brackets: `[]`, `{}`, and `()`.

#### Input Format
* Input file consists of a single string, s, denoting a sequence of brackets.

#### Output Format
* If the brackets are _balanced_, print `YES`; otherwise, print `NO`.

#### Example

    Input : {[(])}

    Output : NO

    Explanation : The string `{[(])}` is not balanced, because the brackets enclosed by the matched pairs `[(]` and `(])` are not balanced.
