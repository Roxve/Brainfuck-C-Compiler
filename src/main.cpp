#include <iostream>
#include <vector>
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
  vector<Token> Tokens;
  string code;
  int line;
  int colmun;
  Tokenizer(string code) {
    code = code;
  }
  bool isSkippable(string x) { return x == " " || x == "\t"; }
  void take() { if(code.length() > 0) code = code.substr(0); }
  bool isLine(string x) { return x == "\n"; }
  void add(TokenType type) {
    Token toAdd;
    toAdd.line = line;
    toAdd.colmun = colmun;
    toAdd.type = type;
    
    Tokens.push_back(toAdd);
  }
};
