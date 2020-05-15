#ifndef RW_H
#define RW_H
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
        char r_sep;
        string r_path;
        string r_header;
        string r_filename;
           int r_skip;
        string w_sep;
        string w_path;
        string w_header;
        string w_filename;
           int w_skip;
    public:
        rw();
        ~rw();
        void write (const MatrixXd& Mat);
        template<typename M>
        M load_file (const std::string & path);
        void set_wSep(const string& w_sep);
        void set_wPath(const std::string & w_path);
        void set_wHeader(const string& w_header);
        void set_wSkip(const int& w_skip);
        void set_wFilename(const string& w_filename);

        void set_rSep(const char& r_sep);
        void set_rPath(const std::string & r_path);
        void set_rHeader(const string& r_header);
        void set_rSkip(const int& r_skip);
        void set_rFilename(const string& r_filename);

        bool is_num(const std::string& s);
        template<typename T>
        std::string type2str(T value);
};

template<typename M>
M rw::load_file (const std::string & r_filename)
{
    this->r_filename = r_filename;
    cout<<"Reading file "<<r_filename<<"...";
    std::ifstream indata;
    std::ifstream indataHeader;
    indata.open(r_path+"/"+r_filename);
    indataHeader.open(r_path+"/"+r_filename);
    std::string line;
    std::vector<double> values;
    std::vector<string> valuesHeader;
    int rows = 0, cols = 0,ii = 0, skipRows = 0, skipCols = 0;
    // Read lines and skip first 5 rows

    /*Exclude header. */
    int nHeader = 0;
    while(std::getline(indataHeader, line)){// Read row from indataHeader
        std::stringstream lineStream(line);
        std::string cell;
        while (std::getline(lineStream, cell, r_sep)){
            if(!is_num(cell)){// If cell is not numeric
                std::getline(indata, line);// Read row from indata
                nHeader++;
                break;
            }
        }
    }

    //cout<<"Number?"<<std::boolalpha<<is_num("11.63741")<<endl;

    while (std::getline(indata, line))
    {
        if(ii<skipRows){
            ii++;
        }else{
            std::stringstream lineStream(line);
            std::string cell;
            int jj = 0;
            cols = 0;
            // Read columns and skip first column
            while (std::getline(lineStream, cell, r_sep))
            {
                if(jj<skipCols){
                    jj++;
                }else{
                    values.push_back(std::stod(cell));
                }
                ++cols;
            }
        ++rows;
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


