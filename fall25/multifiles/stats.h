//header guard
#ifndef STATS_H
#define STATS_H

//
/// \brief Returns the maximum of two vals
/// \param a One of the values
/// \param b The other value
//
int max(int a, int b);
int min(int a, int b);
double avg (int a, int b);
//
/// \brief Returns the ratio of n to d
/// \pre d may not be zero
//
double ratio (int n, int d);
#endif // STATS_H
