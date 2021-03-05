#ifndef RW_H
#define RW_H
#include <math.h>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
using namespace Eigen;

class rw
{
private:
    char m_rsep;
    string m_rpath;
    string m_rheader;
    string m_rfilename;
       int m_rskip;
       int m_rskipRows;
       int m_rskipCols;
       int m_rFirstNRows;
       int m_rFirstNCols;
    ios_base::openmode m_wmode;
    string m_wsep;
    string m_wpath;
    string m_wheader;
    string m_wfilename;
       int m_wskip;
       int m_wskipRows;
       int m_wskipCols;
public:
    rw();
    void write (const MatrixXd& t_Mat);
    static void write(const MatrixXd& t_Mat, const std::string& t_wfilename);
    static void write(const MatrixXd& t_Mat, const std::string& t_wfilename, const std::string& t_wheader);
    static void write(const MatrixXd& t_Mat, const std::string& t_wfilename, const std::string& t_wheader, const int& t_wskip);
    static void append(const MatrixXd& t_Mat, const std::string& t_wfilename);
    template<typename M>
    M load_file (const std::string & t_rfilename);
    MatrixXd load_file (const std::string& t_rfilename);
    void set_wMode(ios_base::openmode t_wmode);
    void set_wSep(const string& t_wsep);
    void set_wPath(const std::string & t_wpath);
    void set_wHeader(const string& t_wheader);
    void set_wSkip(const int& t_wskip);
    void set_wSkipRows(const int& t_wskipRows);
    void set_wSkipCols(const int& t_wskipCols);
    void set_wFilename(const string& t_wfilename);

    void set_rSep(const char& t_rsep);
    void set_rPath(const std::string & t_rpath);
    void set_rHeader(const string& t_rheader);
    void set_rSkip(const int& t_rskip);
    void set_rSkipRows(const int& t_rskipRows);
    void set_rSkipCols(const int& t_rskipCols);
    void set_rFilename(const string& t_rfilename);
    void set_rFirstNRows(const int& t_rFirstNRows);
    void set_rFirstNCols(const int& t_rFirstNCols);

    bool is_num(const std::string& t_s);
    template<typename T>
    std::string type2str(T t_value);
};

template<typename M>
M rw::load_file (const std::string & t_rfilename)
{
    m_rfilename = t_rfilename;
    cout<<"Reading file "<<m_rfilename<<"...";
    std::ifstream indata;
    std::ifstream indataHeader;
    //indata.open(m_rpath+"/"+m_rfilename);//std::ios_base::binary
    indata.open(m_rfilename);//std::ios_base::binary
    //indataHeader.open(m_rpath+"/"+m_rfilename);
    indataHeader.open(m_rfilename);
    std::string line;
    std::vector<double> values;
    std::vector<string> valuesHeader;
    int rows = 0, cols = 0,ii = 0; //skipRows = 0, skipCols = 0;
    // Read lines and skip first 5 rows

    /*Exclude header. */
    int nHeader = 0;
    /*while(std::getline(indataHeader, line)){// Read row from indataHeader
        std::stringstream lineStream(line);
        std::string cell;
        /*while (std::getline(lineStream, cell, m_rsep)){
            if(!is_num(cell)){// If cell is not numeric
                std::getline(indata, line);// Read row from indata
                nHeader++;
                break;
            }
        }
    }*/

    //cout<<"Number?"<<std::boolalpha<<is_num("11.63741")<<endl;
    bool exit = false;
    int aux = 0;
    while (std::getline(indata, line) and !exit)
    {
        if(ii<m_rskipRows){
            ii++;
        }else{
            std::stringstream lineStream(line);
            std::string cell;
            int jj = 0;
            cols = 0;

            // Read columns and skip first column
            while (std::getline(lineStream, cell, m_rsep)){
                if(jj<m_rskipCols){
                    jj++;
                }else if(!is_num(cell)) {
                    //values.push_back(0);
                    //++cols;
                    //++aux;// -> Number of invalid rows
                    --rows;
                    break;
                }else{
                    values.push_back(std::stod(cell));
                    ++cols;
                }
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

    return Map<const Matrix<typename M::Scalar, M::RowsAtCompileTime, M::ColsAtCompileTime, RowMajor>>(values.data(), rows, values.size()/rows);
}





template<typename T>
std::string rw::type2str(T value)
{
    std::ostringstream oss;

    oss << value;
    return oss.str();
}
#endif // RW_H


