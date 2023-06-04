
//for mysql¡¢postgres compression

#include <iostream>
#include <ctime>
#include <random>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
const int polygons = 100;
const int points[5] =
{
200,400,600,800,1000
};
//1000 points
//200 400 600 800 1000
//2000 4000 6000 8000
int main() {

    std::default_random_engine e;
    std::uniform_real_distribution<double> u(-43.5, 78.5); // ×ó±ÕÓÒ±ÕÇø¼ä
    e.seed(time(0));

    ofstream fout[5];
    for (int i = 0;i < 5;++i)
    {
        string tmp = "./mysql/" + to_string(points[i]) + ".sql";
        fout[i].open(tmp, ios::out);
        fout[i].close();
        fout[i].open(tmp, ios::out | ios::app);
    }



    for (int i = 0; i < 5; i++) {
        fout[i] << "use geo_test;" << endl;
        fout[i] << "drop table if exists poly"<< to_string(points[i])<<";" << endl;
        fout[i] << "create table poly" << to_string(points[i]) << "(geom geometry srid 4326);" << endl;
        for (int j = 0;j < polygons;++j)
        {
            fout[i] << "INSERT INTO poly"<< to_string(points[i]) << "(geom) VALUES (ST_PolygonFromText('POLYGON((";
            fout[i].setf(ios::fixed);
            //k==1
            double a = u(e), b = u(e);
            fout[i] << fixed << setprecision(6) << a << " " << b << ",";
            //
            for (int k = 2;k <= points[i];++k)
            {
                if (k != points[i])
                    fout[i] << fixed << setprecision(6) << u(e) << " " << u(e) << ",";
                else
                    fout[i] << fixed << setprecision(6) << a << " " << b << "))',4326));" << endl;
            }
        }
        fout[i] << "SELECT count(*) FROM poly"<<to_string(points[i])<<" WHERE ST_Contains(geom, ST_PolygonFromText('POLYGON((0 0,5 0,5 5, 0 5,0 0))', 4326));" << endl;
        fout[i].close();
    }

    return 0;
}