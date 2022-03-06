#include<iostream>
#include<string>
#include"mat.hpp"

using namespace std;
namespace ariel {
std::string mat(int columns, int rows, char sym1, char sym2){
    if(columns<0 || rows<0){
        throw invalid_argument("Mat size is always odd");
    }
    if (columns==0 || rows==0){
        throw invalid_argument("Mat size is always odd");
    }
    if (columns%2==0 || rows%2==0){
        throw invalid_argument("Mat size is always odd");
    }
    if(sym1 == ' ' || sym2 == ' ' || sym1 == '\n' || sym2 == '\n'
       || sym1 == '\t' || sym2 == '\t' ||
        sym1 == '\r' || sym2 == '\r'){
        throw invalid_argument("Not valid symbol");
    }
    char carpet[rows][columns];
    int currow = 0;
    int currcol=0;
    int counter = 0 ;
    int lastrow=rows;
    int lastcol=columns;
    int i=0;
    int j=0;
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
    std::string ans;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            if(i==0 && j==0){
                ans=carpet[i][j];
            }
            else{
            ans+=carpet[i][j];
            }
        }
        ans+="\n";
    }
    return ans;
}
}