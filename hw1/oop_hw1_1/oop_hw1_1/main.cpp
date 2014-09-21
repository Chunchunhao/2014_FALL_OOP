//
//  main.cpp
//  oop_hw1_1
//
//  Created by Tonygo on 2014/9/20.
//  Copyright (c) 2014年 pika. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int in=0, sum=0;
    while(1){
        if( !(cin >> in) ){
            cin.clear();
            cin.ignore(' ', '\n');
        }
        else{
            if( in < 0)
                break;
            else
                sum+= in ;
        }
    }
    cout << "Sum is : " << sum << endl;
    return 0;
}
