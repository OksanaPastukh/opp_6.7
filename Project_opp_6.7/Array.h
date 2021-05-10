#pragma once
#include <iostream>
using namespace std;
// ≥нтерфейс, що описуЇ функтори - унарн≥ предикати
template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};
// реал≥зуЇмо ≥нтерфейс функтором - перев≥рка, чи значенн€ дор≥внюЇ нулю
template<class T>
class Zero : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};
// реал≥зуЇмо ≥нтерфейс функтором - перев≥рка, чи значенн€ додатне
// працюЇ лише дл€ числових тип≥в
template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};
// реал≥зуЇмо ≥нтерфейс функтором - перев≥рка, чи значенн€ в≥д'Їмне
// працюЇ лише дл€ числових тип≥в
template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};
// реал≥зуЇмо ≥нтерфейс функтором - перев≥рка, чи значенн€ парне
// працюЇ лише дл€ ц≥лих тип≥в
template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};
// реал≥зуЇмо ≥нтерфейс функтором - перев≥рка, чи значенн€ не парне
// працюЇ лише дл€ ц≥лих тип≥в
template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};
// дублюЇмо вс≥ елементи
// begin - ≥тератор початку вх≥дного контейнера (вказуЇ на перший елемент)
// end - ≥тератор к≥нц€ вх≥дного контейнера (вказуЇ на елемент п≥сл€ останнього)
// to - ≥тератор початку результуючого контейнера (вказуЇ на перший елемент)
template<class T>
int replace_copy(T* begin, T* end, T* to, const T& old_value, const T& new_value)
{
	int n = 0; // n - к≥льк≥сть елемент≥в у результуючому контейнер≥
	for (T* from = begin; from < end; from++) // from - ≥тератор вх≥дного контейнера
	{ // вказуЇ на поточний елемент
		*to = (*from == old_value) ? new_value : *from;
		to++;
		n++;
	}
	return n;
}

// дублюЇмо елементи, дл€ €ких предикат p набуваЇ значенн€ true
// begin - ≥тератор початку вх≥дного контейнера (вказуЇ на перший елемент)
// end - ≥тератор к≥нц€ вх≥дного контейнера (вказуЇ на елемент п≥сл€ останнього)
// to - ≥тератор початку результуючого контейнера (вказуЇ на перший елемент)
template<class T>
int replace_copy_if(T* begin, T* end, T* to, Predicate<T>& p, const T& new_value)
{
	int n = 0; // n - к≥льк≥сть елемент≥в у результуючому контейнер≥
	for (T* from = begin; from < end; from++) // from - ≥тератор вх≥дного контейнера
	{ // вказуЇ на поточний елемент
		*to = p(*from) ? new_value : *from;
		to++; // скоп≥ювали елемент
		n++;
	}
	return n;
}

