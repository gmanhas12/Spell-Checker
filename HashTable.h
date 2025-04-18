#pragma once
#include<iostream>
#include<string>
using namespace std;


class HashTable{
  
  public:

    //default constructor 
    HashTable();
    //constructor 
    HashTable(const int n);
    //copy constructor
    HashTable(const HashTable& ht);
    //destructor
    ~HashTable();
    //operator
    HashTable& operator=(const HashTable& ht);
    //insert
    void insert(const string s);
    //find
    bool find(const string s) const;
    //size
    int size() const;
    //maxSize
    int maxSize() const;
    //loadFactor
    double loadFactor() const;
    //Helper for copy constructor
    void deepCopy( const HashTable& ht);
    //helper to print
    void print() const; 

  private:

    //string* to refer to the underlying array of string objects
    string* arr;
    //int to record the size of the underlying array
    int arrSize;
    //int to record the value used by h2
    int hTwoValue;
    //int to record the current number of items in the hash table
    int currentSize;
    // check if prime
    bool isPrime( int n)const ;
    // get a prime number
    int getNextPrimeNum(const int n) const ;
    //First Hash
    int firstHashFunction(const string s) const; 
    // Second Hash
	  int secondHashFunction(const string s) const;











};
