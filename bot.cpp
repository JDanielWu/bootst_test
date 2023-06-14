#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <boost/python.hpp>
#include<iostream>
#include<stdio.h>
using namespace boost::python;
#include <cmath>

class Param
{
  public:
    Param(float a,float b, float c)
    {
      A = a;
      B = b;
      C = c;
    }
  public:
    float A;
    float B;
    float C;
};

class circle_2d {
  // circle center(a,b); radius r; time t
  // x = a+r*cost;
  // y= b+r*sint
public:
  float a, b, r;
  float dist_delt;
  bool clockwise;
 
public:
  circle_2d(float ma, float mb, float mr = 10): a(ma),b(mb),r(mr)
  {
	  printf("construct circle_2d\n");
  }
  circle_2d(Param m)
  {
    a = m.A;
    b = m.B;
    r = m.C;
  }
 
  // x,y input curent position
  // and output next position x y
  float next(float x, float y){
	  printf("next radius=%f\n",r);
	  return (x+y)*r;
  }
};
 
 
BOOST_PYTHON_MODULE(libbot) {
  // const
  // boost::python::scope().attr("yes") = 1;
  // boost::python::scope().attr("no") = 0;
  boost::python::class_<Param>("Param", boost::python::init<float, float, float>());
  boost::python::class_<circle_2d>(
      "circle_2d", boost::python::init<float, float, float>())
      .def(boost::python::init<Param>())
      .def("next", &circle_2d::next);
 
}