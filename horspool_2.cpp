#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int BMH(string text,string pattern)
{
    int p = pattern.size();           //Getting the size of pattern
    int t = text.size();              //Getting size of text
     if (p>t)       
        return -1;           //If pattern is longer than text, pattern is not in text

    int table[128];           //Create a table with 128 size since ASCII code have 128 characters

    for(int i=0;i<128;i++)
        table[i] = p;                //Initialise all elements of table to size of pattern

    for(int j=0;j<p-1;j++)
    {
        table[int(pattern[j])] = p-j-1;           //For the elements that are present in pattern change table value using the formula
    }


    int k = p-1;

    while(k<t)             //While the length of pattern-1 is less than text length (p-1) so as to match indices, starts from 0
    {
        int j = p-1;
        int i = k;

        while((j>=0) && (text[i] == pattern[j]))       //Matching the rightmost character of patter to respective char in text and breakout if j is -1
        {
            j--;
            i--;
        }
        if(j == -1)
            return i+1;        //Returning the index
        
        k+=table[int(text[k])];             //Updating the index for text to search for, using the bad match table
    }

    return -1;


}


int main()
{
    string text;
    cout<<"Enter the text : ";
    cin>>text;
    string pattern;
    cout<<"Enter the pattern to be searched: ";
    cin>>pattern;
    int flag = BMH(text,pattern);
    if(flag == -1)
        cout<<"String not Found!!";
    else    
        cout<<"Pattern found from index "<<flag;
    return 0;
}