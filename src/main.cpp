#include <iostream>
#include <stdio.h>
#include <vector>
#include <numeric>
#include <sstream>

using namespace std;

enum TokenType {
  Right_Pointer,
  Left_Pointer,
  Add_Value,
  Remove_Value,
  Open_Loop,
  Close_Loop,
  ERR,
  END
};

struct Token {
  TokenType type;

  //for error checking
  int colmun;
  int line;
};

class Tokenizer {
  public:
  vector<Token> Tokens;
  string code;
  int line = 1;
  int colmun = 1;
  Tokenizer(string codes) {
    code = codes;
  }
  void take() { if(code.length() > 0) code = code.substr(1); colmun++; }
  void add(TokenType type) {
    take();
    Token toAdd;
    toAdd.line = line;
    toAdd.colmun = colmun;
    toAdd.type = type;
    
    Tokens.push_back(toAdd);
  }

  vector<Token> tokenize() {
    while(code.length() > 0) {
      switch(code[0]) {
        case '>': 
          add(TokenType::Right_Pointer);
          continue;
        case '<':
          add(TokenType::Left_Pointer);
          continue;
        case '[':
          add(TokenType::Open_Loop);
          continue;
        case ']':
          add(TokenType::Close_Loop);
          continue;
        case '+':
          add(TokenType::Add_Value);
          continue;
        case '-':
          add(TokenType::Remove_Value);
          continue;
        case ' ':
          take();
          continue;
        case '\t': 
          take();
          continue;
        case '\n':
          take();
          line++;
          colmun = 0;
          continue;
        default: 
          cout << "\033[1;31merror unknown char '\033[0m" << code[0] << "\033[1;31m'\n at => line:\033[0m" << line << "\033[1;31m, colmun:\033[0m"<< colmun << endl;
          add(TokenType::ERR);
          break;
      }
    }
    add(TokenType::END);
    return Tokens;
  }
};

int main() {
  cout << "enter code: ";
  string code;
  cin >> code;
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
