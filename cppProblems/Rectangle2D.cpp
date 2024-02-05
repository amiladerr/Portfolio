#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(){
    x = 0;
    y = 0;
    width = 1;
    height = 1;
}
Rectangle2D::Rectangle2D(double x, double y, double width, double height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
double Rectangle2D::getX() const{
    return x;
}
double Rectangle2D::getY() const{
    return y;
}
double Rectangle2D::getWidth() const{
    return width;
}
double Rectangle2D::getHeight() const{
    return height;
}
void Rectangle2D::setX(double x){
    this->x = x;
}
void Rectangle2D::setY(double y){
    this->y = y;
}
void Rectangle2D::setWidth(double width){
    this->width = width;
}
void Rectangle2D::setHeight(double height){
    this->height = height;
}
double Rectangle2D::getArea() const{
    return width * height;
}
double Rectangle2D::getPerimeter() const{
    return 2 * (width * height);
}
bool Rectangle2D::contains(double x, double y) const{
	if (x < (this->x + (.5*this->width)) && x > (this->x - (.5*this->width)) &&
        y < (this->y + (.5*this->height)) && y > (this->y - (.5*this->height)))
		return true;
	else
		return false;
}
bool Rectangle2D::constains(const Rectangle2D& r) const{
    int thisLeft = this->x;
    int thisRight = this->x + this->width;
    int thisTop = this->y;
    int thisBottom = this->y + this->height;

    int otherLeft = r.getX();
    int otherRight = r.getX() + r.getWidth();
    int otherTop = r.getY();
    int otherBottom = r.getY() + r.getHeight();

    return thisLeft <= otherLeft && otherRight <= thisRight &&
             thisTop <= otherTop && otherBottom <= thisBottom;
}
bool Rectangle2D::overlaps(const Rectangle2D& r) const{
    float left1, top1, right1, bottom1, left2, top2, right2, bottom2;
    left1 = this->x;
    top1 = this->y;
    right1 = this->x + this->width;
    bottom1 = this->y - this->height;
    left2 = r.getX();
    top2 = r.getY();
    right2 = r.getX() + r.getWidth();
    bottom2 = r.getY() - r.getHeight();

    return !(top1 < bottom2 || top2 < bottom1 || right1 < left2 || right2 < left1);
}
