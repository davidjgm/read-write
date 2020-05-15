#include "rw.h"
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
using namespace Eigen;

rw::rw():
    w_sep(","),
    w_header(""),
    w_skip(0),
    w_path("."),
    w_filename("data.csv"),
    r_sep(','),
    r_header(""),
    r_skip(0),
    r_path("."),
    r_filename("data.csv")
{}

rw::~rw(){}

bool rw::is_num(const std::string& s){
// Errors: if s="" it returns a true value
    double ld;
    return((std::istringstream(s) >> ld >> std::ws).eof());
}
/*
It writes a MatrixXd to a disk file.
    MatrixXd& Mat: Matrix to write.
    string path: Path of the file to write.
    string sep: Separator for each column. sep="," is a CSV file.
    int skipcols:
*/
void rw::write (const MatrixXd& Mat){
    //const static IOFormat CSVFormat(FullPrecision, DontAlignCols, ", ", "\n");
    cout<<"Writing file "<<w_filename<<"...";
    std::ofstream outdata;
    outdata.open(w_path+"/"+w_filename);
    //outdata.precision(10);
    //cout.precision(17);

    // Convert header (string) to header_v (vector)
    std::stringstream ss(w_header);
    std::string cell;
    std::vector<string> header_v;
    while (std::getline(ss, cell, ',')){
        header_v.push_back(cell);
    }
    /* Check if number of names in header is equal to
        the number of columns in matrix. If not
        complete with UNKNOWN VAR. */
    if(!w_header.empty() && header_v.size()<Mat.cols()){
        cout<<endl
                <<"  WARNING: "
                "The header has "
                +type2str(header_v.size())+" variables (columns) and the matrix has "+type2str(Mat.cols())+" variables (columns). "
                "Check if matrix is in the form [rows=observations, cols=variables] or if you missed variables in the header. "
                "The unnamed variables have been replaced by UNKNOWN VAR."<<endl;
        while(header_v.size()!=Mat.cols()){
            header_v.push_back("UNKNOWN COL.");
        }
    }
    if(header_v.size()>Mat.cols()){
        cout<<endl
                <<"  WARNING: "
                  "The number of variables of the header is greater than the number of columns of the matrix. "
                  "The extra variables were ignored."<<endl;
    }
    /* If the header is not empty, fill the first line
        of the file with it. */
    if(!w_header.empty()){
        for(int j=0;j<Mat.cols();j++){
            //std::getline(ss, cell, ',');
            //header_v.push_back(cell);
            outdata<<header_v[j]<<w_sep;
        }
        outdata<<"\n";
    }
    /* Fill the file with the matrix. */
    int fileRows(0), fileCols(0);
    for(int i=0;i<Mat.rows();i=i+1+w_skip){
        fileCols = 0;
        for(int j=0;j<Mat.cols();j++){
            outdata<<Mat(i,j)<<w_sep;
            fileCols++;
        }
        outdata<<"\n";
        fileRows++;
    }
    outdata.close();
    cout
        <<"  Done"<<endl
        <<"  File has: "<<endl
        <<"   Header's rows:       1"<<endl
        <<"   Variables (columns): "<<fileCols<<endl
        <<"   Observations (rows): "<<fileRows
        <<((fileRows<Mat.rows())?(". Some observations were skipped"
                                  ". Original matrix has "+rw::type2str(Mat.rows())+" observations"):(""))<<endl;


}

void rw::set_wHeader(const string& w_header){
    this->w_header = w_header;
}

void rw::set_wSep(const string& w_sep){
    this->w_sep = w_sep;
}

void rw::set_wPath(const string& w_path){
    this->w_path = w_path;
}
void rw::set_wFilename(const string& w_filename){
    this->w_filename = w_filename;
}
void rw::set_wSkip(const int& w_skip){
    this->w_skip = w_skip;
}
void rw::set_rHeader(const string& r_header){
    this->r_header = r_header;
}
void rw::set_rSep(const char& r_sep){
    this->r_sep = r_sep;
}

void rw::set_rPath(const string& r_path){
    this->r_path = r_path;
}
void rw::set_rFilename(const string& r_filename){
    this->r_filename = r_filename;
}
void rw::set_rSkip(const int& r_skip){
    this->r_skip = r_skip;
}
/*

    for(int i=0;i<M.cols();i++){
        for(int j=0;j<M.rows();j=j+1+skip){
            outdata<<M(j,i)<<sep;
*/



