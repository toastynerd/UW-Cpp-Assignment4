//Tyler Morgan
//UW CPP Quarter 3 Assignment 4
//BitmapIterator.h

#pragma once
#include "IBitmapIterator.h"
#include "Bitmap.h"

class BitmapIterator : public IBitmapIterator
{
public:
  BitmapIterator();
  BitmapIterator(const HBitmap& bitmap);

  virtual void nextScanLine();
  virtual bool isEndOfImage() const;
  virtual void nextPixel();
  virtual bool isEndOfScanLine() const;
  virtual Color getColor() const;

  virtual int getBitmapWidth() const;
  virtual int getBitmapHeight() const;
private:
  HBitmap myBitmap;
  Bitmap::ScanLineIterator my ScanLine;
  Bitmap::ColorIterator myColor;
};

