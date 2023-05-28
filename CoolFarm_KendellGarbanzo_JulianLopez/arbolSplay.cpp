#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;

ref class Nodo {
public:
    int clave;
    Nodo^ izquierda;
    Nodo^ derecha;

    Nodo(int valor) {
        clave = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

public ref class SplayTree {
public:
    System::String ^ tipo = "Splay";
    Nodo^ raiz;
    BackgroundWorker^ ThreadSplay;
    int id;
    int x;
    int y;
    int costo = 0;
    int tiempo = 0;
    int tasaCantidad = 0;
    int tasaTiempo = 0;
    int vendidos = 0;
    int perdidos = 0;
    bool xd = false;
    int esperaCrecer = 0;
    

    SplayTree() {
        ThreadSplay = gcnew BackgroundWorker();
        ThreadSplay->WorkerSupportsCancellation = true;
        ThreadSplay->DoWork += gcnew DoWorkEventHandler(this, &SplayTree::ThreadSplay_DoWork);
        raiz = nullptr;


    }

    void ThreadSplay_DoWork(Object^ sender, DoWorkEventArgs^ e)
    {
        while (!ThreadSplay->CancellationPending) {
            if (xd == false) {
                System::Threading::Thread::Sleep(10000);
            }
            this->xd = true;
            this->insertar(tasaTiempo);
            System::Threading::Thread::Sleep(this->tasaTiempo * 1000);
            this->tasaTiempo++;
        }

    }

    void startBackGroundTask() {
        ThreadSplay->RunWorkerAsync();
    }

    Nodo^ rotacionZigZig(Nodo^ nodo) {
        if (nodo == nullptr || nodo->izquierda == nullptr) {
            return nodo;
        }
        Nodo^ izq = nodo->izquierda;
        nodo->izquierda = izq->derecha;
        izq->derecha = nodo;
        return izq;
    }

    Nodo^ rotacionZigZag(Nodo^ nodo) {
        if (nodo == nullptr || nodo->izquierda == nullptr || nodo->izquierda->derecha == nullptr) {
            return nodo;
        }
        Nodo^ izq = nodo->izquierda;
        Nodo^ izq_der = izq->derecha;
        nodo->izquierda = izq_der->derecha;
        izq->derecha = izq_der->izquierda;
        izq_der->izquierda = izq;
        izq_der->derecha = nodo;
        return izq_der;
    }

    Nodo^ splay(Nodo^ nodo, int clave) {
        if (nodo == nullptr || nodo->clave == clave) {
            return nodo;
        }
        if (clave < nodo->clave) {
            if (nodo->izquierda == nullptr) {
                return nodo;
            }
            if (clave < nodo->izquierda->clave) {
                nodo->izquierda->izquierda = splay(nodo->izquierda->izquierda, clave);
                nodo = rotacionZigZig(nodo);
            }
            else if (clave > nodo->izquierda->clave) {
                nodo->izquierda->derecha = splay(nodo->izquierda->derecha, clave);
                if (nodo->izquierda->derecha != nullptr) {
                    nodo->izquierda = rotacionZigZag(nodo->izquierda);
                }
            }
            if (nodo->izquierda == nullptr) {
                return nodo;
            }
            return rotacionZigZig(nodo);
        }
        else {
            if (nodo->derecha == nullptr) {
                return nodo;
            }
            if (clave < nodo->derecha->clave) {
                nodo->derecha->izquierda = splay(nodo->derecha->izquierda, clave);
                if (nodo->derecha->izquierda != nullptr) {
                    nodo->derecha = rotacionZigZag(nodo->derecha);
                }
            }
            else if (clave > nodo->derecha->clave) {
                nodo->derecha->derecha = splay(nodo->derecha->derecha, clave);
                nodo = rotacionZigZig(nodo);
            }
            if (nodo->derecha == nullptr) {
                return nodo;
            }
            return rotacionZigZag(nodo);
        }
    }

    void insertar(int clave) {
        if (raiz == nullptr) {
            raiz = gcnew Nodo(clave);
            return;
        }
        raiz = splay(raiz, clave);
        if (clave < raiz->clave) {
            Nodo^ nuevo_nodo = gcnew Nodo(clave);
            nuevo_nodo->izquierda = raiz->izquierda;
            nuevo_nodo->derecha = raiz;
            raiz->izquierda = nullptr;
            raiz = nuevo_nodo;
        }
        else if (clave > raiz->clave) {
            Nodo^ nuevo_nodo = gcnew Nodo(clave);
            nuevo_nodo->derecha = raiz->derecha;
            nuevo_nodo->izquierda = raiz;
            raiz->derecha = nullptr;
            raiz = nuevo_nodo;
        }
    }

    bool buscar(int clave) {
        raiz = splay(raiz, clave);
        return (raiz != nullptr && raiz->clave == clave);
    }

    int contarElementos(Nodo^ nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return 1 + contarElementos(nodo->izquierda) + contarElementos(nodo->derecha);
    }

    void eliminarArbol(Nodo^ nodo) {
        if (nodo == nullptr) {
            return;
        }
        
        eliminarArbol(nodo->izquierda);
        eliminarArbol(nodo->derecha);
        delete nodo;
    }

     void eliminarTodosElementos() {
        eliminarArbol(raiz);
        raiz = nullptr;
 
    }

     void eliminarPrimerElemento() {
         if (raiz == nullptr) {
             return;
         }

         Nodo^ nodoAEliminar = raiz;
         raiz = splay(raiz, nodoAEliminar->clave);

         // El elemento a eliminar es la raíz del árbol
         if (raiz->izquierda == nullptr) {
             raiz = raiz->derecha;
         }
         else {
             Nodo^ nuevaRaiz = raiz->derecha;
             raiz = splay(raiz->izquierda, nodoAEliminar->clave);
             raiz->derecha = nuevaRaiz;
         }

         delete nodoAEliminar;
     }

};



#include <list>


ref class Heap_tree {
public:

    System::String^ tipo = "HEAP";
    int vendidos = 0;
    int perdidos = 0;
    int id;
    int x;
    int y;
    int costo = 0;
    int tiempo = 0;
    int tasaCantidad = 0;
    int tasaTiempo = 0;
    List<int>^ heap;
    BackgroundWorker^ ThreadHeap;
    bool xd = false;
    int esperaCrecer = 0;


    Heap_tree() {
        heap = gcnew List<int>();
        ThreadHeap = gcnew BackgroundWorker();
        ThreadHeap->WorkerSupportsCancellation = true;
        ThreadHeap->DoWork += gcnew DoWorkEventHandler(this, &Heap_tree::ThreadHeap_DoWork);

    }
    void ThreadHeap_DoWork(Object^ sender, DoWorkEventArgs^ e)
    {
        while (!ThreadHeap->CancellationPending) {


            while (esperaCrecer < 25)
            {
                System::Threading::Thread::Sleep(1000);
                esperaCrecer++;
            }

            System::Threading::Thread::Sleep(this->tasaTiempo * 1000);
            this->xd = true;
            this->Insert(tasaTiempo);
            this->tasaTiempo++;
        }

    }
  

    void startBackGroundTask() {
        ThreadHeap->RunWorkerAsync();
    }



    void HeapifyUp(int index) {
        if (index == 0)
            return;

        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            Swap(parent, index);
            HeapifyUp(parent);
        }
    }

    void HeapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap->Count && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < heap->Count && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            Swap(largest, index);
            HeapifyDown(largest);
        }
    }

    void Swap(int index1, int index2) {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }


    void Insert(int value) {
        heap->Add(value);
        HeapifyUp(heap->Count - 1);
    }

    void Remove() {
        if (heap->Count == 0)
            return;

        heap[0] = heap[heap->Count - 1];
        heap->RemoveAt(heap->Count - 1);
        HeapifyDown(0);
    }

    void Print() {
        for each (int value in heap)
            Console::Write(value + " ");
        Console::WriteLine();
    }

    int contarElementos()
    {
        return heap->Count;
    }


    void eliminarTodosElementos() {
        heap->Clear();
    }


    void EliminarPrimerElemento() {
        if (heap->Count == 0)
            return;

        heap[0] = heap[heap->Count - 1];
        heap->RemoveAt(heap->Count - 1);
        HeapifyDown(0);
    }

};










