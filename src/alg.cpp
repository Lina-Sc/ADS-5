// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char a) {
    if (a == '(')
      return 0;
    else if (a == ')')
      return 1;
    else if (a == '+' || a == '-')
      return 2;
    else if (a == '*' || a == '/')
      return 3;
    else
      return -1;
}
int oper(char a) {
  return (a == '+' || a == '-' || a == '*' || a == '/');
}
int numb(char a) {
  return (a >= '0' && a <= '9');
}

int conv(char a) {
  char arr[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < 10; i++) {
    if (a == arr[i])
      return i;
  }
  return -1;
}

std::string infx2pstfx(std::string inf) {
    TStack<char>  stack1;
    std::string res = "";
    for (int i = 0; i < inf.length(); i++) {
        if (numb(inf[i])) {
            res += inf[i];
            res += " ";
        } else if (inf[i] == '(') {
            stack1.push(inf[i]);
        } else if (inf[i] == ')') {
            while (!stack1.isempty() && stack1.get() != '(') {
                res += stack1.get();
                res += " ";
                stack1.pop();
            }
            stack1.pop();
        } else if (oper(inf[i])) {
            while (!stack1.isempty() && prior(stack1.get()) \
                   >= prior(inf[i])) {
                res += stack1.get();
                res += " ";
                stack1.pop();
            }
            stack1.push(inf[i]);
        }
    }
    while (!stack1.isempty()) {
        res += stack1.get();
        res += " ";
        stack1.pop();
    }
    res.erase(res.length() - 1, 1);
    return res;
}

int eval(std::string pref) {
    TStack<int> stack2;
    for (int i = 0; i < pref.length(); i+=2) {
        if (numb(pref[i])) {
            stack2.push(conv(pref[i]));
        } else if (oper(pref[i])) {
            int y = stack2.get();
            stack2.pop();
            int x = stack2.get();
            stack2.pop();
            if (pref[i] == '+') {
                stack2.push(x + y);
            } else if (pref[i] == '-') {
                stack2.push(x - y);
            } else if (pref[i] == '*') {
                stack2.push(x * y);
            } else if (pref[i] == '/') {
                stack2.push(x / y);
            }
        }
    }
    return stack2.get();
}
