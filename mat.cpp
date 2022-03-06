#include<iostream>
#include<string>
#include"mat.hpp"

using namespace std;
namespace ariel {
std::string mat(int columns, int rows, char sym1, char sym2){
    if(columns<0 || rows<0){
        throw invalid_argument("Mat size is always odd");
    }
    else if (columns==0 || rows==0)
    {
        throw invalid_argument("Mat size is always odd");
    }
    else if (columns%2==0 || rows%2==0)
    {
        throw invalid_argument("Mat size is always odd");
    }
    char carpet[rows][columns];
    int currow = 0, currcol=0, counter = 0 ,lastrow=rows, lastcol=columns, i, j;
    char currsym=sym1;
    while(counter < rows*columns){
        if(counter > 0){
            if(currsym == sym1){
                currsym = sym2;
            }
            else{
                currsym = sym1;
            }
        }
        for(i=currcol;i<lastcol;i++){
            carpet[currow][i] = currsym;
            counter++;
        }
        for(i=currow+1;i<lastrow;i++){
            carpet[i][lastcol-1] = currsym;
            counter++;
        }
        for(i=lastcol-2;i>=currcol;i--){
            carpet[lastrow-1][i] = currsym;
            counter++;
        }
        for(i=lastrow-2;i>currow;i--){
            carpet[i][currcol] = currsym;
            counter++;
        }
        currow++, currcol++, lastcol--, lastrow--;
    }
    string ans = "";
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            ans+=carpet[i][j];
        }
        ans+="\n";
    }
    return ans;
}
}