#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>

class Parameters
{
public:
    Parameters();
};


class PathParameters: public Parameters{
private:
    std::string path;
public:
    PathParameters(std::string _path):path(_path){
    }
    std::string get_path(){
        return path;
    }
};

class brightAndContrastParameters: public Parameters{
private:
    int nBright; // may not be 'int'
    int nContrast;
public:
    brightAndContrastParameters(int bright = 0, int contrast = 100):nBright(bright), nContrast(contrast){}

    int get_nBright(){return nBright;}
    int get_nContrast(){return nContrast;}
};

class IntParameters :public Parameters {
private:
    int value;
public:
    IntParameters(int v) :value(v) {}
    void setvalue(int v) { value = v; }
    int getvalue() { return value; }
};

class Int2Parameters :public Parameters {
private:
    int value1;
    int value2;
public:
    Int2Parameters(int v, int u) :value1(v),value2(u) {}
    void setvalue(int v, int u) { value1 = v; value2 = u; }
    int getvalue1() { return value1; }
    int getvalue2() { return value2; }
};

class DoubleParameters :public Parameters {
private:
    double value;
public:
    DoubleParameters(double v) :value(v) {}
    void setvalue(double v) { value = v; }
    int getvalue() { return value; }
};

class MouseMoveParameters: public Parameters {
private:
    double x_s;
    double y_s;
    double x_e;
    double y_e;
public:
    MouseMoveParameters() :x_s(0), y_s(0), x_e(0), y_e(0) {}
    void set_start_pnt(double vx_s, double vy_s) { x_s = vx_s; y_s = vy_s; }
    void set_end_pnt(double vx_e, double vy_e) { x_e = vx_e; y_e = vy_e; }
    double getx_s() { return x_s; }
    double gety_s() { return y_s; }
    double getx_e() { return x_e; }
    double gety_e() { return y_e; }

};

class SubtitleParameters: public Parameters {
private:
    string text;
    int startframe;
    int endframe;
    double x;
    double y;
    double r;
    double g;
    double b;
    int size;
    bool isbold;
public:
    int getstartframe(){return startframe;}
    int getendframe(){return endframe;}
    string gettext(){return text;}
    double getx(){return x;}
    double gety(){return y;}
    double getr(){return r;}
    double getg(){return g;}
    double getb(){return b;}
    int getsize(){return size;}
    bool getisbold(){return isbold;}
};
#endif // PARAMETERS_H
