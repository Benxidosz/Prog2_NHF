#include <iostream>
#ifndef CSUCS_HPP_INCLUDED
#define CSUCS_HPP_INCLUDED

template<typename T, size_t MaxFok>
class Csucs{
    T adat;
    Csucs** szomszedok;
    size_t fokszam;
public:
    Csucs(T adat): adat(adat), fokszam(0){
        szomszedok = new Csucs*[MaxFok];
    }
    T getAdat(){
        return this->adat;
    }
    void setAdat(T adat){
        this->adat = adat;
    }

    bool push(Csucs* cs){
        if(fokszam >= MaxFok){
            return false;
        }else{
            szomszedok[fokszam++] = cs;
            return true;
        }
    }
    size_t findSzomszed(Csucs* cs){
        for(size_t i = 0; i < fokszam; ++i)
            if(cs == szomszedok[i])
                return i;
        return MaxFok;
    }
    bool remove(Csucs* cs){
        size_t tempi = this->findSzomszed(cs);
        if(tempi >= fokszam)
            return false;
        else{
            for(size_t i = 0; i < fokszam - 1; ++i)
                szomszedok[i] = szomszedok[i + 1];
            szomszedok[fokszam] = NULL;
            return true;
        }
    }

    size_t getFok(){
        return this-> fokszam;
    }

    Csucs* operator [](size_t i){
        if(i >= fokszam){
            throw("Unvalid index!!");
            return NULL;
        }
        return szomszedok[i];
    }

    ~Csucs(){
        delete[] szomszedok;
    }
};

#endif // CSUCS_HPP_INCLUDED
