#include "rw.h"
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
using namespace Eigen;

rw::rw():
    m_rsep(','),
    m_rpath(""),
    m_rheader(""),
    m_rfilename("data.csv"),
    m_rskip(0),
    m_rskipRows(0),
    m_rskipCols(0),
    m_rFirstNRows(-1),
    m_rFirstNCols(-1),
    m_wmode(ios_base::out),
    m_wsep(","),
    m_wpath("."),
    m_wheader(""),
    m_wfilename("data.csv"),
    m_wskip(0),
    m_wskipRows(0),
    m_wskipCols(0)    
{}

bool rw::is_num(const std::string& t_s){
// Errors: if s="" it returns a true value
// Char. "\r" is found at the end of a line in Windows Encoding
    double ld;
    bool o;
    
    if(t_s.length()==1 or t_s=="" or t_s==" " or t_s.empty()){
    //std::cout<<"FALSE"<<std::endl;
        o = false;
    }else{ 
    o = ((std::istringstream(t_s) >> ld >> std::ws).eof());
    }
     return o;
}
/*
It writes a MatrixXd to a disk file.
    MatrixXd& Mat: Matrix to write.
    string path: Path of the file to write.
    string sep: Separator for each column. sep="," is a CSV file.
    int skipcols:
*/
void rw::write (const MatrixXd& t_Mat){
    //const static IOFormat CSVFormat(FullPrecision, DontAlignCols, ", ", "\n");
    //std::cout<<"Writing file "<<m_wfilename<<"...";
    std::ofstream outdata;
    outdata.open(m_wpath+"/"+m_wfilename,m_wmode);
    //outdata.precision(10);
    //cout.precision(17);

    // Convert header (string) to header_v (vector)
    std::stringstream ss(m_wheader);
    std::string cell;
    std::vector<string> header_v;
    while (std::getline(ss, cell, ',')){
        header_v.push_back(cell);
    }
    /* Check if number of names in header is equal to
        the number of columns in matrix. If not
        complete with UNKNOWN VAR. */
    if(!m_wheader.empty() && header_v.size()<t_Mat.cols()){
        std::cout<<endl
                <<"  WARNING: "
                "The header has "
                +type2str(header_v.size())+" variables (columns) and the matrix has "+type2str(t_Mat.cols())+" variables (columns). "
                "Check if matrix is in the form [rows=observations, cols=variables] or if you missed variables in the header. "
                "The unnamed variables have been replaced by UNKNOWN VAR."<<endl;
        while(header_v.size()!=t_Mat.cols()){
            header_v.push_back("UNKNOWN COL.");
        }
    }
    if(header_v.size()>t_Mat.cols()){
        cout<<endl
                <<"  WARNING: "
                  "The number of variables of the header is greater than the number of columns of the matrix. "
                  "The extra variables were ignored."<<endl;
    }
    /* If the header is not empty, fill the first line
        of the file with it. */
    if(!m_wheader.empty()){
        for(int j=0;j<t_Mat.cols();j++){
            //std::getline(ss, cell, ',');
            //header_v.push_back(cell);
            outdata<<header_v[j]<<m_wsep;
        }
        outdata<<"\n";
    }
    /* Fill the file with the matrix. */
    int fileRows(0), fileCols(0);
    for(int i=0;i<t_Mat.rows();i=i+1+m_wskip){
        fileCols = 0;
        for(int j=0;j<t_Mat.cols();j++){
            outdata<<t_Mat(i,j)<<m_wsep;
            fileCols++;
        }
        outdata<<"\n";
        fileRows++;
    }
    outdata.close();
    /*cout
        <<"  Done"<<endl
        <<"  File has: "<<endl
        <<"   Header's rows:       1"<<endl
        <<"   Variables (columns): "<<fileCols<<endl
        <<"   Observations (rows): "<<fileRows
        <<((fileRows<t_Mat.rows())?(". Some observations were skipped"
                                  ". Original matrix has "+rw::type2str(t_Mat.rows())+" observations"):(""))<<endl;
    */
}
void rw::append(const MatrixXd& t_Mat, const std::string& t_wfilename)
{
    rw obj;
    obj.set_wMode(ios_base::app);
    obj.set_wFilename(t_wfilename);
    obj.write(t_Mat);
}
void rw::write(const MatrixXd& t_Mat, const std::string& t_wfilename){
    rw obj;
    obj.set_wFilename(t_wfilename);
    obj.write(t_Mat);
}
void rw::write(const MatrixXd& t_Mat, const std::string& t_wfilename, const std::string& t_wheader){
    rw obj;
    obj.set_wFilename(t_wfilename);
    obj.set_wHeader(t_wheader);
    obj.write(t_Mat);
}
void rw::write(const MatrixXd& t_Mat, const std::string& t_wfilename, const std::string& t_wheader, const int& t_wskip){
    rw obj;
    obj.set_wFilename(t_wfilename);
    obj.set_wHeader(t_wheader);
    obj.set_wSkip(t_wskip);
    obj.write(t_Mat);
}
void rw::set_wMode(ios_base::openmode t_wmode)
{
    m_wmode = t_wmode;
}
void rw::set_wHeader(const string& t_wheader){
    m_wheader = t_wheader;
}

