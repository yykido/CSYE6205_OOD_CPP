/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
Filename: slist1.h
-----------------------------------------------------------------*/
#pragma once

#include "../util/util.h" //NOTHING CAN BE ADDED
#define T int //Must use T. if we want  change to double : #define T double

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
class node;
class slist1;

/*----------------------------------------------------------------
class Node
-----------------------------------------------------------------*/
class node {
public:
		//Write all public functions below
        node();
        node(int a);
		void setdata(int a);
        void setNext(node* b);
        node* next();
        int* getdata();


private:
		T  data_;
		node* next_;
		//YOU CANNOT ADD ANY DATA MEMBERS
		//You can have any number of private functions here
};

/*----------------------------------------------------------------
class slist
-----------------------------------------------------------------*/
class slist1 {
public:
		//Write all public functions below
        slist1();
        void append(int a);
        void prepend(int a);
        int size() const;
        friend ostream& operator<<(ostream& o, const slist1& a);
        const T* operator[](int i);
        bool find(T a);
        bool remove(T a);
        bool operator==(const slist1& rhs);
        bool operator!=(const slist1& rhs);
        slist1(const slist1& rhs);
        slist1& operator=(const slist1& rhs);
        explicit operator bool()const { return first_; }



//        node getLast();
//        build_slist_and_test_basic_(slist1& s, int* a, int l);

private:
		node* first_;
		node* last_;
		//YOU CANNOT ADD ANY OTHER DATA MEMBERS

		//You can have any number of private functions here
		
};


