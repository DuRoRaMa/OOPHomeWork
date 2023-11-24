#include <iostream>
#include <fstream>

struct Figure {
    std::string stroke;
    double stroke_width;
};
struct Line:Figure{
    double x1;
    double y1;
    double x2;
    double y2;
    Line (double x_1,double y_1,double x_2,double y_2,std::string _stroke  ,double _stroke_width ){
        x1=x_1;
        y1=y_1;
        y2=y_2;
        x2=x_2;
        stroke = _stroke;
        stroke_width = _stroke_width;
    }



};
std::ostream& operator <<(std::ostream& os, const Line& l){
    return os <<"<line x1=\"" << l.x1 << "\" y1=\"" << l.y1 << "\" x2=\"" << l.x2 << "\" y2=\"" << l.y2 << "\" stroke=\""<<l.stroke<<"\" stroke-width=\""<<l.stroke_width<<"\" />";
}
struct Rect:Figure{
    double x1;
    double y1;
    double width;
    double height;
    std::string fill;
    Rect (double x_1,double y_1,double _width,double _height, std::string _fill){
        x1=x_1;
        y1 = y_1;
        width=_width;
        height=_height;
        fill = _fill;
    }
};
std::ostream& operator <<(std::ostream& os, const Rect& r){
    return os <<"<rect x=\"" << r.x1 << "\" y=\"" << r.y1 << "\" width=\"" << r.width << "\" height=\"" << r.height << "\" fill=\""<<r.fill<<"\" />";
}
struct Poligon:Figure{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
    std::string fill;
    Poligon (double x_1,double y_1,double x_2,double y_2,double x_3,double y_3,double x_4,double y_4, std::string _fill){
        x1=x_1;
        y1=y_1;
        x2=x_2;
        y2=y_2;
        x3=x_3;
        y3=y_3;
        x4=x_4;
        y4=y_4;
        fill = _fill;
    }

};
std::ostream& operator <<(std::ostream& os, const Poligon& p){
    return os <<"<polygon points=\"" << p.x1 << "," << p.y1 << " " << p.x2 << "," << p.y2 << " " << p.x3 << "," << p.y3 << " " << p.x4 << "," << p.y4 << "\" fill=\""<<p.fill<<"\" />";
};
int main() {
    std::ofstream svg("img.svg");
    Line line(570,800,1000,0,"#f2a577",100);
    Rect rect(500,0,500,700,"#dbc39d");
    Poligon poly(550,130,500,300,810,250,890,100,"#c33d2c");
    Poligon poly2(550,330,575,480,830,400,890,250,"#da614e");
    Poligon poly3(750,370,900,470,990,370,970,225,"#d56746");
   svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"700\">";
   svg << rect << std::endl << line <<std::endl <<poly <<poly3 << poly2;
   svg << "</svg>";
   svg.close();
    return 0;
}
