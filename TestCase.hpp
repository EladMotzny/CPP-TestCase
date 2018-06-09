using namespace std;
#include <iostream>
#pragma once;
#include <string>
#include <sstream>

// template <typename type>
class TestCase{
    public:
        string msg;
        ostream& cerr;

         TestCase(const string msg, ostream& err): cerr(err){ //TestCase<type>::
            this->msg = msg;
            this->cerr <<"";
        }
   
        template <typename type>
        void check_equal(const type &t1, const type &t2) { //TestCase<type>::
	    if(t1 != t2)
            this->cerr << this->msg << ": Failure in test #1: " << type << " should equal " << type << "!" << endl;
        }

        void print(){this->cerr << endl;}

};