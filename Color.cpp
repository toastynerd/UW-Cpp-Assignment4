#include "Color.h"

Color::Color(
    const Binary::Byte& red,
    const Binary::Byte& green,
    const Binary::Byte& blue)
    : myRed(red),
    myGreen(green),
    myBlue(blue)
{
}

Color Color::read(std::istream& sourceStream)
{
    Color color(0, 0, 0);
    color.myBlue = Binary::Byte::read(sourceStream);
    color.myGreen = Binary::Byte::read(sourceStream);
    color.myRed = Binary::Byte::read(sourceStream);
    return color;
}

void Color::write(std::ostream& destinationStream) const
{
    myBlue.write(destinationStream);
    myGreen.write(destinationStream);
    myRed.write(destinationStream);
}

Binary::Byte Color::getRed() const
{
    return myRed;
}

Binary::Byte Color::getGreen() const
{
    return myGreen;
}

Binary::Byte Color::getBlue() const
{
    return myBlue;
}

std::ostream& operator<<(std::ostream& os, const Color& color)
{
    color.write(os);
    return os;
}

