#include "Csucs.hpp"
#include <iostream>
#ifndef GRAF_HPP_INCLUDED
#define GRAF_HPP_INCLUDED

enum osszefugg{
    igen = 1, nem = 0, nincsinf = 3
};

template<typename T, size_t N>
struct BFS_lepes{
    Csucs<T, N-1>* csucs;
    size_t tavolsag;
};

template<typename T, size_t N>
class Graf{
    Csucs<T, N-1>** csucsok;
    size_t elekDb;
    osszefugg osszeFugges;
    bool** matrix;
public:
    Graf(T* adatok, bool** matrix): elekDb(((N*(N-1))/2)+1), osszeFugges(nincsinf), matrix(NULL){
        this->csucsok = new Csucs<T, N-1>*[N];
        for(size_t i = 0; i < N; ++i){
            this->csucsok[i] = new Csucs<T, N-1>(adatok[i]);
        }
        for(size_t i = 0; i < N; ++i)
            for(size_t j = 0; j < N; ++j)
                if(matrix[i][j])
                    this->csucsok[i]->push(csucsok[j]);
    }

    Graf(const Graf& other){

    }

    size_t bejar(size_t csucsi, BFS_lepes<T, N-1>* ut){
        return 0;
    }
    bool osszefuggo(){
        return 0;
    }
    size_t getCsucsdb(){
        return N;
    }
    size_t getEldb(){
        return 0;
    }
    bool** getMatrix(){
        return NULL;
    }
    Csucs<T, N-1>* operator [](size_t i){
        if(i >= N){
            throw("Unvalid index!!");
            return NULL;
        }
        return csucsok[i];
    }

    ~Graf(){
        for(size_t i = 0; i < N; ++i)
            delete csucsok[i];
        delete[] csucsok;

        if(matrix != NULL){
            for(size_t i = 0; i < N; ++i)
                delete[] matrix[i];
            delete[] matrix;
        }
    }
};

#endif // GRAF_HPP_INCLUDED
