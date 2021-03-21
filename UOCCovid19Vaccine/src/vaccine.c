#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "vaccine.h"

// Initialize a vaccine
tError vaccine_init(tVaccine* vac, const char* name, tVaccineTec tec, tVaccinePhase phase) {
   // PR1 EX2

    assert(vac != NULL);
    assert(name != NULL);
	
	vac->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	if (vac->name == NULL) {
        return ERR_MEMORY_ERROR;
	}
	strcpy(vac->name, name);
	
	vac->vaccineTec = tec;
    vac->vaccinePhase = phase;
	
	vac->authCountries = (tCountryTable*)malloc(sizeof(tCountryTable));
	countryTable_init(vac->authCountries);
     //return ERR_NOT_IMPLEMENTED; 
	 return OK;
}

// Release memory used by a vaccine
void vaccine_free(tVaccine* vac) {
    // PR1 EX2
	assert(vac != NULL);
    if (vac != NULL) {
        free(vac->name);
        free(vac->authCountries);
        
        vac->name = NULL;
        vac->authCountries = NULL;
    } 
}

// Compare two vaccines
bool vaccine_equals(tVaccine* vac1, tVaccine* vac2) {
    // PR1 EX2
  assert(vac1 != NULL);
    assert(vac2 != NULL);

    if (strcmp(vac1->name, vac2->name) != 0) {
        return false;
    }
    return true;
}

// Copy a vaccine
tError vaccine_cpy(tVaccine* dest, tVaccine* src) {
    // PR1 EX2
	//tError error;
    //int i;

    assert(dest != NULL);
    assert(src != NULL);

	vaccine_init(src, src->name, src->vaccineTec, src->vaccinePhase);
	src = dest;
	src->name = dest->name;
	src->vaccineTec = dest->vaccineTec;
	src->vaccinePhase = dest->vaccinePhase;

	
	countryTable_free(src->authCountries);
	countryTable_init(src->authCountries);
	countryTable_cpy(dest->authCountries, src->authCountries);
	countryTable_free(dest->authCountries);
	countryTable_init(dest->authCountries);


    return OK; 
    //return ERR_NOT_IMPLEMENTED;
}

// Add an authorized country to a vaccine
tError vaccine_add_authorized_country(tVaccine* vac, tCountry* country) {
	
	countryTable_add(vac->authCountries, country);
	
 /*  
 // PR1 EX2
	tCountryTable* auxVac;
    tError error;
    //Declare preconditions
    assert(vac->authCountries != NULL);
    assert(country != NULL);
	
	auxVac = NULL;
    //Check if the country has the vac authorized already
    if(countryTable_find(auxVac, country->name))
    {
        return ERR_DUPLICATED;
    }
    // we must allocate space for the new vac
    if (auxVac->size == 0) {
        auxVac = (tCountryTable*)malloc((auxVac->size + 1) * sizeof(tCountryTable));

        //check again 
        if (auxVac == NULL) {
            return ERR_MEMORY_ERROR;
        } else {
            vac->authCountries = auxVac; 
        }
         
    } else {
        vac->authCountries = (tCountryTable*)realloc(auxVac->elements, (auxVac->size + 1) * sizeof(tCountryTable));
        //check if the memory is allocated
        if (auxVac == NULL) {
            return ERR_MEMORY_ERROR;
        } else {
           vac->authCountries = auxVac;
           vac->authCountries->size = 1; 
        }
        
    }
    error = vaccine_init(&(vac[vac->authCountries->size - 1]), vac->name, vac->vaccineTec, vac->vaccinePhase);
    if (error != OK) {
        return ERR_NOT_IMPLEMENTED;
    }
*/
    return OK;
}
    //return ERR_NOT_IMPLEMENTED;
