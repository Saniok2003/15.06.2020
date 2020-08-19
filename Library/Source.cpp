# include <iostream>
#include <string>
using namespace std;
class Library;
class Book
{
private:
	string name;
	string autor;
	string publishing;
	int year = 0;
	float rating = 0;
public:
	Book()
	{
		name = "";
		autor = "";
		publishing = "";
		year = 0;
		rating = 0;
	}
	Book(string name, string publishing, string autor, int year, float rating)
	{
		this->name = name;
		this->autor = autor;
		this->publishing = publishing;
		this->year = year;
		this->rating = rating;
	}
	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Autor: " << autor << endl;
		cout << "Publishing: " << publishing << endl;
		cout << "Year: " << year << endl;
		cout << "Rating: " << rating << endl;
	}

	friend Library;

};
class Library
{
private:
	static const int size = 10;
	Book arr[size];
public:

	Library(Book book)
	{

	}
	Library& operator=(const Book& other)
	{
		for (int i = 0; i < size;)
		{
			if (arr[i].name == "")
			{
				arr[i].name = other.name;
				arr[i].autor = other.autor;
				arr[i].publishing = other.publishing;
				arr[i].year = other.year;
				arr[i].rating = other.rating;
				break;
			}
			else
			{
				i++;
			}

		}
		return *this;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].name != "")
			{
				cout << "Name: " << arr[i].name << endl;
				cout << "Autor: " << arr[i].autor << endl;
				cout << "Publishing: " << arr[i].publishing << endl;
				cout << "Year: " << arr[i].year << endl;
				cout << "Rating: " << arr[i].rating<<"/10" << endl << endl;
			}
		}
	}
	void PrintForSearch(int gfg)
	{
		cout << "Name: " << arr[gfg].name << endl;
		cout << "Autor: " << arr[gfg].autor << endl;
		cout << "Publishing: " << arr[gfg].publishing << endl;
		cout << "Year: " << arr[gfg].year << endl;
		cout << "Rating: " << arr[gfg].rating << "/10" << endl;
	}
	void SearchName(string g)
	{
		cout << endl << endl;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].name.find(g) != string::npos)
			{
				PrintForSearch(i);
			}
		}
	}

	void SearchAutor(string g)
	{
		cout << endl << endl;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].autor.find(g) != string::npos)
			{
				PrintForSearch(i);
			}
		}
	}
	void SearchPublishing(string g)
	{
		cout << endl << endl;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].publishing.find(g) != string::npos)
			{
				PrintForSearch(i);
			}
		}
	}
	void Sort()
	{
		Book temp;
		for (int i = 1; i < size; i++)
		{
			for (int j = 1; j < size - i - 1; j++)
			{
				if (arr[j - 1].rating < arr[j].rating)
				{
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void SortYear()
	{
		Book temp;
		for (int i = 1; i < size; i++)
		{
			for (int j = 1; j < size - i - 1; j++)
			{
				if (arr[j - 1].year < arr[j].year)
				{
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void SearchRating(float a)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].rating == a)
			{
				cout << "\nResut search rating" << endl;
				PrintForSearch(i);
			}
		}
	}
	
	void SearchYear(int a)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].year == a)
			{
				cout << "\nResut search year" << endl;
				PrintForSearch(i);
			}
		}
	}
};
int main()
{

	Book b1("Dead Dynasty", "Olga", "Oreo", 1999, 10);
	Book b2("Formula life ", "Kate", "Oreo", 2008, 8);
	Book b3("Dead Note", "Oleg", "Wno", 1329, 9);
	b1.Print();
	Library lib(b2);
	lib.operator=(b1);
	lib.operator=(b2);
	lib.operator=(b3);
	lib.Sort();
	lib.Print();
	lib.SortYear();
	lib.Print();

	system("pause");
	return 0;
}