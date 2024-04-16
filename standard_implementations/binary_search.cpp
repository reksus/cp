// (l, r) way of binary search both l & r exclusive

//   T T T F F F
//l0     l r     r0
// find first True ?

int l = -1, r = n;

// invariat is l0 - l are all true and r - r0 are all false

while(r - l > 1) { // there are still elements in the search space
  int m = l + (r-l)/2;
  if (arr[m]) 
    l = m;
  else
    r = m;
}
// here l is at the last T and r is at the first F 
// (do not whatever you want with it)
// this can be easily reversed if the monotonic seq is F F F F T T T 