#include "../include.hpp"
#include "MenuElement.hpp"

// COME FROM LABO 10

//--------------------------------------------------------------------
void Text::print() {
  fl_color(color);
  fl_font(FL_COURIER, fontSize);
  int width{0}, height{0};
  fl_measure(s.c_str(), width, height, false);
  int x = static_cast<int>(fl_transform_x(
      center.x - width / 2, center.y - fl_descent() + height / 2));
  int y = static_cast<int>(fl_transform_y(
      center.x - width / 2, center.y - fl_descent() + height / 2));
  fl_draw(s.c_str(), x, y);
}

bool Text::contains(Point p) const {
  int w{0}, h{0};
  fl_font(FL_COURIER, fontSize);
  fl_measure(s.c_str(), w, h, false);
  return p.x >= center.x - w / 2 && p.x < center.x + w / 2 &&
         p.y >= center.y - h / 2 && p.y < center.y + h / 2;
} 

//--------------------------------------------------------------------

Rectangle::Rectangle(Point center, int w, int h, Fl_Color frameColor,
                     Fl_Color fillColor)
    : center{center},
      w{w},
      h{h},
      fillColor{fillColor},
      frameColor{frameColor} {}

void Rectangle::print() {
  std::array<Point, 5> points{
      Point{center.x - w / 2, center.y - h / 2},
      Point{center.x - w / 2, center.y + h / 2},
      Point{center.x + w / 2, center.y + h / 2},
      Point{center.x + w / 2, center.y - h / 2},
      Point{center.x - w / 2, center.y - h / 2}
  };
  fl_color(fillColor);
  fl_begin_polygon();
  for (auto &point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_polygon();
  fl_color(frameColor);
  fl_begin_line();
  for (auto &point : points) {
    fl_vertex(point.x, point.y);
  }
  fl_end_line();
}

void Rectangle::setFillColor(Fl_Color newFillColor) {
  this->fillColor = newFillColor;
}

void Rectangle::setFrameColor(Fl_Color newFrameColor) {
  frameColor = newFrameColor;
}

bool Rectangle::contains(Point p) const {
  return p.x >= center.x - w / 2 && p.x < center.x + w / 2 &&
         p.y >= center.y - h / 2 && p.y < center.y + h / 2;
}