#include"HashTable.h"
#include<iostream>
#include <string.h>


//default constructor – creates a hash table of default size: 101; sets all array elements to the empty string (""); sets P2
HashTable::HashTable(){
  arrSize = 101;
  currentSize = 0;
  
  arr = new string[arrSize];
  for(int i = 0; i < arrSize; i++){
    arr[i] = "";
  }
  hTwoValue = getNextPrimeNum(arrSize/2);

}


//constructor – creates a hash table to store n items,sets all array elements to the empty string; sets the value for P2.
HashTable::HashTable(const int n){
  arrSize = getNextPrimeNum(2*n);
  arr = new string[arrSize];
  for(int i = 0; i< arrSize ;i++){
    arr[i] = "";
  }
  hTwoValue = getNextPrimeNum(arrSize/2);
  currentSize = 0;


}





//copy constructor – a constructor that creates a deep copy of its HashTable reference parameter
HashTable::HashTable(const HashTable& ht){
  deepCopy(ht);
}


//destructor – de-allocates any dynamic memory associated with the calling object
HashTable::~HashTable(){
  arrSize = 0;
  currentSize = 0;
  hTwoValue = 0;
  delete []arr;
  arr = nullptr;

}


//operator= – overloads the assignment operator for HashTable objects
HashTable& HashTable::operator=(const HashTable& ht){
  if(this !=  &ht){
    delete[] arr;
    deepCopy(ht);
  }
  return *this;
  }


//insert – searches the hash table for the  string parameter, if a match is not found it inserts the parameter string.
void HashTable::insert(const string s){
  int keyValue = firstHashFunction(s);
  int key = secondHashFunction(s);
  if(s == ""){
    return;
  }
  if(find(s) == true){
    return;
  }
  else{
    while(arr[keyValue]!= s && arr[keyValue] != ""){
    keyValue = ((keyValue + key) % arrSize);
  }
    arr[keyValue] = s;
    currentSize ++;
  }
  if(0.67 < loadFactor() ){
    HashTable newHash = HashTable(arrSize);
    for(int i = 0; i < arrSize ;i++){
      if(arr[i] != ""){
        newHash.insert(arr[i]);
      }
    }
    *this = newHash; 
  }
}











//find – returns true if its string parameter is in the hash table, returns false if it is not
bool HashTable::find(const string s) const{
  int keyValue = firstHashFunction(s);
  int key = secondHashFunction(s);
  if(s == ""){
    return false;
  }
  while(arr[keyValue]!= s && arr[keyValue] != ""){
    keyValue = ((keyValue + key) % arrSize);
  }
  return (arr[keyValue].compare(s) == 0);
}




//size – returns the number of items stored in the hash table
int HashTable::size() const{
  return currentSize;

}
//maxSize – returns the size of the hash table’s underlying array
int HashTable::maxSize() const{
  return arrSize;

}
//loadFactor – returns the load factor of the hash table as a double
double HashTable::loadFactor() const{
  return (double)currentSize/arrSize;

}

//helper for copy constructor
void HashTable::deepCopy( const HashTable& ht){
  arrSize =  ht.arrSize;
  currentSize = ht.currentSize;
  arr =  new string[arrSize];
  for(int i = 0; i < arrSize; i++){
    arr[i] = ht.arr[i];
  }
  hTwoValue = ht.hTwoValue;
}



// if prime returns true else returns false
bool HashTable::isPrime(const int n)const
{

  if (n == 1 || 1>n){
    return false;
  }
  
  for (int i =2; i<n; i++){
    if (n % i ==0){
      return false;
    }
  }

  return true;
}



// gets smallest prime number less than n
int HashTable::getNextPrimeNum( int n)const{
  bool temp =  false;
  int tmp = n;
	if (tmp < 1 || tmp == 1)
	{
		return 2; 
	}
  while(temp==false){
    if(isPrime(n) == true){
      return n;
      }
    n++;
  }
  return n;
}



//First Hash Funcion
int HashTable::firstHashFunction(const string value) const   
{
	int keyValue = value[0] - 96;	

		for (int i = 1; i < value.size(); i++)
		{
			int nextCharAsc = value[i] - 96; 
			keyValue = (keyValue*32 + nextCharAsc) %  arrSize;
		}
		
	
	return keyValue;
}



//Second Hash Function
int HashTable::secondHashFunction(const string value) const 
{
  int keyValue = firstHashFunction(value);
  //key is the distance to be added to the first value
  int key = hTwoValue - ( keyValue % hTwoValue);
	// if(arr[key + keyValue] != ""){
  //   while(arr[keyValue] != ""){
  //     keyValue += key;
  //   }

  // }
  return key;
}

//to print HashTable
void HashTable::print() const 
{
  for(int i = 0; i< arrSize; i++){
    cout<<"i is: " << i <<" the element at i is: " << arr[i]<<endl;
  }
}
