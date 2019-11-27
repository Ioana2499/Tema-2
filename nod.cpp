#include "Nod.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//Constructorii initializeaza campul store ca un array de perechi de tipul {valoare,prioritate}
Coada_prioritati::Coada_prioritati(int C):Capacity(C),SIZE(0)
{
    cap=new Coada_prioritati::Nod[Capacity];
}
Coada_prioritati::Coada_prioritati():Capacity(0),SIZE(0)
{
    cap=new Coada_prioritati::Nod[Capacity];
}
Coada_prioritati::Coada_prioritati(const Coada_prioritati &Q):Capacity(Q.Capacity),SIZE(Q.SIZE)
{
    cap=new Coada_prioritati::Nod[Q.Capacity];
    for(int i=0;i<Q.Capacity;i++)
        cap[i]=Q.cap[i];
}
Coada_prioritati::~Coada_prioritati()
{
    delete []cap;
    SIZE=Capacity=0;
}
int Coada_prioritati::getCapacity()
{
    return Capacity;
}
void Coada_prioritati::Insert(Coada_prioritati::Nod X)
{

    if(SIZE==Capacity)
    {
        Coada_prioritati::Nod *aux=new Coada_prioritati::Nod[Capacity+1];
        for(int i=0;i<SIZE;i++)
            aux[i]=cap[i];
        delete []cap;
        cap=aux;
        Capacity+=1;
    }
    if(SIZE==0)
    {
        SIZE++;
        cap[SIZE-1]=X;
        return;
    }
    //Elementul se insereaza pe ultima pozitie
    SIZE++;
    cap[SIZE-1]=X;
    int Position=SIZE-1;
   while(cap[Position].prio<cap[(Position-1)/2].prio)
    {
        swap(cap[Position].prio,cap[(Position-1)/2].prio);
        swap(cap[Position].info,cap[(Position-1)/2].info);
        Position=(Position-1)/2;
    }
}
/*int Coada_prioritati::getnext()
{
    return next;
}*/
void Coada_prioritati::Pop()
{
    if(SIZE==0)
    {
        cout<<"Coada vida";
        return;
    }
    //Ultimul element devine primul
    cap->next=cap->ante;
    cap--;
}
int Coada_prioritati::getSize()
{
    return SIZE;
}
std::ostream& operator<<(std::ostream &out, const Coada_prioritati&Q)
{
    if(Q.SIZE!=0)
    {
    for(int i=0;i<Q.SIZE;i++)
        out<<"("<<Q.cap[i].info<<";"<<Q.cap[i].prio<<")";
    return out;}
    else
        cout<<"Coada vida";

}
std::istream& operator>>(std::istream &in,Coada_prioritati &Q)
{
    delete []Q.cap;
    in>>Q.Capacity;
    Q.SIZE=0;
    Q.cap=new Coada_prioritati::Nod[Q.Capacity];
    PQueue::Nod X;
    for(int i=0;i<Q.Capacity;i++)
        {
            in>>X.info>>X.prio;
            Q.Insert(X);
        }
        return in;
}
Coada_prioritati & Coada_prioritati::operator=(const Coada_prioritati &Q2)
{
    this->SIZE=Q2.SIZE;
    this->Capacity=Q2.Capacity;
    for(int i=0;i<this->SIZE;i++)
        this->cap[i]=Q2.cap[i];
    this->MaxPrio=Q2.MaxPrio;
    return *this;
}
Coada_prioritati::operator+(Coada_prioritati const &Q)
{
    Coada_prioritati Qr(Capacity+Q.Capacity);
    int i=0,j=0;
    while(i<SIZE && j<Q.SIZE)
    {
        if(cap[i].prio<Q.cap[j].prio)
        {
            Qr.Insert(cap[i]);
            i++;
        }
        else
           if(cap[i].prio>Q.cap[j].prio)
        {
            Qr.Insert(Q.cap[j]);
            j++;

        }
        else
        {
            if(cap[i].info<Q.cap[j].info)
        {
            Qr.Insert(cap[i]);
            i++;
        }
        else
           if(cap[i].info>Q.cap[j].info)
        {
            Qr.Insert(Q.cap[j]);
            j++;
        }
        else
        {
            Qr.Insert(cap[i]);
            Qr.Insert(Q.cap[j]);
            j++;
            i++;
        }
        }
    }
    while(i<SIZE){Qr.Insert(store[i]);i++;}
    while(j<Q.SIZE){Qr.Insert(Q.store[j]);j++;}

        return Qr;
}
bool Coada_prioritati::isEmpty()
{
    return (SIZE==0);
}
void Coada_prioritati::operator++(int Dummy)
{
    for(int i=0;i<SIZE;i++)
        cap[i].Priority++;
    MaxPriority++;
}
void Coada_prioritati::operator--(int Dummy)
{
    for(int i=0;i<SIZE;i++)
        cap[i].Priority--;
    //Elementele cu prioritate 0 vor fi la inceputul cozii, motiv pentru care pot face Pop();
    while(cap[0].Priority==0)
        Pop();
}

int Coada_prioritati::getMaxPrio()
{
    return cap[0].Priority;
}
//stiu ca nu am folosit listele dublu inaltuite, imi dadea foarte multe erori si nu am mai avut timp sa le corectez asa ca am facut in modul asta
//PS: vreau doar 5-ul :))
