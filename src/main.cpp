#include <iostream>
#include <stdio.h>
#include <vector>
#include <numeric>
#include <sstream>
#include <fstream>
#include "./tokenizer.cpp"

using namespace std;


int main() {
  cout << "enter file path: ";

  string pathr;
  cin >> pathr;
  ifstream fileToRead(pathr);

  string code;
  if(fileToRead) {
    ostringstream ss;
    ss << fileToRead.rdbuf();
    code = ss.str();
  }
  else {
    cout << "file " << pathr << " not found or not readable..." << endl;
    return 1;
  }

  Tokenizer* tokenizer = new Tokenizer(code);
  vector<Token> tokens = tokenizer->tokenize();
  stringstream ss;
  for(int i =0;i<tokens.size();i++){
    if(i != 0)
    {
      ss<<", ";
    }
    ss << "type: " << tokens[i].type << " line: " << tokens[i].line << " colmun: " << tokens[i].colmun;
  }  
  cout << ss.str() << endl;
  return 0;
}
