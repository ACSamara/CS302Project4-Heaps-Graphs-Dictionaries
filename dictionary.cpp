#include "dictionary.h"

template <class T>
Dictionary<T>::Dictionary(){
    numEntries = 0;
}
template <class T>
bool Dictionary<T>::insert(string key, T value){
    if(contains(key)){
        return false;
    }
    int index = h(key);
    hashTable[index].insert(value);
    numEntries ++;
    return true;
}
template <class T>
bool Dictionary<T>::remove(string key){
    if(!contains(key)){
        return false;
    }
    int index = h(key);
    for(int i=0; i<hashTable[index].size(); i++){
        if(hashTable[index][i]==key){
            hashTable[index].remove(i);
        }
    }
    numEntries--;
    return true;
}
template <class T>
T Dictionary<T>::get(string key){
    int index = h(key);
    for(int i=0; i<hashTable[index].size(); i++){
        if(hashTable[index][i]==key){
            return hashTable[index][i];
        }
    }
    T junk;
    return junk;
}
template <class T>
bool Dictionary<T>::contains(string key){
    int index = h(key);
    for(int i=0; i<hashTable[index].size(); i++){
        if(hashTable[index][i]==key){
            return true;
        }
    }
    return false;
}
template <class T>
T Dictionary<T>::operator[](string key){
    return get(key);
}
template <class T>
int Dictionary<T>::h(string key){
    int n = 0;
    // Cast ASCII values into integers
    for(int i=0; i<key.length(); i++){
        n+=key[i];
    }
    return n%TABLE_SIZE;
}