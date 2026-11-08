#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void fill_random(std::vector<int>& values, int max_value) // vector de número random
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

void fill_incremental(std::vector<int>& values, int max_value)// vector de número de menor a mayor
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

void fill_decremental(std::vector<int>& values, int max_value) // vector de números de mayor a menor
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = values.size() - 1; i >= 0; --i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

//Funcion de insertionsort
void insertion_sort(std::vector<int>& values){
    for(int i=0;i<values.size();i++){
        int j=0;

        while(j<i && values.at(j)<=values.at(i)){
            j++;
        }
    if (j < i) {
            int temp = values.at(i);
            
            for (int k = i; k > j; k--) {
                values.at(k) = values.at(k - 1);
            }
            
            values.at(j) = temp;
        }
    }
}

//Funcion de selectionsort
void selection_sort(std::vector<int>& values)
{
    for (int i = 0; i < values.size() - 1; i++) {
        // Find the item that belongs in position i.
        // Find the smallest item with index j >= i.
        int min_index = i;
        for (int j = i + 1; j < values.size(); j++) {
            if (values.at(j) < values.at(min_index)) {
                min_index = j;
            }
        }
        std::swap(values.at(i), values.at(min_index));
    }
} 

//Funcion de countingsort
void counting_sort(std::vector<int>& values, int max_value){
    std::vector<int> counts(max_value+1, 0);
    for (int i=0;i<=max_value;i++){
        counts.at(i)=0;
    }
    for(int i=0;i<values.size();i++){
        counts.at(values.at(i))=counts.at(values.at(i))+1;
    }

    int index=0;
    for(int i=0; i<=max_value;i++){
        for(int j=1; j<=counts.at(i); j++){
            values.at(index)=i;
            index=index+1;
        }
    }
} 

//Funcion de bubblesort
void bubble_sort(std::vector<int>&  values){
    bool not_sorted=true;
    while (not_sorted){
        not_sorted=false;

    for (int i =0; i<values.size()-1;i++){
        if (values.at(i) > values.at(i+1)){
            int temp=values.at(i);
            values.at(i)=values.at(i+1);
            values.at(i+1)=temp;
            not_sorted=true;
        } }
        
    } 
}

//Funcion de quicksort
void quicksort(std::vector<int>& values, int start, int end) {

    if (start >= end) {
        return;
    }

    int divider = values.at(end);
    int middle = start;

    for (int i = start; i < end; i++) {
        if (values.at(i) < divider) {
            std::swap(values.at(i), values.at(middle));
            middle++;
        }
    }

    std::swap(values.at(middle), values.at(end));

    quicksort(values, start, middle - 1);
    quicksort(values, middle + 1, end);
}

// Funcion de mergesort
void merge_sort(std::vector<int>& values,std::vector<int>& scratch,int start, int end){
    if (start>=end){
        return;
    }

    int midpoint=start+(end-start)/2;
    merge_sort(values,scratch, start, midpoint);
    merge_sort(values, scratch, midpoint+1,end);
    
    int left_index=start;
    
    int right_index=midpoint+1;
    
    int scratch_index=left_index;

    while((left_index<=midpoint) && (right_index<=end)){
        if (values.at(left_index)<=values.at(right_index)){
            scratch.at(scratch_index)=values.at(left_index);
            left_index++;
        }
        else{
            scratch.at(scratch_index)=values.at(right_index);
            right_index++;
        }
        scratch_index=scratch_index+1;
    }
    for(int i=left_index;i<=midpoint;i++){
        scratch.at(scratch_index)=values.at(i);
        scratch_index=scratch_index+1;
    }
    for (int i=right_index;i<=end;i++){
        scratch.at(scratch_index)=values.at(i);
        scratch_index=scratch_index+1;

    }
    for (int i=start;i<=end;i++){
        values.at(i)=scratch.at(i);
    }
}





void print_vector(const std::vector<int>& values) //para imprimir vector
{
    for (int x : values) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main()
{
    const int max_value = 1'000;
    std::vector<int> a(1'000'000);
    std::vector<int> scratch(a.size());

    //*Para selecionar el orden de los números de VECTOR:
    fill_decremental(a, max_value); 
    //fill_incremental(a, max_value); 
    //fill_random(a, max_value);


    // print_vector(a);
    std::cout << "Is sorted? " << std::is_sorted(a.begin(), a.end()) << "\n";
    auto start = std::chrono::high_resolution_clock::now();

    //*Método a utilizar:
    //selection_sort(a); 
    //insertion_sort(a);
    //counting_sort(a,max_value);
    //quicksort(a,0, a.size() - 1);
    //bubble_sort(a);
    //std::sort(a.begin(), a.end()); //Funcion  std::sort 
    merge_sort(a, scratch, 0, a.size()-1);

    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << " seconds\n";
    std::cout << "Is sorted? " << std::is_sorted(a.begin(), a.end()) << "\n";

    // print_vector(a);

    return 0;
}