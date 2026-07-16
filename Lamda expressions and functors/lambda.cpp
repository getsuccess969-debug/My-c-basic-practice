#include <iostream>
#include <cstring>
#include <utility>

template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Compare adjacent elements
            if (comp(arr[j], arr[j + 1])) {
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j + 1]);
                arr[j + 1] = std::move(temp);
            }
        }
    }
}

struct Comp2 {
    // Corrected operator() for sorting
    bool operator()(int x, int y) { return x > y; }
    
    // For strings, we need a separate way or a different struct
    // Since Sort expects a single callable, we use a separate lambda/struct
};
template<typename T,int size,typename Callback>
void Foreach(T(&arr)[size], Callback op) {
    for (int i = 0;i < size;i++) {
        op(arr[i]);
    }
}
int main() {
    int arr[] = { 1, 7, 5, 3, 5, 3, 2, 6, 3, 2, 6, 7, 3 };
    Comp2 intComp;
    
    Sort(arr, intComp);
    for (int i : arr) std::cout << i << " ";
    std::cout << "\n";

    const char* ar2[] = { "Aarush", "Akshaj", "Maga", "stupid", "AAAAAA", "Faaah" };
    // Pass a lambda for string comparison to match the expected signature
    Sort(ar2, [](const char* x, const char* y) {
        return strcmp(x, y) > 0;
    });

    for (const char* i : ar2) std::cout << i << " ";
    auto lam=[]() {
        std::cout << "\nHello welcome to lambda expressions:!!";
        };
    lam();
    lam();
    std::cout << typeid(lam).name() << "\n";
    
    auto sum = [](auto x, auto y)noexcept{//generic
        if (x > y)
            return x + y+5.67;
        else
            return x / static_cast<double>(y);
        };
    
    std::cout << "\n hla:" << sum(2, 10) << "\n";std::cout << "\n hla:" << sum(20, 10) << "\n";
    auto square = [](auto &i) {i= i * i;};
    auto cube= [](auto& i) {i = i * i*i;};
    auto sin= [](auto& i) {i = std::sin(i);};
    auto print = [](auto& i) {std::cout << (i) << " ";};
    auto off = 5;
    //676767!!!!!!!!!!1
    auto offset = [&](auto& i) {i = i + off;off++;};
    Foreach(arr, square);
    Foreach(arr, print);
    Foreach(arr,offset);
    std::cout << "offset " << off << "\n";
    
    for (int i : arr) {
        std::cout << i << " ";
    }
}