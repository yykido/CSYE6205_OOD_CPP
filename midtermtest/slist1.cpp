/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
Filename: slist1.cpp
-----------------------------------------------------------------*/

#include "slist1.h"
//NOTHING CAN BE ADDED HERE

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/

// node methods -------------------------------------------------------
void node::setdata(int a) {
    this->data_ = a;
}

int* node::getdata() {
    return &data_;
}

void node::setNext(node* b) {
    next_= b;
}

node::node() {
    this->data_ = -1;
    this->next_ = nullptr;
}

node::node(int a) {
    data_ = a;
    next_ = nullptr;
}

node* node::next() {
    return next_;
}


//node* slist1::getLast() {
//    return last_;
//}

// slist1 methods -------------------------------------------------------

slist1::slist1() {
    first_ = nullptr;
    last_ = nullptr;
}

void slist1::append(T a) {
    if(!first_ && !last_) {
        first_ = new node(a);
        last_ = first_;
    }
    else {
        node *cur = new node(a);
        last_->setNext(cur);
        last_ = last_->next();
    }
//    node curnode(a);
//    if(this->first_ == nullptr) {
//        this->first_ = &curnode;
//        this->last_ = &curnode;
//    }
//    else {
//        node lastnode = *this->last_;
//        lastnode.setNext(curnode);
//        *this->last_ = curnode;
//    }
}

void slist1::prepend(T a) {
    if(! first_ && !last_) {
        first_ = new node(a);
        last_ = first_;
    } else {
        node* cur = new node(a);
        cur->setNext(first_);
        first_ = cur;
    }
//    node curnode(a);
//    if(this->first_ == nullptr) {
//        this->first_ = &curnode;
//        this->last_ = &curnode;
//    }
//    else {
//        node firstnode = *this->first_;
//        curnode.setNext(firstnode);
//        *this->first_ = curnode;
//    }
}

int slist1::size() const{
    int count = 0;
    node* cur = first_;
    while(cur != nullptr) {
        count++;
        cur = cur->next();
    }
//    int size = 1;
//    if(!first_ && !last_) {
//        return 0;
//    }
//    node *cur = first_;
//    while (cur!= last_) {
//        size++;
//        cur= cur->next();
//    }

    return count;
}

ostream& operator<<(ostream& o, const slist1& a) {
    node *cur = a.first_;
    while (cur) {
        o<< *(cur->getdata()) <<"->";
        cur = cur->next();
    }
    o << "null" << endl;

    return o;
}

slist1 &slist1::operator=(const slist1& rhs) {
    if(this != &rhs) {

        // copy linklist
        last_ = nullptr;

        node* rightpointer = rhs.first_;
        node* rightcur = rightpointer;
        node* pre = rightcur;
        first_ = new node(*rightpointer->getdata());
        node* leftcur = first_;

        rightcur = rightcur->next();

        while(rightcur != nullptr) {
            leftcur->setNext(new node(*rightcur->getdata()));
            leftcur = leftcur->next();
            rightcur = rightcur->next();
        }

        last_ = leftcur;
    }
    return *this;
}

bool slist1::operator!=(const slist1& rhs) {
    if(*this == rhs) {
        return false;
    }
    else {
        return true;
    }
}

const T* slist1::operator[](int i) {
    if(i<0) return nullptr;
    int count = i;
    node* cur = first_;
    while(count >0) {
        cur = cur->next();
        count--;
    }
    return cur->getdata();
}


bool slist1::find(T a) {
    node* cur = first_;
    node target = a;
    if(*cur->getdata() == *target.getdata())
        return true;
    while(cur != nullptr) {
        cur = cur->next();
        if(cur == nullptr) break;
        if(*cur->getdata() == *target.getdata()) {
            return true;
        }
    }
    return false;

}

bool slist1::remove(T a) {
    node* cur = first_;
    node target = a;
    if(*cur->getdata() == *target.getdata()) {
        first_ = cur->next();
        return true;
    }
    node* pre = cur;
    cur = cur->next();
    while(*cur->getdata() != *target.getdata()) {
        pre = pre->next();
        cur = cur->next();
        if(cur == nullptr) {
            break;
        }
    }
    if(cur == nullptr) return false;

    if(cur->next() == nullptr) {
        pre->setNext(nullptr);
        last_ = pre;
    }
    else {
        pre->setNext(cur->next());
        last_ = pre;
    }
    return true;





}

bool slist1::operator==(const slist1 &rhs) {
    node *pointer1 = first_;
    node *pointer2 = rhs.first_;

    if(this->size() != rhs.size()) {
        return false;
    }
    while(pointer1 && pointer2) {
        T num1 = *(pointer1->getdata());
        T num2 = *(pointer2->getdata());
        if(num1 != num2) {
            return false;
        }
        pointer1 = pointer1->next();
        pointer2 = pointer2->next();
    }
    return true;
}

slist1::slist1(const slist1& rhd) {
//    first_ = nullptr;
    last_ = nullptr;

    node* rightpointer = rhd.first_;
    node* rightcur = rightpointer;
    node* pre = rightcur;
    first_ = new node(*rightpointer->getdata());
    node* leftcur = first_;

    rightcur = rightcur->next();

    while(rightcur != nullptr) {
        leftcur->setNext(new node(*rightcur->getdata()));
        leftcur = leftcur->next();
        rightcur = rightcur->next();
    }

    last_ = leftcur;

}



