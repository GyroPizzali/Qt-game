#include "item.h"

Item::Item()
{

}

void Item::updateRect()
{
    item_rect.setX(x);
    item_rect.setY(y);
    item_rect.setWidth(w);
    item_rect.setHeight(h);
}
