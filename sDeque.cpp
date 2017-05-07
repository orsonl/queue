//
//  myqueue.cpp
//  Project1
//
//  Created by Orson Lin on 2/2/15.
//  Copyright (c) 2015 Orson Lin. All rights reserved.
//

#include "sDeque.h"
#include"iostream"
#include <string>
#include <sstream>

using namespace std;


//Constructor

Deque::Deque()
{
    
    Max_size=4;
    queue= new string[Max_size+1];
    size_of_queue=0;
    rear=0;
    front=0;
    
    
    
    }

//Destructor

Deque::~Deque()
{
    delete[] queue;
}

//Tells whether the queue is full or not.

bool Deque::is_full()
{
    int newrear = (rear+1)%(Max_size+1);
    return (front == newrear);
}

//Tells whether the queue is empty or not.

bool Deque::is_empty()

{
    return (rear==front);
}

//Removes and returns the element at the front of the queue.
string Deque::pop_front()
{
    string ch;
    
    try{
        if (is_empty())
        {
            
            throw 0;
        }
        front=(front+1)%(Max_size+1);
        ch=queue[front];
        size_of_queue--;
        
        try
        {
            if(size_of_queue<Max_size/4){
                
                throw 0;
            }
        }catch(...){
            
            resize("shrink");
        }
    }catch(...){
        cout<<"The queue is empty "<<endl;
    }
    return ch;
}
    

//Removes and returns the element at the back of the queue.

string Deque::pop_back()
{
    int newrear=(rear+Max_size)%(Max_size+1);
    string ch;
    try{
    if (is_empty()){
        throw 0;
    }


        ch=queue[rear];
        try{
        
        if(size_of_queue-1<Max_size/4)
        {
            throw 0;
        }
        }catch(...){
            resize("shrink");
            newrear=(rear+Max_size)%(Max_size+1);
        }

        
        size_of_queue--;
        rear=newrear;
       
    }catch(...){
        cout<<"The queue is empty "<<endl;
    }

    return ch;
}

// Inserts the element at the back of the queue.


void Deque::push_back(string item)
{
   
    try{
    
    
    if (is_full())
   {
       throw 0;
   }


    }catch(...){
        cout<<"Maximum size has been reached"<<endl;
        resize("expand");
    }
    
    queue[rear=(rear+1)%(Max_size+1)]=item;
    size_of_queue++;
}


// Returns the number of elements in the queue.

void Deque::push_front(string item)
{
    int newfront=(front+Max_size)%(Max_size+1);
    try{
        if(is_full())
        {
            throw 0;
        }
        queue[front]=item;
    }catch(...){
        cout<<"Maximum size has been reached"<<endl;
        resize("expand");
        queue[front]=item;
        newfront=(front+Max_size)%(Max_size+1);
    }
    front = newfront;
    
    size_of_queue++;
}


// Returns the number of elements in the queue.


int Deque::size(){
   
    return size_of_queue;
}



/* Puts the contents of the queue from front to back into a
 retrun string with each string item followed by a newline
 */


string Deque::toStr(){
    int front_pos =front,rear_pos=rear;
    string output;
    while(front_pos!=rear_pos)
    {
        front_pos=(front_pos+1)%(Max_size+1);
        
        string row_data = queue[front_pos];
        string Result;
        ostringstream convert;
        convert << row_data;
        Result = convert.str();
        output += Result;
        output += "\n";
    }
    return output;
}



/*Double the size of the queue if the sent command is "expand".
  Shrink the size of the queue to halp if the sent command is "shrink"
  or anything else.
*/


void Deque::resize(string command){
    int modified_size;
    int front_pos =front,rear_pos=rear;
    int i=0;
    string *resized_array = new string[modified_size];
    if(command=="expand")
    {
        cout<<"the queue has been expanded"<<endl;
        modified_size= Max_size * 2+1;
    }
    else
    {
        cout<<"the queue has been shrinked"<<endl;
        modified_size = (Max_size-1)/2;
    }
    
    while(front_pos!=rear_pos)
    {
        front_pos=(front_pos+1)%(Max_size+1);

        resized_array[++i] = queue[front_pos];
    }
    front=0;
    rear=size_of_queue;
    
    if(command=="expand")
    {
    
         Max_size = Max_size * 2 ;
    }
    else
    {
         Max_size = Max_size / 2 ;
    }
    cout<<"the max size is now ";
    cout<< Max_size<<endl;
    delete [] queue;
    queue = resized_array;
}




void Deque::test()
{
    cout<<"The size of the queue is"<<endl;
    cout<<size_of_queue<<endl;
    cout<<"The front is"<<endl;
    cout<<front<<endl;
    cout<<"The rear is"<<endl;
    cout<<rear<<endl;
}




















