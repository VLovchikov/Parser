#pragma once

#include "TStack.h"
#include <iostream>
#include <string>

using namespace std;

class TParser
{
	char *inf;
	string post;
	TStack <char> st_op;
	TStack <string> st_post;
	TStack <string> st_st;
	TStack <string> st_post1;
	TStack <int> st_ex;
public:
	TParser()
	{
		throw "NOTHING TO EXECUTE";
	}
	TParser(char *s) : st_op(100), st_post(100), st_ex(100), st_post1(100), st_st(100)
	{
		if (s == 0) 	throw "NOTHING TO EXECUTE";
		else
		{
			inf = new char[strlen(s) + 1];
			int a = 0;
			while (s[a] != '\0')
			{
				inf[a] = s[a];
				a++;
			}
			a++; inf[a] = '\0';
		}
	}
	~TParser() {};
	char *ret()
	{
		return inf;
	}
	int Priority(char ch);
	bool IsOperation(char ch);
	bool IsNumber(char ch);
	bool Brackets();
	string Convertation();
	int Calculate();
};



