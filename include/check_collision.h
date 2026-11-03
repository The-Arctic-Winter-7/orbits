#pragma once

#include <bn_vector.h>
#include <bn_unique_ptr.h>

#include "Orbiter.h"

void check_collision(bn::vector<Orbiter, Orbiter::MAX_ORBITERS> &orbiters);