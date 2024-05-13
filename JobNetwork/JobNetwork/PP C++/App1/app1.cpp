#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <Anunt.h>
#include <Data.h>
using namespace std;
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
void modificare(int ID, string nj, string nc, string dom, string de, string sk) {
    vector<Anunt> lista;
    lista = Citire();
    for(int i=0;i<lista.size();i++)
        if (lista[i].getID() == ID)
        {
            if (nj != "NULL")
                lista[i].setNumeJob(nj);
            if (nc != "NULL")
                lista[i].setNumeCompanie(nc);
            if (dom != "NULL")
                lista[i].setDomeniu(dom);
            if (de != "NULL")
                lista[i].setDescriere(de);
            if (sk != "NULL")
                lista[i].setSkills(sk);
            break;

        }
    Data data;
    vector<string> aplicanti;
    string filename = "D:\\JobNetwork\\JobNetwork\\PP C++\\Shared\\Files\\Anunturi.txt";
    ofstream listaout;
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
        else
        {
            listaout << lista[i].getNraplicanti() << "\n";
            aplicanti = lista[i].getAplicanti();
            for (int j = 0; j < aplicanti.size(); j++)
                listaout << aplicanti[j] << "\n";
            listaout << lista[i].getNumeJob() << "\n" <<
                lista[i].getNumeCompanie() << "\n" << lista[i].getDomeniu() << "\n" << lista[i].getDescriere() <<
                "\n" << lista[i].getSkills() << "\n" << lista[i].getID() << "\n" << data.getzi() << "\n" <<
                data.getluna() << "\n" << data.getan() << "\n";
        }
    }
    listaout.close();
}
void adaugare(string nj, string nc, string dom, string de, string sk, int z, int l, int a)
{
    string aplicant;
    vector<Anunt> lista;
    Anunt temp;
    Data data;
    int nranunturi;
    string filename = "D:\\JobNetwork\\JobNetwork\\PP C++\\Shared\\Files\\Anunturi.txt";
    ifstream listain;
    listain.open(filename.c_str());
    listain >> nranunturi;
    int id;
    listain.close();
    if (nranunturi != 0) {
        lista = Citire();
        id = lista[lista.size()-1].getID()+1;
    }
    else id = 0;
    vector<string> aplicanti;
    temp=Anunt(id, 0, aplicanti, Data(z, l, a), nj, nc, dom, de, sk);
    temp.print();
    lista.push_back(temp);
    ofstream listaout;
    listaout.open(filename.c_str());
    listaout << lista.size()<<"\n";
    for (int i = 0; i < lista.size(); i++) {
        if (lista.empty())
            continue;
        data = lista[i].getData();
        if (lista[i].getNraplicanti() == 0)
            listaout << lista[i].getNraplicanti() << "\n" << lista[i].getNumeJob() << "\n" <<
            lista[i].getNumeCompanie() << "\n" << lista[i].getDomeniu() << "\n" << lista[i].getDescriere() <<
            "\n" << lista[i].getSkills() << "\n"<<lista[i].getID()<<"\n"<<data.getzi() << "\n"<<data.getluna() <<
            "\n"<<data.getan() << "\n";
        else
        {
            listaout << lista[i].getNraplicanti() << "\n";
            aplicanti = lista[i].getAplicanti();
            for (int j = 0; j < aplicanti.size(); j++)
                listaout << aplicanti[j] << "\n";
            listaout << lista[i].getNumeJob() << "\n" <<
                lista[i].getNumeCompanie() << "\n" << lista[i].getDomeniu() << "\n" << lista[i].getDescriere() <<
                "\n" << lista[i].getSkills() << "\n" << lista[i].getID() << "\n" << data.getzi() << "\n" << 
                data.getluna() << "\n" << data.getan() << "\n";
        }
    }
    listaout.close();
        }   
void stergere(int ID)
{
    vector<Anunt> lista;
    Data data;
    vector<string> aplicanti;
    string filename = "D:\\JobNetwork\\JobNetwork\\PP C++\\Shared\\Files\\Anunturi.txt";
    lista = Citire();
    for (int i = 0; i < lista.size(); i++)
        if (lista[i].getID() == ID)
            lista.erase(lista.begin()+i);
    ofstream listaout;
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
        else
        {
            listaout << lista[i].getNraplicanti() << "\n";
            aplicanti = lista[i].getAplicanti();
            for (int j = 0; j < aplicanti.size(); j++)
                listaout << aplicanti[j] << "\n";
            listaout << lista[i].getNumeJob() << "\n" <<
                lista[i].getNumeCompanie() << "\n" << lista[i].getDomeniu() << "\n" << lista[i].getDescriere() <<
                "\n" << lista[i].getSkills() << "\n" << lista[i].getID() << "\n" << data.getzi() << "\n" <<
                data.getluna() << "\n" << data.getan() << "\n";
        }
    }
    listaout.close();

}
void comenzi()
{
    cout << "1. -Postare <Nume Job> <Nume Companie> <Domeniu> " <<
        "<Descriere> <Skill-urii necesare> <Ziua> <Luna> <Anul>\n";
    cout << "2. -Modificare <ID> <Nume Job> <Nume Companie> <Domeniu> <Descriere> <Skill-uri Necesare> (Pentru a ignora modificarile unei categorii adaugati NULL\n";
    cout << "3. -Stergere <ID>\n";
    cout << "4. -Vizualizare_Candidati <ID>\n";

}
void vizualizare_candidati(int ID)
{
    vector<Anunt> lista;
    vector<string> aplicanti;
    lista = Citire();
    for (int i = 0; i < lista.size(); i++)
        if (lista[i].getID() == ID) {
            if (lista[i].getNraplicanti() == 0)
            {
                std::cout << "Nu exista candidati!\n";
                return;
            }
            aplicanti = lista[i].getAplicanti();
            for (int j = 0; j < aplicanti.size(); j++)
                std::cout << aplicanti[j] << "\n";
            return;
        }
        cout << "Nu exista acest ID de job!\n";

}

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-comenzi") == 0)
        if (argc == 2)
            comenzi();
        else cout << "Sintaxa invalida! Sintaxa corecta: App1.exe -comenzi\n";
    else if (strcmp(argv[1], "-Postare") == 0)
        if (argc == 10)
            adaugare(argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atoi(argv[8]), atoi(argv[9]));
        else cout << "Sintaxa invalida! Sintaxa corecta: App1.exe -Postare <Nume Job> <Nume Companie> < Domeniu> " <<
            "<Descriere> <Skill-urii necesare> <Ziua> <Luna> <Anul>\n";
    else if (strcmp(argv[1], "-Modificare") == 0)
        if (argc==8)
        modificare(atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7]);
        else cout << "Sintaxa invalida! Sintaxa corecta: App1.exe -Modificare <ID> <Nume Job> <Nume Companie> <Domeniu> <Descriere> <Skill-uri Necesare>"<<
             "(Pentru a ignora modificarile unei categorii adaugati NULL\n";
    else if (strcmp(argv[1], "-Stergere") == 0)
        if(argc==3)
        stergere(atoi(argv[2]));
        else cout << "Sintaxa invalida! Sintaxa corecta: App1.exe -Stergere <ID>\n";
    else if (strcmp(argv[1], "-Vizualizare_Candidati") == 0)
        if(argc==3)
        vizualizare_candidati(atoi(argv[2]));
        else cout << "Sintaxa invalida! Sintaxa corecta: App1.exe -Vizualizare_Candidati <ID>\n";
    else std::cout << "Comanda nu exista!\n";
 
    return 0;
}
