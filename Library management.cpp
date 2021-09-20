using namespace std;
#include <iostream>
#include "SearchTree.h"
#include "Library.h"


enum { END='e', ADD='a', REMOVE='b', SEARCH='c', PRINT='d' };
int main() {
	char ch;
	SearchTree<Library> T1;
	Library lb;

	cout << "enter a-e:" << endl;
	cin >> ch;
	while (ch != END)
	{
		switch (ch)
		{
		case ADD: cout << "enter a book" << endl;
			cin >> lb;
			T1.add(lb);
			break;

		case REMOVE: cout << "enter a book" << endl;
			cin >> lb;
			T1.remove(lb);
			break;

		case SEARCH: cout << "enter a book" << endl;
			cin >> lb;
			if (T1.search(lb)) {
				cout << "exist" << endl;
			}
			else
			{
				cout << "no exsit" << endl;
			}
			break;

		case PRINT: T1.inOrder();
			break;

		default: cout << "ERROR" << endl;
			break;
		}
		cout << "enter a-e:" << endl;
		cin >> ch;
	}

	return 0;
	
}

/*
enter a-e:
a
enter a book
2 b b
enter a-e:
a
enter a book
1 a a
enter a-e:
a
enter a book
4 d d
enter a-e:
a
enter a book
7 g g
enter a-e:
a
enter a book
3 c c
enter a-e:
b
enter a book
5 e e
enter a-e:
d
1 a a
 2 b b
 3 c c
 4 d d
 7 g g
 enter a-e:
e

C:\Users\ankor\Documents\מדעי המחשב- שנה א\סמסטר ב\סדנה C++\exercice9.2\Debug\exercice9.2.exe (process 17232) exited with code 0.
Press any key to close this window . . .
*/
