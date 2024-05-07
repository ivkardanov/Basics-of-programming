#include <iostream>

class vect {
public:
    int dim;
    double* b;
    int num;
    static int count;

    vect(int d, int n) : dim(d), num(n) {
        b = new double[dim];
        count++;
        std::cout << "Vector #" << num << " created." << std::endl;
    }

    ~vect() {
        delete[] b;
        count--;
        std::cout << "Vector #" << num << " deleted." << std::endl;
    }

    // Операторы векторной алгебры
    vect operator+(const vect& v) const {
        vect res(dim, count);
        for (int i = 0; i < dim; i++) {
            res.b[i] = b[i] + v.b[i];
        }
        std::cout << "Vector addition performed between #" << num << " and #" << v.num << std::endl;
        return res;
    }

    vect operator-(const vect& v) const {
        vect res(dim, count);
        for (int i = 0; i < dim; i++) {
            res.b[i] = b[i] - v.b[i];
        }
        std::cout << "Vector subtraction performed between #" << num << " and #" << v.num << std::endl;
        return res;
    }

    vect operator-() const {
        vect res(dim, count);
        for (int i = 0; i < dim; i++) {
            res.b[i] = -b[i];
        }
        std::cout << "Vector negation performed on #" << num << std::endl;
        return res;
    }

    double operator*(const vect& v) const { // Скалярное произведение
        double res = 0;
        for (int i = 0; i < dim; i++) {
            res += b[i] * v.b[i];
        }
        std::cout << "Scalar product calculated between #" << num << " and #" << v.num << std::endl;
        return res;
    }

    vect operator*(double k) const { // Умножение на скаляр
        vect res(dim, count);
        for (int i = 0; i < dim; i++) {
            res.b[i] = b[i] * k;
        }
        std::cout << "Vector #" << num << " multiplied by scalar " << k << std::endl;
        return res;
    }

    friend vect operator*(double k, const vect& v) { // Умножение на скаляр (внешняя функция)
        return v * k;
    }

    vect& operator=(const vect& v) { // Присваивание
        if (this != &v) {
            delete[] b;
            dim = v.dim;
            b = new double[dim];
            for (int i = 0; i < dim; i++) {
                b[i] = v.b[i];
            }
        }
        std::cout << "Vector #" << num << " assigned to vector #" << v.num << std::endl;
        return *this;
    }

    // Добавляем вектору оператор умножения на матрицу
    vect operator*(const class matr& m) const;

    // Объявляем оператор умножения вектора на матрицу как другую функцию
    friend vect operator*(const vect& v, const class matr& m);
};

class matr {
public:
    int dim;
    double** a;
    int num;
    static int count;

    matr(int d, int n) : dim(d), num(n) {
        a = new double* [dim];
        for (int i = 0; i < dim; i++) {
            a[i] = new double[dim];
        }
        count++;
        std::cout << "Matrix #" << num << " created." << std::endl;
    }

    ~matr() {
        for (int i = 0; i < dim; i++) {
            delete[] a[i];
        }
        delete[] a;
        count--;
        std::cout << "Matrix #" << num << " deleted." << std::endl;
    }

    // Операторы матричной алгебры
    matr operator+(const matr& m) const {
        matr res(dim, count);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                res.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        std::cout << "Matrix addition performed between #" << num << " and #" << m.num << std::endl;
        return res;
    }

    matr operator-(const matr& m) const {
        matr res(dim, count);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                res.a[i][j] = a[i][j] - m.a[i][j];
            }
        }
        std::cout << "Matrix subtraction performed between #" << num << " and #" << m.num << std::endl;
        return res;
    }

    matr operator-() const {
        matr res(dim, count);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                res.a[i][j] = -a[i][j];
            }
        }

            std::cout << "Matrix negation performed on #" << num << std::endl;
            return res;
    }

    matr operator*(const matr& m) const { // Умножение матриц
        matr res(dim, count);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < dim; k++) {
                    res.a[i][j] += a[i][k] * m.a[k][j];
                }
            }
        }
        std::cout << "Matrix multiplication performed between #" << num << " and #" << m.num << std::endl;
        return res;
    }

    matr operator*(double k) const { // Умножение на скаляр
        matr res(dim, count);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                res.a[i][j] = a[i][j] * k;
            }
        }
        std::cout << "Matrix #" << num << " multiplied by scalar " << k << std::endl;
        return res;
    }

    friend matr operator*(double k, const matr& m) {

            // Умножение на скаляр (внешняя функция)
            return m * k;
    }

    matr& operator=(const matr& m) { // Присваивание
        if (this != &m) {
            for (int i = 0; i < dim; i++) {
                delete[] a[i];
            }
            delete[] a;
            dim = m.dim;
            a = new double* [dim];
            for (int i = 0; i < dim; i++) {
                a[i] = new double[dim];
                for (int j = 0; j < dim; j++) {
                    a[i][j] = m.a[i][j];
                }
            }
        }
        std::cout << "Matrix #" << num << " assigned to matrix #" << m.num << std::endl;
        return *this;
    }

    // Добавляем матрице оператор умножения на вектор
    vect operator*(const vect& v) const;

    // Объявляем оператор умножения матрицы на вектор как другую функцию
    friend vect operator*(const matr& m, const vect& v);
};

vect vect::operator*(const matr& m) const { // Умножение вектора на матрицу
    vect res(dim, count);
    for (int i = 0; i < dim; i++) {
        res.b[i] = 0;
        for (int j = 0; j < dim; j++) {
            res.b[i] += m.a[i][j] * b[j];
        }
    }
    std::cout << "Vector #" << num << " multiplied by matrix #" << m.num << std::endl;
    return res;
}



int vect::count = 0;
int matr::count = 0;

int main() {
    vect v1(3, 1);
    vect v2(3, 2);
    matr m1(3, 1);
    matr m2(3, 2);

    // Примеры операций
    vect v3 = v1 + v2;  // Сложение векторов
    vect v4 = v1 - v2;  // Вычитание векторов
    vect v5 = -v1;      // Негация вектора
    double dot = v1 * v2; // Скалярное произведение векторов

    matr m3 = m1 + m2;  // Сложение матриц
    matr m4 = m1 - m2;  // Вычитание матриц
    matr m5 = -m1;      // Негация матрицы
    matr m6 = m1 * m2;  // Умножение матриц


    return 0;
}

