#include <iostream>
#include <cassert>
using namespace std;


class user_defined_vector{
private:
    int *arr = nullptr;
    int Size = 0;
    int capacity = 0;
public:

    user_defined_vector() {
        arr = new int[capacity];
    }
    
    user_defined_vector(int initial_size) :Size(initial_size) {
        
        if(initial_size < 0){
            Size = 0;
        }
        Size = initial_size;
        capacity = Size;
        arr = new int[capacity] {};
    }

    ~user_defined_vector() {
        delete[] arr;
        arr = nullptr;
    }

    void Expand_capacity(void){
        // Expand capacity
        capacity = (capacity + 1) * 2;

        // Transferring data to the new one
        int *NewArr = new int[capacity];
        for(int i=0; i<Size; i++){
            NewArr[i] = arr[i];
        }

        delete[] arr;
        arr = NewArr;
        NewArr  = nullptr;
    }


    void set(int index, int value){
        assert(index>=0 && index<Size);
        arr[index]=value;
    }

    int get(int index){
        assert(index >=0 && index<Size);
        return arr[index];
    }

    void push_back(int value){
        if(Size == capacity)
           Expand_capacity();

        arr[Size++] = value;
    }

    void insert(int index, int value){
        assert(index >= 0 && index <= Size);
        
        if(index == Size){
            push_back(value);
            return;
        }
          
        if(Size == capacity){
            Expand_capacity();
        }
    
        for(int i=Size; i>index; i--){
            arr[i] = arr[i-1];
        }

        arr[index] = value;
        Size++;
        
    }

    void pop_back(void){
        Size--;
    }
};