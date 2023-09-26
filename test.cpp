#include<cstring>
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
int main(){
    char *p1;  // 指针存在栈上，未分配内存
    char *p2 = (char*)malloc(128);  // 指针存在栈上，分配了内存
    char *p3 = new char; // 指针存在栈上，空间分配在自由存储区
    char *p4 = "hello world"; // 指针存在栈上，空间分配在beta区

}