ref class NodeA {

public:
    int key;
    int height;
    NodeA^ left;
    NodeA^ right;

    NodeA(int k) {
        key = k;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};


ref class AVLTree {
    public :
        System::String^ tipo = "AVL";
        int vendidos = 0;
        int perdidos = 0;
        int id;
        int x;
        int y;
        int costo = 0;
        int tiempo = 0;
        int tasaCantidad = 0;
        int tasaTiempo = 0;
        BackgroundWorker^ ThreadAVL;
        NodeA^ root;
        bool xd = false;
        int esperaCrecer = 0;
        AVLTree() {
            root = nullptr;
            ThreadAVL = gcnew BackgroundWorker();
            ThreadAVL->WorkerSupportsCancellation = true;
            ThreadAVL->DoWork += gcnew DoWorkEventHandler(this, &AVLTree::ThreadAVL_DoWork);

        }

        void ThreadAVL_DoWork(Object^ sender, DoWorkEventArgs^ e){
            while (!ThreadAVL->CancellationPending) {
                while (esperaCrecer < 25)
                {
                    System::Threading::Thread::Sleep(1000);
                    esperaCrecer++;
                }

                System::Threading::Thread::Sleep(this->tasaTiempo * 1000);
                this->xd = true;
                this->Insert(tasaTiempo);
                this->tasaTiempo++;
            }

        }


        void startBackGroundTask() {
            ThreadAVL->RunWorkerAsync();
        }

    int GetHeight(NodeA^ node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int GetBalance(NodeA^ node) {
        if (node == nullptr)
            return 0;
        return GetHeight(node->left) - GetHeight(node->right);
    }

    NodeA^ RotateRight(NodeA^ y) {
        NodeA^ x = y->left;
        NodeA^ T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = Math::Max(GetHeight(y->left), GetHeight(y->right)) + 1;
        x->height = Math::Max(GetHeight(x->left), GetHeight(x->right)) + 1;

        return x;
    }

    NodeA^ RotateLeft(NodeA^ x) {
        NodeA^ y = x->right;
        NodeA^ T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = Math::Max(GetHeight(x->left), GetHeight(x->right)) + 1;
        y->height = Math::Max(GetHeight(y->left), GetHeight(y->right)) + 1;

        return y;
    }

    NodeA^ InsertNode(NodeA^ node, int key) {
        if (node == nullptr)
            return gcnew NodeA(key);

        if (key < node->key)
            node->left = InsertNode(node->left, key);
        else if (key > node->key)
            node->right = InsertNode(node->right, key);
        else
            return node;

        node->height = 1 + Math::Max(GetHeight(node->left), GetHeight(node->right));

        int balance = GetBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return RotateRight(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return RotateLeft(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

    NodeA^ FindMinNode(NodeA^ node) {
        NodeA^ current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }


   
    NodeA ^ DeleteNode(NodeA^ node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = DeleteNode(node->left, key);
        else if (key > node->key)
            node->right = DeleteNode(node->right, key);
        else {
            if (node->left == nullptr) {
                NodeA^ temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                NodeA^ temp = node->left;
                delete node;
                return temp;
            }
            else {
                NodeA^ temp = FindMinNode(node->right);
                node->key = temp->key;
                node->right = DeleteNode(node->right, temp->key);
            }
        }

        node->height = 1 + Math::Max(GetHeight(node->left), GetHeight(node->right));

        int balance = GetBalance(node);

        // Left Left Case
        if (balance > 1 && GetBalance(node->left) >= 0)
            return RotateRight(node);

        // Left Right Case
        if (balance > 1 && GetBalance(node->left) < 0) {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && GetBalance(node->right) <= 0)
            return RotateLeft(node);

        // Right Left Case
        if (balance < -1 && GetBalance(node->right) > 0) {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

    void InorderTraversal(NodeA^ node) {
        if (node != nullptr) {
            InorderTraversal(node->left);
            Console::Write(node->key + " ");
            InorderTraversal(node->right);
        }
    }



        void Insert(int key) {
        root = InsertNode(root, key);
    }

    void Delete(int key) {
        root = DeleteNode(root, key);
    }

    void PrintInorder() {
        InorderTraversal(root);
        Console::WriteLine();
    }


    int contarElementos(NodeA^ node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + contarElementos(node->left) + contarElementos(node->right);
    }


    void eliminarTodosElementos() {
        root = nullptr;
    }

    void EliminarPrimerElemento() {
        if (root == nullptr)
            return;

        NodeA^ minNode = FindMinNode(root);
        root = DeleteNode(root, minNode->key);
    }



};



ref class NodeB {
public:
    int key;
    NodeB^ left;
    NodeB^ right;

    NodeB(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};


ref class BinarySearchTree {
public:

    System::String^ tipo = "Binario";
    int vendidos = 0;
    int perdidos = 0;
    int id;
    int x;
    int y;
    int costo = 0;
    int tiempo = 0;
    int tasaCantidad = 0;
    int tasaTiempo = 0;
    NodeB^ root;
    BackgroundWorker^ ThreadBinario;
    bool xd = false;
    int esperaCrecer = 0;

    BinarySearchTree() {
        root = nullptr;
        ThreadBinario = gcnew BackgroundWorker();
        ThreadBinario->WorkerSupportsCancellation = true;
        ThreadBinario->DoWork += gcnew DoWorkEventHandler(this, &BinarySearchTree::ThreadBinario_DoWork);

    }

    void ThreadBinario_DoWork(Object^ sender, DoWorkEventArgs^ e) {
        while (!ThreadBinario->CancellationPending) {
            while (esperaCrecer < 25)
            {
                System::Threading::Thread::Sleep(1000);
                esperaCrecer++;
            }

            System::Threading::Thread::Sleep(this->tasaTiempo * 1000);
            this->xd = true;
            this->Insert(tasaTiempo);
            this->tasaTiempo++;
        }

    }


    void startBackGroundTask() {
        ThreadBinario->RunWorkerAsync();
    }

    NodeB^ InsertNode(NodeB^ node, int key) {
        if (node == nullptr)
            return gcnew NodeB(key);

        if (key < node->key)
            node->left = InsertNode(node->left, key);
        else if (key > node->key)
            node->right = InsertNode(node->right, key);

        return node;
    }

    NodeB^ DeleteNode(NodeB^ node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = DeleteNode(node->left, key);
        else if (key > node->key)
            node->right = DeleteNode(node->right, key);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                NodeB^ temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                NodeB^ temp = node->left;
                delete node;
                return temp;
            }
            else {
                NodeB^ successor = GetSuccessor(node->right);
                node->key = successor->key;
                node->right = DeleteNode(node->right, successor->key);
            }
        }

        return node;
    }

    NodeB^ GetSuccessor(NodeB^ node) {
        NodeB^ current = node;
        while (current != nullptr && current->left != nullptr)
            current = current->left;
        return current;
    }

    void InorderTraversal(NodeB^ node) {
        if (node != nullptr) {
            InorderTraversal(node->left);
            Console::Write(node->key + " ");
            InorderTraversal(node->right);
        }
    }


    void Insert(int key) {
        root = InsertNode(root, key);
    }

    void Delete(int key) {
        root = DeleteNode(root, key);
    }

    void PrintInorder() {
        InorderTraversal(root);
        Console::WriteLine();
    }

    int contarElementos(NodeB^ node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + contarElementos(node->left) + contarElementos(node->right);
    }



    void eliminarNodos(NodeB^ node) {
        if (node == nullptr)
            return;

        eliminarNodos(node->left);
        eliminarNodos(node->right);
        delete node;
    }


    void eliminarTodosElementos() {
        eliminarNodos(root);
        root = nullptr;
    }

    NodeB^ GetMinNode(NodeB^ node) {
        NodeB^ current = node;
        while (current != nullptr && current->left != nullptr)
            current = current->left;
        return current;
    }



    void EliminarPrimerElemento() {
        if (root == nullptr)
            return;

        NodeB^ minNode = GetMinNode(root);
        root = DeleteNode(root, minNode->key);
    }


};
