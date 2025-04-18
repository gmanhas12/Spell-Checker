#pragma once
#include <vector>
#include <algorithm>
#include "HashTable.h"
//works
vector<string> extraLetter(const HashTable & dict, string word){
  vector<string> a;
  
 
  if(dict.find(word))
  {
    a.push_back(word);
    return a;
  }
  
  for(int i = 0; i< word.size(); i++){
    string temp = word;
    temp.erase(temp.begin()+i);
    if(dict.find(temp)){
      //unique insertion into vector was inspired/learned from https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
      if (find(a.begin(), a.end(), temp) == a.end()) {
        a.push_back(temp);
      }

    }
  }
 
  return a;




}


vector<string> transposition(const HashTable & dict, string word){
  vector<string> a;
  
 
  if(dict.find(word))
  {
    a.push_back(word);
    return a;
  }

  for(int i = 0; i < word.size()-1 ; i++){
    string temp = word;
    swap(temp[i], temp[i+1]);
    if(dict.find(temp))
      //unique insertion into vector was inspired/learned from https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
      if (find(a.begin(), a.end(), temp) == a.end()) {
        a.push_back(temp);
      }
    }
  return a;
}





vector<string> missingSpace(const HashTable & dict, string word){
  vector<string> a;
  
  if(dict.find(word))
  {
    a.push_back(word);
    return a;
  }

  for(int i = 0; i< word.size(); i++){
    string temp = word.substr(0,i+1);
    string temp2 = word.substr(i+1,word.length()-i-1);
    if(dict.find(temp) && dict.find(temp2) ){
      //unique insertion into vector was inspired/learned from https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
      string test = temp + " " + temp2;
      if (find(a.begin(), a.end(), test) == a.end()) {
        a.push_back(test);
      }
      
    }
    
  }
  return a;

}


vector<string> missingLetter(const HashTable & dict, string word){
  vector<string> a;
  
  if(dict.find(word))
  {
    a.push_back(word);
    return a;
  }
  for(int i = 0; i <= word.size(); i++){
    for(int x = 0 ; x < 26; x++){
      string temp = word;
      temp.insert(i, 1, x+97);
      if(dict.find(temp)){
        //unique insertion into vector was inspired/learned from https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
        if (find(a.begin(), a.end(), temp) == a.end()) {
          a.push_back(temp);
        }
      }
    }
  }
  return a; 
}

vector<string> incorrectLetter(const HashTable & dict, string word){
  vector<string> a;
  
  if(dict.find(word))
  {
    a.push_back(word);
    return a;
  }
  for(int i = 0; i < word.size(); i++){
    for(int x = 0 ; x < 26; x++){ 
      string temp = word;
      temp[i] = x + 97;
      if(dict.find(temp)){
        //unique insertion into vector was inspired/learned from https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
        if (find(a.begin(), a.end(), temp) == a.end()) {
          a.push_back(temp);
        }
      }
    }
  }
  return a;
}

