#ifndef MATRIXHANDLER_H
#define MATRIXHANDLER_H

double *matrix_mult_left_vector(double *, double *, int);
double *matrix_mult_matrix(double *, double *, int);

//MARK: Rotation matrix

double *matrix_get_rotation_x(double);
double *matrix_get_rotation_y(double);
double *matrix_get_rotation_z(double);

double *matrix_get_shift(double, double, double);

double *matrix_get_scale(double);


#endif // MATRIXHANDLER_H
