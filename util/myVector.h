//
// Created by DELL on 2019/4/12.
//

#ifndef DATASTRUCT_MYVECTOR_H
#define DATASTRUCT_MYVECTOR_H

namespace Util {
    template<class T>
    class MyVector {
    private:
        int capacity;
        int count;
        T *data;

    public:
        MyVector(int size) {
            data = new T[size];
            capacity = size;
            count = 0;
        };

        ~MyVector() {
            delete[]data;
        };

        int Push(T element) {
            if (count >= capacity) {
                return -1;
            }
            data[count] = element;
            count++;
            return 0;
        };

        T Peek() {
            return data[0];
        };

        T Tail() {
            return data[count];
        };


        int Pop() {
            count--;
            return 0;
        };
    };

}


#endif //DATASTRUCT_MYVECTOR_H
