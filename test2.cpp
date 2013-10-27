#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
	char* a = "hello";
	char* c;
	printf("%s", a);
	char* b="world";
	c = strcat(a, "h");
	printf("%s", c);
}