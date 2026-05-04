#ifndef ENERGY_MODEL_H
#define ENERGY_MODEL_H

#define BASE_ENERGY 10.0
#define ENERGY_PER_UNIT_DISTANCE 0.5
#define PAYLOAD_WEIGHT_FACTOR 0.1

double calculate_total_energy(double distance, double payload_weight);

#endif
