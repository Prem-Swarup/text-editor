#include "rope.hpp"
#include <stdexcept>  



datastructure::Rope::Rope() : root(nullptr) {}

datastructure::Rope::Rope(const std::string& str) {
    root = new datastructure::RopeNode(str);  
}

datastructure::Rope::~Rope() {
    deleteTree(root);
}

void datastructure::Rope::deleteTree(datastructure::RopeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void datastructure::Rope::append(const std::string& str) {
    datastructure::RopeNode* newNode = new datastructure::RopeNode(str);
    root = concatenate(root, newNode);
}

datastructure::RopeNode* datastructure::Rope::concatenate(datastructure::RopeNode* left, datastructure::RopeNode* right) {
    return new datastructure::RopeNode(left, right);
}

void datastructure::Rope::insert(int index, const std::string& str) {
    datastructure::RopeNode* newNode = new datastructure::RopeNode(str);
    datastructure::RopeNode* left, * right;
    split(root, index, left, right);
    root = concatenate(concatenate(left, newNode), right);
}

void datastructure::Rope::split(datastructure::RopeNode* node, int index, datastructure::RopeNode*& left, datastructure::RopeNode*& right) {
    if (!node) {
        left = nullptr;
        right = nullptr;
        return;
    }

    if (index <= node->weight) {
        split(node->left, index, left, right);
        if (left) {
            node->left = left;
            left = new datastructure::RopeNode(node->left->str.substr(0, index));
            node->weight = index;
        }
        right = node->right;
    } else {
        index -= node->weight;
        split(node->right, index, left, right);
    }
}

void datastructure::Rope::remove(int index, int length) {
    datastructure::RopeNode* left, * right;
    split(root, index, left, right);
    datastructure::RopeNode* midLeft, * midRight;
    split(right, length, midLeft, midRight);
    root = concatenate(left, midRight);
}

char datastructure::Rope::at(int index) {
    return access(root, index);
}

char datastructure::Rope::access(datastructure::RopeNode* node, int index) {
    if (!node) {
        throw std::out_of_range("Index out of bounds");
    }

    if (index < node->weight) {
        return access(node->left, index);
    } else {
        return access(node->right, index - node->weight);
    }
}

std::string datastructure::Rope::toString() {
    if (!root) return "";
    return root->str;
}

void datastructure::Rope::print() {
    std::cout << toString() << std::endl;
}

