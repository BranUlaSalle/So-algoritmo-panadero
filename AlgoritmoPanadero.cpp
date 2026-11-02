#include <iostream> 
#include <vector> 
#include <thread> 
#include <atomic> 
using namespace std; 

const int N = 3;  

atomic<bool> eligiendo[N]; 
atomic<int> numero[N]; 

void panadero(int id) {
    eligiendo[id] = true; 

    int maximo = 0; 
    for (int i = 0; i < N; i++) { 
        if (numero[i] > maximo)
            maximo = numero[i];
    } 

    numero[id] = maximo + 1; 
    eligiendo [id] = false; 

<<<<<<< HEAD
=======
    //recorrido
    for(int j = 0;j<N;j++){
        if(j==id)continue;
        while(eligiendo[j]){
            this_thread::yield();
        }
        while(numero[j] != 0 && (numero[j] < numero[id]|| (numero[j] == numero[id] && j < id))){
            this_thread::yield();
        }
    }
>>>>>>> origin/carlos
}


int main() {
    for (int i = 0; i < N; i++) {
        eligiendo[i] = false;
        numero[i] = 0;
    }
    thread p1(panadero, 0);
    thread p2(panadero, 1);
    thread p3(panadero, 2);

    p1.join();
    p2.join();
    p3.join();

    return 0;
}