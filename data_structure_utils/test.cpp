#include "rope.hpp"
#include <iostream>

int main() {
    
    datastructure::Rope rope("This ");
    rope.append("rope!");
    rope.print();  

    rope.insert(5, "is a ");
    rope.print(); 

    rope.remove(5, 5);  
    rope.print();  

    try {
        std::cout << "Character at position 6: " << rope.at(6) << std::endl;
        std::cout << "Character at position 50: " << rope.at(50) << std::endl;  
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;  
    }


    return 0;
}
