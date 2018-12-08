#include <iostream>
#include<typeinfo>
using namespace std;

struct date 
{
    int j,m,a;
};
class perso {
int nume;
string fonction;
date date_debut;
int nbh;
public:
perso() //constructeur 1
{
    nume=0;
    fonction="0";
    date_debut.j=0;
    date_debut.m=0;
    date_debut.a=0;
    nbh=0;
}
perso(int a,string b,int c,int c2,int c3, int d)  //constructeur 2
{
    nume=a;
    fonction=b;
    date_debut.j=c;
    date_debut.m=c2;
    date_debut.a=c3;
    nbh=d;
}


perso(perso const &e) //constructeur de recopie
{
    nume=e.nume;
    fonction=e.fonction;
    
    date_debut=e.date_debut;
    nbh=e.nbh;
}
void affiche() //affichage
{
    cout<<nume<<endl<<fonction<<endl<<date_debut.a<<"/"<<date_debut.m<<"/"<<date_debut.j<<endl<<nbh<<endl<<"--------"<<endl;
}
int getnum() // returoune nume
{
    return nume;
}
date getdate()
{
    date d;
    d.j=date_debut.j;
    d.m=date_debut.m;
    d.a=date_debut.a;
    return d;
}
};

class comp {
public:
int nb,taille;
perso *t;
perso* gett()
{
    return t;
}
comp(int a) //constructeur 
{
    t=new perso [a];
    taille=a;
    nb=0;
}

int existe (int a) //search
{
    int i=0;
    while (i<nb )
    {
        if (t[i].getnum()==a)
        return i;
        else 
        i++;
    }
return -1;
}
void ajouter (perso a) //ajouter objet
{
    if (existe(a.getnum())==-1 && nb<taille)
    {
        t[nb]=a;
        nb++;
        cout<<"objet ajoute"<<endl;
    }
    else if  (nb==taille)
    cout<<"plein"<<endl;
    else
     cout<<"cet objet existe"<<endl;
    
    
}
int calcul (perso a) // calcule nb heure
{
    return((a.getdate().a*356*24+a.getdate().m*30*24+a.getdate().j*24)-(2017*356*24+12*30*24+11*24));
}
void supprimer(perso a) //supprimere objet 
{
    if   (existe(a.getnum())==-1)
    {
       cout<<"cet objet n'existe pas"<<endl;
    }
    else 
    {
        for (int i=existe(a.getnum());i<nb;i++)
        {
            t[i]=t[i+1];
            
        }
        cout <<"objet supprime"<<endl;
       
        nb--;
    }
}
void affiche () //afficher tableau
{
    
        for (int i=0;i<nb;i++)
        t[i].affiche();
        
}
};
int main() //main, boys
{
    perso *p1=new perso(1254,"pilote",5,2,2006,90);
    perso *p2=new perso(4541,"co-pilote",4,6,2009,90);
    perso *p3=new perso(3678,"hotesse",15,21,2010,180);
    perso *p4=new perso(9565,"steward",11,6,2016,180);
    perso *p5=new perso(9999,"hotesse",9,6,2015,180);
    comp c (10);
  
    c.ajouter(*p1);
    c.ajouter(*p2);
    c.ajouter(*p3);
    c.ajouter(*p4);
    c.ajouter(*p5);

   perso p6(*p1);
    for (int i=0;i<c.nb;i++)
        if (c.calcul(*(c.gett()+i))<6000)
        c.supprimer(*(c.gett()+i));
    c.affiche();
    c.supprimer(p6);

}