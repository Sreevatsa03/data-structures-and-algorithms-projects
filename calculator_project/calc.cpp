#ifndef CALC_CPP_
#define CALC_CPP_

#include "calc.h"

using namespace std;


float calc::arithmetic (string s) {
    ans=convert(s).eval();
    return ans;
}

mathNode calc::convert (string s) {
    int para = 0;
    int index=0;
    bool canRem=true;
    if (s.size() == 1) canRem = false;
    string op ="0";
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == ')')
            para++;
        if (s[i] == '(')
            para--;
        if (para != 0)
            continue;
        if (para == 0 && i != 0)
            canRem=false;
        if (s[i]=='+'||s[i]=='-') {
             op=s[i];
             index = i;
             break;
        }
        if ((s[i]=='*'||s[i]=='/')&&(op.compare("*") != 0&&op.compare("/") != 0)) {
             op=s[i];
             index=i;
        }
        else if (((s[i]=='^')&&(op.compare("*") != 0&&op.compare("/") != 0&&op.compare("^") != 0))) {
            op=s[i];
            index=i;
        }
    }
    if (canRem) return convert(s.substr(1,s.size()-2));
    if (s.compare("ans")==0) return mathNode(ans);
    if ((s.substr(0,3).compare("sin") == 0) || (s.substr(0,3).compare("cos") == 0) ||(s.substr(0,3).compare("tan") == 0) ||(s.substr(0,3).compare("cot") == 0) ||(s.substr(0,3).compare("sec") == 0) ||(s.substr(0,3).compare("csc") == 0)) {
        return mathNode(s.substr(0,3),convert(s.substr(4,s.size()-5)));
    }
    if (op.compare("0") == 0) return mathNode(stof(s));
    mathNode o = mathNode(op,convert(s.substr(0,index)),convert(s.substr(index+1,s.size()-index-1)));
    o.bah();
    return o;
}

string calc::linearRegressionLine(vector<double> x, vector<double> y, int n) {
    double a,b;
    string rl;

    double xsum = 0, x2sum = 0, ysum = 0, xysum = 0;
    for (int i = 0; i < n; i++)
    {
        xsum = xsum+x[i];
        ysum = ysum+y[i];
        x2sum = x2sum+pow(x[i],2);
        xysum = xysum+x[i]*y[i];
    }
    a = (n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);
    b = (x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);

    rl = "y = " + to_string(a) + "x + " + to_string(b) ;
    return rl;
}



#endif /* CALC_CPP_ */
