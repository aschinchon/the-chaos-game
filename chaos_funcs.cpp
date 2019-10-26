#include <Rcpp.h>
using namespace Rcpp;

// Function createChaos1:
// A point inside a polygon repeatedly jumps half of the distance towards a randomly 
// chosen vertex, but the currently chosen vertex cannot be the same as the previously 
// chosen vertex.

// [[Rcpp::export]]
DataFrame createChaos1(int n, 
                       int n_vertex,
                       double x0, 
                       double y0) {
  // create the columns
  NumericVector x(n);
  NumericVector y(n);
  
  int v;
  
  x[0] = x0;
  y[0] = y0;
  
  int v_prev = 98;
  
  for(int i = 1; i < n; ++i) {
    
    // Pick a vertex
    v = rand() % n_vertex + 1;
    while(v==v_prev){
      v = rand() % n_vertex + 1;
    };
    
    v_prev = v;
    
    // Coordinates of vertex
    double angle = (v-1)*2*M_PI/n_vertex + M_PI/2;
    
    double vx = cos(angle);
    double vy = sin(angle);
    
    // Distance of current point to vertex
    double d = sqrt(pow(x[i-1]-vx,2)+pow(y[i-1]-vy,2));
    
    // Direction
    double a = atan2(vy-y[i-1], vx-x[i-1]);
    
    // New point  
    x[i] = x[i-1] + (d/2)*cos(a);
    y[i] = y[i-1] + (d/2)*sin(a);
    
  }
  // return a new data frame
  return DataFrame::create(_["x"]= x, _["y"]= y);
}

// Function createChaos2:
// A point inside a polygon repeatedly jumps half of the distance towards 
// a randomly chosen vertex, but the currently chosen vertex cannot neighbor 
// the previously chosen vertex if the two previously chosen vertices are the same.

// [[Rcpp::export]]
DataFrame createChaos2(int n, 
                      int n_vertex,
                      double x0, 
                      double y0) {
  // create the columns
  NumericVector x(n);
  NumericVector y(n);
  
  int v;
  
  x[0] = x0;
  y[0] = y0;
  int v_prev2 = 99;
  int v_prev1 = 98;
  
  for(int i = 1; i < n; ++i) {

    

    // Pick a vertex
    if (v_prev1 == v_prev2){
      v = rand() % n_vertex + 1;
      // Pick a vertex
          while (abs(v-v_prev1)==1 ||
                 (v+1) % n_vertex == v_prev1 ||
                 (v_prev1+1) % n_vertex == v
                   
                 
            //  (n_vertex+1) % v == v_prev1 || 
            //     abs(v-v_prev1)==1 ||
            //     (n_vertex+1) % v_prev1 == v
            ){
            v = rand() % n_vertex + 1;
          }
      
     } else {
      v = rand() % n_vertex + 1;  
    };
    v_prev2 = v_prev1;
    v_prev1 = v;
    
    // Coordinates of vertex
    double angle = (v-1)*2*M_PI/n_vertex + M_PI/2;
    
    double vx = cos(angle);
    double vy = sin(angle);
    
    // Distance of current point to vertex
    double d = sqrt(pow(x[i-1]-vx,2)+pow(y[i-1]-vy,2));
    
    // Direction
    double a = atan2(vy-y[i-1], vx-x[i-1]);
      
    // New point  
    x[i] = x[i-1] + (d/2)*cos(a);
    y[i] = y[i-1] + (d/2)*sin(a);

  }
  // return a new data frame
  return DataFrame::create(_["x"]= x, _["y"]= y);
}

// Function createChaos3:
// A point inside a polygon repeatedly jumps half of the distance towards 
// a randomly chosen vertex, but the currently chosen vertex cannot neighbor 
// the previously chosen vertex if the three previously chosen vertices are the same.


// [[Rcpp::export]]
DataFrame createChaos3(int n, 
                       int n_vertex,
                       double x0, 
                       double y0) {
  // create the columns
  NumericVector x(n);
  NumericVector y(n);
  
  int v;
  
  x[0] = x0;
  y[0] = y0;
  int v_prev3 = 99;
  int v_prev2 = 98;
  int v_prev1 = 97;
  
  for(int i = 1; i < n; ++i) {
    
    
    
    // Pick a vertex
    if (v_prev1 == v_prev2 && v_prev2 == v_prev3){
      v = rand() % n_vertex + 1;
      // Pick a vertex
      while (abs(v-v_prev1)==1 ||
             (v+1) % n_vertex == v_prev1 ||
             (v_prev1+1) % n_vertex == v
               
               
               //  (n_vertex+1) % v == v_prev1 || 
               //     abs(v-v_prev1)==1 ||
               //     (n_vertex+1) % v_prev1 == v
      ){
        v = rand() % n_vertex + 1;
      }
      
    } else {
      v = rand() % n_vertex + 1;  
    };
    v_prev3 = v_prev2;
    v_prev2 = v_prev1;
    v_prev1 = v;
    
    // Coordinates of vertex
    double angle = (v-1)*2*M_PI/n_vertex + M_PI/2;
    
    double vx = cos(angle);
    double vy = sin(angle);
    
    // Distance of current point to vertex
    double d = sqrt(pow(x[i-1]-vx,2)+pow(y[i-1]-vy,2));
    
    // Direction
    double a = atan2(vy-y[i-1], vx-x[i-1]);
    
    // New point  
    x[i] = x[i-1] + (d/2)*cos(a);
    y[i] = y[i-1] + (d/2)*sin(a);
    
  }
  // return a new data frame
  return DataFrame::create(_["x"]= x, _["y"]= y);
}

