// SQL SERVER SPATIAL INDEX
#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
#include <random>
#include<iomanip>
using namespace std;
//2000、4000、6000、8000、10000 polygons
//每个polygon 5 个点。
const int num[5] = { 200,400,600,800,1000 };
const int points = 5;
const string level = "MEDIUM";//HIGH LOW MEDIUM
const string CELLS_PER_OBJ = "16";
int main()
{
	std::default_random_engine e;
	std::uniform_real_distribution<double> u(-43.5, 78.5); // 左闭右闭区间
	e.seed(time(0));

    ofstream fout[5];
    for (int i = 0;i < 5;++i)
    {
        string tmp = "./ss/" + to_string(num[i]) + "ss.sql";
        fout[i].open(tmp, ios::out);
        fout[i].close();
        fout[i].open(tmp, ios::out | ios::app);

    }



    for (int i = 0; i < 5; i++) {//5 files
        fout[i] << "use geom;" << endl;
        fout[i] << "drop table if exists poly" << to_string(num[i]) << ";" << endl;
        fout[i] << "create table poly" << to_string(num[i]) << "(id int not null PRIMARY KEY,geom geography);" << endl;
        fout[i] << "SET QUOTED_IDENTIFIER ON;" << endl;
        for (int j = 1;j <= num[i];++j)//num[i] polygons
        {
       
            fout[i] << "insert into poly" << to_string(num[i])
                << "(id,geom) values("<< to_string(j)<<",geography::STGeomFromText('POLYGON((";
            fout[i].setf(ios::fixed);
            //k==1
            double a = u(e), b = u(e);
            fout[i] << fixed << setprecision(6) << a << " " << b << ",";
            //
            for (int k = 2;k <= points;++k)//points points per polygons
            {
                if (k != points)
                    fout[i] << fixed << setprecision(6) << u(e) << " " << u(e) << ",";
                else
                    fout[i] << fixed << setprecision(6) << a << " " << b << "))', 4326).MakeValid());" << endl;
            }
        }
        fout[i] << "CREATE SPATIAL INDEX idx_poly" << to_string(num[i]) << " ON poly"<< to_string(num[i]) <<"(geom)"
            << " USING GEOGRAPHY_GRID"
            << " WITH(GRIDS = (LEVEL_1 = "<<level<<", LEVEL_2 = "<<level<<", LEVEL_3 = " << level << ", LEVEL_4 = " << level << "), CELLS_PER_OBJECT = " << CELLS_PER_OBJ << ");" << endl;
        fout[i].close();
    }


	return 0;
}