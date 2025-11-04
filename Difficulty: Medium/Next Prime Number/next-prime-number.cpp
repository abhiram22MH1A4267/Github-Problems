// User function Template for C++

void getprimes(vector<int>&primes){
    primes[0] = primes[1] = 0;
    
    for(int i = 2; i <= (501 / 10); i++){
        for(int j = i+i; j < 501; j += i){
            primes[j] = 0;
        }
    }
}

int nextPrime(int n) {

    // code here to find next prime number
    // return next prime number
    vector<int>primes(501, 1);
    getprimes(primes);
    
    for(int i = n+1; i < 501; i++){
        if(primes[i] == 1) return i;
    }
    
    return 0;
}