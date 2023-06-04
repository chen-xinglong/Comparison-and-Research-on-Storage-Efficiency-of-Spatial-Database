//for sql server compression
#include <iostream>
#include <ctime>
#include <random>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
//多边形个数一样，组成多边形的点数不同
const int polygons = 200;//0-1
//const int polygons2 = 40;//2-8
const int points[5] =
{
7,8,9,10,11
};
//1000 points
//200 400 600 800 1000
//2000 4000 6000 8000
int main() {

    std::default_random_engine e;
    std::uniform_real_distribution<double> u(-43.5, 78.5); // 左闭右闭区间
    e.seed(time(0));

    ofstream fout[5];
    for (int i = 0;i < 5;++i)
    {
        string tmp = "./ss/"+to_string(points[i]) +"ss.sql";
        fout[i].open(tmp,ios::out);
        fout[i].close();
        fout[i].open(tmp,ios::out|ios::app);
    }



    for (int i = 0; i < 5; i++) {
        fout[i] << "use geom;" << endl;
        fout[i] << "drop table if exists poly" << to_string(points[i]) << ";" << endl;
        fout[i] << "create table poly" << to_string(points[i]) << "(geom geography);" << endl;
        fout[i] << "SET QUOTED_IDENTIFIER ON;" << endl;
        for (int j = 0;j < polygons;++j)
        {
            //insert into poly1(geom) values(geometry::STGeomFromText('POINT (20 180)', 0));
            fout[i] <<"insert into poly"<<to_string(points[i])
                << "(geom) values(geography::STGeomFromText('POLYGON((";
            fout[i].setf(ios::fixed);
            //k==1
            double a = u(e), b = u(e);
            fout[i] << fixed << setprecision(6) << a << " " << b << ",";
            //
            for (int k = 2;k <= points[i];++k)
            {
                if(k!=points[i])
                    fout[i] << fixed << setprecision(6) << u(e) << " " << u(e) << ",";
                else
                    fout[i] << fixed << setprecision(6) <<a << " " << b << "))', 4326).MakeValid());"<<endl;
            }
        }
        fout[i].close();
    }

    //for (int i = 2; i < 5; i++) {
    //    fout[i] << "use geom;" << endl;
    //    fout[i] << "create table poly" << to_string(points[i]) << "(geom geography);" << endl;
    //    fout[i] << "SET QUOTED_IDENTIFIER ON;" << endl;
    //    for (int j = 0;j < polygons2;++j)
    //    {
    //        
    //        //insert into poly1(geom) values(geometry::STGeomFromText('POINT (20 180)', 0));
    //        fout[i] << "insert into poly" << to_string(points[i])
    //            << "(geom) values(geography::STGeomFromText('POLYGON((";
    //        fout[i].setf(ios::fixed);
    //        //k==1
    //        double a = u(e), b = u(e);
    //        fout[i] << fixed << setprecision(6) << a << " " << b << ",";
    //        //
    //        for (int k = 2;k <= points[i];++k)
    //        {
    //            if (k != points[i])
    //                fout[i] << fixed << setprecision(6) << u(e) << " " << u(e) << ",";
    //            else
    //                fout[i] << fixed << setprecision(6) << a << " " << b << "))', 4326).MakeValid());" << endl;
    //        }
    //    }
    //    fout[i].close();
    //}

    return 0;
}