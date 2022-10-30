/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
Filename: slist1test.cpp
compile: g++ slist1.cpp slist1test.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
																		NOTHING CAN BE CHANGED BELOW
											No grade will be given if U change anything below
-----------------------------------------------------------------*/
#include "slist1.h"

class slist1Test {
public:
		slist1Test() { test_(); }

private:
		int marks_ = 0;
		void test_();
		void test1_();
		void test2_();
		void test3_();
		void build_slist_and_test_basic_(slist1& s, const T a[], int l);
		void test_delete_(int n);
};

/*----------------------------------------------------------------
All tests 100 marks
-----------------------------------------------------------------*/
void slist1Test::test_() {
		test1_();
		test2_();
		test3_();
		cout << "Total marks " << marks_ << endl;
}

/*----------------------------------------------------------------
Testing append prepend cout and s[i] - 33 marks
-----------------------------------------------------------------*/
void slist1Test::test1_() {
		cout << "-----------Testing append prepend cout and s[i] - 33 marks-------- \n";
		const T a[] = { 1,2,3,4,5 };
		int l = sizeof(a) / sizeof(T);
		slist1 s;
		build_slist_and_test_basic_(s, a, l);
		marks_ = marks_ + 33;
		cout << "You got " << marks_ << " marks now\n";
}

/*----------------------------------------------------------------
Testing copy, equal on slist
-----------------------------------------------------------------*/
void slist1Test::test2_() {
		cout << "-----------Testing copy, equal on slist - 33 marks-------- \n";
		const T a[] = { 1,2,3,4,5 };
		int l = sizeof(a) / sizeof(T);
		slist1 s1;
		for (const T& d : a) {
				s1.prepend(d);
		}
		int s1size = s1.size();
		if (s1size != l) {
				cout << "Your slist has " << s1size << " elements but it should have " << l << " elements" << endl;
				assert(l == s1size);
		}
		cout << s1 << endl;

		slist1 s2;
		for (const T& d : a) {
				s2.append(d);
		}
		int s2size = s2.size();
		if (s2size != l) {
				cout << "Your slist has " << s2size << " elements but it should have " << l << " elements" << endl;
				assert(l == s2size);
		}
		cout << s2 << endl;

		bool x = (s1 != s2);
		if (!x) {
				cout << s1 << endl;
				cout << s2 << endl;
				cout << "How they are same\n";
				assert(false);
		}

		slist1 s3(s1);
		int s3size = s3.size();
		if (s3size != l) {
				cout << "Your slist has " << s3size << " elements but it should have " << l << " elements" << endl;
				assert(l == s3size);
		}
		cout << s3 << endl;

		slist1 s4(s2);
		int s4size = s4.size();
		if (s4size != l) {
				cout << "Your slist has " << s4size << " elements but it should have " << l << " elements" << endl;
				assert(l == s4size);
		}
		cout << s4 << endl;
		s4 = s3 = s2 = s2 = s2 = s1;
		cout << s4 << endl;
		x = ((s1 == s2) && (s1 == s3) && (s1 == s4));
		if (!x) {
				cout << s1 << endl;
				cout << s2 << endl;
				cout << s3 << endl;
				cout << s4 << endl;
				cout << "All above must be same\n";
				assert(false);
		}

		marks_ = marks_ + 33;
		cout << "You got " << marks_ << " marks now\n";
}

