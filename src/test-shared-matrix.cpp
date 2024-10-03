#include <iostream>

#ifdef shared_matrixlib_EXPORTS
/* We are building this library */
#   define MATRIXLIB_EXPORT __declspec(dllexport)
#else
/* We are using this library */
#   define MATRIXLIB_EXPORT __declspec(dllimport)
#endif


struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif

    extern Matrix *MATRIXLIB_EXPORT math_createMatrix(int, int);
    extern void MATRIXLIB_EXPORT math_set(Matrix *, int, int, double);
    extern void MATRIXLIB_EXPORT math_print(Matrix *);
    extern void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *);

    extern double MATRIXLIB_EXPORT math_get(const Matrix *, int, int);
    extern Matrix *MATRIXLIB_EXPORT math_add(const Matrix *, const Matrix *);
    extern Matrix *MATRIXLIB_EXPORT math_subtruct(const Matrix *, const Matrix *);
    extern Matrix *MATRIXLIB_EXPORT math_dot(const Matrix *, const Matrix *);
    
    extern void MATRIXLIB_EXPORT math_add_assign(const Matrix *, Matrix *);
    extern void MATRIXLIB_EXPORT math_subtruct_assign(const Matrix *, Matrix *);
    extern void MATRIXLIB_EXPORT math_dot_assign(const Matrix *, Matrix *);

    extern void MATRIXLIB_EXPORT math_fprint(const Matrix *);
    extern void MATRIXLIB_EXPORT math_fscan(Matrix *);

#ifdef __cplusplus
}
#endif

int main()
{
    Matrix* m = math_createMatrix(3, 3);
    Matrix* m1 = math_createMatrix(3, 3);

    math_set(m, 0, 0, 1.);
    math_set(m, 1, 1, 1.);
    std::cout << "m = " << std::endl;   
    math_print(m);

    math_set(m1, 0, 0, 5.);
    math_set(m1, 1, 1, 5.);
    std::cout << "m1 = " << std::endl;   
    math_print(m1);

    Matrix* m2 = math_add(m, m1);
    std::cout << "m2 = m + m1:" << std::endl;
    math_print(m2);

    Matrix* m3 = math_subtruct(m, m1);
    std::cout << "m3 = m - m1:" << std::endl;
    math_print(m3);

    Matrix* m4 = math_dot(m, m1);
    std::cout << "m4 = m * m1:" << std::endl;
    math_print(m4);



    math_add_assign(m, m1);
    std::cout << "m += m1:" << std::endl;
    math_print(m);

    math_subtruct_assign(m, m1);
    std::cout << "m -= m1:" << std::endl;
    math_print(m);

    math_dot_assign(m, m1);
    std::cout << "m *= m1:" << std::endl;
    math_print(m);



    // Ввод матрицы с клавиатуры
    printf("Введите элементы для матрицы m (3x3):\n");
    math_fscan(m);

    // Вывод матрицы в стандартный вывод
    printf("Матрица m:\n");
    math_fprint(m);

 

    math_deleteMatrix(m);
    math_deleteMatrix(m1);
    math_deleteMatrix(m2);
    math_deleteMatrix(m3);  
    math_deleteMatrix(m4);  

    return 0;
}