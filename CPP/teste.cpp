#include <iostream>

enum modoDeque { frente = 0, retaguarda };

class Deque {
    private:
        int *v;
        int size;
        int capacity;
        int begin;
        int end;
    public:
        Deque(int capacity) {
            this->v = new int[capacity];
            this->capacity = capacity;
            this->size = 0;
            this->begin = 0;
            this->end = 0;
        }
        ~Deque() {
            delete[] v;
        }
        Deque &add(int x, modoDeque md) {
            if(size == capacity) {
                std::cout << "Not possible to add more elements" << std::endl;
                return *this;
            }
            if(md == frente) {
                v[end] = x;
                end = (end + 1) % capacity;
            } else {
                begin = (begin - 1 + capacity) % capacity;
                v[begin] = x;
            }
            size++;
            return *this;
        }
        Deque &remove(modoDeque md) {
            if(size == 0) {
                std::cout << "Removal not possible" << std::endl;
                return *this;
            }
            if(md == frente) {
                end = (end - 1 + capacity) % capacity;
            } else {
                begin = (begin + 1) % capacity;
            }
            size--;
            return *this;
        }
        void display() {
            int i = 0;
            while(i < size) {
                std::cout << v[(i + begin) % capacity] << " ";
                i++;
            }
            std::cout << std::endl;
        }
};

int main() {
    Deque d(4);
    d.add(3, frente).add(4, retaguarda).display();
    d.add(10, retaguarda).add(9,frente).display();
    d.remove(frente).display();

    return 0;
}