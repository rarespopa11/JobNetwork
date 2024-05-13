#pragma once
class Data
{
	int zi, luna, an;
public:
	Data(int, int, int);
	Data();
	Data& operator=(const Data&);
	const int& getzi() const;
	const int& getluna() const;
	const int& getan() const;
	void print();
};

