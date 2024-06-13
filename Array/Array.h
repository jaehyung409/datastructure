//
// Created by user on 24. 5. 29.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <stdexcept>
#include <algorithm>

#include <type_traits>

template <typename T>
struct DefaultValue {
    static constexpr T value = std::conditional_t<std::is_arithmetic<T>::value, std::integral_constant<T, 0>, std::integral_constant<T*, nullptr>>::value;
};

template <typename T, size_t N>
struct Array {
    T data[N];

    T& operator[](const int index) {
        if (index >= N){
            throw std::out_of_range("index out out_of_range");
        }
        return data[index];
    }
    const T& operator[](const int index) const {
        if (index >= N){
            throw std::out_of_range("index out out_of_range");
        }
        return data[index];
    }
    int capacity(){
        return N;
    }
    int size(){
        for(const auto& element : data) {
            if (element == DefaultValue<T>::value)
                return &element - data;
        }
    }
    void print(){
        for(const auto& element : data) {
            if(element != DefaultValue<T>::value)
                std::cout << element << ' ';
        }
        std::cout << '\n';
    }
    void sorting(int index){
        std::sort(data, data+index);
    }
    int find(T element);
    void insert(T element, int index);
    void remove(T element);
    int sort_find(T element, int low, int high);
    void sort_insert(T element);
    void sort_remove(T element);
    void reverse_array_extra_array();
    void reverse_array_two_pointer();
};


#endif //ARRAY_ARRAY_H

