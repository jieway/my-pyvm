#include "arrayList.hpp"
#include <stdio.h>

// 构造函数， n 初始长度
template <typename T>
ArrayList<T>::ArrayList(int n) {
    _length = n;
    _size = 0;
    _array = new T[n];
}

// 在列表尾部添加元素
template <typename T>
void ArrayList<T>::add(T t) {
    if (_size >= _length) {
        expand();
    }
    _array[_size++] = t;
}

// TODO: 此处没有边界判断！！！
// 向指定索引中插入元素
template <typename T>
void ArrayList<T>::insert(int index,T t) {

    // 其目的是为了扩增 _size 长度
    add(NULL);

    for (int i = _size ; i > index; i--) {
        _array[i] = _array[i-1];
    }
    _array[index] = t;
}

// 数组扩容两倍
template <typename T>
void ArrayList<T>::expand() {
    // 二进制左移 1 位等同于 _length * 2
    T* new_array = new _array[_length << 1];

    for (int i = 0; i < _length; i++) {
        new_array[i] = _array[i];
    }
    delete[] _array;
    _array = new_array;
    _length <<= 1;

    printf("expand an array to %d,size is %d\n",_length,_size);
}

template <typename T>
int ArrayList<T>::size() {
    return _size;
}

template <typename T>
int ArrayList<T>::length() {
    return _length;
}

// 获取指定位置的元素
template <typename T>
T ArrayList<T>::get(int index) {
    return _array[index];
}

// set 设置指定位置的元素
template <typename T>
void ArrayList<T>::set(int index, T t) {
    if (index >= _size) {
        _size = index + 1;
    }

    while (_size > _length) {
        expand();
    }

    _array[index] = t;
}


template <typename T>
T ArrayList<T>::pop() {
    return _array[--_size];
}

