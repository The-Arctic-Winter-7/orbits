#include "Center.h"

Center::Center(bn::fixed_point starting_position, bn::fixed mass, bn::fixed speed) : _sprite(bn::sprite_items::sun.create_sprite(starting_position)),
                                                                                     _mass(mass),
                                                                                     _speed(speed)
{
}

void Center::update()
{
    dPadMoveSprite(_sprite, _speed);
}

bn::fixed_point Center::position()
{
    return _sprite.position();
}

bn::fixed Center::mass()
{
    return _mass;
}