void rw::set_wSep(const string& t_wsep){
    m_wsep = t_wsep;
}

void rw::set_wPath(const string& t_wpath){
    m_wpath = t_wpath;
}
void rw::set_wFilename(const string& t_wfilename){
    m_wfilename = t_wfilename;
}
void rw::set_wSkip(const int& t_wskip){
    this->m_wskip = t_wskip;
}
void rw::set_wSkipRows(const int& t_wskipRows){
    m_wskipRows = t_wskipRows;
}
void rw::set_wSkipCols(const int& t_wskipCols){
    m_wskipCols = t_wskipCols;
}

void rw::set_rHeader(const string& t_rheader){
    m_rheader = t_rheader;
}
void rw::set_rSep(const char& t_rsep){
    m_rsep = t_rsep;
}

void rw::set_rPath(const string& t_rpath){
    m_rpath = t_rpath;
}
void rw::set_rFilename(const string& t_rfilename){
    m_rfilename = t_rfilename;
}
void rw::set_rSkip(const int& t_rskip){
    m_rskip = t_rskip;
}
void rw::set_rSkipRows(const int& t_rskipRows){
    m_rskipRows = t_rskipRows;
}
void rw::set_rSkipCols(const int& t_rskipCols){
    m_rskipCols = t_rskipCols;
}

void rw::set_rFirstNRows(const int& t_rFirstNRows){
    m_rFirstNRows = t_rFirstNRows;
}

void rw::set_rFirstNCols(const int& t_rFirstNCols){
    m_rFirstNCols = t_rFirstNCols;
}

/*

    for(int i=0;i<M.cols();i++){
        for(int j=0;j<M.rows();j=j+1+skip){
            outdata<<M(j,i)<<sep;
*/

MatrixXd rw::load_file (const std::string& t_rfilename)
{
    MatrixXd t_mat;
    m_rfilename = t_rfilename;
    cout<<"Reading file[] "<<m_rfilename<<"...";
    std::ifstream indata;
    std::ifstream indataHeader;
    indata.open(m_rpath+"/"+m_rfilename);
    indataHeader.open(m_rpath+"/"+m_rfilename);
    std::string line;
    std::vector<double> values;
    std::vector<string> valuesHeader;
    int rows = 0, cols = 0,ii = 0; //skipRows = 0, skipCols = 0;
    // Read lines and skip first 5 rows

    /*Exclude header. */
    int nHeader = 0;
    while(std::getline(indataHeader, line)){// Read row from indataHeader
        std::stringstream lineStream(line);
        std::string cell;
        while (std::getline(lineStream, cell, m_rsep)){
            if(!is_num(cell)){// If cell is not numeric
                //std::getline(indata, line);// Read row from indata
                nHeader++;
                break;
            }
        }
    }

    //cout<<"Number?"<<std::boolalpha<<is_num("11.63741")<<endl;
    bool exit = false;
    while (std::getline(indata, line))
    {
        if(ii<m_rskipRows){
            ii++;
        }else{
            std::stringstream lineStream(line);
            std::string cell;
            int jj = 0;
            cols = 0;
            // Read columns and skip first column
            while (std::getline(lineStream, cell, m_rsep))
            {
                if(jj<m_rskipCols){
                    jj++;
                }else{
                    values.push_back(std::stod(cell));
                }
                ++cols;
            }
            ++rows;
            exit = (rows>=m_rFirstNRows and m_rFirstNRows>0)?true:false;
        }
    }
    cout<<"  Done"<<endl
        <<"  File has: "<<endl
        <<"   Header's rows:       "<<nHeader<<endl
        <<"   Variables (columns): "<<cols<<endl
        <<"   Observations (rows): "<<rows<<endl;

    t_mat = Map<const Matrix<typename MatrixXd::Scalar, MatrixXd::RowsAtCompileTime, MatrixXd::ColsAtCompileTime, RowMajor>>(values.data(), rows, values.size()/rows);
    return t_mat;
}

