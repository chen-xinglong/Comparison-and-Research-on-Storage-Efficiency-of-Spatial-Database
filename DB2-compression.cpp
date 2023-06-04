//for db2 compression
#include <iostream>
#include <ctime>
#include <random>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
//多边形个数一样，组成多边形的点数不同
const int polygons = 1000;//0-1
//const int polygons2 = 40;//2-8
int points[2] = {4,5};

int main() {
    
    std::default_random_engine e;
    std::uniform_real_distribution<double> u(0, 180); // 左闭右闭区间
    e.seed(time(0));

    ofstream fout[2];
    for (int i = 0;i < 2;++i)
    {
        string tmp = "./db2/"+to_string(points[i]) +".sql";
        fout[i].open(tmp,ios::out);
        fout[i].close();
        fout[i].open(tmp, ios::out | ios::app);
    }



    for (int i = 0; i < 2; i++) {
        fout[i] << "SET CURRENT SCHEMA \"10482\";" << endl;
        fout[i] << "drop table poly4;" << endl;
        fout[i] << "create table poly" << to_string(points[i]) << "(geometry db2gse.ST_Polygon);" << endl;
        //fout[i] << "SET QUOTED_IDENTIFIER ON;" << endl;
        for (int j = 0;j < polygons;++j)
        {
            //insert into poly1(geom) values(geometry::STGeomFromText('POINT (20 180)', 0));
            fout[i] <<"insert into poly"<<to_string(points[i])
                << "(geometry) values(db2gse.ST_Polygon('POLYGON((";
            //fout[i].setf(ios::fixed);
            //k==1
            double a = u(e), b = u(e);
            fout[i] /*<< fixed << setprecision(6)*/ << int(a) << " " << int(b) << ",";
            //
            for (int k = 2;k <= points[i];++k)
            {
                if(k!=points[i])
                    fout[i] /*<< fixed << setprecision(6)*/ << int(u(e)) << " " <<int( u(e)) << ",";
                else
                    fout[i] /*<< fixed << setprecision(6)*/ <<int(a) << " " << int(b) << "))',1));"<<endl;
            }
        }
        fout[i].close();
    }

   

    return 0;
}