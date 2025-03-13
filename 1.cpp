#include <iostream>
using namespace std;

struct Vector {
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;
};

void constructor(int*& m, int& m1, int& m2, int& m3, int& m4) {
    m1 = 0;
    m2 = 10;
    m3 = 10;
    m = new int[m2];
    m4 = m2;
}

void Resize(int*& Vect, int& Max) {
    const int delta = 10;
    int* pTemp = new int[Max + delta];
    for (int i = 0; i < Max; i++)
        pTemp[i] = Vect[i];
    delete[] Vect;
    Vect = pTemp;
    Max += delta;
}

void Insert(int*& rpVect, int& rnCount, int& rnMax, int elem) {
    if (rnCount == rnMax)
        Resize(rpVect, rnMax);
    rpVect[rnCount++] = elem;
}

template<class T>
class CVector {
public:
    CVector(int delta = 10) {
        tammax = delta;
        tam = 0;
        head = new T[tammax];
        ptr = head;
    }

    void expan() {
        int h = 10;
        T* ptr1 = new T[tammax + h];
        for (int i = 0; i < tammax; i++)
            ptr1[i] = head[i];
        tammax += h;
        delete[] head;
        head = ptr1;
        ptr = head;
    }

    void Insert(T elem) {
        if (tam == tammax)
            expan();
        head[tam++] = elem;
    }

    void print() {
        for (int i = 0; i < tam; i++)
            cout << head[i] << " ";
        cout << endl;
    }

private:
    T* head;
    T* ptr;
    int tam;
    int tammax;
};

class CVectorSinTemplate {
public:
    CVectorSinTemplate(int delta = 10) {
        tammax = delta;
        tam = 0;
        head = new int[tammax];
        ptr = head;
    }

    void expan() {
        int h = 10;
        int* ptr1 = new int[tammax + h];
        for (int i = 0; i < tammax; i++)
            ptr1[i] = head[i];
        tammax += h;
        delete[] head;
        head = ptr1;
        ptr = head;
    }

    void Insert(int elem) {
        if (tam == tammax)
            expan();
        head[tam++] = elem;
    }

    void print() {
        for (int i = 0; i < tam; i++)
            cout << head[i] << " ";
        cout << endl;
    }

private:
    int* head;
    int* ptr;
    int tam;
    int tammax;
};

int main() {
    CVector<int> vec1(10);
    for (int i = 0; i < 20; i++)
        vec1.Insert(i);
    vec1.print();

    CVectorSinTemplate vec2(10);
    for (int i = 0; i < 20; i++)
        vec2.Insert(i);
    vec2.print();

    Vector v;
    constructor(v.m_pVect, v.m_nCount, v.m_nMax, v.m_nDelta, v.m_nMax);
    for (int i = 0; i < 20; i++)
        Insert(v.m_pVect, v.m_nCount, v.m_nMax, i);
    for (int i = 0; i < v.m_nCount; i++)
        cout << v.m_pVect[i] << " ";
    

    return 0;
}

