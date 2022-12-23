#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include <array>
#include <vector>
#include <string>
#include "../configs.h" //pour struct point et observer(subject)

// ###################################################################
class Printable {
 public:
  virtual bool contains(Point p) const = 0;
  virtual void print() = 0;
  virtual ~Printable()                 = default;
};

//--------------------------------------------------------------------
class Text : public virtual Printable {
  std::string   s;
  Point    center;
  int      fontSize;
  Fl_Color color;

 public:
  // Constructor
  Text(std::string s, Point center, int fontSize = 10, Fl_Color color = FL_BLACK)
      : s{std::move(s)}, center{center}, fontSize{fontSize}, color{color} {}

  // Draw
  void print() override;

  // Setters and getters
  std::string getString() { return s; }
  void   setString(const std::string &newString) { s = newString; }
  int    getFontSize() { return fontSize; }
  void   setFontSize(int newFontSize) { fontSize = newFontSize; }
  Point  getCenter() { return center; }
  void   setCenter(Point newCenter) { center = newCenter; }
  bool   contains(Point p) const override;
};


// ###################################################################
class Rectangle : public virtual Printable {
  Point    center;
  int      w, h;
  Fl_Color fillColor, frameColor;

 public:
  Rectangle(Point center, int w, int h, Fl_Color frameColor = FL_BLACK,
            Fl_Color fillColor = FL_WHITE);
  void     print() override;
  void     setFillColor(Fl_Color newFillColor);
  Fl_Color getFillColor() { return fillColor; }
  void     setFrameColor(Fl_Color newFrameColor);
  Fl_Color getFrameColor() { return frameColor; }
  void     setWidth(int neww) { w = neww; }
  void     setHeight(int newh) { h = newh; }
  int      getWidth() const { return w; }
  int      getHeight() const { return h; }
  bool     contains(Point p) const override;
  Point    getCenter() const { return center; }
};

//--------------------------------------------------------------------
class TextRectangle : public Text, public Rectangle {
 public:
  TextRectangle(Point center, int w, int h, std::string text, int fontSize = 10)
      : Text{std::move(text), center, fontSize}, Rectangle{center, w, h} {}
  bool contains(Point p) const override { return Rectangle::contains(p); }
  void print() override {
    Rectangle::print();
    Text::print();
  }
  ~TextRectangle() override {}
};

//--------------------------------------------------------------------
/*class IntRectangle : public TextRectangle, public Subject {
  int  theInteger = 0;
  void update() {
    setString(std::to_string(theInteger));
    notifyObservers();
  }

 public:
  IntRectangle(Point center, int w, int h, int theInteger, int textSize = 10)
      : TextRectangle{center, w, h, "", textSize}, theInteger{theInteger} {
    update();
  }
       operator int() { return theInteger; }
  int  getInteger() { return theInteger; }
  void setInteger(int newInteger) {
    theInteger = newInteger;
    update();
  }
};*/