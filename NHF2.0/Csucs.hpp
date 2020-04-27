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
        std::cout << "Csucs ctor" << std::endl;
        szomszedok = new Csucs*[MaxFok];
    }
    Csucs(const Csucs& other){
        std::cout << "Csucs copytor" << std::endl;
    }

    T getAdat(){
        return this->adat;
    }
    void setAdat(T adat){
        this->adat = adat;
    }

    bool push(const Csucs* cs){
        std::cout << "Csucs push" << std::endl;
        return 0;
    }
    size_t findSzomszed(const Csucs* cs){
        std::cout << "Csucs findszomszed" << std::endl;
        return 0;
    }
    bool remove(const Csucs* cs){
        std::cout << "Csucs remove" << std::endl;
        return 0;
    }

    size_t getFok(){
        return this-> fokszam;
    }

    Csucs* operator [](size_t i){
        std::cout << "Csucs index" << std::endl;
    }

    ~Csucs(){
        delete[] szomszedok;
        std::cout << "Csucs dtor" << std::endl;
    }
};

#endif // CSUCS_HPP_INCLUDED
