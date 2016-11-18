#include <iostream>

using namespace std;

// ---------------------------------------------------

static double constant_function(double x) {
    return 2.0;
}

static double linear_function(double x) {
    return x;
}

static double quadratic_function(double x) {
    return -8*x*x+24*x-15;
}
 
// ---------------------------------------------------

// specifies different functions for different intervals 
//      [start:end[
      
// TODO: This is kind of an on-the-fly declaration and initialization.
//       Can you split it up into the two respective parts? 
//       (structure definition and example array)

// Done! the example_table array is an instance of a data structure called "LookupTable_entry"
struct LookupTable_entry {
    double start; // inclusive
    double end; // exclusive
    double (*func)(double x);
}; 

LookupTable_entry example_table[] = {    //and array of data structures of the type "LookupTable_entry
     {0.0, 1.0, &linear_function},
     {1.0, 2.0, &quadratic_function},
     {2.0, 3.0, &constant_function}
};

// ---------------------------------------------------

double query_lookuptable(
    struct LookupTable_entry *table,
    int numberOfElementsInTable,
    double querypoint
) {
    double result = 0.0;
	double *presult = &result;  //have to create a pointer here because we want to modify inside the for loop

	
	for (int i=0; i<numberOfElementsInTable; i++) {
		if (querypoint >= table[i].start and querypoint <= table[i].end) {
		*presult = table[i].func(querypoint);
		break;
		} 
	}
		

    // TODO: Implement the mapping rule from intervals to functions
    //       1. Loop through all entries in the given lookup table
    //       2. Check for every entry if our query point is part 
    //          of the respective interval
    //       3. If so, call the corresponding function with the 
    //          query point as argument and stop the loop.
    //          If not, try the other entries.
    
    return result;
}

// ---------------------------------------------------

int main(int argc, char **argv) {

    // TODO: What does this magic line do? Why does it work in this case?  
	// !! because the number of doubles in each linear/quadratic/ ect is co-incidentally the same.
    // Does this method work for arrays which are stored in the heap as well?
    size_t numberOfElementsInTable = sizeof(example_table) / sizeof(example_table[0]);

    std::cout << "# x_pos y_value" << std::endl;
    for (double x=-1.0; x < 4.0; x = x + 0.1) {
        double result_value = query_lookuptable(example_table, numberOfElementsInTable, x);

        std::cout << x  << " "  
                  << result_value
                  << std::endl;
    }

    return 0;
}
