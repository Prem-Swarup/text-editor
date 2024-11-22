#ifndef ROPE_H
#define ROPE_H

#include <iostream>
#include <string>


namespace datastructure {

struct RopeNode {
    std::string str;    
    int weight;         
    RopeNode* left;     
    RopeNode* right;    

    
    RopeNode(const std::string& s) : str(s), weight(s.length()), left(nullptr), right(nullptr) {}

    
    RopeNode(RopeNode* l, RopeNode* r) : left(l), right(r), weight(l ? l->weight : 0) {
        str = l ? l->str + r->str : r->str;  
    }
};


class Rope {
private:
    RopeNode* root;  

    
    RopeNode* concatenate(RopeNode* left, RopeNode* right);
    void split(RopeNode* node, int index, RopeNode*& left, RopeNode*& right);
    char access(RopeNode* node, int index);
    void deleteTree(RopeNode* node);

public:
    
    Rope();
    Rope(const std::string& str);

    
    ~Rope();

    
    void append(const std::string& str);
    void insert(int index, const std::string& str);
    void remove(int index, int length);
    char at(int index); 
    std::string toString(); 

    
    void print();
};

}  

#endif 
