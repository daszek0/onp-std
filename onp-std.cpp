#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	stack<pair<string, int>> o;
	pair<string, int> a1, a2, a;
	string inp;
	cin >> inp;
	while (inp != "=")
	{
		if (inp == "+" || inp == "-" || inp == "*" || inp == "/" || inp == "^")
		{
			if (o.empty())
			{
				cerr << "Brakuje argumentów.\n";
				exit(0);
			}
			a2 = o.top();
			o.pop();
			if (o.empty())
			{
				cerr << "Brakuje argumentów.\n";
				exit(0);
			}
			a1 = o.top();
			o.pop();
			if (inp == "+" || inp == "-")
				a.second = 2;
			else if (inp == "*" || inp == "/")
				a.second = 1;
			else
				a.second = 0;
			a.first = (a1.second > a.second ? "(" : "") + a1.first + (a1.second > a.second ? ")" : "") + " " + inp + " " + (a2.second > a.second ? "(" : "") + a2.first + (a2.second > a.second ? ")" : "");
			o.push(a);
		}
		else
		{
			for (auto i : inp)
				if (i < '0' || i > '9')
				{
					cerr << "Błędny argument/operator: " << inp << ".\n";
					exit(0);
				}
			o.push(make_pair(inp, 0));
		}
		cin >> inp;
	}
	if (o.size() > 1)
	{
		cerr << "Brakuje operatorów.\n";
		exit(0);
	}
	else
		cout << o.top().first << "\n";
	return 0;
}