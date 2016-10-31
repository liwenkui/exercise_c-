 #include <iostream>
 using namespace std;
 int& a(int &i)
 {
     i+=1;
     return i;
 }
 int main(){
     int i=3;
     if(a(i)!=i)
     cout<<i<<endl;
     return 0;
 }