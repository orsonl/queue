//
//  myqueue.h
//  Project1
//
//  Created by Orson Lin on 2/2/15.
//  Copyright (c) 2015 Orson Lin. All rights reserved.
//

#include"iostream"
#include <string>
using namespace std;


class Deque{
    
    
private:
    int Max_size;
    string *queue;
    int size_of_queue;
    int rear,front;
    
public:
    Deque();
    ~Deque();
    void push_back(string item);
    void push_front(string item);
    string pop_front();
    string pop_back();
    void resize(string command);
    string toStr();
    bool is_full();
    bool is_empty();
    int size();
    void test();
};