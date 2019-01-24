#include <iostream>
#include <string>

using namespace std;

class A{
public:
    void fun1() { fun2();}
    void fun2() { cout << 1;}
};

class B : public A{
public:
    void fun2() {cout << 2;}

};

class C : public B{
public:
    void fun1() {fun2();}
};

class D : public C{
public:
    void fun2() {cout << 3;}
};

int main() {
    A vara;
    B varb;
    C varc;
    D vard;

    vara.fun1();
    varb.fun1();
    varc.fun1();
    vard.fun1();

    return 0;
}
