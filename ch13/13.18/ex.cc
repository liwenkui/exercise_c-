#include <string>
#include <iostream>
using namespace std;

class Employee{
    Employee(){id_=s_increment++;}
    Employee(string n):name_(n){id_=s_increment++;}
    Employee(const Employee&)=delete;   //casue there really is no sensible meaning,Employee can't copy in real world
    Employee& operator=(const Employee&)=delete;
    private:
    int id_;
    string name_;
    static int s_increment;
};
int Employee::s_increment=0;
int main(){
    return 0;
}