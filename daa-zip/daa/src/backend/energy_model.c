#include "energy_model.h"

double calculate_total_energy(double distance, double payload_weight) {
    double weight_factor = 1.0 + (payload_weight * PAYLOAD_WEIGHT_FACTOR);
    return BASE_ENERGY + (distance * ENERGY_PER_UNIT_DISTANCE * weight_factor);
}
