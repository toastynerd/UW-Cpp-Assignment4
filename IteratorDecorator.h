//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//IteratorDecorator.h

#include "IBitmapIterator.h"

class IteratorDecorator
{
public:
  virtual void nextScanLine()
  {
    myOriginalIterator->nextScanLine();
  }

  virtual bool isEndOfImage() const
  {
    myOriginalIterator->isEndOfImage();
  }

  virtual void nextPixel()
  {
    myOriginalIterator->nextPixel();
  }

  virtual bool isEndOfScanLine() const
  {
    myOriginalIterator->isEndOfScanLine();
  }

  virtual Color getColor() const
  {
    myOriginalIterator->getColor();
  }

  virtual int getBitmapWidth() const
  {
    myOriginalIterator->getBitmapWidth();
  }

  virtual int getBitmapHeight() const
  {
    myOriginalIterator->getBitmapHeight();
  }

private:
  HBitmapIterator myOriginalIterator;
};

