#pragma once
class complex
{
private:
	float re;
	float im;

public:
	
	complex();
	complex(int re);
	complex(int re, int im);

	complex operator =(const complex &number);
	complex operator +(const complex &number);
	complex operator -(const complex &number);
	complex operator *(const complex &number);
	complex operator /(const complex &number);
	complex operator ^(int power);
	int operator ~();

	void display();
	
	~complex();
};

