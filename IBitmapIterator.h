//Tyler Morgan 
//UW CPP Quarter 3 assignment 4
//IBitmapIterator.h

#pragma once

#include <memory>

class Color;

class IBitmapIterator
{
public:
  virtual ~IBitmapIterator() { }

  virtual void nextScanLine() = 0;
  virtual bool isEndOfImage() const = 0;
  virtual void nextPixel()= 0;
  virtual bool isEndOfScanLine() const = 0;
  virtual Color getColor() const = 0;

  virtual int getBitmapWidth() const = 0;
  virtual int getBitmapHeight() const = 0;
};

typedef std::shared_ptr<IBitmapIterator> HBitmapIterator;

