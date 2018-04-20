/**
 * @file binary_tree.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <cstdio>
#include <iostream>
#include <string>

#include "node.h"

/** @brief Template BinaryTree class using type parameter for node.
  * Binary search tree property: for all roots: left < root < right
  *
**/
template<class T>
class BinaryTree {
public:
  // Initialize with root as NULL
  BinaryTree() : root_(nullptr) {}

  // Insert such that order is maintained: left < root < right (for all subroots)
  void Insert(T* node);

  // Sorted order print using recursion.
  void Print() {
    if (root_) {
      PrintRecurse(root_);
    } else {
      std::cout << "Empty" << std::endl;
    }
  }

  // Max and Min node finder.
  T* MaxNode() {
    if (!root_) return nullptr;
    T * root = root_;
    while (root->get_right() != nullptr) {
      root = root->get_right();
    }
    return root;
  }
  T* MinNode() {
    if (!root_) return nullptr;
    T * root = root_;
    while (root->get_left() != nullptr) {
      root = root->get_left();
    }
    return root;
  }
private:
  void PrintRecurse(T* root);
  T * root_;
};

// Templates are unique as to when the compiler reserves space, hence
// declaration and definition in the header file
template<class T>
void BinaryTree<T>::PrintRecurse(T* root) {
  if (root != nullptr) {
    this->PrintRecurse(root->get_left());
    std::cout << *root << std::endl;
    this->PrintRecurse(root->get_right());
  }
}

template<class T>
void BinaryTree<T>::Insert(T* node) {
  // First node? Then, make it the root.
  if (root_ == nullptr) {
    root_ = node;
    return;
  }
  T* y = nullptr;
  T* x = root_;
  // While not to a leaf node
  while (x != nullptr) {
    y = x;
    // Check if need to insert left(<) or right(>=) to maintain property
    if (*node < *x) {
      x = x->get_left();
    } else {
      x = x->get_right();
    }
  }
  // Determine if node should be inserted left or right in leaf node
  if (*node < *y) {
    y->set_left(node);
  } else {
    y->set_right(node);
  }
}

#endif  // BINARY_TREE_H_
