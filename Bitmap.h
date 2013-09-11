#pragma once

#include "Color.h"
#include <list>
#include <memory>

class Bitmap
{
public:
    typedef std::list<Color> ScanLine;
    typedef ScanLine::iterator ColorIterator;

private:
    typedef std::list<ScanLine> ScanLineCollection;

public:
    typedef ScanLineCollection::iterator ScanLineIterator;

    Bitmap(int width, int height, std::istream& sourceStream);

    ScanLineIterator begin();
    ScanLineIterator end();

    int getWidth() const;
    int getHeight() const;
    int getNumberOfPadBytes() const;

    void read(std::istream& sourceStream);
    void write(std::ostream& destinationStream) const;

private:
    int myWidth;
    int myHeight;
    int myNumberOfPadBytes;

    ScanLineCollection myScanLines;
};

typedef std::shared_ptr<Bitmap> HBitmap;
