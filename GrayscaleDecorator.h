//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//GrayscaleDecorator.h
//

#pragma once

#include "IBitmapIterator.h"

class GrayscaleDecorator: public IBitmapIterator
{
public:
  GrayscaleDecorator(const HBitmapIterator& originalIterator)
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
    int averageItensity = (originalColor.getRed() +
                           originalColor.getBlue() +
                           originalColor.getGreen()) /3; 
    return Color(averageItensity,averageItensity,averageItensity);
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


