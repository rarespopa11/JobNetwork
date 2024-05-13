#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <Anunt.h>
#include <Data.h>
using namespace std;
vector<Anunt> Citire();
void afisare_anunturi()
{
    vector<Anunt> lista;
    lista = Citire();
    for (int i = 0; i < lista.size(); i++)
        lista[i].print();
}
void aplicare_job(int ID, string nume) {
    vector<Anunt> lista;
    vector<string> aplicanti;
    Data data;
    ofstream listaout;
    string filename = "D:\\JobNetwork\\JobNetwork\\PP C++\\Shared\\Files\\Anunturi.txt";
    lista = Citire();
    bool ok = true;
    int poz = -1;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getID() == ID) {
            poz = i;
            aplicanti = lista[i].getAplicanti();
            for (int j = 0; j < aplicanti.size(); j++) {
                if (aplicanti[j] == nume) {
                    ok = false;
                    break;
                }
            }
            break;
        }
    }
    if (poz != -1 && ok == true) {
        vector<string> updatedAplicanti = aplicanti;  // Create a new vector for applicants
        updatedAplicanti.push_back(nume);
        lista[poz].setNraplicanti(updatedAplicanti.size());
        lista[poz].setAplicanti(updatedAplicanti);
        listaout.open(filename.c_str());
        listaout << lista.size() << "\n";
        for (int i = 0; i < lista.size(); i++) {
            if (lista.empty())
                continue;
            data = lista[i].getData();
            if (lista[i].getNraplicanti() == 0)
                listaout << lista[i].getNraplicanti() << "\n" << lista[i].getNumeJob() << "\n" <<
                lista[i].getNumeCompanie() << "\n" << lista[i].getDomeniu() << "\n" << lista[i].getDescriere() <<
                "\n" << lista[i].getSkills() << "\n" << lista[i].getID() << "\n" << data.getzi() << "\n" << data.getluna() <<
                "\n" << data.getan() << "\n";
            else {
                listaout << lista[i].getNraplicanti() << "\n";
                updatedAplicanti = lista[i].getAplicanti();
                for (int j = 0; j < updatedAplicanti.size(); j++)
                    listaout << updatedAplicanti[j] << "\n";
                listaout << lista[i].getNumeJob() << "\n" <<
                    lista[i].getNumeCompanie() << "\n" << lista[i].getDomeniu() << "\n" << lista[i].getDescriere() <<
                    "\n" << lista[i].getSkills() << "\n" << lista[i].getID() << "\n" << data.getzi() << "\n" <<
                    data.getluna() << "\n" << data.getan() << "\n";
            }
        }
        listaout.close();
    }
}
void filtrare(string sk)
{
    string temp;
    vector<Anunt> lista;
    lista = Citire();
    int c = 0;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getSkills().find(sk) != string::npos) {
            lista[i].print();
            c += 1;
        }
    }
    if (c == 0)
        cout << "Nu exista anunt cu skill-ul specificat.\n";
}
vector<Anunt> Citire()
{
    int nr_anunturi;
    string aplicant;
    string tempint;
    vector<Anunt> lista;
    int nr_a, id, zi, luna, an;
    Data d;
    string nj, nc, dom, de, sk;
    vector<string>aplicanti;
    string filename = "D:\\JobNetwork\\JobNetwork\\PP C++\\Shared\\Files\\Anunturi.txt";
    ifstream listain;
    listain.open(filename.c_str());
    getline(listain, tempint);
    nr_anunturi = stoi(tempint);
    if (nr_anunturi != 0)
        for (int i = 0; i < nr_anunturi; i++)
        {
            aplicanti.clear();
            getline(listain, tempint);
            nr_a = stoi(tempint);
            if (nr_a > 0)
            {
                for (int j = 0; j < nr_a; j++) {
                    getline(listain, aplicant);
                    aplicanti.push_back(aplicant);
                }
            }
            getline(listain, nj);
            getline(listain, nc);
            getline(listain, dom);
            getline(listain, de);
            getline(listain, sk);
            getline(listain, tempint);
            id = stoi(tempint);
            getline(listain, tempint);
            zi = stoi(tempint);
            getline(listain, tempint);
            luna = stoi(tempint);
            getline(listain, tempint);
            an = stoi(tempint);
            d = Data(zi, luna, an);
            if (nr_a == 0) {
                lista.push_back(Anunt(id, 0, aplicanti, d, nj, nc, dom, de, sk));
            }
            else
                lista.push_back(Anunt(id, nr_a, aplicanti, d, nj, nc, dom, de, sk));
        }

    listain.close();
    return lista;
}
void comenzi()
{
    cout << "1. -Afisare_Anunturi\n";
    cout << "2. -Aplicare_Job <ID> <Nume>\n";
    cout << "3. -Filtrare <Skill>\n";

}

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-comenzi") == 0)
        if (argc == 2)
            comenzi();
        else cout << "Sintaxa incorecta! Sintaxa corecta: App2.exe -comenzi\n";
    else if (strcmp(argv[1], "-Afisare_Anunturi") == 0)
        if (argc == 2)
            afisare_anunturi();
        else cout << "Sintaxa incorecta! Sintaxa corecta: App2.exe -Afisare_Anunturi\n";
     else if (strcmp(argv[1], "-Aplicare_Job") == 0)
        if(argc==4)
         aplicare_job(atoi(argv[2]), argv[3]);
        else cout<< "Sintaxa incorecta! Sintaxa corecta: App2.exe -Aplicare_Job <ID> <Nume>\n";
     else if (strcmp(argv[1], "-Filtrare") == 0)
        if(argc==3)
         filtrare(argv[2]);
        else cout<<"Sintaxa incorecta! Sintaxa corecta: App2.exe -Filtrare <Skill>\n";
     else std::cout << "Comanda inexistenta!\n";
    return 0;
}