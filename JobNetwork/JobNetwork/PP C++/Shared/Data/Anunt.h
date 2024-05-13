#pragma once
#include "Data.h"
#include <string>
#include <vector>
using namespace std;
class Anunt
{
private:
	int nraplicanti;
	int ID;
	Data data;
	string nume_job, nume_companie, domeniu, descriere, skills;
	vector<string> aplicanti;
public:
	void setSkills(string);
	void setNumeJob(string);
	void setNumeCompanie(string);
	void setDomeniu(string);
	void setDescriere(string);
	void setNraplicanti(int);
	void setAplicanti(vector<string>);
	int getNraplicanti() const;

    int getID() const;

    const Data& getData() const;

    const string& getNumeJob() const;
    const string& getNumeCompanie() const;

    const string& getDomeniu() const;
    const string& getDescriere() const;

    const string& getSkills() const;

    const vector<string>& getAplicanti() const;
	Anunt();
	void print();
	Anunt(int, int, vector<string>, Data, string, string, string, string, string);
	Anunt& operator=(const Anunt&);
};




