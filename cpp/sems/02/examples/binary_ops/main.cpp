#include <bitset>
#include <iostream>
#include <string>

const short int kWordSize = 8;

struct BinOps {
  std::string name;
  int op1;
  int op2;
  int result;
};

void PrintNumber(int numb) {
  std::cout << numb << "(" << std::bitset<kWordSize>(numb) << ")";
}

void PrintOp(const BinOps& data) {
  PrintNumber(data.op1);
  std::cout << " " << data.name << " ";
  PrintNumber(data.op2);
  std::cout << " = ";
  PrintNumber(data.result);
  std::cout << std::endl;
}

void Xor(BinOps& data) {
  data.name = "^";
  data.result = data.op1 ^ data.op2;
  PrintOp(data);
}

void LeftShift(BinOps& data) {
  data.name = "<<";
  data.result = data.op1 << data.op2;
  PrintOp(data);
}

void RightShift(BinOps& data) {
  data.name = ">>";
  data.result = data.op1 >> data.op2;
  PrintOp(data);
}

void And(BinOps& data) {
  data.name = "&";
  data.result = data.op1 & data.op2;
  PrintOp(data);
}

void Not(BinOps& data) {
  std::cout << "~";
  PrintNumber(data.op1);
  std::cout << " = ";
  PrintNumber(~data.op1);
}

int main() {
  int first_number = 0;
  int second_number = 0;
  std::cin >> second_number >> second_number;
  BinOps evaluator;
  evaluator.op1 = first_number;
  evaluator.op2 = second_number;
  Xor(evaluator);
  LeftShift(evaluator);
  RightShift(evaluator);
  And(evaluator);
  Not(evaluator);

  return 0;
}
