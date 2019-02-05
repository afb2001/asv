// This file was written by Mostafa Hussein as part of his CS830 final project.

#ifndef DUBINS_H
#define DUBINS_H

typedef enum
{
    LSL = 0,
    LSR = 1,
    RSL = 2,
    RSR = 3,
    RLR = 4,
    LRL = 5
} DubinsPathType;

typedef struct
{
    /* the initial configuration */
    double qi[3];
    /* the lengths of the three segments */
    double param[3];
    /* model forward velocity / model angular velocity */
    double rho;
    /* the path type described */
    DubinsPathType type;
} DubinsPath;

#define EDUBOK        (0)   /* No error */
#define EDUBCOCONFIGS (1)   /* Colocated configurations */
#define EDUBPARAM     (2)   /* Path parameterisitation error */
#define EDUBBADRHO    (3)   /* the rho value is invalid */
#define EDUBNOPATH    (4)   /* no connection between configurations with this word */

typedef int (*DubinsPathSamplingCallback)(double q[3], double t, void* user_data);

int dubins_shortest_path(DubinsPath* path, double q0[3], double q1[3], double rho);


int dubins_path(DubinsPath* path, double q0[3], double q1[3], double rho, DubinsPathType pathType);

double dubins_path_length(DubinsPath* path);

double dubins_segment_length(DubinsPath* path, int i);

double dubins_segment_length_normalized( DubinsPath* path, int i );


DubinsPathType dubins_path_type(DubinsPath* path);


int dubins_path_sample(DubinsPath* path, double t, double q[3]);


int dubins_path_sample_many(DubinsPath* path, double stepSize, DubinsPathSamplingCallback cb, void* user_data);

int dubins_path_endpoint(DubinsPath* path, double q[3]);


int dubins_extract_subpath(DubinsPath* path, double t, DubinsPath* newpath);


#endif /* DUBINS_H */

