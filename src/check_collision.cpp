#include <bn_log.h>

#include "check_collision.h"

void check_collision(bn::vector<Orbiter, Orbiter::MAX_ORBITERS> &orbiters)
{
    // This is the radius of an orbiters sprite
    bn::fixed r = 4;

    bn::vector<bool, Orbiter::MAX_ORBITERS> index_to_remove = {};

    for (int k = 0; k < orbiters.size(); k++)
    {
        index_to_remove.push_back(false);
    }

    // i represents x and j represents y; radius is the same for colliding pairs
    // Use distance formula: (x2 - x1)^2 + (y2 - y1)^2 <= (2r)^2
    for (int i = 0; i < orbiters.size(); i++)
    {
        // Nested for loop checks every possible pair every frame
        for (int j = i + 1; j < orbiters.size(); j++)
        {
            // These variables represent the x and y coordiates of two orbiters
            bn::fixed x1 = orbiters[i]._sprite.x();
            bn::fixed x2 = orbiters[j]._sprite.x();
            bn::fixed y1 = orbiters[i]._sprite.y();
            bn::fixed y2 = orbiters[j]._sprite.y();

            // Butano has no math function for powers so a workaroud is needed
            // These are expanded polynomials for each x and y binomial pairing
            bn::fixed x_dist = ((x1 * x1) - (2 * x1 * x2) + (x2 * x2));
            bn::fixed y_dist = ((y1 * y1) - (2 * y1 * y2) + (y2 * y2));
            // This is meant to be the two radii of each object, but all orbiters are the same size
            bn::fixed r_dist = (2 * r) * (2 * r);

            // Uses distance formula to check if a pair of orbiters intersect with each other
            if (x_dist + y_dist <= r_dist)
            {
                index_to_remove[i] = true;
                index_to_remove[j] = true;
                BN_LOG("Collided! Orbiters ", i, " and ", j);
                // orbiters.erase(orbiters.begin() + i);
                // orbiters.erase(orbiters.begin() + (j - 1));
            }
        }
    }
    for (int k = orbiters.size() - 1; k >= 0; k--)
    {
        if (index_to_remove[k])
            orbiters.erase(orbiters.begin() + k);
    }
}
