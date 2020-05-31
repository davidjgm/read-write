#include <iostream>
#include "rw.h"
#include <Eigen/Dense>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
using namespace Eigen;

using namespace std;

int main(){

    MatrixXd x(4,4);
    //x<<1,2,3,4,5,6;
    x.setRandom(4,4);
    rw rwObj;
    rwObj.set_wSep(",");
    rwObj.set_wPath(".");
    rwObj.set_wSkip(0);
    rwObj.set_wFilename("x.csv");
    rwObj.set_wHeader("a,b,c,d");
    rwObj.write(x);
    std:string path ="x.csv";

    MatrixXd y;
    rwObj.set_rPath(".");
    y = rwObj.load_file<MatrixXd>("x.csv");

    cout<<"Testing if the read matrix is the same as the written file"<<endl;
    double tol(1e-3);

    if(((x-y).array().abs()<tol).all()){
        cout<<"  Passed"<<endl;
    }else{
        cout<<"  Error!"<<endl;
        assert(((x-y).array().abs()<tol).all());
    }
    remove("x.csv");
}