/*----------------------------------------------------------------
Testing find and delete on slist
-----------------------------------------------------------------*/
void slist1Test::test3_() {
		cout << "-----------Testing find and delete - 34 marks-------- \n";
		const T a[] = { 1,2,3,4,5 };
		int l = sizeof(a) / sizeof(T);
		slist1 s1;
		for (const T& d : a) {
				s1.prepend(d);
		}
		int s1size = s1.size();
		if (s1size != l) {
				cout << "Your slist has " << s1size << " elements but it should have " << l << " elements" << endl;
				assert(l == s1size);
		}
		cout << s1 << endl;

		slist1 s2;
		for (const T& d : a) {
				s2.append(d);
		}
		int s2size = s2.size();
		if (s2size != l) {
				cout << "Your slist has " << s2size << " elements but it should have " << l << " elements" << endl;
				assert(l == s2size);
		}
		cout << s2 << endl;
		bool x = (s1 != s2);
		if (!x) {
				cout << s1 << endl;
				cout << s2 << endl;
				cout << "How they are same\n";
				assert(false);
		}
		s1 = s2;
		x = (s1 == s2);
		if (!x) {
				cout << s1 << endl;
				cout << s2 << endl;
				cout << "How they are NOT same\n";
				assert(false);
		}
		cout << s1 << endl;
		cout << s2 << endl;
		for (const T& d : a) {
				bool x = s1.find(d);
				if (!x) {
						cout << "Why " << d << " is Not there in s1 " << endl;
						assert(false);
				}
				x = s2.find(d);
				if (!x) {
						cout << "Why " << d << " is Not there in s2 " << endl;
						assert(false);
				}
		}
		{
				T d(100);
				bool x = s1.find(d);
				if (x) {
						cout << "Why " << d << " is there in s1 " << endl;
						assert(false);
				}
		}

		{
				T d(1);
				bool x = s1.remove(d);
				cout << s1 << endl;
				if (!x) {
						cout << "Why " << d << " is Not removed from s1 " << endl;
						assert(false);
				}
				for (int i = 1; i < l; ++i) {
						const T* p = s1[i - 1];
						const T& v = *(p);
						const T& e = a[i];
						if (v != e) {
								cout << "Correct s1[" << i << "]= " << e << endl;
								cout << "Yours   s1[" << i << "]= " << v << endl;
								assert(false);
						}
				}
		}
		{
				T d(5);
				bool x = s1.remove(d);
				cout << s1 << endl;
				if (!x) {
						cout << "Why " << d << " is Not removed from s1 " << endl;
						assert(false);
				}
				for (int i = 1; i < l - 1; ++i) {
						const T* p = s1[i - 1];
						const T& v = *(p);
						const T& e = a[i];
						if (v != e) {
								cout << "Correct s1[" << i << "]= " << e << endl;
								cout << "Yours   s1[" << i << "]= " << v << endl;
								assert(false);
						}
				}
		}
		{
				cout << s1 << endl;
				cout << s2 << endl;
				bool x = (s1 != s2);
				if (!x) {
						cout << "How are they same?. You cheated me in copy constructor\n";
						assert(false);
				}
		}
		{
				int n = 100;
				test_delete_(n);
				n = 1001;
				test_delete_(n);
		}

		marks_ = marks_ + 34;
		cout << "You got " << marks_ << " marks now\n";
}

/*----------------------------------------------------------------
Testing find and delete on slist in arbitrary position
-----------------------------------------------------------------*/
void slist1Test::test_delete_(int n) {
		cout << "-----------test_delete-- " << n << endl;
		slist1 s;
		for (int i = 0; i < n; ++i){
				s.prepend(2*i - 21);
		}

		while (s) {
				{
						int i = 0;
						int j = s.size();
						int m = (i + j) / 2;
						const T* p = s[m];
						if (p) {
								const T& v = *(p);
								s.remove(v);
						}
				}
				{
						int i = 0;
						const T* p = s[i];
						if (p) {
								const T& v = *(p);
								s.remove(v);
						}
				}
				{
						int j = s.size();
						const T* p = s[j-1];
						if (p) {
								const T& v = *(p);
								s.remove(v);
						}
				}

		}
}

/*----------------------------------------------------------------
const T a[] = { 1,2,3,4,5 };
1->2->3->4->5->null
-----------------------------------------------------------------*/
void slist1Test::build_slist_and_test_basic_(slist1& s, const T a[], int l) {
		for (int i = 0; i < l; ++i) {
				s.append(a[i]);
		}
		int n = s.size();
		int t = l;
		if (n != t) {
				cout << "Your slist has " << n << " elements but it should have " << t << " elements" << endl;
				assert(n == t);
		}
		cout << s << endl;
		for (int i = 0; i < l; ++i) {
				s.prepend(a[i]);
		}
		t = l + l;
		n = s.size();
		if (n != t) {
				cout << "Your slist has " << n << " elements but it should have " << t << " elements" << endl;
				assert(n == t);
		}
		cout << s << endl;
		for (int i = 0; i < l; ++i) {
				const T* p = s[i];
				const T& v = *(p);
				const T& e = a[l - 1 - i];
				if (v != e) {
						cout << "Correct slist1[" << i << "]= " << e << endl;
						cout << "Yours   slist1[" << i << "]= " << v << endl;
						assert(false);
				}
		}
		assert(s[t] == nullptr);
		assert(s[-1] == nullptr);
		for (int i = 0; i < l; ++i) {
				const T* p = s[i + l];
				const T& v = *(p);
				const T& e = a[i];
				if (v != e) {
						cout << "Correct slist1[" << i << "]= " << e << endl;
						cout << "Yours   slist1[" << i << "]= " << v << endl;
						assert(false);
				}
		}
		assert(s[t] == nullptr);
		assert(s[-1] == nullptr);

}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
		slist1Test h = slist1Test();
		cout << "for 100 marks, there should be no memory leaks here \n";
		cout << "Only UPLOAD slist1.cpp  slist1.h in Canvas. NO ZIP FILE\n";
		cout << "DO NOT UPLOAD slist1test.cpp to Canvas\n";
		cout << "We will run with master slist1test.cpp and all tests must pass\n";
}

