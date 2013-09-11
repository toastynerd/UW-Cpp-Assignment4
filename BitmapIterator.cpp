//Tyler Morgan
//UW CPP Quarter 3 Assignment 4
//BitmapIterator.cpp

#include "BitmapIterator.h"


BitmapIterator::BitmapIterator(const HBitmap& bitmap)
  :myBitmap(bitmap),
  myScanLine(bitmap->begin()),
  myColor(myScanLine->begin())
{
}

void BitmapIterator::nextScanLine()
{
  ++myScanLine;
  if(myScanLine != myBitmap->end())
  {
    myColor = myScanLine->begin();
  }
}

bool BitmapIterator::isEndOfImage() const
{
  return myScanLine == myBitmap->end();
}

void BitmapIterator::nextPixel()
{
  ++myColor;
}

bool BitmapIterator::isEndOfScanLine() const
{
  return myColor== myScanLine->end();
}

Color BitmapIterator::getColor() const
{
  return *myColor;
}

int BitmapIterator::getBitmapWidth() const
{
  return myBitmap->getWidth();
}

int BitmapIterator::getBitmapHeight() const
{
  return myBitmap->getHeight();
}





