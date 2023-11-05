// barchartanimate.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = nullptr;
        size = 0;
        capacity = 4;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;        
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if(barcharts!=nullptr){
            delete[]barcharts;
        }        
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
        // getline(file)
        // if(size==capacity){
        //     int newCapacity = capacity*2;
        //     // BarChart newBarchart = new Bar[newCapacity];
        //     for(int i = 0; i<size; ++i){
        //         newBarchart[i] = barcharts[i];
        //     }
        //     delete[] barcharts;
        //     barcharts = newBarchart;
        //     capacity = newCapacity;

        // }
    	
        // TO DO:  Write this constructor.
        
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        for(int i = 0; i<endIter; i++){
            usleep(3 * microsecond);
            output << CLEARCONSOLE;
            cout << "The most populous cities in the world from 1500 to 2018" << endl;
            cout << "Sources: SEDAC; United Nations; Demographia" << endl;
            barcharts[i].graph(output,colorMap, top);
            cout << "Population (thousands)" << endl;
            cout << "Frame: " ;


        }
    }

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        return size;
    }
    int getCapacity(){
        return capacity;
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        BarChart b;
        if(i<0 || i>= size){
            throw out_of_range("BarchartAnimate: i out of bounds");
        }
        return barcharts[i];
    }
};
