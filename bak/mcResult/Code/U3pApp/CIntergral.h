#pragma once

extern double uacos(double vx, int vn, double vphi, int vt);

extern double ubcos(double vx, int vn, double vphi, int vt);

extern double uccos(double vx, int vn, double vphi, int vt);

extern double uasin(double vx, int vn, double vphi, int vt);

extern double ubsin(double vx, int vn, double vphi, int vt);

extern double ucsin(double vx, int vn, double vphi, int vt);

extern double integral(double(*pfun)(double, int, double, int), double va, double vb, double vk, int vn, double vphi, int vt);