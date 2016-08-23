// Compute the dot product AB.BC

int dot(vector<int>A,vector<int>B,vector<int>C){
	
   vector<int>AB(2);
   vector<int>BC(2);

   AB[0]=B[0]-A[0];
   AB[1]=B[1]-A[1];

   BC[0]=C[0]-B[0];
   BC[1]=C[1]-B[1];

   //AB=(x2-x1)i + (y2-y1)j
   //

   int dot=AB[0]*BC[0]+AB[1]*BC[1];
   return dot;
}

// AB * AC

int cross(vector<int>A,vector<int>B,vector<int>C){
 
   vector<int>AB(2);
   vector<int>AC(2);

   AB[0]=B[0]-A[0];
   AB[1]=B[1]-A[1];

   AC[0]=C[0]-A[0];
   AC[1]=C[1]-A[1];

   int cross=AB[0]*AC[1]-AC[0]*AB[1];

   return cross;
   
}

// Compute the distance from A to B

double distance(vector<int>A,vector<int>B){

   int d1=A[0]-B[0];
   int d2=A[1]-B[1];

   return sqrt(d1*d1+d2*d2);

}

// Compute the distance from AB to C
// if isSegment is true,  AB is a isSegment

double linePointDist(vector<int>A,vector<int>B,vector<int>C,int isSegment){
 
   double dist=cross(A,B,C)/distance(A,B); // Normal Perpendicular distance

   if(isSegment){

     int dot1=dot(A,B,C); // closest point outside line segment or not.
     if(dot1>0) return distance(B,C);

     int dot2=dot(B,A,C);
     if(dot2>0) return distance(A,C);

   }

   return abs(dist);


}
