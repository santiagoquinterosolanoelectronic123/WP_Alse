#include <iostream>

float numDec= 3.14;

void func(){
    numDec=3.14156;
    std::cout<<"Global variable: "<<numDec<<std::endl;
}

int main(){
    int a=1; 
    std::cout<<"Global variable: "<<numDec<<std::endl;
    std::cout<<"main func variable: "<<a<<std::endl;
    func();
    return 0;
}