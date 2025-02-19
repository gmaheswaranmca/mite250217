int findFactorial(int N) {
    //base cond
    if(N <= 1) {
        return 1;
    }
    
    return N * findFactorial(N-1);//recursive call
}
/*
//N! = N * (N-1)!
//5! = 5 * 4!
     = 5 * 4 * 3!
     = 5 * 4 * 3 * 2!
     = 5 * 4 * 3 * 2 * 1!
     = 5 * 4 * 3 * 2 * 1
     = 5 * 4 * 3 * 2
     = 5 * 4 * 6
     = 5 * 24
     = 120
*/