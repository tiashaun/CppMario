#include "locator.hpp"

void Locator::init ()
{
    Locator::graphics  = new Graphics();
    Locator::resources = new Resources();
}

void Locator::setGraphics (Graphics& graphics)
{
    Locator::graphics = &graphics;
}

void Locator::setResources (Resources& resources)
{
    Locator::resources = &resources;
}

Graphics& Locator::getGraphics ()
{
    return *graphics;
}

Resources& Locator::getResources ()
{
    return *resources;
}

Graphics*  Locator::graphics  = NULL;
Resources* Locator::resources = NULL;
