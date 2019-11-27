#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED
#include <iostream>
class Nod
{
    protected:
    char* info;
    Nod* next;
};
class Nod_dublu:public Nod
{
    protected:
    Nod* ante;
};
class Nod_prioritate:public Nod_dublu

{
    protected:
    int prio;
};
class Coada_prioritati:Nod_prioritate
{
     Nod_prioritate *x;
     Nod* cap=NULL;
     int MaxPrio,SIZE;
     int Capacity;
public:
    Coada_prioritati();//Constructor
    Coada_prioritati(int);//Constructor cu parametrii
    Coada_prioritati(const Coada_prioritati&);//Constructor de copiere
    ~Coada_prioritati();//destructor
    void Top();//intoarce primul cuvant din coada, cel cu prioritate maxima
    void Insert(Nod);//Insereaza o pereche {valoare,prioritate}
    void Pop();//Elimina elementul din coada
    bool isEmpty();
    int getMaxPrio();//Intoarce cea mai mare prioritate
    void List(int );//Functia care construieste o lista plecand de la un nod dat
    int getinfo();
    int getCapacity();
    int getSize();
    int getnext();
    Coada_prioritati operator+(Coada_prioritati const &);
    Coada_prioritati& operator=(const Coada_prioritati &);
    void operator++(int);
    void operator--(int);
    friend std::ostream& operator<<(std::ostream &,const Coada_prioritati &);
    friend std::istream& operator>>(std::istream &,Coada_prioritati &);
};

#endif // NOD_H_INCLUDED
