#include <iostream>
#include <cassert>

using namespace std;
typedef unsigned long long ull;

constexpr ull mid(int a, int b) { return (a+b) / 2; }

/*
 * Sqrt helper template
 */

template<int N, int l, int r>
struct sqrt_st_helper
{
	static const int value = (mid(l,r)*mid(l,r)==N) ? mid(l,r) : 
								(r == l + 1 && l*l < N && r*r > N) ? l :
									sqrt_st_helper<N, 
												(mid(l,r) * mid(l,r) > N) ? l : mid(l,r), 
												(mid(l,r) * mid(l,r) > N) ? mid(l,r) : r>::value;
};

template<int N, int l>
struct sqrt_st_helper<N, l, l>
{
	static const int value = l;
};

/*
 * Main sqrt template
 * Returns integer equal to floor(sqrt(N))
 */

template<int N>
struct sqrt_st
{
	static const int value = sqrt_st_helper<N, 1, N>::value;
};

int main()
{
	assert(sqrt_st<0>::value == 0);
	assert(sqrt_st<1>::value == 0);
	assert(sqrt_st<2>::value == 1);
	assert(sqrt_st<3>::value == 1);
	assert(sqrt_st<4>::value == 2);
	assert(sqrt_st<5>::value == 2);
	assert(sqrt_st<6>::value == 2);
	assert(sqrt_st<7>::value == 2);
	assert(sqrt_st<8>::value == 2);
	assert(sqrt_st<9>::value == 3);
	assert(sqrt_st<10>::value == 3);
	assert(sqrt_st<11>::value == 3);
	assert(sqrt_st<12>::value == 3);
	assert(sqrt_st<13>::value == 3);
	assert(sqrt_st<14>::value == 3);
	assert(sqrt_st<15>::value == 3);
	assert(sqrt_st<16>::value == 4);
	assert(sqrt_st<17>::value == 4);
	assert(sqrt_st<18>::value == 4);
	assert(sqrt_st<19>::value == 4);
	assert(sqrt_st<20>::value == 4);

	assert(sqrt_st<64>::value == 8);
	assert(sqrt_st<256>::value == 16);

	assert(sqrt_st<1023>::value == 31);
	assert(sqrt_st<1024>::value == 32);
	assert(sqrt_st<1025>::value == 32);
	assert(sqrt_st<1000000>::value == 1000);
	assert(sqrt_st<17994564>::value == 4242);

	return 0;
}
