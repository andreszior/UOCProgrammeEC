#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "vaccine.h"

// Initialize a vaccine
tError vaccine_init(tVaccine* vac, const char* name, tVaccineTec tec, tVaccinePhase phase) {
    // PR1 EX2

     return ERR_NOT_IMPLEMENTED;
}

// Release memory used by a vaccine
void vaccine_free(tVaccine* vac) {
    // PR1 EX2
   
}

// Compare two vaccines
bool vaccine_equals(tVaccine* vac1, tVaccine* vac2) {
    // PR1 EX2
  
    return false;
}

// Copy a vaccine
tError vaccine_cpy(tVaccine* dest, tVaccine* src) {
    // PR1 EX2

    return ERR_NOT_IMPLEMENTED;
}

// Add an authorized country to a vaccine
tError vaccine_add_authorized_country(tVaccine* vac, tCountry* country) {
    // PR1 EX2

    return ERR_NOT_IMPLEMENTED;

}
