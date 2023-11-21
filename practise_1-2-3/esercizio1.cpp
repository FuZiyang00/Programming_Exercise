#include<iostream>

int main () {
    char meas;
    double x; 
    float Temp;
    std::cout <<"Temperature in:";
    std::cin >> meas;
    std:: cin >> x; 

    if (meas=='C'){
         Temp = (x*9.0/5.0) + 32;
    }
    else if (meas=='F'){
         Temp = (x-32)*5.0/9.0;
    }
    else{
        std::cout <<"Invalid measure";
    }
    std::cout <<"Temperature in:" << Temp << std::endl;
    return 0;
}