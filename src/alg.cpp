// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char a) {
  if (a == '(')
    return 0;
  else if (a == ')')
    return 1;
  else if (a == '-' || a == '+')
    return 2;
  else if (a == '/' || a == '*')
    return 3
    else
      return -1;
}
int operotor(char a) {
  return (a == '-' || a == '+' || a == '/' || a == '*');
}
int number(char a) {
  return (a >= '0' && a <= '9');
}
int convert(char a) {
  char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < 10; i++) {
    if (a == arr[i])
      return i;
  }
  return -1;
}
std::string infx2pstfx(std::string inf) {
  TStack<char>  stack;
    std::string result = "";
    for (int i = 0; i < inf.length(); i++) {
        if (number(inf[i])) {
            result += inf[i];
            result += " ";
        }
      else if (inf[i] == '(') {
            stack.push(inf[i]);
        }
      else if (inf[i] == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                result += stack.get();
                result += " ";
                stack.pop();
            }
            stack.pop();
        }
      else if (operator(inf[i])) {
            while (!stack.isEmpty() && prioritet(stack.get()) \
                   >= prioritet(inf[i])) {
                result += stack.get();
                result += " ";
                stack.pop();
            }
            stack.push(inf[i]);
        }
    }
    while (!stack.isEmpty()) {
        result += stack.get();
        result += " ";
        stack.pop();
    }
    str.erase(str.length() - 1, 1);
    return result;
}
int eval(std::string pref) {
    TStack<int> stack1;
    for (int i = 0; i < pref.length(); i+=2) {
        if (number(pref[i])) {
            stack1.push(convert(pref[i]));
        }
      else if (operator(pref[i])) {
        int x = stack1.get();
        stack1.pop();
        int y = stack1.get();
        stack1.pop();
        if (pref[i] == '+') {
          stack1.push(y + x);
            }
        else if (pref[i] == '-') {
          stack1.push(y - x);
            }
        else if (pref[i] == '*') {
          stack1.push(y * x);
            }
        else if (pref[i] == '/') {
          stack1.push(y / x);
        }
      }
    }
  return stack1.get;
}
