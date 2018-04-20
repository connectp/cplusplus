/**
 * @file data.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef NODE_H_
#define NODE_H_

#include <cstdio>
#include <iostream>
#include <string>

/** @brief Template Node using type parameters for key and value for
  * binary tree
  *
  * Node has key (for sorting), value, and left and right child pointers
  * Type parameter T1 is for key_, and T2 is for value_
  **/
template<class T1, class T2>
class Node {
 public:
  Node() : left_child_(nullptr), right_child_(nullptr) {
  }
  Node(T1 k, T2 v) : left_child_(nullptr), right_child_(nullptr), key_(k), value_(v) {
  }

  // Overloaded logical operators used to compare nodes using keys
  bool operator<(const Node& rhs) {
    return key_ < rhs.key_;
  }
  bool operator<=(const Node& rhs) {
    return key_ <= rhs.key_;
  }
  bool operator>(const Node& rhs) {
    return key_ > rhs.key_;
  }
  bool operator>=(const Node& rhs) {
    return key_ >= rhs.key_;
  }

  friend std::ostream& operator<<(std::ostream& os, const Node& node) {
    return os << node.key_ << ": " << node.value_;
  }

  // Getters and setters for child nodes
  Node* get_left() { return left_child_; }
  void set_left(Node* left) { left_child_ = left; }
  Node* get_right() { return right_child_; }
  void set_right(Node* right) { right_child_ = right; }

  // Getters for key and value
  T1 get_key() const { return key_; }
  T2 get_value() const { return value_; }

 private:
  Node * left_child_;
  Node * right_child_;
};

#endif  // NODE_H_
