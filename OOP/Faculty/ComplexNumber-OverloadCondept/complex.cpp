#include "complex.h"
#include <iostream>



complex::complex()
{
	this->re = 0;
	this->im = 0;
}

complex::complex(int re)
{
	this->re = re;
	this->im = 0;
}

complex::complex(int re, int im)
{
	this->re = re;
	this->im = im;
}

complex complex::operator=(const complex &number)
{
	complex temp;

	temp.re = number.re;
	temp.im = number.im;

	return temp;
}

complex complex::operator+(const complex &number)
{	
	complex temp;
	
	temp.re = this->re + number.re;
	temp.im = this->im + number.im;

	return temp;
}

complex complex::operator-(const complex &number)
{
	complex temp;

	temp.re = this->re - number.re;
	temp.im = this->im - number.im;

	return temp;
}

complex complex::operator*(const complex &number)
{
	complex temp;

	temp.re = this->re * number.re - this->im * number.im;
	temp.im = this->re * number.im + this->im * number.re;

	return temp;
}

complex complex::operator /(const complex &number)
{	
	complex multiply, multiply2, invers, division;
	multiply.re = this->re * number.re - this->im * number.im;
	multiply.im = this->re * number.im + this->im * number.re;

	invers.re = number.re;
	invers.im = -number.im;

	multiply2.re = invers.re * number.re - invers.im * number.im;

	division.re = multiply.re / multiply2.re;
	division.im = multiply.im / multiply2.re;

	return division;
}

complex complex::operator^(int power)
{	
	complex temp, temp2;

	if (power == 1)
	{
		return complex();
	}
	else if (power >= 2)
	{	
		temp.re = this->re * this->re - this->im * this->im;
		temp.im = this->re * this->im + this->im * this->re;
		
		for (int i = 2; i < power; i++) {
			temp2.re = temp.re * this->re - temp.im * this->im;
			temp2.im = this->im * temp.re + this->re * temp.im;

			temp = temp2;
		}

		return temp2;
	}

	
}

int complex::operator~()
{	
	int modul;

	modul = this->re * this->re + this->im * this->im;

	return modul;
}

void complex::display()
{
	std::cout << "(" << re << ")" << " + " << "(" << im << "i" << ")" << std::endl;
}


complex::~complex()
{
}
