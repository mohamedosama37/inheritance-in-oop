#include <iostream>

using namespace std;

class Base
{
private:
    int a ;
    int b ;
public:
    Base()
    {
        a=b=0;
        cout<<"this is Base default constructor"<<endl;
    }
    Base(int n)
    {
        a=b=n;
        cout<<"this is Base constructor with one paramter"<<endl;
    }
    Base(int x , int y)
    {
        a=x;
        b=y;
    }
    void seta(int x)
    {
        a=x;
    }
    void setb(int y)
    {
        b=y;
    }
    int geta()
    {
        return a;
    }
    int getb()
    {
        return b;
    }
    int productab()
    {
        return a*b;
    }

};


class Derived : public Base
{
private:
    int c;
public:
    Derived ():Base()
    {
        c=0;
        cout<<"this default Dervied constructor"<<endl;
    }
    Derived(int n):Base(n)
    {
        c=n;
        cout<<"this Derived constructor with one paramter"<<endl;
    }
    Derived (int x, int y, int z):Base (x,y)
    {
        c=z;
         cout<<"this Derived constructor with three paramter"<<endl;
    }
    void setc(int z)
    {
        c=z;
    }
    int getc()
    {
        return c;
    }
    int productabc()
    {
        return productab()*c;
    }

};


class Second_derived:public Derived
{
private:
    int d;
    public:
    Second_derived ():Derived()
    {
        d=0;
        cout<< "this is  Second DERIVED default"<<endl;
    }
    Second_derived(int n):Derived(n)
    {
        d=n;
         cout<< "this is  Second DERIVED 1paramter "<<endl;
    }
    Second_derived(int x, int y , int m,  int z):Derived(x,y,m)
    {
        d=z;
        cout<< "this is  Second DERIVED 4 paramter "<<endl;
    }

    void setd(int z)
{
    d=z;
}
int getd ()
{
    return d;
}
int product()
{
    return geta()*getb()*getc()*d;
}
};


int main()
{
    Derived obj1;
    obj1.seta(3);
    obj1.setb(7);
    obj1.setc(1);
    cout<<"obj1"<<obj1.productabc()<<endl;
    Base b(5,4);
    b.seta(3);
    b.setb(7);

    cout<<b.productab()<<endl;
    Base bo(5,4);
    Derived obj;
    cout<<bo.productab()<<endl;
    cout<<obj.productabc()<<endl;
    cout<<obj.Base::productab()<<endl;
    Derived obj2(10,20,30);
    Base *pt=&obj2;
    cout<<obj2.productabc()<<endl;
    cout<<obj2.Base::productab()<<endl;
    cout<<pt->productab()<<endl;
}
