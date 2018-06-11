using namespace std;
#include <iostream>
#pragma once
#include <string>
#include <sstream>

// template <typename type>
class TestCase{
    public:
        string msg;
        ostream& cerr;
        int pass,fail,testNum;//to see how many tests have passed/failed

         TestCase(const string msg, ostream& err): cerr(err){ //TestCase<type>::
            this->msg = msg;
            this->cerr <<"";
            this->pass=0;//number of passed tests
            this->fail=0;//number of failed tests
            this->testNum=0;//number of tests
        }

        template <typename type>
        TestCase& check_equal(const type &t1,const type &t2) { //TestCase<type>::
            testNum++;
            if(!(t1 == t2)){
                this->cerr << this->msg << ": Failure in test #"<< testNum <<": "<< t1 << " should equal " << t2 << "!" << endl;
                fail++;
            }
            else{
                pass++;
            }
            
            return *this;
        }

        template <typename type>
        TestCase& check_different(const type &t1, const type &t2){
            testNum++;
            if(!(t1==t2)){//the test is ok
                pass++;//maybe this->pass
            }
            else{//test failed
                fail++;
                this->cerr << this->msg << ": Failure in test #" << testNum << ": "<< t1 << "should NOT be equal to " << t2 << endl;
            }
            return *this;
        }

        template <typename type>
        TestCase& check_output(const type &t1,const string &st){
            testNum++;
            stringstream s;
            s << t1;
            if(s.str()!=st){
                fail++;
                this->cerr << this->msg << ": Failure in test #" << testNum << "string value should be " << s.str() << " but is "<< st << endl;
            }
            else{
                pass++;
            }
            return *this;
        }

        template <typename function, typename type1, typename type2>
        TestCase& check_function(function func,const type1 &t1, const type2 &t2){
            testNum++;
            if(func(t1)==t2){
                pass++;
            }
            else{
                fail++;
                this->cerr << this->msg << ":Failure in test #" << testNum << ": Function should return "<< t2 <<" but returned "<< func(t1) << "!" <<endl;
            }
            return *this;
        }


        void print(){this->cerr << fail<<" failed, " << pass <<" passed," << testNum <<" in total" << endl;}

};