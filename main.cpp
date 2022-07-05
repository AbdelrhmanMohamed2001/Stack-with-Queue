#include <iostream>

using namespace std;


template <class t>

class Queue
{
public:
    t*arrQueue;                           //declare queue
    int size;                             //size of queue

    Queue()                                         //default constructor
    {
        size=0;
        arrQueue=new t[100];
    }

    queue(t value, int intial_size)                           //parameterize constructor
    {
       size= intial_size;
       arrQueue=new t[intial_size];
      for(int i=0; i<size; i++)
         arrQueue[i]=value;
    }

    ~Queue()

    {

        size=0;

        delete []arrQueue;

    }

    t& front()
    {
        return arrQueue[0];
    }

     void pop()
     {
        for(int i=0; i<size; i++)
            arrQueue[i-1]=arrQueue[i];
        size=size-1;
     }

     void push(t value)
     {
         arrQueue[size++]=value;
     }


     int Get_size()
     {
         return size;
     }

};
class Stack

{

public:

    Queue <int>arrQueue;

    void push(int val)

    {
        int S_Size=arrQueue.Get_size();                 //make size stack = size queue
        arrQueue.push(val);                             //put value in stack

        while (S_Size--)

        {
            arrQueue.push(arrQueue.front());            //first element of stack from under is the element of queue
            arrQueue.pop();                             //top = top-1
        }

    }

    int top()

    {return arrQueue.front();}                             //first element of stack from under is the element of queue



    void pop()

    {arrQueue.pop();}                                       //delete top



};



int main()

{
    Queue <int> c;
    //add elements into queue
    c.push(10);
    c.push(20);
    c.push(30);
    c.push(40);
    c.push(50);
    cout<<"size before deletion"<< c.Get_size()<<endl;                       //get size
    cout<<"the first element before deletion is "<< c.front()<<endl;           //get the first element
    c.pop();                                                                //delete first element
    cout<<"the first element after deletion is "<< c.front()<<endl;           //get the first element after deleting first element
    cout<<"size after deletion"<< c.Get_size()<<endl;                       //get size after deleting first element




    Stack a;

    a.push(50);
    a.push(60);
    a.push(70);
    a.push(80);
    cout<<"top of stack is before deletion "<<a.top()<<endl;
    a.pop();
    cout<<"top of stack is after deletion "<<a.top()<<endl;

    return 0;

}





