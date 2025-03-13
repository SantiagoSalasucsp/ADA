#include <iostream>
using namespace std;



struct Vector
{
        int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
};

void Resize(int*& Vect, int& Max)
{
    const int delta = 10; // Used to increase the vector size
     int *pTemp, i;
     pTemp = new int[Max + delta]; // Alloc a new vector
     for(i = 0 ; i < Max ; i++) // Transfer the elements
            pTemp[i] = Vect[i]; // we can also use the function memcpy
        delete [ ] Vect; // delete the old vector
        Vect = pTemp;
        Max += delta; // The Max has to be increased by delta
}
void Insert(int*& rpVect, int& rnCount, int& rnMax, int elem)
{
    if (rnCount == rnMax) // Verify the overflow
        Resize(rpVect, rnMax); // Resize the vector before inserting elem
    rpVect[rnCount++] = elem; // Insert the element at the end of the sequence
}



template<class T>
class  CVector {

    public:
        CVector(int delta = 10) {
            tammax = delta;
            head = new T[tammax];
            ptr = head;
        }
        void expan() {
            int h = 10;
            T* ptr1 = new T[tammax+h];
            for (int i = 0; i < tammax; i++) // Transfer the elements
                ptr1[i] = head[i];
            tammax += h;
            delete[] head;
            head = ptr1;
            ptr = head;


        }
        void Insert(T elem) {
            if (tam == tammax)
                expan();
            *(ptr + tam) = elem;
            tam++;

        }
        void print() {
            T* f = head;
            for (int i = 0; i < tam; i++) {
                cout << *(f + i) << " ";
            }
            cout << endl;
        }

    private:
        T* head;
        T* ptr;
        int tam;
        int tammax;
};







class  CVectorSinTemplate {

public:
    CVectorSinTemplate(int delta = 10) {
        tammax = delta;
        head = new int [tammax];
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
    void Insert(int  elem) {
        if (tam == tammax)
            expan();
        *(ptr + tam) = elem;
        tam++;

    }
    void print() {
        int* f = head;
        for (int i = 0; i < tam; i++) {
            cout << *(f + i) << " ";
        }
        cout << endl;
    }

private:
    int* head;
    int* ptr;
    int tam;
    int tammax;
};











int main()
{
    CVector<int> x(3);
    x.Insert(1);
    x.Insert(2);
    x.Insert(3);
    x.print();
    x.Insert(4);
    x.print();

    CVectorSinTemplate gh(10);

    for (int y = 0; y < 20; y++) {
        gh.Insert(y);
    }
    gh.print();

    Vector f();



}
