/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#include <cstdio>
#include <iostream>
#include <cstring>

#include "binary_tree.h"


int main() {

  Node<int,std::string> * node; // temp variable

  // THE binary search tree
  BinaryTree<Node<int,std::string>> tree;

  // Create a tree of 5 elements
  node = new Node<int,std::string>(10,"ten");
  tree.Insert(node);
  node = new Node<int,std::string>(15,"fifteen");
  tree.Insert(node);
  node = new Node<int,std::string>(2,"two");
  tree.Insert(node);
  node = new Node<int,std::string>(6,"six");
  tree.Insert(node);
  node = new Node<int,std::string>(11,"eleven");
  tree.Insert(node);

  // Print in sorted order
  tree.Print();

  // Find the min and max
  node = tree.MaxNode();
  std::cout << "MAX: ";
  if (node) { std::cout << *node << std::endl; }

  node = tree.MinNode();
  std::cout << "MIN: ";
  if (node) { std::cout << *node << std::endl; }

  return 1;
}
