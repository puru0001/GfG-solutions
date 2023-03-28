#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    string convertToWords(long n) {
        // code here
        int l=0,g=0;
       stack<int> st;
       while(n!=0)
        {
            st.push(n%10);
            n=n/10;
            l++;
         }
          if(l>2) g++;
          string s;
          
      if(l%2==0&&l>3) {
         int a=st.top();
         simp(s,a);
         if(l==8) cror(s);
         if(l==6) lakh(s);
         if(l==4) tho(s);
         st.pop();
         l--;
         }
         
      if(l==3){
          int a=st.top();
          simp(s,a);
          if(a!=0) hun(s);
          st.pop();
          l--;
         }
      
      while(l>3){
          int a=st.top();
          st.pop();
          int b=st.top();
          st.pop();
            if(a<2){ 
              int c=a*10+b;
                 if(c==10){
                 s=s+"ten ";
                 if(l==8||l==9) cror(s);
                 if(l==6||l==7)  lakh(s);
                 if(l==4||l==5)  tho(s);
                 }
                 if(c!=10) simp(s,c);
                 if(l==8||l==9&&(b!=0)) cror(s);
                 if(l==6||l==7&&(b!=0))  lakh(s);
                 if(l==4||l==5&&(b!=0))  tho(s);
          }
          else{
                bas(s,a);
                simp(s,b);
                if(l==8||l==9) cror(s);
                if(l==6||l==7)  lakh(s);
                if(l==4||l==5)  tho(s);
          }
          l=l-2;
         }
      if(l==3){
          int a=st.top();
          simp(s,a);
          if(a!=0) hun(s);
          st.pop();
          l--;
      }
      if(l<3&&l>0){
          int a=st.top();
          st.pop();
          l--;
         if(st.size()==0){ 
             simp(s,a);
             s.pop_back();
             return s;
         }
         int b=st.top();
         st.pop();
         l--;
         if((a==1||a==0)&&g!=0){
             if(b!=0||a!=0)s=s+"and ";
             int c=a*10+b;
             simp(s,c);
         }
         if((a==0||a==1)&&g==0){ 
             int c=a*10+b;
             simp(s,c);
             s.pop_back();
             return s;
         }
         if(a>1&&g==0){
            bas(s,a);
            simp(s,b);
         }
         if(a>1&&g!=0){
             s=s+"and ";
             bas(s,a);
             simp(s,b);
         }
      }
      s.pop_back();
     return s;  
    }
    void cror(string&s){
        string s1="crore ";
        s=s+s1;
    }
    void lakh(string&s){
        string s1="lakh ";
        s=s+s1;
    }
    void tho(string&s){
        string s1="thousand ";
        s=s+s1;
    }
    void hun(string&s){
        string s1="hundred ";
        s=s+s1;
    }
    void simp(string &s,int x){
         if(x==0) s=s;
         if(x==1) s=s+"one ";
         if(x==2) s=s+"two ";
         if(x==3) s=s+"three ";
         if(x==4) s=s+"four ";
         if(x==5) s=s+"five ";
         if(x==6) s=s+"six ";
         if(x==7) s=s+"seven ";
         if(x==8) s=s+"eight ";
         if(x==9) s=s+"nine ";
         if(x==10) s=s+"ten ";
         if(x==11) s=s+"eleven ";
         if(x==12) s=s+"twelve ";
         if(x==13) s=s+"thirteen ";
         if(x==14) s=s+"fourteen ";
         if(x==15) s=s+"fifteen ";
         if(x==16) s=s+"sixteen ";
         if(x==17) s=s+"seventeen ";
         if(x==18) s=s+"eighteen ";
         if(x==19) s=s+"nineteen ";
    }
    void bas(string &s,int x){
        if(x==2) s=s+"twenty ";
        if(x==3) s=s+"thirty ";
        if(x==4) s=s+"forty ";
        if(x==5) s=s+"fifty ";
        if(x==6) s=s+"sixty ";
        if(x==7) s=s+"seventy ";
        if(x==8) s=s+"eighty ";
        if(x==9) s=s+"ninety ";
    }
};
