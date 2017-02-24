import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 * 
 * Problem: 
 *  k-tree is a tree that each node has at most k children
 *  binary tree is a special case of k-tree where k = 2
 *  Develop an algorithm to convert k-tree to 2-tree that can convert back to original k-tree
 */

class Solution {
  // default Node Class tempalte for KTree
  public static class Node<T> {
    private T value;
    private List<Node<T>> children;    
    
    public Node(T value) {
      this.value = value;
      this.children = new LinkedList<Node<T>>();
    }
    
    public void addChild(T value) {
      Node<T> child = new Node<T>(value);
      this.children.add(child);
    }
    
  }
  
  /*
  KTree(k) with interfaces
    Node<Integer> random() function to generate k-tree
    Node<Integer> to2Tree(k-root, b-root, left) function to convert to binary tree, return b-root
    Node<Integer> toKTree(b-root, left, k-root) function to convert back to k-tree, return k-root
    void printTree() function for visualization and debugging
  */
  static class KTree {
    private Node<Integer> root; 
    private Random rand;
    private int N;
    private int k;
    
    public KTree(int k) {
      this.N = 1;
      this.k = k;
      rand = new Random();
      root = random(new Node<Integer>(1));
    }    
    
    /*
      Randomize function to generate a k-tree with p(having children) = 0.25
      N = the number of nodes in k-tree, N is arbitrary
      As K increases, p(having children) decreases to avoid INFINITE loop
    */
    
    Node<Integer> random(Node<Integer> root) {
      // randomly choosing the number of children from 1 -> k
      int temp = rand.nextInt(k) + 1;
      
      // adding chilren to current node
      for (int i = 0; i < temp; i++) {
        N++;
        root.children.add(new Node<Integer>(N));
      }
      
      for (int i = 0; i < root.children.size(); i++)
        // each node has 25% chance of having chilren
        if (rand.nextFloat() <= 0.25) 
          random(root.children.get(i));
      return root;
    }    
    
    /*
      Time Complexity: O(n)
      Space Complexity: O(n)
    */    
    public Node<Integer> to2Tree(Node<Integer> kroot, Node<Integer> broot, int branch) {
      // terminal state
      if (kroot == null) return null;
      
      // binary tree requires left and right children to execute properly
      broot.children.add(new Node<Integer>(-1));
      broot.children.add(new Node<Integer>(-1));
      
      // save to b-root to a temporary variable
      Node<Integer> temp = broot;
      
      /*
        Default direction: left
        Original direction: branch
        Opposite direction: 1^branch
        
        In each recursion:
        1. Iterate through each child of k-root.children        
        2. Moves to the next child in b-root (original direction
        3. Replace value of b-root by value of the current child
        4. As we move to the next depth, the direction of 2-tree is changed <-- most important concept
      */
      for (Node<Integer> child : kroot.children) {        
        broot = broot.children.get(branch);
        broot.value = child.value;
        to2Tree(child, broot, 1^branch); // 1^branch is shortcut for branch = 1 - branch
      }
      
      return temp;
    }
    
    /*
      Time Complexity: O(n)
      Space Complexity: O(n)
    */
    public Node<Integer> toKTree(Node<Integer> broot, int branch, Node<Integer> kroot) {
      // terminal state
      if (broot == null || broot.value == -1) return null;
      
      /*
      Default direction: left (as constructed from to2Tree function
      Variable branch represents the direction of all siblings in k-tree            
      Two cases of direction: left-right or right-left
      
      In each recursion:
      1. Add b-root.value to k-root.children
      2. Recur the newly added child with the opposite direction (must be done before step 3)
      3. Recur with the original direction to add new value from 2-tree to k-root.chilren
      */
      kroot.children.add(new Node<Integer>(broot.value));      
      toKTree(broot.children.get(1^branch), 1^branch, kroot.children.get(kroot.children.size()-1));     
      toKTree(broot.children.get(branch), branch, kroot);
      
      return kroot;
    }
    
    
    
    // function printTree to easily visualize the algorithm
    public void printTree(Node<Integer> root) {
      // terminal state
      if (root == null) return;
      
      if (root.children.size() > 0) {
        // print root
        System.out.print(root.value + " -> ");
        for (int i = 0; i < root.children.size(); i++) {
          Node<Integer> temp = root.children.get(i);
          // print children
          System.out.print(temp.value + " ");
        }        
        // next line
        System.out.println();
      }
      // recursively print the whole tree
      for (int i = 0; i < root.children.size(); i++)
        printTree(root.children.get(i));
    }    
    
    // ------------- END -------------
    
  }
  
  public static void main(String[] args) {
    KTree tree = new KTree(5);
    
    System.out.println("------------- Original KTree -------------");
    tree.printTree(tree.root);
    
    System.out.println("------------- KTree to 2Tree -------------");
    Node<Integer> broot = tree.to2Tree(tree.root, new Node<Integer>(tree.root.value), 0);
    tree.printTree(broot);    
        
    System.out.println("------------- 2Tree to KTree -------------");
    Node<Integer> kroot = tree.toKTree(broot, 0, new Node<Integer>(broot.value));    
    // the algorithm duplicates root at first child's position, therefore the removal is inevitable
    kroot.children.remove(0); 
    tree.printTree(kroot);
    
    
  }
}
