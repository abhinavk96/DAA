/*
 * *
 * Copyright (C) 2008  Bert Huang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdlib.h>

int recursiveSelect(float *V, int *inds, int start, int end, int k)
{
    /*recursively partitions vector V to find kth element */
    int pivot, i, tmp;
    float tmpdbl;
        
    if (start==end-1) /* active set is only one entry    */
        return inds[start];
    
    /*otherwise pick pivot and split */
    pivot = start;
    
    for (i=start+1; i<end; i++) {
        /* put all entries greater than V[pivot] to the left of pivot*/
     
        
        if (V[i]>V[pivot]) {
            /* first move pivot value up one index */
            tmp = inds[pivot];
            tmpdbl = V[pivot];
            inds[pivot] = inds[pivot+1];
            V[pivot] = V[pivot+1];
            inds[pivot+1] = tmp;
            V[pivot+1] = tmpdbl;
            
            
            if (i>pivot+1) {
                /* now we need to swap i th with pivot-1 th */
                tmp = inds[pivot];
                tmpdbl = V[pivot];
                inds[pivot] = inds[i];
                V[pivot] = V[i];
                inds[i] = tmp;
                V[i] = tmpdbl;
            }
            
            pivot++;            
        }
        
    }
        
    if (pivot==k)
        return inds[pivot];
    /* now we decide if kth is to the right of the pivot or the left */
    else if (pivot > k) {
        return recursiveSelect(V,inds,start,pivot,k);
    } else {
        return recursiveSelect(V,inds,pivot+1,end,k);
    }
}


int quickselect(float *V, int N, int k)
{
    /* returns the index of the kth greatest value in vector V */
    float *Vcopy;
    int i, *inds, ret;

    if (k>=N) {
        return -1;
    }
    if (k<0) {
        return -1;
    }
    
    Vcopy = (float*)malloc(N*sizeof(float));
    inds = (int*)malloc(N*sizeof(int));
    
    for (i=0; i<N; i++) {
        Vcopy[i] = V[i];
        
        inds[i] = i;
    }
    
    ret = recursiveSelect(Vcopy,inds,0,N,k);
        
    
    free(Vcopy);
    free(inds);
    return ret;
}

