#ifndef __FIRDES_AUTOTEST_H__
#define __FIRDES_AUTOTEST_H__

#include "autotest/autotest.h"
#include "liquid.h"

void autotest_design_rrcos_filter() {

    // Initialize variables
    unsigned int k=2, m=3;
    float beta=0.3f;
    float offset=0.0f;

    // Initialize pre-determined coefficient array
    float h0[13] = {
       -3.311577E-02, 
        4.501582E-02, 
        5.659688E-02, 
       -1.536039E-01, 
       -7.500154E-02, 
        6.153450E-01, 
        1.081972E+00, 
        6.153450E-01, 
       -7.500154E-02, 
       -1.536039E-01, 
        5.659688E-02, 
        4.501582E-02,
       -3.311577E-02}; 

    // Create filter
    float h[13];
    design_rrc_filter(k,m,beta,offset,h);

    // Ensure data are equal
    unsigned int i;
    for (i=0; i<13; i++)
        CONTEND_DELTA( h[i], h0[i], 0.00001f );
}


#endif // __FIRDES_AUTOTEST_H__

