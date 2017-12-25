#include "stdafx.h"
#include "TParser.h"

int TParser::Priority(char ch)
{
	int n;
	switch (ch)
	{
	case '(': n = 0; break;
	case '+':
	case '-': n = 1; break;
	case '*':
	case '/': n = 2; break;
	default: n = -1;
	}
	return n;
}

bool TParser::IsOperation(char ch)
{
	if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') )
		return true;
	else
		return false;
}

bool TParser::IsNumber(char ch)
{
	if ((ch >= '0') && (ch <= '9') )
		return true;
	else
		return false;
}

bool TParser::Brackets()
{
	int r = 0;
	int l = 0;
	for (int i = 0; i < (strlen(inf) + 1); i++)
	{
		if (inf[i] == '(') l++;
		else if (inf[i] == ')') r++;
	}
	return (r == l);
}

string TParser::Convertation()
{
	
	int pos = 0;
	char t;
	if (!Brackets()) throw "Check the brackets!";
	do
	{
		t = inf[pos];
		pos++;
		if (IsNumber(t))
		{
			string num;
			num = num + t;
			t = inf[pos];
			while (IsNumber(t))
			{
				num = num + t;
				pos++;
				t = inf[pos];
			}
			st_post.Push(num);
		}
		else if (t == '(')
		{
			st_op.Push(t);
		}
		else if (t == ')')
		{
			string op;
			char oper = st_op.Pop();
			while (oper != '(');
			{
				op = op + oper;
				st_post.Push(op);
				op = "";
				oper = st_op.Pop();
			} 

		}
		else if (IsOperation(t))
		{
			string op;
			if (st_op.IsEmpty()) st_op.Push(t);
			else
			{
				while (!st_op.IsEmpty())
				{
					char oper = st_op.Pop();
					if (Priority(t) <= Priority(oper))
					{
						op = op + oper;
						st_post.Push(op);
						op = "";
					}
					else
					{
						st_op.Push(oper); break;
					}
					
				}
				st_op.Push(t);
			}
		}
	} while ((pos < strlen(inf)) || t != '\0');
	while (!st_op.IsEmpty())
	{
		string j;
		j = j + st_op.Pop();
		st_post.Push(j);
	}
	while (!st_post.IsEmpty())
	{
		string a = st_post.Pop();
		st_post1.Push(a);
		a = "";
	}
	
	while (!st_post1.IsEmpty())
	{
		string b;
		b = st_post1.Pop();
		post = post + b;
		st_st.Push(b);
		b = "";
	}
	return post;
}

int TParser::Calculate()
{
	int res = 0;
	int op1 = 0;
	int op2 = 0;
	while (!st_st.IsEmpty())
	{
		string s;
		s = st_st.Pop();
		if (s == "+" || s == "-" || s == "*" || s == "/")
		{
			char t = s[0];
			op2 = st_ex.Pop();
			op1 = st_ex.Pop();
			switch (t)
			{
			case '+':res = op1 + op2; break;
			case '-':res = op1 - op2; break;
			case '*':res = op1*op2; break;
			case '/':res = op1 / op2; break;
			}
			st_ex.Push(res);
			
		}
		else
		{
			int t = atoi(s.c_str());
			st_ex.Push(t);
		}
		s = "";
	}
	return res;
}
