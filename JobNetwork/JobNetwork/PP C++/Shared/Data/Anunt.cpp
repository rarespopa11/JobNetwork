#include "Anunt.h"
#include<iostream>
Anunt::Anunt(int id1, int nr_a, vector<string>apl, Data d, string nj, string nc, string dom, string de, string sk)
{
    ID = id1;
    nraplicanti = nr_a;
    aplicanti = apl;
    data = d;
    nume_job = nj;
    nume_companie = nc;
    domeniu = dom;
    descriere = de;
    skills = sk;

}
void Anunt::print() {
    cout << "ID: " << ID << "\n";
    if(nraplicanti>0)
    cout << "Numar aplicanti: " << nraplicanti << "\n";
    cout << "Data: ";
    data.print(); 
    cout << "Nume Job: " << nume_job << "\n";
    cout << "Nume Companie: " << nume_companie << "\n";
    cout << "Domeniu: " << domeniu << "\n";
    cout << "Descriere: " << descriere << "\n";
    cout << "Skills: " << skills << "\n";
   /* if (nraplicanti > 0) {
        std::cout << "Aplicanti:\n";
        for (const auto& aplicant : aplicanti) {
            std::cout << aplicant << std::endl;
        }
    }*/
    cout << "\n";
}
Anunt::Anunt()
{
    ID = -1;
    nraplicanti = 0;
    data = Data(0,0,0);

}
Anunt& Anunt::operator=(const Anunt& other) {
    if (this == &other) {
        return *this;
    }

    nraplicanti = other.nraplicanti;
    ID = other.ID;
    data = other.data;
    nume_job = other.nume_job;
    nume_companie = other.nume_companie;
    domeniu = other.domeniu;
    descriere = other.descriere;
    skills = other.skills;
    aplicanti = other.aplicanti;

    return *this;
}

int Anunt::getNraplicanti() const {
    return nraplicanti;
}

int Anunt::getID() const {
    return ID;
}

const Data& Anunt::getData() const {
    return data;
}

const string& Anunt::getNumeJob() const {
    return nume_job;
}

const string& Anunt::getNumeCompanie() const {
    return nume_companie;
}

const string& Anunt::getDomeniu() const {
    return domeniu;
}

const string& Anunt::getDescriere() const {
    return descriere;
}

const string& Anunt::getSkills() const {
    return skills;
}

const vector<string>& Anunt::getAplicanti() const {
    return aplicanti;
}

void Anunt::setNumeJob(string nj) {
    nume_job=nj;
}

void Anunt::setNumeCompanie(string nc) {
    nume_companie=nc;
}
void Anunt::setDomeniu(string dom) {
    domeniu=dom;
}

void Anunt::setDescriere(string de) {
    descriere=de;
}

void Anunt::setSkills(string sk) {
    skills=sk;
}
void Anunt::setNraplicanti(int nr)
{
    nraplicanti=nr;
}
void Anunt::setAplicanti(vector<string> apl) {
    aplicanti = apl;
}