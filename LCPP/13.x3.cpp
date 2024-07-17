#include <bits/stdc++.h>

template <typename T = int, typename U = int, typename V = int>
struct Triad
{
    T num1 {};
    U num2 {};
    V num3 {};
};

template <typename T, typename U, typename V>
Triad(T, U, V) -> Triad<T, U, V>;

template <typename T, typename U, typename V>
void print(const Triad<T, U, V>& t)
{
    std::cout << "[" << t.num1 << ", " << t.num2 << ", " << t.num3 << "]"; 
}

int main()
{
	Triad t1{ 1, 2, 3 };
	print(t1);

	Triad t2{ 1.2, 3, 5.6 };
	print(t2);

	return 0;
}
