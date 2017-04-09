#include <iostream>
#include <cstdio>

// Definicja typu obiektowego stack
//---------------------------------
struct list
{
	list * next;
	int data;

};
struct stack
{
	list * S; // lista przechowuj¹ca stos

	stack(); // konstruktor
	~stack(); // destruktor
	bool empty(void);
	list * top(void);
	void push(int v);
	void pop(void);
	void show(void);
	void change_pos(void);
	void sum(void);
	void moveToNPlace(void);
	list * search(int n);
};
//---------------------
// Metody obiektu stack
//---------------------
// Konstruktor
//------------
stack::stack()
{
	S = NULL;

}
// Destruktor - zwalnia tablicê dynamiczn¹
//----------------------------------------
stack::~stack()
{
	while (S) pop();

}
// Sprawdza, czy stos jest pusty
//------------------------------
bool stack::empty(void)
{
	return !S;
}
// Zwraca szczyt stosu
//--------------------
list * stack::top(void)
{
	return S;
}
// Zapisuje na stos
//-----------------
void stack::push(int v)
{
	list * e = new list;
	e->data = v;
	e->next = S;
	S = e;

}
// Usuwa ze stosu
//---------------
void stack::pop(void)
{
	if (S)
	{
		list * e = S;
		S = S->next;
		delete e;
	}

}

// Wyœwietla stos
//---------------
void stack::show()
{
	list * tmp;
	tmp = top();
	while (tmp != NULL)
	{
		if (tmp->next != NULL)
			printf("%d ", tmp->data);
		else
		{
			printf("%d", tmp->data);
			break;
		}
		tmp = tmp->next;
	}
}

// Wyjmuje 2 liczby ze stosu i sumuje
//---------------
void stack::sum()
{
	list * l1 = S;
	list * l2 = S->next;

	int sum = l1->data + l2->data;

	pop();
	pop();

	push(sum);
}

// Zamienia 2 liczby miejscami
//---------------
void stack::change_pos()
{
	list * l1 = S;
	list * l2 = l1->next;
	list * l3 = l2->next;

	S = l2;
	l2->next = l1;
	l1->next = l3;
}
// Szuka poprzednika n-tego miejsca
//---------------
list * stack::search(int n)
{
	list * target = S;
	int counter = 0;

	while (target != NULL && counter < n - 1)
	{
		target = target->next;
		counter++;
	}

	return target;
}

// Przenosi liczbe z góry stosu na n-te miejsce na stosie
//---------------
void stack::moveToNPlace()
{
	if (S != NULL)
	{
		int n = S->data;
		pop();
		list * target = search(n);

		if (target != NULL)
		{
			list * l1 = S;
			list * l2 = target;
			list * l3 = l2->next;

			if (n == 2)
				change_pos();
			if (n >= 3)
			{
				S = S->next;
				l2->next = l1;
				l1->next = l3;
			}
		}
	}
}

//---------------
// Program g³ówny
//---------------
int main()
{
	stack * stos = new stack();

	const int rozmiar = 20;

	char t[rozmiar] = { '\0' };
	char *p, *q;

	bool endOfNumber = false;
	bool isNumber = false;
	
	int liczba = 0;
	int calaLiczba = 0;

	while (fgets(t, sizeof t, stdin))
	{
		liczba = 0;
		endOfNumber = false;
		isNumber = false;
		calaLiczba = 0;

		if (t[0] == 'q')
			break;
		for (p = t, q = t + sizeof t; p < q; p++)
		{
			switch (*p)
			{
				case '\n':
					endOfNumber = true;
					break;
				case ' ':
					endOfNumber = true;
					break;
				case 'p':
					if(stos->S != NULL)
						stos->show();
					break;
				case 's':
					if (stos->S->next != NULL)
						stos->change_pos();
					break;
				case 'x':
					if (stos->S != NULL)
						stos->pop();
					break;
				case '+':
					if (stos->S->next != NULL)
						stos->sum();
					break;
				case 'r':
					stos->moveToNPlace();
					break;
			}
			if (*p >= 48 && *p <= 57)
			{
				liczba = *p - 48;
				calaLiczba = calaLiczba * 10 + liczba;
				isNumber = true;
			}

			if (endOfNumber && isNumber)
			{
				stos->push(calaLiczba);
				endOfNumber = false;
				isNumber = false;
				calaLiczba = 0;
			}		
		}

		for (int i = 0; i < rozmiar; i++)
			t[i] = '\0';

		printf("\n");
	}

	return 0;
}