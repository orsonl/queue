//
//  main.cpp
//  Project1
//
//  Created by Orson Lin on 2/2/15.
//  Copyright (c) 2015 Orson Lin. All rights reserved.
//

#include <iostream>
#include "sDeque.h"
#include <string>





int main(int argc, char **argv) {
    int op=0;
    string input;
    Deque *DQ = new Deque();
    
    while (op<6)
    {
        std::cin>> op;
        switch(op) {
            case 0:
                std::cin>>input;
                DQ->push_front(input);
                
                break;
            case 1:
                std::cin>>input;
                DQ->push_back(input);
                
                break;
            case 2:
                DQ->pop_front();
                
                break;
            case 3:
                DQ->pop_back();
                
                break;
            case 4:
                cout<<DQ->toStr();
                break;
            case 5:
                DQ->test();
                break;
        }
    }
    
    return 0;
    
}

    
    
    

