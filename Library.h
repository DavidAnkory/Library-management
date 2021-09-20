#pragma once
#include <string>
using namespace std;


class Library
{
	int code_book;
	string author;
	string book;

public:
	Library():code_book(0),author("\0"),book("\0") {}

//operators
	bool operator==(Library& lb) const;
	bool operator!=(Library& lb) const;

	bool operator>(Library& lb) const;
	bool operator>=(Library& lb) const;

	bool operator<(Library& lb) const;
	bool operator<=(Library& lb) const;

//frinde methods
	friend std::istream& operator>>(std::istream& in, Library& lb);//cin 
	friend std::ostream& operator<<(std::ostream& out, const Library& lb);//cout
};

//the cpp file
bool Library::operator==(Library& lb) const
{
	return( (code_book==lb.code_book) && (author==lb.author) &&(book==lb.book) );
}

bool Library::operator!=(Library& lb) const
{
	return !(*this==lb);
}

bool Library::operator>(Library& lb) const
{
	if (author == lb.author)
	{
		if (book == lb.book)
		{
			if (code_book == lb.code_book)
			{
				return false;
			}
			else
			{
				return code_book > lb.code_book;
			}
		}
		else
		{
			return book > lb.book;
		}
	}
	else
	{
		return author > lb.author;
	}

}

bool Library::operator>=(Library& lb) const
{
	if (*this == lb)
	{
		return true;
	}
	else
	{
		return (*this > lb);
	}
}


bool Library::operator<(Library& lb) const
{
	if (author == lb.author)
	{
		if (book == lb.book)
		{
			if (code_book == lb.code_book)
			{
				return false;
			}
			else
			{
				return code_book > lb.code_book;
			}
		}
		else
		{
			return book < lb.book;
		}
	}
	else
	{
		return author < lb.author;
	}

}


bool Library::operator<=(Library& lb) const
{
	if (*this == lb)
	{
		return true;
	}
	else
	{
		return (*this < lb);
	}
}

std::istream& operator>>(std::istream& in, Library& lb)
{
	in >> lb.code_book;
	in >> lb.author;
	in >> lb.book;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Library& lb)
{
	out << lb.code_book << ' ' << lb.author << ' ' << lb.book << endl;
	return out;
}


