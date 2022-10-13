//EXTRANEOUS TEXT
//This function deletes any extraneous characters entered after extraction (cleans up the buffer until reaching '\n')

#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



//MISMATCH OF INPUT TYPE AND EXTRACTION VARIABLE'S TYPE OR OVERFLOW
if (!std::cin) // has a previous extraction failed?
{
    // yep, so let's handle the failure
    std::cin.clear(); // put us back in 'normal' operation mode
    ignoreLine(); // and remove the bad input
}



//USING ASSERT() FROM <CASSERT>
//in some cases the error massage isn't descriptive enough so you can make your assert statements more descriptive:
assert(found && "Car could not be found in database"); // A string literal always evaluates to Boolean true



//DOCUMENT UNIMPLEMENTED CASES WITH ASSESRT()
assert(moved && "Need to handle case where student was just moved to another classroom");




//NOTE: Assertions should be used to document cases that should be logically impossible. 
//      Error handling should be used to handle cases that are possible.
    
