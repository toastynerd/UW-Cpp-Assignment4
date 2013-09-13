//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//ReverseColorDecorator.h

#pragma once

#include "IBitmapIterator.h"

class ReverseColorDecorator: public IBitmapIterator
{
public:
  ReverseColorDecorator(const HBitmapIterator& originalIterator)
    :myOriginalIterator(originalIterator) { }

  virtual void nextScanLine()
  {
    myOriginalIterator->nextScanLine();
  }

  virtual bool isEndOfImage() const
  {
    return myOriginalIterator->isEndOfImage();
  }

  virtual void nextPixel()
  {
    myOriginalIterator->nextPixel();
  }

  virtual bool isEndOfScanLine() const
  {
    return myOriginalIterator->isEndOfScanLine();
  }

  virtual Color getColor() const
  {
    Color originalColor = myOriginalIterator->getColor();
    return Color(255 - originalColor.getRed(), 255 - originalColor.getGreen(), 255- originalColor.getBlue());
  }

  virtual int getBitmapWidth() const
  {
    return myOriginalIterator->getBitmapWidth();
  }

  virtual int getBitmapHeight() const
  {
    return myOriginalIterator->getBitmapHeight();
  }

private:
  HBitmapIterator myOriginalIterator;
};


