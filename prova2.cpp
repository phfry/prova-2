#include<stdio.h>

typedef int dado;

struct No {

    dado valor;
    No *prox;

    No(dado _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Node {

    dado valor;
    Node *prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct Pilha {

    No *cabeca;
    int s;

    Pilha() {
        cabeca = NULL;
        s = 0;
    }

    bool empty() {
        return (cabeca == NULL);
    }

    int size() {
        return s;
    }

    void push(dado e) {
        if (empty()) {
            cabeca = new No(e);
        } else {
            No *novo = new No(e);
            novo->prox = cabeca;
            cabeca = novo;
        }
        s++;
    }

    void pop() {
        if (!empty()) {
            No *aux = cabeca;
            cabeca = cabeca->prox;
            delete(aux);
            s--;
        }
    }

    dado top() {
        if (!empty()) {
            return cabeca->valor;
        } else {
            return NULL;
        }
    }

};

struct Fila {

    Node *cabeca, *cauda;
    int size;

    Fila() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* enqueue(dado valor) { //O(1) - push back
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* dequeue() { //O(1) -- pop front
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    dado front() {
        if (!empty()) {
            return cabeca->valor;
        } else {
            return NULL;
        }
    }


    void inverter(){
        Pilha p;
        if(size == 0){
            printf("Fila Vazia");
        }
        else{
            Node *tmp = cabeca;
            while(cauda->prox != NULL){
                cabeca = cabeca->prox;
                p.push(tmp->valor);
                delete(tmp);
                cabeca = tmp;
        }
    }
    No *tmp = p.cabeca;
    while(p.cabeca != NULL){
        p.cabeca = p.cabeca->prox;
        enqueue(tmp->valor);
        delete(tmp);
        tmp = p.cabeca;
    }

 }

     void imprimir(){
         Node* tmp = cabeca;
        while(tmp != NULL){
            printf("%d\n", tmp->valor);
            tmp = tmp->prox;
        }

     }



};






int main(){
    Fila f;

    f.enqueue(10);
    f.enqueue(20);
    f.enqueue(30);

    f.imprimir();
    f.inverter();
    f.imprimir();

    return 0;
}
